#include "../StdAfx.h"

#include "MissSkin.h"
#include <wx/bitmap.h>
#include <wx/dc.h>
#include <tinyxml.h>

class MissSkin::MissSkinImpl
{
public:
    wxString                 m_SkinName;
    wxString                 m_BGPicPath;
    wxString                 m_Locale;
    std::vector<MissElement> m_Element;
    wxBitmap                 m_ClockBGPic;
};

MissSkin::MissSkin():
    m_pImpl(new MissSkinImpl)
{
    //ctor
    _wsetlocale(LC_TIME,wxT("chs"));
}

MissSkin::~MissSkin()
{
    //dtor
}

void MissSkin::DrawSkin(wxDC& dc, struct tm *tmNow)
{
    dc.DrawBitmap(m_pImpl->m_ClockBGPic,0,0);
    static wchar_t str[100];
    wchar_t *str1 = L"心情";
    std::wstring str2 = L"测试";
    const wchar_t *str3 = str2.c_str();
    wxStrftime (str,100,wxT("%A"),tmNow);
    dc.SetFont(wxFont(12,wxFONTFAMILY_SWISS ,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL ));
    dc.DrawText(str2,10,10);
    std::wcout<<str1<<std::endl;
    std::wcout<<str2<<std::endl;
    std::wcout<<str3<<std::endl;
    std::wcout<<str<<std::endl;
    /*
    for (size_t ix = 0;ix != m_pImpl->m_Element.size(); ++ix)
    {
        if (m_pImpl->m_Element[ix].m_Show)
        {
            dc.SetFont(m_pImpl->m_Element[ix].m_Font);
            dc.SetTextForeground(m_pImpl->m_Element[ix].m_Colour);
            static wchar_t str[100];
            wxStrftime (str,100,m_pImpl->m_Element[ix].m_Content,tmNow);
            //std::wcout<<m_pImpl->m_Element[ix].m_Content<<"<->"<<str<<std::endl;
            static wxCoord width;
            wxString strOut (str,wxConvLocal);
            dc.GetTextExtent(strOut,&width,NULL,NULL,NULL,NULL);
            dc.DrawText(strOut,m_pImpl->m_Element[ix].m_X-width*m_pImpl->m_Element[ix].m_Alignment, m_pImpl->m_Element[ix].m_Y);
        }
    }
    */
}

MissElement& MissSkin::GetElement(int nIndex)
{
    return m_pImpl->m_Element.at(nIndex);
}

void MissSkin::SetSkinName(const wxString& strName)
{
    m_pImpl->m_SkinName = strName;
}

void MissSkin::SetBGPicPath(const wxString& strPicPath)
{
    m_pImpl->m_BGPicPath = strPicPath;
}

void MissSkin::SetLocale(const wxString& strLocale)
{
    m_pImpl->m_Locale = strLocale;
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
        wxString bgPicAddr = wxString::Format(wxT("Skin\\%s\\%s"),m_pImpl->m_SkinName.c_str(),m_pImpl->m_BGPicPath.c_str());
        m_pImpl->m_ClockBGPic = wxBitmap(bgPicAddr, wxBITMAP_TYPE_PNG);
        std::wcout<<bgPicAddr.c_str()<<std::endl;
    }
    else
    {
        m_pImpl->m_ClockBGPic = wxBitmap(m_pImpl->m_BGPicPath, wxBITMAP_TYPE_PNG);
    }
}

const wxString& MissSkin::GetSkinName()
{
    return m_pImpl->m_SkinName;
}

const wxString& MissSkin::GetBGPicPath()
{
    return m_pImpl->m_BGPicPath;
}

const wxString& MissSkin::GetLocale()
{
    return m_pImpl->m_Locale;
}

int MissSkin::GetElementSize()
{
    return m_pImpl->m_Element.size();
}

const wxBitmap& MissSkin::GetBGBitmap()
{
    return m_pImpl->m_ClockBGPic;
}
