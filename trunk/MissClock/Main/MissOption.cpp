#include "MissOption.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include "../Data/MissConfig.h"
#include "../Data/MissSkin.h"
#include <wx/fontdlg.h>
#include <wx/colordlg.h>


MissOption::MissOption(wxWindow* parent)
    :
    MissOptionBase(parent),
    m_nThemeItem(0)
{

}

void MissOption::SetDataSrc(shared_ptr<MissConfig>& pConfig, shared_ptr<MissSkin>& pSkin)
{
    m_pConfig = pConfig;
    m_pSkin = pSkin;
}

void MissOption::OnInitDialog(wxInitDialogEvent& event)
{
    m_choTheme->Append(GetSkinsName());
    m_choTheme->SetStringSelection(m_pConfig->GetSkinName());
    m_lstItem->InsertColumn(0, _T("ID"), wxLIST_FORMAT_LEFT, 40);
    m_lstItem->InsertColumn(1, _T("名称"), wxLIST_FORMAT_LEFT, 120);
    EnableItemSet(false);
    LoadThemeOption();
}

void MissOption::EnableItemSet(bool bEnable)
{
    m_edtName->Enable(bEnable);
    m_cbtnShow->Enable(bEnable);
    m_edtContent->Enable(bEnable);
    m_btnFont->Enable(bEnable);
    m_btnColor->Enable(bEnable);
    m_edtAlign->Enable(bEnable);
    m_sldAlign->Enable(bEnable);
    m_spX->Enable(bEnable);
    m_spY->Enable(bEnable);
    m_btnDeleteItem->Enable(bEnable);
}

wxArrayString MissOption::GetSkinsName()
{
    wxArrayString ret;
    wxString diraddr = wxT("Skin\\");
    wxDir dir(diraddr);
    if (dir.IsOpened())
    {
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while (cont)
        {
            if (wxFileName::FileExists(diraddr + filename + wxT("\\ClockSkin.xml")))
            {
                ret.Add(filename);
            }
            cont = dir.GetNext(&filename);
        }
    }
    return ret;
}

void MissOption::OnThemeChoChange(wxCommandEvent& event)
{
// TODO: Implement OnSkinChoChange
    /*
     *ProcessEvent是同步处理一个事件，该事件被处理完才结束；
     *wxPostEvent(AddPendingEvent)是异步处理一个事件，将事件加入到对应事件句柄的事件待处理队列，
    */
    //wxCommandEvent event();
    GetParent()->GetEventHandler()->ProcessEvent(event);
    LoadThemeOption();
}

void MissOption::LoadThemeOption()
{
    m_edtBGPath->SetValue(m_pSkin->GetBGPicPath());
    m_cobLocale->SetValue(m_pSkin->GetLocale());

    m_lstItem->DeleteAllItems();

    for (int ix = 0; ix < m_pSkin->GetElementSize(); ++ix)
    {
        m_lstItem->InsertItem(ix, wxEmptyString);
        m_lstItem->SetItem(ix, 0, wxString::Format(wxT("%d"), ix));
        m_lstItem->SetItem(ix, 1, m_pSkin->GetElement(ix).m_Name);
    }

}

void MissOption::OnModifyThemeBtnClick(wxCommandEvent& event)
{
// TODO: Implement OnModifySkinBtnClick

}

void MissOption::OnZoomCbtnClick(wxCommandEvent& event)
{
// TODO: Implement OnZoomCbtnClick
}

void MissOption::OnZoomSldChanged(wxScrollEvent& event)
{
// TODO: Implement OnZoomSldChanged
}

void MissOption::OnTransSldChanged(wxScrollEvent& event)
{
// TODO: Implement OnTransSldChanged
}

void MissOption::OnNtpBtnClick(wxCommandEvent& event)
{
// TODO: Implement OnNtpBtnClick
}

void MissOption::OnCancel(wxCommandEvent& event)
{
// TODO: Implement OnCancel
    EndModal(wxID_CANCEL);
}

