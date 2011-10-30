#define WIN32_LEAN_AND_MEAN

//#include <windows.h>
#include <time.h>
#include <sys/timeb.h>
#include <winsock.h>
#include "CMissDDE.h"
#include <iostream>

HINSTANCE hInst;

const int NTP_PORT = 123;
const int JAN_1970 = 0x83aa7e80;

/* How to multiply by 4294.967296 quickly (and not quite exactly)
* without using floating point or greater than 32-bit integers.
* If you want to fix the last 12 microseconds of error, add in
* (2911*(x))>>28)
*/
#define NTPFRAC(x) (4294 * (x) + ((1981 * (x))>>11))

/* The reverse of the above, needed if we want to set our microsecond
 * clock (via settimeofday) based on the incoming time in NTP format.
 * Basically exact.
 */
#define USEC(x) (((x) >> 12) - 759 * ((((x) >> 10) + 32768) >> 16))

struct ntptime
{
	unsigned int coarse;
	unsigned int fine;
};


void send_packet(int fd)
{
	unsigned int data[12];
	/*struct timeval now;*/
	struct _timeb now;
	int ret;
#define LI 0
#define VN 3
#define MODE 3
#define STRATUM 0
#define POLL 4
#define PREC -6

	if (sizeof(data) != 48)
	{
		///fprintf(stderr,"size error\n");
		return;
	}

	memset((char*)data, 0, sizeof(data));
	data[0] = htonl((LI << 30) | (VN << 27) | (MODE << 24)
	              | (STRATUM << 16) | (POLL << 8) | (PREC & 0xff));
	data[1] = htonl(1<<16);  /* Root Delay (seconds) */
	data[2] = htonl(1<<16);  /* Root Dispersion (seconds) */
	_ftime(&now);
	/*gettimeofday(&now, NULL);*/
	data[10] = htonl(now.time + JAN_1970); /* Transmit Timestamp coarse */
	data[11] = htonl(NTPFRAC(now.millitm));  /* Transmit Timestamp fine   */
	ret = send(fd, (char*)data, 48, 0);
	///printf("Send packet to ntp server, ret: %d\n", ret);
}

void get_packet_timestamp(int usd, struct ntptime *udp_arrival_ntp)
{
	/*struct timeval udp_arrival;*/
	struct _timeb udp_arrival;

	_ftime(&udp_arrival);
	/*gettimeofday(&udp_arrival, NULL);*/
	udp_arrival_ntp->coarse = udp_arrival.time + JAN_1970;
	udp_arrival_ntp->fine   = NTPFRAC(udp_arrival.millitm);
}

void rfc1305print(unsigned int *data, struct ntptime *arrival, struct timeval* tv)
{
/* straight out of RFC-1305 Appendix A */
	int li, vn, mode, stratum, poll, prec;
	int delay, disp, refid;
	struct ntptime reftime, orgtime, rectime, xmttime;
//	struct tm *ltm;

#define Data(i) ntohl(((unsigned int *)data)[i])
	li      = Data(0) >> 30 & 0x03;
	vn      = Data(0) >> 27 & 0x07;
	mode    = Data(0) >> 24 & 0x07;
	stratum = Data(0) >> 16 & 0xff;
	poll    = Data(0) >>  8 & 0xff;
	prec    = Data(0)       & 0xff;
	if (prec & 0x80) prec|=0xffffff00;
	delay   = Data(1);
	disp    = Data(2);
	refid   = Data(3);
	reftime.coarse = Data(4);
	reftime.fine   = Data(5);
	orgtime.coarse = Data(6);
	orgtime.fine   = Data(7);
	rectime.coarse = Data(8);
	rectime.fine   = Data(9);
	xmttime.coarse = Data(10);
	xmttime.fine   = Data(11);
#undef Data

	tv->tv_sec = xmttime.coarse - JAN_1970;
	tv->tv_usec = USEC(xmttime.fine);
	/**
	ltm = localtime(&tv->tv_sec);
	printf("Get ntp server time: %.4d_%.2d_%.2d %.2d:%.2d:%.2d\n",
			ltm->tm_year + 1900,
			ltm->tm_mon + 1,
			ltm->tm_mday,
			ltm->tm_hour,
			ltm->tm_min,
			ltm->tm_sec);
    */
}

bool set_local_time(struct timeval &tv)
{
	SYSTEMTIME time;
	struct tm* ltm;

	ltm = localtime(&tv.tv_sec);
	time.wYear = ltm->tm_year + 1900;
	time.wMonth = ltm->tm_mon + 1;
	time.wDay = ltm->tm_mday;
	time.wHour = ltm->tm_hour;
	time.wMinute = ltm->tm_min;
	time.wSecond = ltm->tm_sec;
	time.wMilliseconds = 0;
	return (0 != SetLocalTime(&time));
//	{
		///perror("SetLocalTime");
//		return;
//	}

	///printf("set local time to ntp server's time.\n");
}

