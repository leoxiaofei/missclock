#include "../StdAfx.h"
#include "MissXML.h"
#include "MissSkin.h"
#include <tinyxml.h>

bool MissXML::SaveSkin(const shared_ptr<MissSkin>& pSkin)
{
    bool ret(false);
    TiXmlDocument * xmlDocs = new TiXmlDocument();
    TiXmlDeclaration * xmlDec = new TiXmlDeclaration("1.0", "UTF-8", "yes");
    xmlDocs->LinkEndChild(xmlDec);

    TiXmlElement* root = new TiXmlElement("ApplictionConfig");
    xmlDocs->LinkEndChild(root);

    TiXmlElement *elemPic = new TiXmlElement("背景图片");
    TiXmlText *elemPicText = new TiXmlText(pSkin->GetBGPicPath().utf8_str());
    elemPic->LinkEndChild(elemPicText);
    root->LinkEndChild(elemPic);
    TiXmlElement *elemLoc = new TiXmlElement("区域代码");
    TiXmlText *elemLocText = new TiXmlText(pSkin->GetLocale().utf8_str());
    elemLoc->LinkEndChild(elemLocText);
    root->LinkEndChild(elemLoc);

    TiXmlElement *elemShow = new TiXmlElement("显示条目");
    root->LinkEndChild(elemShow);
    int nCount = pSkin->GetElementSize();
    for(int ix = 0;ix != nCount; ++ix)
    {
        TiXmlElement *elem = new TiXmlElement(pSkin->GetElement(ix).m_Name.utf8_str());
        elem->SetAttribute("显示",pSkin->GetElement(ix).m_Show?1:0);
        elem->SetAttribute("字体",pSkin->GetElement(ix).m_Font.GetFaceName().utf8_str());
        elem->SetAttribute("字号",pSkin->GetElement(ix).m_Font.GetPointSize());
        elem->SetAttribute("粗体",pSkin->GetElement(ix).m_Font.GetWeight());
        elem->SetAttribute("斜体",pSkin->GetElement(ix).m_Font.GetStyle());
        elem->SetAttribute("颜色",pSkin->GetElement(ix).m_Colour.GetAsString(wxC2S_HTML_SYNTAX).utf8_str());
        elem->SetAttribute("对齐",wxString::Format(wxT("%.1f"),pSkin->GetElement(ix).m_Alignment).utf8_str());
        elem->SetAttribute("X",pSkin->GetElement(ix).m_X);
        elem->SetAttribute("Y",pSkin->GetElement(ix).m_Y);
        TiXmlText *elemText = new TiXmlText(wxString(pSkin->GetElement(ix).m_Content.c_str(),wxConvLocal ).utf8_str());
        elem->LinkEndChild(elemText);
        elemShow->LinkEndChild(elem);
    }
    wxString SkinAddr = wxString::Format(wxT("Skin\\%s\\ClockSkin.xml"),pSkin->GetSkinName().c_str());
    ret=xmlDocs->SaveFile(SkinAddr.mb_str());
    delete xmlDocs;
    return ret;
}

void MissXML::LoadSkin(const shared_ptr<MissSkin>& pSkin, const wxString& SkinName)
{
    pSkin->SetSkinName( SkinName );
    wxString SkinAddr = wxString::Format(wxT("Skin\\%s\\ClockSkin.xml"),SkinName.c_str());
    TiXmlDocument doc(SkinAddr.mb_str());
    doc.LoadFile();
    TiXmlElement* root = doc.FirstChildElement("ApplictionConfig");
    if (root)///检测主节点ApplictionConfig是否存在
    {
        ///背景图片节点
        TiXmlElement * CurElement = root->FirstChildElement("背景图片");
        ///背景图片节点检测开始
        if (CurElement)
        {
            const char* CurStr = CurElement->GetText();
            pSkin->SetBGPicPath(wxString(CurStr, wxConvUTF8));
            //wxMessageBox(BGS, _("背景图片节点检测"));
        }
        ///背景图片节点检测结束

        ///区域格式节点
        CurElement = root->FirstChildElement("区域代码");
        if (CurElement)
        {
            const char* CurStr = CurElement->GetText();
            pSkin->SetLocale( wxString(CurStr, wxConvUTF8) );
            ///wxMessageBox(BGS, _("区域格式节点检测"));
        }
        ///区域格式节点检测结束
        CurElement = root->FirstChildElement("显示条目");
        CurElement = CurElement->FirstChildElement();
        MissElement elem;
        pSkin->ClearElement();
        while(CurElement)
        {
            const char* CurStr = CurElement->Value();
            elem.m_Name=wxString(CurStr, wxConvUTF8);

            CurStr = CurElement->Attribute("显示");
            elem.m_Show=(wxString(CurStr, wxConvUTF8)==wxT("1"));

            CurStr = CurElement->Attribute("字体");
            wxString fontname=wxString(CurStr, wxConvUTF8);

            CurStr = CurElement->Attribute("字号");
            int fontsize=atoi(CurStr);

            CurStr = CurElement->Attribute("粗体");
            int fontbold=atoi(CurStr);

            CurStr = CurElement->Attribute("斜体");
            int fontitalic=atoi(CurStr);

            elem.m_Font = wxFont(fontsize,wxFONTFAMILY_DEFAULT, fontitalic,fontbold,false,fontname);

            CurStr = CurElement->Attribute("颜色");
            elem.m_Colour.Set(wxString(CurStr, wxConvUTF8));
            //elem.m_colour.Set(elem.m_colour.Red(),elem.m_colour.Green(),elem.m_colour.Blue());

            CurStr = CurElement->Attribute("对齐");
            elem.m_Alignment = atof(CurStr);

            CurStr = CurElement->Attribute("X");
            elem.m_X = atoi(CurStr);

            CurStr = CurElement->Attribute("Y");
            elem.m_Y = atoi(CurStr);

            CurStr = CurElement->GetText();
            elem.m_Content = wxString(CurStr, wxConvUTF8).mb_str();

            pSkin->AddElement(elem);
            CurElement=CurElement->NextSiblingElement();
        }
    }
}