void MissOption::OnOK(wxCommandEvent& event)
{
// TODO: Implement OnOK
    EndModal(wxID_OK);
}
void MissOption::OnBtnBGPathClick(wxCommandEvent& event)
{
}

void MissOption::OnCobLocaleSelect(wxCommandEvent& event)
{

}

void MissOption::OnlstItemSelect(wxListEvent& event)
{
    EnableItemSet(true);

    m_nThemeItem = static_cast<int>(event.GetIndex());
    m_edtName->SetValue( m_pSkin->GetElement(m_nThemeItem).m_Name );
    m_cbtnShow->SetValue( m_pSkin->GetElement(m_nThemeItem).m_Show );
    m_edtContent->SetValue( wxString(m_pSkin->GetElement(m_nThemeItem).m_Content.c_str(),wxConvLocal ) );
    m_spX->SetValue( m_pSkin->GetElement(m_nThemeItem).m_X );
    m_spY->SetValue( m_pSkin->GetElement(m_nThemeItem).m_Y );

    if ( m_pSkin->GetElement(m_nThemeItem).m_Alignment == 0.5 )
    {
        m_sldAlign->SetValue(1);
    }
    else if ( m_pSkin->GetElement(m_nThemeItem).m_Alignment == 1.0 )
    {
        m_sldAlign->SetValue(2);
    }
    else
    {
        m_sldAlign->SetValue(0);
    }

    UpdateEdtAlignText();

}

void MissOption::OnlstItemDeselect(wxListEvent& event)
{
    EnableItemSet(false);
}

void MissOption::UpdateEdtAlignText()
{
    switch (m_sldAlign->GetValue())
    {
    case 0:
        m_edtAlign->SetValue(wxT("左对齐"));
        break;
    case 1:
        m_edtAlign->SetValue(wxT("居中"));
        break;
    case 2:
        m_edtAlign->SetValue(wxT("右对齐"));
        break;
    }
}

void MissOption::OnBtnAddItem(wxCommandEvent& event)
{
}

void MissOption::OnBtnDeleteItem(wxCommandEvent& event)
{

}

void MissOption::OnEdtNameKillFocus(wxFocusEvent& event)
{
}

void MissOption::OnCbtnShowClick(wxCommandEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Show = m_cbtnShow->GetValue();
    //更新主界面
}

void MissOption::OnEdtContentKillFocus(wxFocusEvent& event)
{
}

void MissOption::OnBtnFont(wxCommandEvent& event)
{
    wxFontData data ;
    data.SetInitialFont ( m_pSkin->GetElement(m_nThemeItem).m_Font );
    data.EnableEffects(false);
    wxFontDialog dialog ( this ,data );
    if ( dialog.ShowModal () == wxID_OK )
    {
        m_pSkin->GetElement(m_nThemeItem).m_Font = dialog.GetFontData().GetChosenFont();
        //更新主界面
    }
}

void MissOption::OnBtnColor(wxCommandEvent& event)
{
    wxColourData data;
    wxColour clrtmp;
    data.SetChooseFull(true);
    data.SetColour( m_pSkin->GetElement(m_nThemeItem).m_Colour );
    wxColourDialog dialog( this , &data );
    if ( dialog.ShowModal () == wxID_OK )
    {
        m_pSkin->GetElement(m_nThemeItem).m_Colour = dialog.GetColourData().GetColour();
        //更新主界面

    }
}

void MissOption::OnSldAlignScrollThumbRelease(wxScrollEvent& event)
{
    UpdateEdtAlignText();
    m_pSkin->GetElement(m_nThemeItem).m_Alignment = m_sldAlign->GetValue() / 2.0;
    //更新主界面
}

void MissOption::OnSpXChange(wxSpinEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_X = m_spX->GetValue();
    //更新主界面
}

void MissOption::OnSpYChange(wxSpinEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Y = m_spY->GetValue();
    //更新主界面
}
