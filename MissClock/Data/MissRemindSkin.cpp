#include "MissRemindSkin.h"


#include <wx/brush.h>
#include <map>
#include <mAlgorithm.hpp>
#include <wx/dcmemory.h>

class MissRemindSkin::MissRemindSkinImpl
{
public:
    MissRemindSkinImpl():
    m_pTextBG(NULL)
    {}

    int                       m_nOverallWidth;    ///整体宽度
    int                       m_nMinHeight;       ///最小高度
    int                       m_nMaxHeight;       ///最大高度
    wxColour                  m_cBG;              ///背景颜色
    CloseBtnInfo              m_cButtonInfo;      ///关闭按钮信息
    OutTextInfo               m_oTextInfo;        ///输出文字信息
    std::vector<PatternInfo>  m_vecPatterns;      ///窗口图案信息
    std::vector<FillInfo>     m_vecFills;         ///填充信息

    ///临时
    int                            m_nOverallHeight;   ///整体高度（计算得来）
    int                            m_nTextHeight;      ///字体高度（计算得来）
    std::map<PatternPos, wxBitmap> m_mapPatterns;      ///临时的图片存储
    std::map<FillPos,    wxBrush>  m_mapFills;         ///临时画刷存储
    std::vector<wxString>          m_vecTextOut;       ///格式化后的输出文字
    wxBitmap                      *m_pTextBG;          ///文字背景图片
};

MissRemindSkin::MissRemindSkin():
m_pImpl(new MissRemindSkinImpl)
{
    /*
    m_pImpl->m_nOverallWidth = 700;
    m_pImpl->m_nMinHeight = 100;
    m_pImpl->m_nMaxHeight = 800;

    m_pImpl->m_cButtonInfo.ptPos = wxPoint(45,-50);
    m_pImpl->m_cButtonInfo.strBtnText = wxT("我知道了");
    m_pImpl->m_cButtonInfo.colorBtn.Set(wxT("#FF00FF"));
    m_pImpl->m_cButtonInfo.fontBtn = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    m_pImpl->m_oTextInfo.ptPos = wxPoint(45,98);
    m_pImpl->m_oTextInfo.nBottomHeight = 83;
    m_pImpl->m_oTextInfo.fontText = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    m_pImpl->m_oTextInfo.colorText.Set(wxT("#FFFFFF"));
    m_pImpl->m_oTextInfo.nTextWidth = m_pImpl->m_nOverallWidth - 90;

    m_pImpl->m_vecPatterns.resize(6);
    m_pImpl->m_vecPatterns[0].ePos = PP_TOP_LEFT;
    m_pImpl->m_vecPatterns[0].strBitmap = wxT("Remind/tl.png");

    m_pImpl->m_vecPatterns[1].ePos = PP_TOP_MID;
    m_pImpl->m_vecPatterns[1].strBitmap = wxT("Remind/tm.png");

    m_pImpl->m_vecPatterns[2].ePos = PP_TOP_RIGHT;
    m_pImpl->m_vecPatterns[2].strBitmap = wxT("Remind/tr.png");

    m_pImpl->m_vecPatterns[3].ePos = PP_BOTTOM_LEFT;
    m_pImpl->m_vecPatterns[3].strBitmap = wxT("Remind/bl.png");

    m_pImpl->m_vecPatterns[4].ePos = PP_BOTTOM_MID;
    m_pImpl->m_vecPatterns[4].strBitmap = wxT("Remind/bm.png");

    m_pImpl->m_vecPatterns[5].ePos = PP_BOTTOM_RIGHT;
    m_pImpl->m_vecPatterns[5].strBitmap = wxT("Remind/br.png");


    m_pImpl->m_vecFills.resize(4);
    m_pImpl->m_vecFills[0].ePos      = PP_TOP_OTHER;
    m_pImpl->m_vecFills[0].strBrush  = wxT("Remind/to.png");
    m_pImpl->m_vecFills[0].nSize     = 98;

    m_pImpl->m_vecFills[1].ePos      = PP_BOTTOM_OTHER;
    m_pImpl->m_vecFills[1].strBrush  = wxT("Remind/bo.png");
    m_pImpl->m_vecFills[1].nSize     = 83;

    m_pImpl->m_vecFills[2].ePos      = PP_LEFT_OTHER;
    m_pImpl->m_vecFills[2].strBrush  = wxT("Remind/lo.png");
    m_pImpl->m_vecFills[2].nSize     = 45;

    m_pImpl->m_vecFills[3].ePos      = PP_RIGHT_OTHER;
    m_pImpl->m_vecFills[3].strBrush  = wxT("Remind/ro.png");
    m_pImpl->m_vecFills[3].nSize     = 45;
    */

}

MissRemindSkin::~MissRemindSkin()
{
    //dtor
}

