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
#include "MissOption.h"
#include "MissSoundThread.h"
#include "MissRemind.h"

#include "../Data/MissConfig.h"
#include "../Data/MissSkin.h"
#include "../Data/MissRemindSkin.h"
#include "../Data/MissXML.h"
#include "../Data/MissWxSQLite3.h"
#include "../Common/MissGlobal.h"
#include "../Common/MissTools.h"

#include <algorithm>
//#include <boost/progress.hpp>

#include <wx/dcmemory.h>
#include <wx/menu.h>
#include <winuser.h>
//#include "windows.h"

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
    m_pTaskBarIcon(new MissTaskBarIcon()),
    m_pMainTimer(new wxTimer(this)),
//    m_pSkin(new MissSkin),
//    m_pRemindSkin(new MissRemindSkin),
    m_bRightMenu(true),
    m_bReloadSkin(false)
{
    m_pConfig = &MissConfig::GetInstance();
    m_pSkin   = &MissConfig::GetInstance().GetCurrentSkin();

    m_hWnd = static_cast<HWND>(GetHandle());
    m_pTaskBarIcon->SetIcon(wxICON(RC_CLOCK_ICON), wxT("迷失日历时钟"));
    m_pMainTimer->Start(1000);
    InitEvent();
    InitUI();
    UpdateMenu();
}

MissClockFrame::~MissClockFrame()
{
    std::cout << "~MissClockFrame()" << std::endl;
    this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));
}

void MissClockFrame::InitEvent()
{
    this->Connect(wxEVT_TIMER, wxTimerEventHandler(MissClockFrame::OnTimer));

    ConnectSlot(sg_MinUp,&MissClockFrame::CheckTask);
    UpdateAudioChimer();

    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_RIGHT_UP, (wxObjectEventFunction)&MissClockFrame::OnRightUp, NULL, this);
    m_pTaskBarIcon->Connect(wxEVT_TASKBAR_LEFT_UP, (wxObjectEventFunction)&MissClockFrame::OnTaskBarIconLeftUP, NULL, this);
}

void MissClockFrame::InitUI()
{
    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);

    m_Blend.BlendOp = AC_SRC_OVER;      ///指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。
    m_Blend.BlendFlags = 0;             ///必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; ///该成员控制源和目标位图被解释的方式。
    UpdateAlpha();
    UpdateTheme();
    UpdateTop();
    UpdateShadow();

    ///设置时钟位置
    Move(m_pConfig->GetPos());

    ///第一次刷新界面
    wxTimerEvent send;
    AddPendingEvent(send);
}

void MissClockFrame::UpdateMenu()
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
    MissXML::LoadRemindSkin(&m_pConfig->GetCurrentRemindSkin(), m_pConfig->GetSkinName());
    UpdateSize();
}

