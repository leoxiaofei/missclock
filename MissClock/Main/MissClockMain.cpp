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
#include "windows.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
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

MissClockFrame::MissClockFrame(wxFrame *frame)
    : GUIFrame(frame),
    m_pTaskBarIcon(new MissTaskBarIcon),
    m_pMainTimer(new wxTimer(this))
{
    m_hWnd = static_cast<HWND>(GetHandle());
    m_pTaskBarIcon->SetIcon(wxICON(RC_CLOCK_ICON),wxT("迷失日历时钟"));
    m_pMainTimer->Start(1000);
    InitEvent();
    InitUI();
}

MissClockFrame::~MissClockFrame()
{
    std::cout << "~MissClockFrame()";
    this->Disconnect(wxEVT_TIMER,wxTimerEventHandler(MissClockFrame::OnTimer));
}

void MissClockFrame::InitEvent()
{
    this->Connect(wxEVT_TIMER,wxTimerEventHandler(MissClockFrame::OnTimer));
    sg_SecUp.connect(&MissClockFrame::UpdateClock);
    sg_MinUp.connect(&MissClockFrame::CheckTast);
    sg_MinUp.connect(&MissClockFrame::CheckAudioChimer);
}

void MissClockFrame::InitUI()
{
    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);

    m_Blend.BlendOp = AC_SRC_OVER;      //指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。 详情，请参阅下面的备注部分。
    m_Blend.BlendFlags = 0;             //必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; //该成员控制源和目标位图被解释的方式。
    m_Blend.SourceConstantAlpha = 255;  //指定用于整张源位图的Alpha透明度值。(0~255)
}

void MissClockFrame::OnTimer(wxTimerEvent& event)
{
    boost::progress_timer t;
    std::cout << "OnTimer" << std::endl;

    m_ttNow=time(NULL);
    m_tmNow=localtime(&m_ttNow);
    static int s_savemin = m_tmNow->tm_min;
    sg_SecUp(this);
    if(s_savemin != m_tmNow->tm_min )
    {
        sg_MinUp(this);
        s_savemin = m_tmNow->tm_min;
    }
}

void MissClockFrame::OnLeftDown(wxMouseEvent& event)
{
    //移动窗口 Windows API
    PostMessage(m_hWnd,WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(),event.GetY()));
}



void MissClockFrame::UpdateClock()
{
    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc={0,0};

    m_SizeWindow.cx = static_cast<int>(100/*m_Skin.m_BakWidth*m_Config.m_Zoom*/);
    m_SizeWindow.cy = static_cast<int>(100/*m_Skin.m_BakHeight*m_Config.m_Zoom*/);


    wxBitmap bitmap(m_SizeWindow.cx,m_SizeWindow.cy,32);
    BITMAP bm;
    GetObject(static_cast<HBITMAP>(bitmap.GetHBITMAP()), sizeof(bm), &bm);
    int nPixCount = bm.bmWidth * bm.bmHeight + 1;

    unsigned int *pBitmap = static_cast<unsigned int *>(bm.bmBits);
    int nColor = 0x8000FF00;
    while( --nPixCount )
    {
        memcpy(pBitmap,&nColor,4);
        ++pBitmap;
    }
    wxMemoryDC memdc(bitmap);

    UpdateLayeredWindow(m_hWnd,s_hdcScreen,NULL,&m_SizeWindow,(HDC)memdc.GetHDC(),&s_ptSrc,0,&m_Blend,ULW_ALPHA);
}

void MissClockFrame::CheckTast()
{
}

void MissClockFrame::CheckAudioChimer()
{
}


void MissClockFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void MissClockFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void MissClockFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