void MissRemindSkin::LoadTempData()
{
    ///加载图案信息
    for(std::vector<PatternInfo>::const_iterator itor = m_pImpl->m_vecPatterns.begin();
        itor != m_pImpl->m_vecPatterns.end(); ++itor)
    {
        m_pImpl->m_mapPatterns[itor->ePos] = wxBitmap(itor->strBitmap, wxBITMAP_TYPE_PNG);
    }

    ///加载填充信息
    for(std::vector<FillInfo>::const_iterator itor = m_pImpl->m_vecFills.begin();
        itor != m_pImpl->m_vecFills.end(); ++itor)
    {
        m_pImpl->m_mapFills[itor->ePos] = wxBrush(wxBitmap(itor->strBrush, wxBITMAP_TYPE_PNG));
    }

    if(!m_pImpl->m_oTextInfo.strBitmap.IsEmpty())
    {
        m_pImpl->m_pTextBG = new wxBitmap(m_pImpl->m_oTextInfo.strBitmap, wxBITMAP_TYPE_PNG);
    }
}

void MissRemindSkin::ClearTempData()
{
    m_pImpl->m_mapPatterns.clear();
    m_pImpl->m_mapFills.clear();
    std::vector<wxString> ().swap(m_pImpl->m_vecTextOut);
    delete m_pImpl->m_pTextBG; m_pImpl->m_pTextBG = NULL;
}

void MissRemindSkin::DrawSkin(wxDC& dc)
{
    dc.SetPen(*wxTRANSPARENT_PEN);
    DrawFill       (dc);
    DrawPattern    (dc);
    DrawRemindText (dc);
    DrawButton     (dc);
}

void MissRemindSkin::DrawFill(wxDC& memdc)
{
    int nX, nY, nW, nH;
    int &nOverallWidth = m_pImpl->m_nOverallWidth;
    int &nOverallHeight = m_pImpl->m_nOverallHeight;

    const wxBitmap *bitmapTemp(NULL);
    const wxBrush  *brushTemp(NULL);
    for(std::vector<FillInfo>::const_iterator itor = m_pImpl->m_vecFills.begin();
        itor != m_pImpl->m_vecFills.end(); ++itor)
    {
        nX = nY = nW = nH = 0;
        switch(itor->ePos)
        {
        case PP_TOP_OTHER:
            bitmapTemp = GetPatternByPos(PP_TOP_LEFT);
            if(bitmapTemp != NULL)
            {
                nX = bitmapTemp->GetWidth();
            }
            bitmapTemp = GetPatternByPos(PP_TOP_RIGHT);
            if(bitmapTemp != NULL)
            {
                nW = bitmapTemp->GetWidth();
            }
            nW = nOverallWidth - nX - nW;
            nH = itor->nSize;
            break;
        case PP_BOTTOM_OTHER:
            bitmapTemp = GetPatternByPos(PP_BOTTOM_LEFT);
            if(bitmapTemp != NULL)
            {
                nX = bitmapTemp->GetWidth();
            }

            nY = nOverallHeight - itor->nSize;
            bitmapTemp = GetPatternByPos(PP_BOTTOM_RIGHT);
            if(bitmapTemp != NULL)
            {
                nW = bitmapTemp->GetWidth();
            }
            nW = nOverallWidth - nX - nW;
            nH = itor->nSize;
            break;
        case PP_LEFT_OTHER:
            bitmapTemp = GetPatternByPos(PP_TOP_LEFT);
            if(bitmapTemp != NULL)
            {
                nY = bitmapTemp->GetHeight();
            }
            nW = itor->nSize;
            bitmapTemp = GetPatternByPos(PP_BOTTOM_LEFT);
            if(bitmapTemp != NULL)
            {
                nH = bitmapTemp->GetHeight();
            }
            nH = nOverallHeight - nY - nH;
            break;
        case PP_RIGHT_OTHER:
            nX = nOverallWidth - itor->nSize;
            bitmapTemp = GetPatternByPos(PP_TOP_RIGHT);
            if(bitmapTemp != NULL)
            {
                nY = bitmapTemp->GetHeight();
            }
            nW = itor->nSize;
            bitmapTemp = GetPatternByPos(PP_BOTTOM_RIGHT);
            if(bitmapTemp != NULL)
            {
                nH = bitmapTemp->GetHeight();
            }
            nH = nOverallHeight - nY - nH;
            break;
        }
        brushTemp = GetFillByPos(itor->ePos);
        assert(brushTemp != NULL);
        memdc.SetDeviceOrigin(nX, nY);
        memdc.SetBrush(*brushTemp);
        memdc.DrawRectangle(0, 0, nW, nH);
    }
}

