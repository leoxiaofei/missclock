#include "MissTaskBarIcon.h"
#include <windef.h>
#include <shellapi.h>
//#include <Winbase.h>
#include <wx/frame.h>

class wxTaskBarIconWindow: public wxFrame {
    public:
        wxTaskBarIconWindow(wxTaskBarIcon* icon): wxFrame(NULL, wxID_ANY,
            wxEmptyString, wxDefaultPosition, wxDefaultSize, 0), m_icon(icon){}

        WXLRESULT MSWWindowProc(WXUINT msg, WXWPARAM wParam, WXLPARAM lParam) {
                return 0;
        }
    private:
        wxTaskBarIcon* m_icon;
};

MissTaskBarIcon::MissTaskBarIcon():
wxTaskBarIcon()
{
    //ctor
}

MissTaskBarIcon::~MissTaskBarIcon()
{
    //dtor
}


bool MissTaskBarIcon::ShowBalloon(wxString strTitle, wxString strMsg, int iconID, unsigned int timeout)
{
    if (!IsOk())
    {
        return false;
    }
    ///微软规定的...又不是我。
    assert(strTitle.Length() < 64);
    assert(strMsg.Length() < 256);

    NOTIFYICONDATA notifyData;
    notifyData.cbSize = sizeof(notifyData);
    notifyData.hWnd = (HWND)m_win->GetHWND();
    notifyData.uFlags = NIF_INFO;
    wcsncpy(notifyData.szInfoTitle,strTitle.c_str(),64);
    wcsncpy(notifyData.szInfo,strMsg.c_str(),256);

    //lstrcpyn(notifyData.szInfo, strMsg.c_str(), sizeof(notifyData.szInfo));
    //lstrcpyn(notifyData.szInfoTitle, strTitle.c_str(), sizeof(notifyData.szInfoTitle));
    notifyData.dwInfoFlags = iconID; // | NIIF_NOSOUND; modified by palinx
    notifyData.uTimeout = timeout;
    notifyData.uID = 99;

    if (m_iconAdded) {
        return (Shell_NotifyIcon(NIM_MODIFY, &notifyData) != 0);
    } else {
        return false;
    }
}
