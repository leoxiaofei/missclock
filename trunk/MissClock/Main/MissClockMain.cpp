/***************************************************************
 * Name:      MissClockMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-03-13
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "../StdAfx.h"

#include "MissClockMain.h"
#include "MissTaskBarIcon.h"
#include <wx/dcmemory.h>
#include <boost/progress.hpp>
#include <wx/menu.h>
#include "../Data/MissConfig.h"
#include "MissOption.h"
#include "../Data/MissSkin.h"
#include "../Data/MissXML.h"
#include "MissSoundThread.h"
//#include "../Common/MissFrame.h"
#include "../Common/MissGlobal.h"
#include <algorithm>

#include "windows.h"
//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

MissClockFrame::MissClockFrame(wxFrame* frame):
    GUIFrame(frame),
    m_pTaskBarIcon(new MissTaskBarIcon),
    m_pMainTimer(new wxTimer(this)),
    m_pSkin(new MissSkin),
    m_pConfig(new MissConfig),
    m_bRightMenu(true),
    m_bReloadSkin(false)
{
    m_hWnd = static_cast<HWND>(GetHandle());
    m_pTaskBarIcon->SetIcon(wxICON(RC_CLOCK_ICON), wxT("迷失日历时钟"));
    m_pMainTimer->Start(1000);
    InitEvent();
    InitUI();
    InitMenu();
    //MissFrame *a = new MissFrame(this);
    //a->Show();
}

MissClockFrame::~MissClockFrame()
{
    std::cout << "~MissClockFrame()" << std::endl;
    this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));
}

void MissClockFrame::InitEvent()
{
    this->Connect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));
    //sg_SecUp.connect(&MissClockFrame::UpdateClock);

    ConnectSlot(sg_MinUp,&MissClockFrame::CheckTask);
    ConnectSlot(sg_MinUp,&MissClockFrame::CheckAudioChimer);

    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_RIGHT_UP, (wxObjectEventFunction)&MissClockFrame::OnRightUp, NULL, this);
    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_LEFT_UP, (wxObjectEventFunction)&MissClockFrame::OnTaskBarIconLeftUP, NULL, this);
}

void MissClockFrame::InitUI()
{
    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);

    m_Blend.BlendOp = AC_SRC_OVER;      ///指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。 详情，请参阅下面的备注部分。
    m_Blend.BlendFlags = 0;             ///必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; ///该成员控制源和目标位图被解释的方式。
    UpdateAlpha();
    UpdateTheme();

    //设置时钟位置
    Move(m_pConfig->GetPos());
}

void MissClockFrame::InitMenu()
{
    m_pmimPin->Check(m_pConfig->GetPin());
    m_pmimShadow->Check(m_pConfig->GetShadow());
    m_pmimTop->Check(m_pConfig->GetTop());
    m_pmimShow->Check(m_pConfig->GetShowClock());

}

void MissClockFrame::UpdateAlpha()
{
    ///指定用于整张源位图的Alpha透明度值。(0~255)
    m_Blend.SourceConstantAlpha = m_pConfig->GetOpacity();
}

void MissClockFrame::UpdateTheme()
{
    MissXML::LoadSkin(m_pSkin, m_pConfig->GetSkinName());
    UpdateSize();
}

void MissClockFrame::OnTimer(wxTimerEvent& event)
{
    boost::progress_timer t;

    m_ttNow = time(NULL);
    m_tmNow = localtime(&m_ttNow);
    static int s_savemin = m_tmNow->tm_min;

    ///如果要显示时钟，那么每秒钟刷新界面
    if(m_pConfig->GetShowClock())
    {
        UpdateClock();
    }

    if (s_savemin != m_tmNow->tm_min)
    {
        OnMinUp();
        s_savemin = m_tmNow->tm_min;
    }
}

void MissClockFrame::OnLeftDown(wxMouseEvent& event)
{
    if(!m_pConfig->GetPin())
    {
        ///移动窗口 Windows API
        ::PostMessage(m_hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
    }
}

void MissClockFrame::OnRightUp(wxMouseEvent& event)
{
    //::SetForegroundWindow(m_hWnd);
    Raise();
    if(m_bRightMenu)
        PopupMenu(m_pMainMenu);
}

void MissClockFrame::OnTaskBarIconLeftUP(wxEvent& event)
{
    Raise();
}

void MissClockFrame::UpdateSize()
{
    m_SizeWindow.cx = static_cast<int>(m_pSkin->GetBGBitmap().GetWidth() * m_pConfig->GetZoom());
    m_SizeWindow.cy = static_cast<int>(m_pSkin->GetBGBitmap().GetHeight() * m_pConfig->GetZoom());
    m_bpUI = wxBitmap(m_SizeWindow.cx, m_SizeWindow.cy, 32);
    BITMAP bm;
    ::GetObject(static_cast<HBITMAP>(m_bpUI.GetHBITMAP()), sizeof(bm), &bm);
    m_nPixCount = bm.bmWidth * bm.bmHeight;
    m_pBitmap = static_cast<unsigned int*>(bm.bmBits);
}

bool MissClockFrame::UpdateClock()
{
    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc = {0, 0};

    static int nPixCount;
    static unsigned int* pBitmap;

    nPixCount = m_nPixCount;
    pBitmap = m_pBitmap;

    while (--nPixCount)
    {
        *pBitmap = 0x01000000;
        ++pBitmap;
    }

    wxMemoryDC memdc(m_bpUI);
    memdc.SetUserScale(m_pConfig->GetZoom(), m_pConfig->GetZoom());
    m_pSkin->DrawSkin(memdc, m_tmNow);

    nPixCount = m_nPixCount;
    pBitmap = m_pBitmap;
    while (--nPixCount)
    {
        *pBitmap -= 0x01000000;
        ++pBitmap;
    }
    return ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                          &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
}

void MissClockFrame::CheckTask()
{
}

void MissClockFrame::CheckAudioChimer()
{
    if ( m_tmNow->tm_min == 0 )
    {
        MissSoundThread *thread = new MissSoundThread(m_tmNow->tm_hour);
        if (thread->Create() == wxTHREAD_NO_ERROR)
        {
            thread->Run();
        }
        else
        {
             wxMessageBox( wxT(" Can't create thread !" ));
        }
    }
}

void MissClockFrame::OnExit(wxCommandEvent& event)
{
    wxCloseEvent send(wxEVT_CLOSE_WINDOW);
    /**
    ///关闭子对话框代码
    wxWindowList&list = GetChildren();
    for (wxWindowList::iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(dynamic_cast<wxDialog *>(*iter) != NULL)
        {
            (*iter)->ProcessEvent(send);
        }
    }
    */
    AddPendingEvent(send);
}