void MissRemindSkin::DrawPattern(wxDC& memdc)
{
    int nX, nY;
    int &nOverallWidth = m_pImpl->m_nOverallWidth;
    int &nOverallHeight = m_pImpl->m_nOverallHeight;
    const wxBitmap *bitmapTemp(NULL);

    memdc.SetDeviceOrigin(0, 0);
    for(std::vector<PatternInfo>::const_iterator itor = m_pImpl->m_vecPatterns.begin();
        itor != m_pImpl->m_vecPatterns.end(); ++itor)
    {
        bitmapTemp = GetPatternByPos(itor->ePos);
        assert(bitmapTemp != NULL);
        switch(itor->ePos)
        {
        case PP_TOP_LEFT:
            nX = 0;
            nY = 0;
            break;
        case PP_TOP_MID:
            nX = nOverallWidth / 2 - bitmapTemp->GetWidth() / 2;
            nY = 0;
            break;
        case PP_TOP_RIGHT:
            nX = nOverallWidth - bitmapTemp->GetWidth();
            nY = 0;
            break;
        case PP_MID_LEFT:
            nX = 0;
            nY = nOverallHeight / 2 - bitmapTemp->GetHeight() / 2;
            break;
        case PP_MID_RIGHT:
            nX = nOverallWidth - bitmapTemp->GetWidth();
            nY = nOverallHeight / 2 - bitmapTemp->GetHeight() / 2;
            break;
        case PP_MID_MID:
            nX = nOverallWidth / 2 - bitmapTemp->GetWidth() / 2;
            nY = nOverallHeight / 2 - bitmapTemp->GetHeight() / 2;
            break;
        case PP_BOTTOM_LEFT:
            nX = 0;
            nY = nOverallHeight - bitmapTemp->GetHeight();
            break;
        case PP_BOTTOM_MID:
            nX = nOverallWidth / 2 - bitmapTemp->GetWidth() / 2;
            nY = nOverallHeight - bitmapTemp->GetHeight();
            break;
        case PP_BOTTOM_RIGHT:
            nX = nOverallWidth - bitmapTemp->GetWidth();
            nY = nOverallHeight - bitmapTemp->GetHeight();
            break;
        default:
            assert(false);
            break;
        }
        memdc.DrawBitmap(*bitmapTemp, nX, nY);
    }
}

