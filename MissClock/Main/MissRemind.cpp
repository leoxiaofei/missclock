#include "MissRemind.h"
#include <wx/dcmemory.h>
#include "../Data/MissRemindSkin.h"
#include "../Data/MissXML.h"

#include <winuser.h>
#ifdef DrawText
#undef DrawText
#endif
MissRemind::MissRemind(shared_ptr<MissRemindSkin> &pRemindSkin, wxWindow* parent )
:
MissRemindBase( parent ),
m_pRemindSkin(pRemindSkin)
{
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

    wxTimerEvent send;
    AddPendingEvent(send);
}

void MissRemind::OnDrawSkin()
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



    //PatternInfo painfo;
    m_pRemindSkin->LoadTempData();
    m_pRemindSkin->TakeOrderWithNewline(vecContent);

    m_SizeWindow.cx = m_pRemindSkin->GetOverallWidth();
    m_SizeWindow.cy = m_pRemindSkin->GetOverallHeight();


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
    m_pRemindSkin->DrawSkin(memdc);
    m_pRemindSkin->ClearTempData();
    //gc->GetTextExtent(m_Config.btn_content,&m_width,&m_height,NULL,NULL);
    //gc->DrawText(m_Config.btn_content, m_Config.btn_x, m_Config.btn_y);

    //gc->SetPen( wxPen( m_Config.btn_colour,2 ) );
    //gc->DrawRectangle( m_Config.btn_x-10,m_Config.btn_y-4,m_width+20,m_height+6 );

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
}

void MissRemind::OnTimer(wxTimerEvent& event)
{
    OnDrawSkin();
    return;
}

void MissRemind::OnLeftDown(wxMouseEvent& event)
{
    /*
    if ( event.GetX() > m_Config.btn_x-10 && event.GetX() < m_Config.btn_x+m_width+20 )
    {
        if ( event.GetY() > m_Config.btn_y-4 && event.GetY() < m_Config.btn_y+m_height+6 &&!m_isOption )
        {
            Close();
        }
    }
    */
    ///移动窗口 Windows API
    ::PostMessage(m_hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
}

