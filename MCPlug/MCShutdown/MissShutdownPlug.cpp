#include "MissShutdownPlug.h"
#include "GUIFrame.h"
#include <wx/artprov.h>
#include <wx/image.h>
#include <wx/msgdlg.h>
#include "Shutdown.xpm"

#define _WIN32_WINNT 0x0500

#include <windows.h>

MissShutdownPlug::MissShutdownPlug():
MissTaskPlugBase(wxT("定时关机"),wxT("3261B663-0415-4B99-AA91-58D9EB043172"))
{
    //ctor
}

MissShutdownPlug::~MissShutdownPlug()
{
    //dtor
}

void MissShutdownPlug::GetIcon(wxImage& image)
{
    //wxBitmap icon = wxIcon( wxT("RC_SHUTDOWN_ICON"), wxBITMAP_TYPE_ICO_RESOURCE, 48, 48 );
    wxBitmap icon = wxIcon(Shutdown_xpm);
    image = icon.ConvertToImage();
}

void MissShutdownPlug::InitPanel(wxWindow* parent)
{
    m_pan = new MCShutdown(parent);
}

wxString MissShutdownPlug::GetTaskContent()
{
    wxString strRet;
    int nSelect = static_cast<MCShutdown*>(m_pan)->m_rBoxShutdown->GetSelection();
    if(static_cast<MCShutdown*>(m_pan)->m_cbtnForce->GetValue())
    {
        nSelect += 3;
    }
    strRet.Printf(wxT("%d"), nSelect );
    return strRet;
}

#define SHTDN_REASON_MAJOR_OPERATINGSYSTEM 0x00020000
#define SHTDN_REASON_MINOR_UPGRADE 0x00000003
#define SHTDN_REASON_FLAG_PLANNED 0x80000000

void MissShutdownPlug::TimeUpRun(tm* tmNow, const wxString& strTaskContent)
{
    unsigned long nType(0);
    unsigned int uFlags(0);
    bool bToken(true);
    if(strTaskContent.ToULong(&nType))
    {
        switch(nType % 3)
        {
        case 0:
            bToken = AdjustToken();
            uFlags = EWX_SHUTDOWN;
            break;
        case 1:
            bToken = AdjustToken();
            uFlags = EWX_REBOOT;
            break;
        case 2:
            uFlags = EWX_LOGOFF;
            break;
        }

        if(bToken)
        {
            uFlags |= (nType / 3 == 1) ? EWX_FORCE : EWX_FORCEIFHUNG;

            if (!ExitWindowsEx(uFlags ,
                SHTDN_REASON_MAJOR_OPERATINGSYSTEM |
                SHTDN_REASON_MINOR_UPGRADE |
                SHTDN_REASON_FLAG_PLANNED))
            {
                ///TODO：关机失败
            }
        }
        else
        {
            ///TODO：获取关机权限失败
            wxMessageBox(wxT("非常抱歉，该用户没有关机权限。"));
        }
    }
}

void MissShutdownPlug::Release()
{
}

void MissShutdownPlug::InitData(const wxString& strTaskContent)
{
    unsigned long nIndex;
    if(strTaskContent.ToULong(&nIndex))
    {
        static_cast<MCShutdown*>(m_pan)->m_cbtnForce->SetValue(nIndex / 3 == 1);
        static_cast<MCShutdown*>(m_pan)->m_rBoxShutdown->SetSelection(nIndex % 3);
    }
}

wxString MissShutdownPlug::s_strDescription[] = {wxT("关机"), wxT("重启"), wxT("注销"),wxT("强制")};

wxString MissShutdownPlug::GetDescription(const wxString& strTaskContent)
{
    wxString strRet;
    unsigned long nIndex;
    if(strTaskContent.ToULong(&nIndex))
    {
        if(nIndex / 3 == 1)
        {
            strRet =  s_strDescription[3];
        }
        strRet += s_strDescription[nIndex % 3];
    }

    return strRet;
}

bool MissShutdownPlug::HasShortcutMenu()
{
    return true;
}

bool MissShutdownPlug::AdjustToken()
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
    TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        return false;

    // Get the LUID for the shutdown privilege.

    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.

    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
    (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS)
        return false;

    return true;
}
