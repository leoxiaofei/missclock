#include "MissRemind.h"
#include <wx/dcmemory.h>
#include <mAlgorithm.hpp>
#include <winuser.h>

MissRemind::MissRemind( wxWindow* parent )
:
MissRemindBase( parent )
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

void MissRemind::OnTimer(wxTimerEvent& event)
{
    int nWidth = 400;
    int nHeight = 100;
    std::vector<wxString> vecContent;
    vecContent.push_back(wxT("这是一个测试。"));
    vecContent.push_back(wxT("This is a Test!!!\n回车测试。\n回车测试。\n回车测试。"));
    vecContent.push_back(wxT("这是一段很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长很长的文字，超长文字测试。"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));
    vecContent.push_back(wxT("不知道效果是怎样的？"));

    //wxString strText = wxT("1、这是一个测试，\n2、This is a Test.!!!\n3、不知道效果是怎样的？");
    wxBitmap top1(wxT("Remind/lemon_yyt_1.png"),wxBITMAP_TYPE_PNG),top2(wxT("Remind/lemon_yyt_2.png"),wxBITMAP_TYPE_PNG),top3(wxT("Remind/lemon_yyt_3.png"),wxBITMAP_TYPE_PNG);
    wxBitmap mid1,mid2(wxT("Remind/lemon_yyt_6.png"),wxBITMAP_TYPE_PNG),mid3;
    wxBitmap bottom1(wxT("Remind/lemon_yyt_5.png"),wxBITMAP_TYPE_PNG),bottom2(wxT("Remind/lemon_yyt_5.png"),wxBITMAP_TYPE_PNG),bottom3(wxT("Remind/lemon_yyt_4.png"),wxBITMAP_TYPE_PNG);

    ///计算最少宽度
    int nTemp = top1.GetWidth() + top3.GetWidth();
    nWidth = nWidth < nTemp ? nTemp : nWidth;
    nTemp = bottom1.GetWidth() + bottom3.GetWidth();
    nWidth = nWidth < nTemp ? nTemp : nWidth;

    int nContentWidth = nWidth - 20;

    std::vector<wxString> vecTextOut;
    wxMemoryDC tmpdc(m_bpUI);

    std::vector<wxString> vecLines;
    wxSize fontSize;
    wxArrayInt widthsArray;
    for(std::vector<wxString>::size_type ix = 0; ix != vecContent.size(); ++ix)
    {
        ///第一步处理换行
        vecLines = Miss::Split(
                    vecContent.size() == 1 ? vecContent[0]: wxString::Format(wxT("%d、%s"),ix+1,vecContent[ix].wc_str()),
                    wxT("\n"));

        for(std::vector<wxString>::iterator itor = vecLines.begin(); itor != vecLines.end(); ++itor)
        {
            fontSize = tmpdc.GetTextExtent(*itor);
            ///如果文字大于最大宽度，就要进行分段处理。
            if(fontSize.GetWidth() > nContentWidth)
            {
                widthsArray.Clear();
                tmpdc.GetPartialTextExtents(*itor, widthsArray);

                int nStart(0),nStartWidth(0);
                for(size_t nIndex = 0; nIndex != widthsArray.GetCount(); ++nIndex)
                {
                    if(widthsArray[nIndex] - nStartWidth > nContentWidth)
                    {
                        vecTextOut.push_back(itor->SubString(nStart,nIndex-1));
                        nStart = nIndex;
                        nStartWidth = widthsArray[nIndex - 1];
                    }
                }
                vecTextOut.push_back(itor->Right(itor->size() - nStart));
            }
            else
            {
                vecTextOut.push_back(*itor);
            }
        }
    }
    fontSize = tmpdc.GetTextExtent(vecContent[0]);
    std::cout<<fontSize.GetWidth()<<":"<<fontSize.GetHeight()<<std::endl;


    ///计算最少高度
    nTemp = top1.GetHeight() + bottom1.GetHeight() + mid2.GetHeight() * vecTextOut.size();
    nHeight = nHeight < nTemp ? nTemp : nHeight;


    /*
    if(fontSize.GetHeight() > mid2.GetHeight())
    {
        wxBitmap Bitmap(mid2.GetWidth(), fontSize.GetHeight());
        wxMemoryDC d(Bitmap);
        d.DrawBitmap
    }
    */

    m_bpUI = wxBitmap(nWidth, nHeight, 32);
    BITMAP bm;
    ::GetObject(static_cast<HBITMAP>(m_bpUI.GetHBITMAP()), sizeof(bm), &bm);
    int nPixCount = bm.bmWidth * bm.bmHeight;
    unsigned int *pBitmap = static_cast<unsigned int*>(bm.bmBits);


    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc = {0, 0};
    m_SizeWindow.cx = nWidth;
    m_SizeWindow.cy = nHeight;

    int nPixTemp = nPixCount;
    unsigned int* pBitmapTemp = pBitmap;
    while (--nPixTemp)
    {
        *pBitmapTemp = 0x01000000;
        ++pBitmapTemp;
    }

    wxMemoryDC memdc(m_bpUI);
    memdc.DrawBitmap(top1, 0, 0);
    memdc.DrawBitmap(top3, nWidth - top3.GetWidth(), 0);
    memdc.DrawBitmap(bottom1, 0, nHeight - bottom1.GetHeight());
    memdc.DrawBitmap(bottom3,nWidth - bottom3.GetWidth(), nHeight - bottom3.GetHeight());

    memdc.SetPen(*wxTRANSPARENT_PEN);

    memdc.SetDeviceOrigin(top1.GetWidth(), 0);
    memdc.SetBrush(wxBrush(top2));
    memdc.DrawRectangle(0, 0, nWidth - top3.GetWidth() - top1.GetWidth(), top1.GetHeight());

    memdc.SetDeviceOrigin(bottom1.GetWidth(), nHeight - bottom1.GetHeight());
    memdc.SetBrush(wxBrush(bottom2));
    memdc.DrawRectangle(0, 0, nWidth - bottom1.GetWidth() - bottom3.GetWidth(), bottom1.GetHeight());

    memdc.SetDeviceOrigin(0,top1.GetHeight());
    memdc.SetBrush(wxBrush(wxColour(wxT("#FBF7ED"))));
    memdc.DrawRectangle(0, 0, 10, nHeight - top1.GetHeight() - bottom1.GetHeight());

    memdc.SetDeviceOrigin(nWidth - 10, top3.GetHeight());
    memdc.SetBrush(wxBrush(wxColour(wxT("#FBF7ED"))));
    memdc.DrawRectangle(0, 0, 10, nHeight - top3.GetHeight() - bottom3.GetHeight());

    for(size_t ix = 0; ix != vecTextOut.size(); ++ix)
    {
        memdc.SetDeviceOrigin(10, top1.GetHeight() + mid2.GetHeight() * ix);
        memdc.SetBrush(wxBrush(mid2));
        memdc.DrawRectangle(0, 0, nWidth - 10 - 10, mid2.GetHeight()/*nHeight - top3.GetHeight() - bottom3.GetHeight()*/);
        memdc.DrawLabel(vecTextOut[ix],wxRect(0, 0, nWidth - 10 - 10, mid2.GetHeight()),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    }
    /*
    memdc.SetDeviceOrigin(10, top1.GetHeight() + mid2.GetHeight());
    memdc.SetBrush(wxBrush(mid2));
    memdc.DrawRectangle(0, 0, nWidth - 10 - 10, mid2.GetHeight()/*nHeight - top3.GetHeight() - bottom3.GetHeight());
    memdc.DrawLabel(wxT("2、This is a Test!!!"),wxRect(0, 0, nWidth - 10 - 10, mid2.GetHeight()),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);


    memdc.SetDeviceOrigin(10, top1.GetHeight() + mid2.GetHeight() * 2);
    memdc.SetBrush(wxBrush(mid2));
    memdc.DrawRectangle(0, 0, nWidth - 10 - 10, mid2.GetHeight()/*nHeight - top3.GetHeight() - bottom3.GetHeight());
    memdc.DrawLabel(wxT("3、不知道效果是怎样的？"),wxRect(0, 0, nWidth - 10 - 10, mid2.GetHeight()),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    */


    nPixTemp = nPixCount;
    pBitmapTemp = pBitmap;
    while (--nPixTemp)
    {
        *pBitmapTemp -= 0x01000000;
        ++pBitmapTemp;
    }

    ::UpdateLayeredWindow(m_hWnd, s_hdcScreen, NULL, &m_SizeWindow, static_cast<HDC>(memdc.GetHDC()),
                          &s_ptSrc, 0, &m_Blend, ULW_ALPHA);
}

void MissRemind::OnLeftDown(wxMouseEvent& event)
{
    ///移动窗口 Windows API
    ::PostMessage(m_hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
}