void MissClockFrame::OnClose(wxCloseEvent& event)
{
    /*
    wxWindowList&list = GetChildren();
    for (wxWindowList::iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(dynamic_cast<wxDialog *>(*iter) != NULL)
        {
            (*iter)->Close();
        }
    }
    */

    std::cout << "MissClockFrame::OnClose()" << std::endl;
    m_pConfig->SetPos(GetPosition());
    m_pConfig->SavePos();
    Destroy();
}

void MissClockFrame::OnAbout(wxCommandEvent& event)
{
    wxString msgb = wxbuildinfo(long_f);
    wxMessageBox(msgb, _("Welcome to..."));
}

void MissClockFrame::OnmimTopSelected(wxCommandEvent& event)
{
    long lStyle = GetWindowStyleFlag();
    if (lStyle & wxSTAY_ON_TOP)
    {
        lStyle &= ~wxSTAY_ON_TOP;
    }
    else
    {
        lStyle |= wxSTAY_ON_TOP;
    }
    SetWindowStyleFlag(lStyle);
    m_pConfig->SetTop(lStyle & wxSTAY_ON_TOP);
    m_pConfig->SaveTop();
}

void MissClockFrame::OnmimOptionSelected(wxCommandEvent& event)
{
    m_bRightMenu = false;
    MissOption OptionDlg(this);
    OptionDlg.SetDataSrc(m_pConfig, m_pSkin);
    OptionDlg.Connect(wxEVT_MCUI_EVENT, wxCommandEventHandler(MissClockFrame::OnOptionUiEvent), NULL, this);
    if (OptionDlg.ShowModal() == wxID_OK)
    {

    }
    else
    {
        ReloadSkin();
    }
    m_bRightMenu = true;
}

void MissClockFrame::OnmimRemindSelected(wxCommandEvent& event)
{

}

void MissClockFrame::OnmimShowSelected(wxCommandEvent& event)
{
    m_pConfig->SetShowClock(!m_pConfig->GetShowClock());

    if (m_pConfig->GetShowClock())
    {
        Show(true);
    }
    else
    {
        //m_pImpl->m_Icon.ShowBalloon(wxT("温馨提示："),wxT("时钟隐藏，您可以在这里打开菜单。"));
        Show(false);
    }

    m_pConfig->SaveShowClock();
}

void MissClockFrame::OnmimPinSelected(wxCommandEvent& event)
{
    m_pConfig->SetPin(!m_pConfig->GetPin());
    m_pConfig->SavePin();
}

void MissClockFrame::OnmimShadowSelected(wxCommandEvent& event)
{
}

void MissClockFrame::OnMinUp()
{
    for(Slots::iterator itor = sg_MinUp.begin(); itor != sg_MinUp.end(); ++itor)
    {
        (this->*(*itor))();
    }
}

void MissClockFrame::ConnectSlot(Slots& slots, FrameFunc func)
{
    Slots::iterator itor = std::find(slots.begin(),slots.end(),func);
    if(itor == slots.end())
    {
        slots.push_back(func);
    }
}

void MissClockFrame::DisConnectSlot(Slots& slots, FrameFunc func)
{
    Slots::iterator itor = std::find(slots.begin(),slots.end(),func);
    if(itor != slots.end())
    {
        slots.erase(itor);
    }
}

void MissClockFrame::OnOptionUiEvent(wxCommandEvent& event)
{
    switch(event.GetInt())
    {
    case MissGlobal::UE_UPDATE:
        {
            UpdateClock();
        }
        break;
    case MissGlobal::UE_UPDATETHEME:
        {
            UpdateTheme();
            UpdateClock();
        }
        break;
    case MissGlobal::UE_SAVETHEME:
        {
            MissXML::SaveSkin(m_pSkin);
        }
        break;
    case MissGlobal::UE_ZOOMCHANGE:
        {
            UpdateSize();
            UpdateClock();
        }
        break;
    case MissGlobal::UE_ALPHACHANGE:
        {
            UpdateAlpha();
            UpdateClock();
        }
        break;
    }
    m_bReloadSkin = true;
}

void MissClockFrame::ReloadSkin()
{
    if(m_bReloadSkin)
    {
        m_pConfig->LoadIniFile();
        UpdateTheme();
        m_Blend.SourceConstantAlpha = m_pConfig->GetOpacity();
        UpdateClock();
        m_bReloadSkin = false;
    }
}
