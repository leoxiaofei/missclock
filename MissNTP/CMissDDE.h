#ifndef CMISSDDE_H
#define CMISSDDE_H

#include <windef.h>
#include <ddeml.h>

class CMissDDE
{
public:
    CMissDDE();
    virtual ~CMissDDE();
public:
    // 静态回调成员函数
    static HDDEDATA CALLBACK DdeCallback(
        UINT  uType, UINT  uFmt, HCONV hconv, HSZ   hsz1,
        HSZ   hsz2, HDDEDATA  hdata, ULONG_PTR dwData1, ULONG_PTR dwData2);

    void DdeCall(UINT iType, const wchar_t* szItem, const wchar_t* szBuffer = NULL, int nSize = 0);
    //void DdeServer(CString strReply);
    void DdeClientInit(LPCSTR szSvr, LPCSTR szTopic);

private:
    static CMissDDE* s_pDDE;
    DWORD            m_idInst;
    static LPCSTR    s_strSvrName;
    HCONV            m_hConv;
};

#endif // CMISSDDE_H
