#include "StdAfx.h"
#include "MissClockThemePlug.h"

#include <wx/dcmemory.h>
#include <winuser.h>
#include "./Data/MissSkin.h"
#include "./Data/MissXML.h"
#include "./Data/MissConfig.h"
#include "./Dialog/MissTheme.h"


MissClockThemePlug::MissClockThemePlug(HWND hWnd):
    MissCThemePlugBase(hWnd)
{
    //ctor
    m_Blend.BlendOp = AC_SRC_OVER;      ///指定源混合操作。目前，唯一的源和目标混合操作被定义为 AC_SRC_OVER。
    m_Blend.BlendFlags = 0;             ///必须为 0
    m_Blend.AlphaFormat = AC_SRC_ALPHA; ///该成员控制源和目标位图被解释的方式。
}

MissClockThemePlug::~MissClockThemePlug()
{
    //dtor
}

void MissClockThemePlug::InitDll(const wchar_t* strDllPath)
{
    MissConfig::GetInstance().InitConfigPath(strDllPath);
    m_pSkin = &MissConfig::GetInstance().GetCurrentSkin();
}

bool MissClockThemePlug::RunOption()
{
    MissTheme ThemeDlg(0);
    //ThemeDlg.SetDataSrc(m_pSkin);
    if(ThemeDlg.ShowModal() == wxID_OK)
    {
        ///保存主题设置
        //wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
        //send.SetInt(MissGlobal::UE_SAVETHEME);
        //GetEventHandler()->ProcessEvent(send);
        return true;
    }
    return false;
}

void MissClockThemePlug::TimeUpDrawClock(const tm* tmNow)
{
    static HDC s_hdcScreen = ::GetDC(m_hWnd);
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
    memdc.SetUserScale(m_dZoom,m_dZoom);

    m_pSkin->DrawSkin(memdc, tmNow);

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

void MissClockThemePlug::SetScale(const double& dZoom)
{
    m_dZoom = dZoom;

    m_SizeWindow.cx = static_cast<int>(m_pSkin->GetBGBitmap().GetWidth() * dZoom);
    m_SizeWindow.cy = static_cast<int>(m_pSkin->GetBGBitmap().GetHeight() * dZoom);
    m_bpUI = wxBitmap(m_SizeWindow.cx, m_SizeWindow.cy, 32);
    BITMAP bm;
    ::GetObject(static_cast<HBITMAP>(m_bpUI.GetHBITMAP()), sizeof(bm), &bm);
    m_nPixCount = bm.bmWidth * bm.bmHeight;
    m_pBitmap = static_cast<unsigned int*>(bm.bmBits);
}

void MissClockThemePlug::SetOpacity(int nOpacity)
{
    ///指定用于整张源位图的Alpha透明度值。(0~255)
    m_Blend.SourceConstantAlpha = nOpacity;
}

void MissClockThemePlug::LoadSkin()
{
    wxString strSkinPath = MissConfig::GetInstance().GetConfigPath() + wxT("ClockSkin\\")
                                    + MissConfig::GetInstance().GetSkinName() + wxT("\\");
    MissXML::LoadSkin(m_pSkin, strSkinPath);
}
