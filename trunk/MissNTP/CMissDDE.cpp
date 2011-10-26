#include "CMissDDE.h"
#include <iostream>

#define CF_TEXT 1

LPCSTR    CMissDDE::s_strSvrName = "MissClock";
CMissDDE* CMissDDE::s_pDDE = NULL;

CMissDDE::CMissDDE():
m_idInst(0),
m_hConv(NULL)
{
    //ctor
}

CMissDDE::~CMissDDE()
{
    //dtor
    if(m_hConv != NULL)
    DdeDisconnect(m_hConv);
}

HDDEDATA CALLBACK CMissDDE::DdeCallback(UINT uType, UINT uFmt, HCONV hconv, HSZ hsz1, HSZ hsz2,
                                        HDDEDATA hdata, ULONG_PTR dwData1, ULONG_PTR dwData2)
{
    std::cout<<"DdeCallback"<<std::endl;
    char szBuffer[100];
    switch(uType)
    {
    // 建立连接
    case XTYP_CONNECT:
        // 获得应用名
        DdeQueryString(s_pDDE->m_idInst,hsz2,
            szBuffer,sizeof(szBuffer),0);

        // 如果此应用不能被此服务器支持,返回NULL
        if(strcmp(szBuffer,s_strSvrName))  return NULL;
        // 获得topic名
        DdeQueryString(s_pDDE->m_idInst,hsz1,
            szBuffer,sizeof(szBuffer),0);
        std::cout<<"XTYP_CONNECT"<<std::endl;
        // 如果连接成功,返回1
        return (HDDEDATA)1;
    case XTYP_DISCONNECT:
        break;
    case XTYP_POKE:
        break;
    /*
    case XTYP_REQUEST:
        // 获得topic名
        DdeQueryString(s_pDDE->m_idInst,hsz1,
            szBuffer,sizeof(szBuffer),0);

        if(strcmp(szBuffer,"query")==0)
        {
            // 获得Item 名
            DdeQueryString(s_pDDE->m_idInst,hsz2,
                szBuffer,sizeof(szBuffer),0);

            strcpy(szBuffer,s_pDDE->m_strReply);
            return DdeCreateDataHandle(s_pDDE->m_idInst,
                (LPBYTE)szBuffer,sizeof(szBuffer),0,hsz2,CF_TEXT,0);
        }
        break;

    case XTYP_EXECUTE:
        // 获得topic名
        DdeQueryString(s_pDDE->m_idInst,hsz1,
            szBuffer,sizeof(szBuffer),0);
        if(strcmp(szBuffer,"data")==0)
        {
            // 获得数据
            DdeGetData(hData, (LPBYTE)szBuffer, 40L, 0L);
            s_pDDE->m_strRequest=szBuffer;
            return (HDDEDATA)1;
        }
        break;
    */
    }

    return NULL;
}


void CMissDDE::DdeCall(UINT iType, const wchar_t* szItem, const wchar_t* szBuffer, int nSize)
{
    HSZ hszItem     = DdeCreateStringHandle(m_idInst,(char*)szItem,CP_WINUNICODE);

    HDDEDATA hData;
    DWORD dwResult;
    switch(iType)
    {
    case XTYP_POKE:
        // 向服务器发送执行命令
        hData = DdeClientTransaction((LPBYTE)szBuffer,
            nSize, m_hConv,
            hszItem, CF_TEXT, iType, 5000, &dwResult);
        break;
    /*
    case XTYP_REQUEST:

        // 向服务器发送请求
        hData = DdeClientTransaction(NULL,0,hConv,
            hszItem, CF_TEXT, iType, 5000, &dwResult);

        // 从服务器取得返回值
        dwLength = DdeGetData(hData, (LPBYTE)szBuffer,sizeof(szBuffer), 0);
        if (dwLength > 0)
            m_strReply=szBuffer;
        break;
    case XTYP_EXECUTE:
        strcpy(szBuffer,m_strRequest);

        // 向服务器发送执行命令
        hData = DdeClientTransaction((LPBYTE)szBuffer,
            sizeof(szBuffer), hConv,
            hszItem, CF_TEXT, iType, 5000, &dwResult);
        break;
    */
    default:
        break;
    }


    DdeFreeStringHandle(m_idInst,hszItem);
}

void CMissDDE::DdeClientInit(LPCSTR szSvr, LPCSTR szTopic)
{

    s_pDDE = this;
    DdeInitialize(&m_idInst,NULL,APPCLASS_STANDARD|
        CBF_FAIL_ADVISES|
        CBF_FAIL_EXECUTES|
        CBF_FAIL_REQUESTS|
        CBF_SKIP_REGISTRATIONS|
        CBF_SKIP_UNREGISTRATIONS,0L);

    HSZ hszServName = DdeCreateStringHandle(m_idInst,szSvr,CP_WINANSI);
    HSZ hszTopic    = DdeCreateStringHandle(m_idInst,szTopic,CP_WINANSI);
    m_hConv         = DdeConnect(m_idInst,hszServName,hszTopic,NULL);
    DdeFreeStringHandle(m_idInst,hszServName);
    DdeFreeStringHandle(m_idInst,hszTopic);
}
/*
void CMyDde::DdeServer(CString strReply)
{
    m_strReply=strReply;
    fakeThis=this;
    // 建立DDE
    DdeInitialize(&idInst,DdeCallback,APPCLASS_STANDARD|
        CBF_FAIL_ADVISES|
        CBF_FAIL_POKES|
        CBF_SKIP_REGISTRATIONS|
        CBF_SKIP_UNREGISTRATIONS,0L);
    // 注册服务名MyDDEService,使该程序作为DDE服务器
    AppName="MyDDEService";
    HSZ hszService=DdeCreateStringHandle(idInst,AppName,0);
    DdeNameService(idInst,hszService,NULL,DNS_REGISTER);
}
*/