int TimeFunction(const char *pNTP_SERVER)
{
    int sock;
    struct sockaddr_in addr_src;
	struct sockaddr_in addr_dst;
	int addr_len = sizeof(struct sockaddr_in);
    CMissDDE dde;
    dde.DdeClientInit("MissClock","ToolTip");

	/*WSAStartup*/
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2), &wsadata);

    /* create socket. */
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (-1 == sock)
	{
		///perror("create socket");
		const wchar_t *strText = L"错误:create socket";
		dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
		return (1);
	}

	/* bind local address. */
	memset(&addr_src, 0, addr_len);
	addr_src.sin_family = AF_INET;
	addr_src.sin_addr.s_addr = htonl(INADDR_ANY);
	addr_src.sin_port = htons(0);
	if (-1 == bind(sock, (struct sockaddr*)&addr_src, addr_len))
	{
		///perror("bind socket");
        const wchar_t *strText = L"错误:bind socket";
		dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
		return (1);
	}

	/* connect to ntp server. */
	memset(&addr_dst, 0, addr_len);
	addr_dst.sin_family = AF_INET;
	{
		struct hostent* host = gethostbyname(pNTP_SERVER);
		if (NULL == host)
		{
			///perror("gethostbyname");
			const wchar_t *strText = L"抱歉:错误的URL";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
			return (1);
		}
		if (4 != host->h_length)
		{
			///fprintf(stderr, "host->h_length is not 4!\n");
			return (1);
		}
		memcpy(&(addr_dst.sin_addr.s_addr), host->h_addr_list[0], 4);
	}
	addr_dst.sin_port = htons(NTP_PORT);

	///printf("Connecting to ntp server: %s ip: %s port: %d ...\n",
	///       pNTP_SERVER, inet_ntoa(addr_dst.sin_addr), NTP_PORT);
	if (-1 == connect(sock, (struct sockaddr*)&addr_dst, addr_len))
	{
		///perror("connect ntp server");
        const wchar_t *strText = L"错误:connect ntp server";
        dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
		return (1);
	}

    //while (0)
	{
		fd_set fds_read;
		struct timeval timeout;
		int ret;

		unsigned int buf[12];
		int len;

		struct sockaddr server = {0};
		int svr_len = sizeof(struct sockaddr);
		struct ntptime arrival_ntp;
		struct timeval newtime;

		FD_ZERO(&fds_read);
		FD_SET(sock, &fds_read);

        send_packet(sock);

		timeout.tv_sec = 4;
		timeout.tv_usec = 0;
		ret = select(sock + 1, &fds_read, NULL, NULL, &timeout);
		if (-1 == ret)
		{
			///perror("select");
            const wchar_t *strText = L"错误:select";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
            return (1);
		}
		if(0 == ret)
        {
            ///超时，没有接收到数据
            const wchar_t *strText = L"汗~网络不是很通啊~，请关闭您的防火墙，并确定您的网络连接是否畅通，然后再试。";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
			return (1);
        }
		//if (0 == ret || !FD_ISSET(sock, &fds_read))
		//{
			/* send ntp protocol packet. */
		//	send_packet(sock);
		//	continue;
		//}

		/* recv ntp server's response. */
		len = recvfrom(sock, (char*)buf, sizeof(buf), 0, (struct sockaddr*)&server, &svr_len);
		if (-1 == len)
		{
			///perror("recvfrom");
			const wchar_t *strText = L"错误:recvfrom";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
			return (1);
		}
		/*
		if (0 == len)
		{
			//continue;
            const wchar_t *strText = L"汗~网络不是很通啊~，请关闭您的防火墙，并确定您的网络连接是否畅通，然后再试。";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
			return (1);
		}
		*/
        std::cout<<"get_packet_timestamp"<<std::endl;
		/* get local timestamp. */
		get_packet_timestamp(sock, &arrival_ntp);
		/* get server's time and print it. */
		rfc1305print(buf, &arrival_ntp, &newtime);
		/* set local time to the server's time, if you're a root user. */
		if(set_local_time(newtime))
        {
            const wchar_t *strText = L"网络校时成功。";
            dde.DdeCall(XTYP_POKE,
                L"恭喜",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
        }
        else
        {
            const wchar_t *strText = L"调整系统时间失败，请检查是否有权限。";
            dde.DdeCall(XTYP_POKE,
                L"抱歉",
                strText,
                sizeof(wchar_t)*(wcslen(strText)+1) );
        }
	}

	closesocket(sock);
	WSACleanup();
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    char* pNTP_SERVER = NULL;
    {
        int nStartIndex = -1;
        int nEndIndex = -1;
        int ix = -1;
        int nState = 0; ///0、无状态；1、接收指令状态；2、准备接收服务器地址状态；3、接收服务器地址
        while(lpCmdLine[++ix] != 0)
        {
            switch(nState)
            {
            case 0:
                if(lpCmdLine[ix] == '/')
                {
                    nState = 1;
                }
                break;
            case 1:
                {
                    switch(lpCmdLine[ix])
                    {
                    case 'n':
                    case 'N':
                        nState = 2;
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2:
                {
                    if(lpCmdLine[ix] != ' ' && lpCmdLine[ix] != '\t')
                    {
                        nStartIndex = ix;
                        nState = 3;
                    }
                }
                break;
            case 3:
                {
                    if(lpCmdLine[ix] == ' ' || lpCmdLine[ix] == '\t')
                    {
                        nEndIndex = ix;
                        nState = 4;
                    }
                }
                break;
            default:
                break;
            }
        }

        if(nEndIndex == -1)
        {
            nEndIndex = ix;
        }
        pNTP_SERVER = new char[nEndIndex - nStartIndex + 1];
        memcpy(pNTP_SERVER, &lpCmdLine[nStartIndex], nEndIndex - nStartIndex);
        pNTP_SERVER[nEndIndex - nStartIndex] = 0;
    }

    int nRet(0);
    if(pNTP_SERVER != NULL)
    {
        std::cout<<pNTP_SERVER<<std::endl;
        nRet = TimeFunction(pNTP_SERVER);
        std::cout<<nRet<<std::endl;
    }

    return nRet;
    // The user interface is a modal dialog box
    //return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}
