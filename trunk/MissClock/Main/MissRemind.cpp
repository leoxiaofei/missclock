#include "MissRemind.h"
#include <wx/dcmemory.h>

#include "../Data/MissConfig.h"
//#include "../Data/MissRemindSkin.h"
//#include "../Data/MissXML.h"

#include <winuser.h>
#include <wx/timer.h>

#ifdef DrawText
#undef DrawText
#endif
MissRemind::MissRemind(const std::vector<wxString> &vecContent, wxWindow* parent )
:
MissRemindBase( parent ),
m_pTimer(new wxTimer(this))
{
///    m_pRemindSkin = &MissConfig::GetInstance().GetCurrentRemindSkin();
///    m_pRemindSkin->TakeOrderWithNewline(vecContent);
    m_hWnd = static_cast<HWND>(GetHandle());

    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);

    m_Blend.BlendOp = AC_SRC_OVER;      ///指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。
    m_Blend.BlendFlags = 0;             ///必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; ///该成员控制源和目标位图被解释的方式。
    m_Blend.SourceConstantAlpha = 255;

    std::cout<<"MissRemind"<<std::endl;


    Connect(wxEVT_TIMER, wxTimerEventHandler(MissRemind::OnTimer));
    Connect(wxEVT_FIRST_EVENT, wxCommandEventHandler(MissRemind::OnInitEvent), NULL, this);
    //wxTimerEvent send;
    //AddPendingEvent(send);

    wxCommandEvent send(wxEVT_FIRST_EVENT,GetId());
    AddPendingEvent(send);
}

void MissRemind::OnDrawSkin()
{
    //PatternInfo painfo;
///    m_pRemindSkin->LoadTempData();

///    m_SizeWindow.cx = m_pRemindSkin->GetOverallWidth();
///    m_SizeWindow.cy = m_pRemindSkin->GetOverallHeight();


    m_bpUI = wxBitmap(m_SizeWindow.cx, m_SizeWindow.cy, 32);
    BITMAP bm;
    ::GetObject(static_cast<HBITMAP>(m_bpUI.GetHBITMAP()), sizeof(bm), &bm);
    int nPixCount = bm.bmWidth * bm.bmHeight;
    unsigned int *pBitmap = static_cast<unsigned int*>(bm.bmBits);


    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc = {0, 0};

    int nPixTemp = nPixCount;
    unsigned int* pBitmapTemp = pBitmap;
    while (--nPixTemp)
    {
        *pBitmapTemp = 0xFF000000;
        ++pBitmapTemp;
    }

    wxMemoryDC memdc(m_bpUI);
    ///开始绘图
    //m_pRemindSkin->DrawSkin(memdc);

    //m_pRemindSkin->ClearTempData();


    nPixTemp = nPixCount;
    pBitmapTemp = pBitmap;
    while (--nPixTemp)
    {
        *pBitmapTemp -= 0x01000000;
        ++pBitmapTemp;
    }
    //MissXML::SaveRemindSkin(m_pRemindSkin);
    ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                          &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
    CentreOnScreen();
    //m_pTimer->Start(100);
}
/*
void MissRemind::OnDrawText()
{
    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc = {0, 0};
    //wxBitmap bpUI = wxBitmap(m_SizeWindow.cx, m_SizeWindow.cy, 32);
    //wxMemoryDC memdc(bpUI);
    //memdc.DrawBitmap(m_bpUI,0,0);
    wxMemoryDC memdc;
    memdc.SelectObjectAsSource(m_bpUI);
    static unsigned int uLen = 0;
    static unsigned int uCoutLen = m_pRemindSkin->GetRemindStringLength();
    if(uLen <= uCoutLen)
    {
        m_pRemindSkin->DrawText(memdc, ++++uLen);
        ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                        &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
    }
    else
    {
        ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                        &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
        m_pTimer->Stop();
    }
}
*/
void MissRemind::OnInitEvent(wxCommandEvent& event)
{
    OnDrawSkin();
}

void MissRemind::OnTimer(wxTimerEvent& event)
{
    //OnDrawText();
    //OnDrawSkin();
    //return;
}

void MissRemind::OnLeftDown(wxMouseEvent& event)
{
    /*
    if(m_pRemindSkin->PtInCloseBtn(event.GetPosition()))
    {
        Close();
    }
    */
    ///移动窗口 Windows API
    ::PostMessage(m_hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
}

void MissRemind::OnClose(wxCloseEvent& event)
{
    Destroy();
    //delete this;
}

DEFINE_LOCAL_EVENT_TYPE(wxEVT_FIRST_EVENT);