void MissRemindSkin::DrawRemindText(wxDC& memdc)
{
    if(m_pImpl->m_pTextBG != NULL)
        memdc.SetBrush(wxBrush(*m_pImpl->m_pTextBG));
    memdc.SetTextForeground(m_pImpl->m_oTextInfo.colorText);

    for(size_t ix = 0; ix != m_pImpl->m_vecTextOut.size(); ++ix)
    {
        memdc.SetDeviceOrigin(m_pImpl->m_oTextInfo.ptPos.x,
                m_pImpl->m_oTextInfo.ptPos.y + m_pImpl->m_nTextHeight * ix);

        if(m_pImpl->m_pTextBG != NULL)
        {
            memdc.DrawRectangle(0, 0, m_pImpl->m_oTextInfo.nTextWidth, m_pImpl->m_nTextHeight);
        }
        memdc.DrawLabel(m_pImpl->m_vecTextOut[ix],wxRect(0, 0,
            m_pImpl->m_oTextInfo.nTextWidth, m_pImpl->m_nTextHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    }

}

void MissRemindSkin::DrawButton(wxDC& memdc)
{
    ///关闭按钮信息
    memdc.SetDeviceOrigin(0,0);
    //gc->SetFont(m_Config.btn_font,m_Config.btn_colour);
    wxSize fontSize = memdc.GetTextExtent(m_pImpl->m_cButtonInfo.strBtnText);
    int nTempX(0), nTempY(0);

    if(m_pImpl->m_cButtonInfo.ptPos.x < 0)
    {
        nTempX = m_pImpl->m_nOverallWidth;
    }
    nTempX += m_pImpl->m_cButtonInfo.ptPos.x;

    if(m_pImpl->m_cButtonInfo.ptPos.y < 0)
    {
        nTempY = m_pImpl->m_nOverallHeight;
    }
    nTempY += m_pImpl->m_cButtonInfo.ptPos.y;

    memdc.SetPen(wxPen(m_pImpl->m_cButtonInfo.colorBtn));
    memdc.SetBrush(*wxTRANSPARENT_BRUSH);
    memdc.SetTextForeground(m_pImpl->m_cButtonInfo.colorBtn);
    memdc.DrawText(m_pImpl->m_cButtonInfo.strBtnText, nTempX, nTempY);
    memdc.DrawRectangle(nTempX-10,nTempY-4,fontSize.GetWidth()+20,fontSize.GetHeight()+8);
}

const wxBitmap* MissRemindSkin::GetPatternByPos(const PatternPos& pos)
{
    std::map<PatternPos, wxBitmap>::const_iterator iFind = m_pImpl->m_mapPatterns.find(pos);
    if(iFind != m_pImpl->m_mapPatterns.end())
    {
        return &(iFind->second);
    }
    return NULL;
}

const wxBrush* MissRemindSkin::GetFillByPos(const FillPos& pos)
{
    std::map<FillPos, wxBrush>::const_iterator iFind = m_pImpl->m_mapFills.find(pos);
    if(iFind != m_pImpl->m_mapFills.end())
    {
        return &iFind->second;
    }
    return NULL;
}

void MissRemindSkin::TakeOrderWithNewline(const std::vector<wxString>& vecIn)
{
    wxMemoryDC tmpdc;
    std::vector<wxString> vecLines;
    wxSize fontSize;
    wxArrayInt widthsArray;
    std::vector<wxString>& vecOut = m_pImpl->m_vecTextOut;

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
            if(fontSize.GetWidth() > m_pImpl->m_oTextInfo.nTextWidth)
            {
                widthsArray.Clear();
                tmpdc.GetPartialTextExtents(*itor, widthsArray);

                int nStart(0),nStartWidth(0);
                for(size_t nIndex = 0; nIndex != widthsArray.GetCount(); ++nIndex)
                {
                    if(widthsArray[nIndex] - nStartWidth > m_pImpl->m_oTextInfo.nTextWidth)
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

    ///计算最少高度

    m_pImpl->m_nTextHeight = m_pImpl->m_pTextBG != NULL? m_pImpl->m_pTextBG->GetHeight():fontSize.GetHeight();
    m_pImpl->m_nOverallHeight = m_pImpl->m_oTextInfo.ptPos.y + m_pImpl->m_oTextInfo.nBottomHeight
                                + m_pImpl->m_nTextHeight * vecOut.size();

    m_pImpl->m_nOverallHeight = m_pImpl->m_nOverallHeight < m_pImpl->m_nMinHeight ? m_pImpl->m_nMinHeight :
         m_pImpl->m_nOverallHeight > m_pImpl->m_nMaxHeight ? m_pImpl->m_nMaxHeight : m_pImpl->m_nOverallHeight;
}


int MissRemindSkin::GetOverallWidth() const
{
    return m_pImpl->m_nOverallWidth;
}

int MissRemindSkin::GetOverallHeight() const
{
    return m_pImpl->m_nOverallHeight;
}

void MissRemindSkin::SetOverallWidth(int nOverallWidth)
{
    m_pImpl->m_nOverallWidth = nOverallWidth;
}

void MissRemindSkin::SetMinHeight(int nMinHeight)
{
    m_pImpl->m_nMinHeight = nMinHeight;
}

void MissRemindSkin::SetMaxHeight(int nMaxHeight)
{
    m_pImpl->m_nMaxHeight = nMaxHeight;
}

void MissRemindSkin::SetBtnInfo(const CloseBtnInfo& cButtonInfo)
{
    m_pImpl->m_cButtonInfo = cButtonInfo;
}

void MissRemindSkin::SetBGColor(const wxColor& cBG)
{
    m_pImpl->m_cBG = cBG;
}

void MissRemindSkin::SetTextInfo(const OutTextInfo& oTextInfo)
{
    m_pImpl->m_oTextInfo = oTextInfo;
}

void MissRemindSkin::AddPattern(const PatternInfo& info)
{
    m_pImpl->m_vecPatterns.push_back(info);
}

void MissRemindSkin::AddFill(const FillInfo& info)
{
    m_pImpl->m_vecFills.push_back(info);
}

void MissRemindSkin::ClearPattern()
{
    m_pImpl->m_vecPatterns.clear();
}

void MissRemindSkin::ClearFill()
{
    m_pImpl->m_vecFills.clear();
}

int MissRemindSkin::GetMinHeight() const
{
    return m_pImpl->m_nMinHeight;
}

int MissRemindSkin::GetMaxHeight() const
{
    return m_pImpl->m_nMaxHeight;
}

const MissRemindSkin::CloseBtnInfo& MissRemindSkin::GetCloseBtnInfo() const
{
    return m_pImpl->m_cButtonInfo;
}

const MissRemindSkin::OutTextInfo& MissRemindSkin::GetOutTextInfo() const
{
    return m_pImpl->m_oTextInfo;
}

const MissRemindSkin::PatternInfo& MissRemindSkin::GetPatternInfo(int nIndex) const
{
    return m_pImpl->m_vecPatterns[nIndex];
}

const MissRemindSkin::FillInfo& MissRemindSkin::GetFillInfo(int nIndex) const
{
    return m_pImpl->m_vecFills[nIndex];
}

int MissRemindSkin::GetPatternSize() const
{
    return m_pImpl->m_vecPatterns.size();
}

int MissRemindSkin::GetFillSize() const
{
    return m_pImpl->m_vecFills.size();
}

