#include "MissRemind.h"
#include <wx/dcmemory.h>
#include <mAlgorithm.hpp>

#include <winuser.h>
#ifdef DrawText
#undef DrawText
#endif
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

const wxBitmap* MissRemind::GetPatternByPos(const std::vector<PatternInfo>& vecPatterns, const PatternPos& pos)
{
    for(std::vector<PatternInfo>::const_iterator itor = vecPatterns.begin();
        itor != vecPatterns.end(); ++itor)
    {
        if(itor->pos == pos)
        {
            if(itor->bit.IsOk())
            {
                return &(itor->bit);
            }
        }
    }
    return NULL;
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


    int nOverallWidth = 700;
    int nMinHeight    = 100;
    int nMaxHeight    = 800;
    wxColour cBG;
    wxPoint ptBtn(150, - 30);
    wxString strBtn = wxT("我知道了");
    std::vector<PatternInfo> vecPatterns(6);
    std::vector<FillInfo>    vecFills(4);
    OutTextInfo oTextInfo;

    //PatternInfo painfo;
    vecPatterns[0].pos = PP_TOP_LEFT;
    vecPatterns[0].bit = wxBitmap(wxT("Remind/tl.png"),wxBITMAP_TYPE_PNG);

    vecPatterns[1].pos = PP_TOP_MID;
    vecPatterns[1].bit = wxBitmap(wxT("Remind/tm.png"),wxBITMAP_TYPE_PNG);

    vecPatterns[2].pos = PP_TOP_RIGHT;
    vecPatterns[2].bit = wxBitmap(wxT("Remind/tr.png"),wxBITMAP_TYPE_PNG);

    vecPatterns[3].pos = PP_BOTTOM_LEFT;
    vecPatterns[3].bit = wxBitmap(wxT("Remind/bl.png"),wxBITMAP_TYPE_PNG);

    vecPatterns[4].pos = PP_BOTTOM_MID;
    vecPatterns[4].bit = wxBitmap(wxT("Remind/bm.png"),wxBITMAP_TYPE_PNG);

    vecPatterns[5].pos = PP_BOTTOM_RIGHT;
    vecPatterns[5].bit = wxBitmap(wxT("Remind/br.png"),wxBITMAP_TYPE_PNG);

    //FillInfo fInfo;
    vecFills[0].pos    = PP_TOP_OTHER;
    vecFills[0].brush  = wxBrush(wxBitmap(wxT("Remind/to.png"),wxBITMAP_TYPE_PNG));
    vecFills[0].nSize  = 98;

    vecFills[1].pos    = PP_BOTTOM_OTHER;
    vecFills[1].brush  = wxBrush(wxBitmap(wxT("Remind/bo.png"),wxBITMAP_TYPE_PNG));
    vecFills[1].nSize  = 83;

    vecFills[2].pos    = PP_LEFT_OTHER;
    vecFills[2].brush  = wxBrush(wxBitmap(wxT("Remind/lo.png"),wxBITMAP_TYPE_PNG));
    vecFills[2].nSize  = 45;

    vecFills[3].pos    = PP_RIGHT_OTHER;
    vecFills[3].brush  = wxBrush(wxBitmap(wxT("Remind/ro.png"),wxBITMAP_TYPE_PNG));
    vecFills[3].nSize  = 45;


    oTextInfo.pos = wxPoint(45,98);
    oTextInfo.nBottomHeight = 83;
    oTextInfo.nTextWidth = nOverallWidth - 90;

    std::vector<wxString> vecTextOut;
    int nFontHeight = TakeOrderWithNewline(oTextInfo.nTextWidth, vecContent, vecTextOut);

    ///计算最少高度
    int nTextHeight = oTextInfo.bitmap.IsOk()? oTextInfo.bitmap.GetHeight():nFontHeight;
    int nOverallHeight = oTextInfo.pos.y + oTextInfo.nBottomHeight + nTextHeight * vecTextOut.size();

    nOverallHeight = nOverallHeight < nMinHeight ? nMinHeight : nOverallHeight > nMaxHeight ?
                nMaxHeight : nOverallHeight;

    m_bpUI = wxBitmap(nOverallWidth, nOverallHeight, 32);
    BITMAP bm;
    ::GetObject(static_cast<HBITMAP>(m_bpUI.GetHBITMAP()), sizeof(bm), &bm);
    int nPixCount = bm.bmWidth * bm.bmHeight;
    unsigned int *pBitmap = static_cast<unsigned int*>(bm.bmBits);


    static HDC s_hdcScreen = GetDC(m_hWnd);
    static POINT s_ptSrc = {0, 0};
    m_SizeWindow.cx = nOverallWidth;
    m_SizeWindow.cy = nOverallHeight;

    int nPixTemp = nPixCount;
    unsigned int* pBitmapTemp = pBitmap;
    while (--nPixTemp)
    {
        *pBitmapTemp = 0xFF000000;
        ++pBitmapTemp;
    }

    wxMemoryDC memdc(m_bpUI);
    ///开始绘图
    int nX,nY;
    int nW,nH;
    memdc.SetPen(*wxTRANSPARENT_PEN);
    const wxBitmap *bitmapTemp;
    for(std::vector<FillInfo>::const_iterator itor = vecFills.begin();
        itor != vecFills.end(); ++itor)
    {
        nX = 0;
        nY = 0;
        nW = 0;
        nH = 0;
        switch(itor->pos)
        {
        case PP_TOP_OTHER:
            bitmapTemp = GetPatternByPos(vecPatterns,PP_TOP_LEFT);
            if(bitmapTemp != NULL)
            {
                nX = bitmapTemp->GetWidth();
            }
            bitmapTemp = GetPatternByPos(vecPatterns,PP_TOP_RIGHT);
            if(bitmapTemp != NULL)
            {
                nW = bitmapTemp->GetWidth();
            }
            nW = nOverallWidth - nX - nW;
            nH = itor->nSize;
            break;
        case PP_BOTTOM_OTHER:
            bitmapTemp = GetPatternByPos(vecPatterns,PP_BOTTOM_LEFT);
            if(bitmapTemp != NULL)
            {
                nX = bitmapTemp->GetWidth();
            }

            nY = nOverallHeight - itor->nSize;
            bitmapTemp = GetPatternByPos(vecPatterns,PP_BOTTOM_RIGHT);
            if(bitmapTemp != NULL)
            {
                nW = bitmapTemp->GetWidth();
            }
            nW = nOverallWidth - nX - nW;
            nH = itor->nSize;
            break;
        case PP_LEFT_OTHER:
            bitmapTemp = GetPatternByPos(vecPatterns,PP_TOP_LEFT);
            if(bitmapTemp != NULL)
            {
                nY = bitmapTemp->GetHeight();
            }
            nW = itor->nSize;
            bitmapTemp = GetPatternByPos(vecPatterns,PP_BOTTOM_LEFT);
            if(bitmapTemp != NULL)
            {
                nH = bitmapTemp->GetHeight();
            }
            nH = nOverallHeight - nY - nH;
            break;
        case PP_RIGHT_OTHER:
            nX = nOverallWidth - itor->nSize;
            bitmapTemp = GetPatternByPos(vecPatterns,PP_TOP_RIGHT);
            if(bitmapTemp != NULL)
            {
                nY = bitmapTemp->GetHeight();
            }
            nW = itor->nSize;
            bitmapTemp = GetPatternByPos(vecPatterns,PP_BOTTOM_RIGHT);
            if(bitmapTemp != NULL)
            {
                nH = bitmapTemp->GetHeight();
            }
            nH = nOverallHeight - nY - nH;
            break;
        }
        memdc.SetDeviceOrigin(nX, nY);
        memdc.SetBrush(itor->brush);
        memdc.DrawRectangle(0, 0, nW, nH);
    }
    memdc.SetDeviceOrigin(0, 0);
    for(std::vector<PatternInfo>::const_iterator itor = vecPatterns.begin();
        itor != vecPatterns.end(); ++itor)
    {
        switch(itor->pos)
        {
        case PP_TOP_LEFT:
            nX = 0;
            nY = 0;
            break;
        case PP_TOP_MID:
            nX = nOverallWidth / 2 - itor->bit.GetWidth() / 2;
            nY = 0;
            break;
        case PP_TOP_RIGHT:
            nX = nOverallWidth - itor->bit.GetWidth();
            nY = 0;
            break;
        case PP_MID_LEFT:
            nX = 0;
            nY = nOverallHeight / 2 - itor->bit.GetHeight() / 2;
            break;
        case PP_MID_RIGHT:
            nX = nOverallWidth - itor->bit.GetWidth();
            nY = nOverallHeight / 2 - itor->bit.GetHeight() / 2;
            break;
        case PP_MID_MID:
            nX = nOverallWidth / 2 - itor->bit.GetWidth() / 2;
            nY = nOverallHeight / 2 - itor->bit.GetHeight() / 2;
            break;
        case PP_BOTTOM_LEFT:
            nX = 0;
            nY = nOverallHeight - itor->bit.GetHeight();
            break;
        case PP_BOTTOM_MID:
            nX = nOverallWidth / 2 - itor->bit.GetWidth() / 2;
            nY = nOverallHeight - itor->bit.GetHeight();
            break;
        case PP_BOTTOM_RIGHT:
            nX = nOverallWidth - itor->bit.GetWidth();
            nY = nOverallHeight - itor->bit.GetHeight();
            break;
        default:
            assert(false);
            break;
        }
        memdc.DrawBitmap(itor->bit, nX, nY);
    }

    ///文字信息
    for(size_t ix = 0; ix != vecTextOut.size(); ++ix)
    {
        memdc.SetDeviceOrigin(oTextInfo.pos.x, oTextInfo.pos.y + nTextHeight * ix);
        if(oTextInfo.bitmap.IsOk())
        {
            memdc.SetBrush(wxBrush(oTextInfo.bitmap));
            memdc.DrawRectangle(0, 0, oTextInfo.nTextWidth, nTextHeight);//nHeight - top3.GetHeight() - bottom3.GetHeight());
        }
        memdc.SetTextForeground(*wxWHITE);
        memdc.DrawLabel(vecTextOut[ix],wxRect(0, 0, oTextInfo.nTextWidth, nTextHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    }

    ///关闭按钮信息
    memdc.SetDeviceOrigin(0,0);
    //gc->SetFont(m_Config.btn_font,m_Config.btn_colour);
    wxSize fontSize = memdc.GetTextExtent(strBtn);
    int nTempX(0), nTempY(0);

    if(ptBtn.x < 0)
    {
        nTempX = nOverallWidth;
    }
    nTempX += ptBtn.x;

    if(ptBtn.y < 0)
    {
        nTempY = nOverallHeight;
    }
    nTempY += ptBtn.y;

    memdc.DrawText(strBtn, nTempX, nTempY);
    memdc.SetPen(*wxWHITE_PEN);
    memdc.SetBrush(*wxTRANSPARENT_BRUSH);
    memdc.DrawRectangle(nTempX-10,nTempY-4,fontSize.GetWidth()+20,fontSize.GetHeight()+8);
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

int MissRemind::TakeOrderWithNewline(int nTextWidth, const std::vector<wxString>& vecIn, std::vector<wxString>& vecOut)
{
    wxMemoryDC tmpdc(m_bpUI);
    std::vector<wxString> vecLines;
    wxSize fontSize;
    wxArrayInt widthsArray;
    for(std::vector<wxString>::size_type ix = 0; ix != vecIn.size(); ++ix)
    {
        ///第一步处理换行
        vecLines = Miss::Split(
                    vecIn.size() == 1 ? vecIn[0]: wxString::Format(wxT("%d、%s"),ix+1,vecIn[ix].wc_str()),
                    wxT("\n"));
        ///第二步处理过长
        for(std::vector<wxString>::iterator itor = vecLines.begin(); itor != vecLines.end(); ++itor)
        {
            fontSize = tmpdc.GetTextExtent(*itor);
            ///如果文字大于最大宽度，就要进行分段处理。
            if(fontSize.GetWidth() > nTextWidth)
            {
                widthsArray.Clear();
                tmpdc.GetPartialTextExtents(*itor, widthsArray);

                int nStart(0),nStartWidth(0);
                for(size_t nIndex = 0; nIndex != widthsArray.GetCount(); ++nIndex)
                {
                    if(widthsArray[nIndex] - nStartWidth > nTextWidth)
                    {
                        vecOut.push_back(itor->SubString(nStart,nIndex-1));
                        nStart = nIndex;
                        nStartWidth = widthsArray[nIndex - 1];
                    }
                }
                vecOut.push_back(itor->Right(itor->size() - nStart));
            }
            else
            {
                vecOut.push_back(*itor);
            }
        }
    }
    return fontSize.GetHeight();
}