void MissClockFrame::OnTimer(wxTimerEvent& event)
{
    //boost::progress_timer t;
    //SetTransparent(rand()%255);
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
        s_savemin = m_tmNow->tm_min;
        OnMinUp();
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

void MissClockFrame::LoadTask()
{
    //std::cout<<"LoadTask::"<<m_tmNow->tm_hour<<":"<<m_tmNow->tm_min<<std::endl;
    //std::vector<std::pair<int,MissGlobal::TaskData> > vecData;
    m_vecMinData.clear();
    try
    {
        MissWxSQLite3 sql;
        sql.QusetNextRemind(wxString::Format(wxT("%04d-%02d-%02d"),m_tmNow->tm_year+1900,
            m_tmNow->tm_mon+1,m_tmNow->tm_mday),wxString::Format(wxT("%02d:%02d"),
            m_tmNow->tm_hour,m_tmNow->tm_min),m_vecMinData);
    }
    catch(...)
    {
    }
    ///wxDateTime类影响localtime内部静态变量的值
    m_ttNow = time(NULL);
    localtime(&m_ttNow);
}

void MissClockFrame::CheckTask()
{
    //std::cout<<"CheckTask::"<<m_tmNow->tm_hour<<":"<<m_tmNow->tm_min<<std::endl;
    if(!m_vecMinData.empty())
    {
        if(m_vecMinData[0].strTaskTime == wxString::Format(wxT("%02d:%02d"),m_tmNow->tm_hour,m_tmNow->tm_min))
        {
            //wxMessageBox(m_vecMinData[0].strTaskContent);
            //int nIndex(0);
            std::vector<wxString> vecRemindContent;
            for(std::vector<MissGlobal::TaskData>::iterator itor = m_vecMinData.begin();
                itor != m_vecMinData.end(); ++itor)
            {
                switch(itor->nTaskType)
                {
                case 0:     ///文字提醒任务
                    {
                        vecRemindContent.push_back( itor->strTaskContent );
                    }
                    break;
                case 1:     ///程序任务
                    {
                        wxExecute(itor->strTaskContent);
                    }
                    break;
                case 2:
                    break;
                }
            }
            if(!vecRemindContent.empty())
            {
                PopUpRemind(vecRemindContent);
            }
            LoadTask();
        }
    }
}

void MissClockFrame::PopUpRemind(const std::vector<wxString>& vecContent)
{
    MissRemind *a = new MissRemind(vecContent, this);
    a->Show();
}

void MissClockFrame::CheckAudioChimer()
{
    std::cout<<"CheckAudioChimer::"<<m_tmNow->tm_hour<<":"<<m_tmNow->tm_min<<std::endl;
    if ( m_tmNow->tm_min == 0 )
    {
        MissSoundThread *thread = new MissSoundThread(m_tmNow->tm_hour);
        if (thread->Create() == wxTHREAD_NO_ERROR)
        {
            thread->Run();
        }
        else
        {
             wxMessageBox( wxT("Can't create thread !" ));
        }
    }
}

void MissClockFrame::OnExit(wxCommandEvent& event)
{

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
    wxCloseEvent send(wxEVT_CLOSE_WINDOW);
    AddPendingEvent(send);
}

void MissClockFrame::OnClose(wxCloseEvent& event)
{
    std::cout << "MissClockFrame::OnClose()" << std::endl;
    ///保存时钟坐标信息
    m_pConfig->SetPos(GetPosition());
    m_pConfig->SavePos();

    ///执行关闭时任务

    Destroy();
}

void MissClockFrame::OnAbout(wxCommandEvent& event)
{
    wxString msgb = wxbuildinfo(long_f);
    wxMessageBox(msgb, _("Welcome to..."));
}

void MissClockFrame::OnmimTopSelected(wxCommandEvent& event)
{
    m_pConfig->SetTop(!m_pConfig->GetTop());
    UpdateTop();
    m_pConfig->SaveTop();
}

void MissClockFrame::OnmimOptionSelected(wxCommandEvent& event)
{
    m_bRightMenu = false;
    MissOption OptionDlg(this);
    OptionDlg.Connect(wxEVT_MCUI_EVENT, wxCommandEventHandler(MissClockFrame::OnOptionUiEvent), NULL, this);
    OptionDlg.Connect(wxEVT_MCDATA_EVENT, wxCommandEventHandler(MissClockFrame::OnDataEvent), NULL, this);
    if (OptionDlg.ShowModal() == wxID_OK)
    {
        UpdateAudioChimer();
        UpdateTop();
        UpdateShowClock();
        UpdateShadow();
        UpdateMenu();
    }
    else
    {
        ReloadSkin();
    }
    m_bRightMenu = true;
}

void MissClockFrame::OnmimRemindSelected(wxCommandEvent& event)
{
    std::vector<wxString> vecContent;
    vecContent.push_back(wxT("这是一个测试。"));
    vecContent.push_back(wxT("This is a Test!!!\n回车测试。\n回车测试。\n回车测试。"));
    vecContent.push_back(wxT("这是一段很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长的文字，超长文字测试。"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    MissRemind *a = new MissRemind(vecContent,this);
    a->Show();
}

void MissClockFrame::OnmimShowSelected(wxCommandEvent& event)
{
    m_pConfig->SetShowClock(!m_pConfig->GetShowClock());
    UpdateShowClock();
    m_pConfig->SaveShowClock();
}

void MissClockFrame::OnmimPinSelected(wxCommandEvent& event)
{
    m_pConfig->SetPin(!m_pConfig->GetPin());
    m_pConfig->SavePin();
}

void MissClockFrame::OnmimShadowSelected(wxCommandEvent& event)
{
    m_pConfig->SetShadow(!m_pConfig->GetShadow());
    UpdateShadow();
    m_pConfig->SaveShadow();
}

void MissClockFrame::OnmimCopyDateSelected(wxCommandEvent& event)
{
    m_pTaskBarIcon->ShowBalloon(wxT("测试"),wxT("这是一个测试。"));
    char str[100];
    strftime (str,100, m_pConfig->GetPDateFormat().mb_str(),m_tmNow);
    MissTools::CopyToClipboard( wxString(str,wxConvLocal) );
}

void MissClockFrame::OnmimCopyTimeSelected(wxCommandEvent& event)
{
    char str[100];
    strftime (str,100, m_pConfig->GetPTimeFormat().mb_str(),m_tmNow);
    MissTools::CopyToClipboard( wxString(str,wxConvLocal) );
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

void MissClockFrame::OnDataEvent(wxCommandEvent& event)
{
    std::cout<<"OnDataEvent"<<std::endl;
    LoadTask();
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

void MissClockFrame::UpdateShowClock()
{
    if (m_pConfig->GetShowClock())
    {
        Show(true);
    }
    else
    {
        Show(false);
        m_pTaskBarIcon->ShowBalloon(wxT("温馨提示："),wxT("时钟隐藏，您可以在这里打开菜单。"));
    }
}

void MissClockFrame::UpdateTop()
{
    long lStyle = GetWindowStyleFlag();
    if (!m_pConfig->GetTop())
    {
        lStyle &= ~wxSTAY_ON_TOP;
    }
    else
    {
        lStyle |= wxSTAY_ON_TOP;
    }
    SetWindowStyleFlag(lStyle);
}

void MissClockFrame::UpdateShadow()
{
    long exStyle = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
    if (!m_pConfig->GetShadow())
    {
        exStyle &= ~WS_EX_TRANSPARENT;
    }
    else
    {
        exStyle |= WS_EX_TRANSPARENT;
        m_pTaskBarIcon->ShowBalloon(wxT("温馨提示："),wxT("时钟已设置有影无形，您可以在这里打开菜单。"));
    }
    ::SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle);
}

void MissClockFrame::UpdateAudioChimer()
{
    if(m_pConfig->GetAudioChimer())
    {
        ConnectSlot(sg_MinUp,&MissClockFrame::CheckAudioChimer);
    }
    else
    {
        DisConnectSlot(sg_MinUp,&MissClockFrame::CheckAudioChimer);
    }
}
