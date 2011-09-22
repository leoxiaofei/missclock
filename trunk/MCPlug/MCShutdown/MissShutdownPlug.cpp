#include "MissShutdownPlug.h"
#include "GUIFrame.h"
#include <wx/artprov.h>
#include <wx/image.h>

#include <wx/msgdlg.h>

MissShutdownPlug::MissShutdownPlug():
MissPlugBase(wxT("定时关机"),wxT("3261B663-0415-4B99-AA91-58D9EB043172"))
{
    //ctor
}

MissShutdownPlug::~MissShutdownPlug()
{
    //dtor
}

void MissShutdownPlug::GetIcon(wxImage& image)
{
    image = wxArtProvider::GetBitmap( wxART_NORMAL_FILE, wxART_FRAME_ICON ).ConvertToImage();
}

void MissShutdownPlug::InitPanel(wxWindow* parent)
{
    m_pan = new MCShutdown(parent);
}

wxString MissShutdownPlug::GetTaskContent()
{
    wxString strRet;
    strRet.Printf(wxT("%d"),static_cast<MCShutdown*>(m_pan)->m_rBoxShutdown->GetSelection());
    return strRet;
}

void MissShutdownPlug::TimeUpRun(tm* tmNow, const wxString& strTaskContent)
{
    wxMessageBox(GetDescription(strTaskContent));
}

void MissShutdownPlug::Release()
{
}

void MissShutdownPlug::InitData(const wxString& strTaskContent)
{
    unsigned long nIndex;
    if(strTaskContent.ToULong(&nIndex))
    {
        if(nIndex < 3)
        {
            static_cast<MCShutdown*>(m_pan)->m_rBoxShutdown->SetSelection(nIndex);
        }
    }
}

wxString MissShutdownPlug::s_strDescription[] = {wxT("关机"), wxT("重启"), wxT("注销")};

wxString MissShutdownPlug::GetDescription(const wxString& strTaskContent)
{
    wxString strRet;
    unsigned long nIndex;
    if(strTaskContent.ToULong(&nIndex))
    {
        if(nIndex < 3)
        {
            strRet = s_strDescription[nIndex];
        }
    }

    return strRet;
}
