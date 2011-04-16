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

const long MissClockFrame::ID_MENUITEM_PIN = wxNewId();
const long MissClockFrame::ID_MENUITEM_SHADOW = wxNewId();
const long MissClockFrame::ID_MENUITEM_TOP = wxNewId();
const long MissClockFrame::ID_MENUITEM_SHOW = wxNewId();
const long MissClockFrame::ID_MENUITEM_OPTION = wxNewId();
const long MissClockFrame::ID_MENUITEM_REMIND = wxNewId();
const long MissClockFrame::ID_MENUITEM_COPYDATE = wxNewId();
const long MissClockFrame::ID_MENUITEM_COPYTIME = wxNewId();
const long MissClockFrame::ID_MENUITEM_SETTIME = wxNewId();
const long MissClockFrame::ID_MENUITEM_ABOUT = wxNewId();
const long MissClockFrame::ID_MENUITEM_EXIT = wxNewId();

MissClockFrame::MissClockFrame(wxFrame* frame)
    :
    GUIFrame(frame),
    m_pTaskBarIcon(new MissTaskBarIcon),
    m_pMainTimer(new wxTimer(this)),
    m_pSkin(new MissSkin),
    m_pConfig(new MissConfig),
    m_pMainMenu(new wxMenu)
{
    m_hWnd = static_cast<HWND>(GetHandle());
    m_pTaskBarIcon->SetIcon(wxICON(RC_CLOCK_ICON), wxT("迷失日历时钟"));
    m_pMainTimer->Start(1000);
    InitEvent();
    InitMenu();
    InitUI();
}

MissClockFrame::~MissClockFrame()
{
    std::cout << "~MissClockFrame()" << std::endl;
    this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));
}

void MissClockFrame::InitMenu()
{
    m_pmimPin = m_pMainMenu->Append(ID_MENUITEM_PIN, _("固定位置(&P)"), wxEmptyString, wxITEM_CHECK);
    m_pmimShadow = m_pMainMenu->Append(ID_MENUITEM_SHADOW, _("有影无形(&h)"), wxEmptyString, wxITEM_CHECK);
    m_pmimTop = m_pMainMenu->Append(ID_MENUITEM_TOP, _("总在最前(&T)"), wxEmptyString, wxITEM_CHECK);
    m_pmimShow = m_pMainMenu->Append(ID_MENUITEM_SHOW, _("显示时钟(&C)"), wxEmptyString, wxITEM_CHECK);
    m_pmimOption = m_pMainMenu->Append(ID_MENUITEM_OPTION, _("选项(&O)"), wxEmptyString, wxITEM_NORMAL);
    m_pmimRemind = m_pMainMenu->Append(ID_MENUITEM_REMIND, _("提醒管理(&R)"), wxEmptyString, wxITEM_NORMAL);
    m_pmimCopyDate = m_pMainMenu->Append(ID_MENUITEM_COPYDATE, _("复制日期(&D)"), wxEmptyString, wxITEM_NORMAL);
    m_pmimCopyTime = m_pMainMenu->Append(ID_MENUITEM_COPYTIME, _("复制时间(&i)"), wxEmptyString, wxITEM_NORMAL);
    m_pmimSetTime = m_pMainMenu->Append(ID_MENUITEM_SETTIME, _("校时(&S)"), wxEmptyString, wxITEM_NORMAL);
    m_pmimAbout = m_pMainMenu->Append(ID_MENUITEM_ABOUT, _("关于(&A)..."), wxEmptyString, wxITEM_NORMAL);
    m_pmimExit = m_pMainMenu->Append(ID_MENUITEM_EXIT, _("退出(&x)"), wxEmptyString, wxITEM_NORMAL);

    m_pmimShow->Check(m_pConfig->GetShowClock());
}

