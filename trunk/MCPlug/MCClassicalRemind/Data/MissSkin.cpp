//#include "../StdAfx.h"

#include "MissSkin.h"
#include <wx/bitmap.h>
#include <wx/dc.h>
#include <tinyxml.h>

class MissSkin::MissSkinImpl
{
public:
    wxString                 m_SkinPath;
    wxString                 m_BGPicPath;
    wxString                 m_Locale;
    std::vector<MissElement> m_Element;
    wxBitmap                 m_ClockBGPic;
};

MissSkin::MissSkin():
    m_pImpl(new MissSkinImpl)
{
    //ctor
}

MissSkin::~MissSkin()
{
    //dtor
}

void MissSkin::DrawSkin(wxDC& dc, const tm* tmNow)
{
    static char str[100];
    static wxCoord width;
    static wxString strOut;
    dc.DrawBitmap(m_pImpl->m_ClockBGPic,0,0);

    for (size_t ix = 0;ix != m_pImpl->m_Element.size(); ++ix)
    {
        if (m_pImpl->m_Element[ix].m_Show)
        {
            dc.SetFont(m_pImpl->m_Element[ix].m_Font);
            dc.SetTextForeground(m_pImpl->m_Element[ix].m_Colour);
            strftime (str,100, m_pImpl->m_Element[ix].m_Content.c_str(),tmNow);

            strOut = wxString(str,wxConvLocal);
            dc.GetTextExtent(strOut,&width,NULL,NULL,NULL,NULL);
            dc.DrawText(strOut,m_pImpl->m_Element[ix].m_X-width*m_pImpl->m_Element[ix].m_Alignment, m_pImpl->m_Element[ix].m_Y);
        }
    }
}

MissElement& MissSkin::GetElement(int nIndex) const
{
    return m_pImpl->m_Element.at(nIndex);
}

void MissSkin::SetSkinPath(const wxString& strPath)
{
    m_pImpl->m_SkinPath = strPath;
}

void MissSkin::SetBGPicPath(const wxString& strPicPath)
{
    m_pImpl->m_BGPicPath = strPicPath;
    LoadBGPic();
}

void MissSkin::DelElement(unsigned int nIndex)
{
    if(nIndex < m_pImpl->m_Element.size())
    {
        std::vector<MissElement>::iterator itor = m_pImpl->m_Element.begin();
        itor = itor + nIndex;
        m_pImpl->m_Element.erase(itor);
    }
}

void MissSkin::SetLocale(const wxString& strLocale)
{
    m_pImpl->m_Locale = strLocale;
    wxSetlocale(LC_TIME,strLocale);
}

void MissSkin::AddElement(const MissElement& element)
{
    m_pImpl->m_Element.push_back(element);
}

void MissSkin::ClearElement()
{
    m_pImpl->m_Element.clear();
}

void MissSkin::LoadBGPic()
{
    if( wxNOT_FOUND == m_pImpl->m_BGPicPath.Find(wxT("\\")) )
    {
        wxString bgPicAddr = m_pImpl->m_SkinPath + m_pImpl->m_BGPicPath;
        m_pImpl->m_ClockBGPic = wxBitmap(bgPicAddr, wxBITMAP_TYPE_PNG);
        std::wcout<<bgPicAddr.c_str()<<std::endl;
    }
    else
    {
        m_pImpl->m_ClockBGPic = wxBitmap(m_pImpl->m_BGPicPath, wxBITMAP_TYPE_PNG);
    }
}

const wxString& MissSkin::GetSkinPath() const
{
    return m_pImpl->m_SkinPath;
}

const wxString& MissSkin::GetBGPicPath() const
{
    return m_pImpl->m_BGPicPath;
}

const wxString& MissSkin::GetLocale() const
{
    return m_pImpl->m_Locale;
}

int MissSkin::GetElementSize() const
{
    return m_pImpl->m_Element.size();
}

const wxBitmap& MissSkin::GetBGBitmap() const
{
    return m_pImpl->m_ClockBGPic;
}