void MissClockFrame::InitEvent()
{
    this->Connect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));
    //sg_SecUp.connect(&MissClockFrame::UpdateClock);

    ConnectSlot(sg_MinUp,&MissClockFrame::CheckTask);
    ConnectSlot(sg_MinUp,&MissClockFrame::CheckAudioChimer);

    //Connect(ID_MENUITEM_PIN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimPinSelected);
    //Connect(ID_MENUITEM_SHADOW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimShadowSelected);
    Connect(ID_MENUITEM_TOP, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MissClockFrame::OnmimTopSelected);
    Connect(ID_MENUITEM_SHOW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimShowSelected);
    Connect(ID_MENUITEM_OPTION, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MissClockFrame::OnmimOptionSelected);
    //Connect(ID_MENUITEM_REMIND,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimRemindSelected);
    //Connect(ID_MENUITEM_COPYDATE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimCopyDateSelected);
    //Connect(ID_MENUITEM_COPYTIME,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimCopyTimeSelected);
    //Connect(ID_MENUITEM_SETTIME,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MissClockFrame::OnmimSetTimeSelected);
    this->Connect(ID_MENUITEM_ABOUT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MissClockFrame::OnAbout);
    this->Connect(ID_MENUITEM_EXIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MissClockFrame::OnClose);

    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_RIGHT_UP, (wxObjectEventFunction)&MissClockFrame::OnRightUp, NULL, this);
    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_LEFT_UP, (wxObjectEventFunction)&MissClockFrame::OnTaskBarIconLeftUP, NULL, this);
}

void MissClockFrame::InitUI()
{
    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);

    m_Blend.BlendOp = AC_SRC_OVER;      //指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。 详情，请参阅下面的备注部分。
    m_Blend.BlendFlags = 0;             //必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; //该成员控制源和目标位图被解释的方式。
    UpdateAlpha();
    UpdateTheme();

    //设置时钟位置
    Move(m_pConfig->GetPos());
}

void MissClockFrame::UpdateAlpha()
{
    m_Blend.SourceConstantAlpha = m_pConfig->GetOpacity();  //指定用于整张源位图的Alpha透明度值。(0~255)
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

    //如果要显示时钟，那么每秒钟刷新界面
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
    //移动窗口 Windows API
    ::PostMessage(m_hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
}

void MissClockFrame::OnRightUp(wxMouseEvent& event)
{
    //::SetForegroundWindow(m_hWnd);
    Raise();
    PopupMenu(m_pMainMenu.get());
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

void MissClockFrame::UpdateClock()
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
    ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                          &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
}

void MissClockFrame::CheckTask()
{
}

void MissClockFrame::CheckAudioChimer()
{
    //if ( m_tmNow->tm_min == 0 )
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

void MissClockFrame::OnClose(wxCloseEvent& event)
{
    m_pConfig->SetPos(GetPosition());
    m_pConfig->SavePos();
    Destroy();
}

void MissClockFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
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
}

void MissClockFrame::OnmimOptionSelected(wxCommandEvent& event)
{
    MissOption OptionDlg(this);
    OptionDlg.SetDataSrc(m_pConfig, m_pSkin);
    OptionDlg.Connect(wxEVT_MCUI_EVENT, wxCommandEventHandler(MissClockFrame::OnOptionUiEvent), NULL, this);
    if (OptionDlg.ShowModal() == wxID_OK)
    {

    }
    else
    {
        m_pConfig->LoadIniFile();
        UpdateTheme();
        m_Blend.SourceConstantAlpha = m_pConfig->GetOpacity();
        UpdateClock();
    }
}

void MissClockFrame::OnmimShowSelected(wxCommandEvent& event)
{
    m_pConfig->SetShowClock(!m_pConfig->GetShowClock());

    if (m_pConfig->GetShowClock())
    {
        //m_pImpl->m_Icon.ShowBalloon(wxT("温馨提示："),wxT("时钟隐藏，您可以在这里打开菜单。"));
        Show(true);
    }
    else
    {
        Show(false);
    }

    m_pConfig->SaveShowClock();
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
    case MissOption::UE_UPDATE:
        {
            UpdateClock();
        }
        break;
    case MissOption::UE_UPDATETHEME:
        {
            UpdateTheme();
            UpdateClock();
        }
        break;
    case MissOption::UE_SAVETHEME:
        {
            MissXML::SaveSkin(m_pSkin);
        }
        break;
    case MissOption::UE_ZOOMCHANGE:
        {
            UpdateSize();
            UpdateClock();
        }
        break;
    case MissOption::UE_ALPHACHANGE:
        {
            UpdateAlpha();
            UpdateClock();
        }
        break;
    }

}
