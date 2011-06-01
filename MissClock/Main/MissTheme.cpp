#include "MissTheme.h"
#include <wx/fontdlg.h>
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include "../Data/MissSkin.h"
#include "../Common/MissGlobal.h"

MissTheme::MissTheme( wxWindow* parent )
:
MissThemeBase( parent ),
m_nThemeItem(-1)
{

}

void MissTheme::SetDataSrc(shared_ptr<MissSkin>& pSkin)
{
    m_pSkin = pSkin;
}

void MissTheme::OnInitDialog( wxInitDialogEvent& event )
{
// TODO: Implement OnInitDialog
    m_lstItem->InsertColumn(0, _T("ID"), wxLIST_FORMAT_LEFT, 40);
    m_lstItem->InsertColumn(1, _T("名称"), wxLIST_FORMAT_LEFT, 120);
    LoadThemeOption();
}

void MissTheme::OnBtnBGPathClick( wxCommandEvent& event )
{
// TODO: Implement OnBtnBGPathClick
    wxFileDialog fdgBGPic(this, _("Select file"), wxEmptyString, wxEmptyString,
                          _("PNG Files(*.png)|*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition,
                          wxDefaultSize, _T("wxFileDialog"));
    if ( fdgBGPic.ShowModal() == wxID_OK )
    {
        wxString bgPicAddr = wxString::Format(wxT("%s\\Skin\\%s\\"),wxGetCwd().c_str(),
                                              m_pSkin->GetSkinName().c_str());

        bgPicAddr<<fdgBGPic.GetFilename();

        if(!fdgBGPic.GetFilename().Upper().EndsWith(wxT(".PNG")))
        {
            wxMessageBox(wxT("抱歉，暂时只支持PNG格式的图片。"));
            return;
        }

        if (bgPicAddr == fdgBGPic.GetPath())
        {
            m_pSkin->SetBGPicPath(fdgBGPic.GetFilename());
            m_edtBGPath->SetValue(fdgBGPic.GetFilename());
        }
        else
        {
            wxString tip = wxString::Format(
            wxT("是否将其图片复制到主题文件夹中？\n该主题文件夹位于：\n%s\n这将会覆盖同名文件。"),
                                            bgPicAddr.c_str());
            if ( wxYES == wxMessageBox(tip,wxT("提示："),wxYES_NO|wxYES_DEFAULT) )
            {

                if (wxCopyFile( fdgBGPic.GetPath(),bgPicAddr ))
                {
                    m_pSkin->SetBGPicPath(fdgBGPic.GetFilename());
                    m_edtBGPath->SetValue(fdgBGPic.GetFilename());
                }
                else
                {
                    wxMessageBox(wxT("复制文件失败！我只好放弃复制文件。"));
                    m_pSkin->SetBGPicPath(fdgBGPic.GetPath());
                    m_edtBGPath->SetValue(fdgBGPic.GetPath());
                }
            }
            else
            {
                m_pSkin->SetBGPicPath(fdgBGPic.GetPath());
                m_edtBGPath->SetValue(fdgBGPic.GetPath());
            }
        }
        ///更新主界面
        SendUpdateEvent();
    }
}

void MissTheme::OnCobLocaleSelect( wxCommandEvent& event )
{
// TODO: Implement OnCobLocaleSelect
}

void MissTheme::OnlstItemDeselect( wxListEvent& event )
{
// TODO: Implement OnlstItemDeselect
	EnableItemSet(false);
}

void MissTheme::OnlstItemSelect( wxListEvent& event )
{
// TODO: Implement OnlstItemSelect
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

void MissTheme::OnBtnAddItem( wxCommandEvent& event )
{
// TODO: Implement OnBtnAddItem
    MissElement newEment;
    newEment.m_Name = wxT("新建");
    newEment.m_Show = true;
    newEment.m_X = 0;
    newEment.m_Y = 0;
    newEment.m_Alignment = 0;
    newEment.m_Font = wxFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL );
    newEment.m_Colour = wxColor(0xFF,0xFF,0xFF);

    m_pSkin->AddElement(newEment);

    int nItemcount = m_lstItem->GetItemCount();
    m_lstItem->InsertItem(nItemcount, wxEmptyString);
    m_lstItem->SetItem(nItemcount,0,wxString::Format(wxT("%d"),nItemcount));
    m_lstItem->SetItem(nItemcount,1,newEment.m_Name);
}

void MissTheme::OnBtnDeleteItem( wxCommandEvent& event )
{
// TODO: Implement OnBtnDeleteItem
    m_pSkin->DelElement(m_nThemeItem);
    m_lstItem->DeleteItem(m_nThemeItem);
    for ( int ix=0; ix < m_lstItem->GetItemCount(); ++ix )
    {
        m_lstItem->SetItem(ix,0,wxString::Format(wxT("%d"),ix));
    }
    ///更新界面
    SendUpdateEvent();
}

void MissTheme::OnEdtNameKillFocus( wxFocusEvent& event )
{
// TODO: Implement OnEdtNameKillFocus
    m_pSkin->GetElement(m_nThemeItem).m_Name = m_edtName->GetValue();
    m_lstItem->SetItem(m_nThemeItem,1,m_edtName->GetValue());
}

void MissTheme::OnCbtnShowClick( wxCommandEvent& event )
{
// TODO: Implement OnCbtnShowClick
    m_pSkin->GetElement(m_nThemeItem).m_Show = m_cbtnShow->GetValue();
    ///更新主界面
    SendUpdateEvent();
}

void MissTheme::OnEdtContentKillFocus( wxFocusEvent& event )
{
// TODO: Implement OnEdtContentKillFocus
    m_pSkin->GetElement(m_nThemeItem).m_Content = m_edtContent->GetValue().mb_str();
    ///更新主界面
    SendUpdateEvent();
}

void MissTheme::OnBtnFont( wxCommandEvent& event )
{
// TODO: Implement OnBtnFont
    wxFontData data ;
    data.SetInitialFont ( m_pSkin->GetElement(m_nThemeItem).m_Font );
    data.EnableEffects(false);
    wxFontDialog dialog ( this ,data );
    if ( dialog.ShowModal () == wxID_OK )
    {
        m_pSkin->GetElement(m_nThemeItem).m_Font = dialog.GetFontData().GetChosenFont();
        ///更新主界面
        SendUpdateEvent();
    }
}

void MissTheme::OnBtnColor( wxCommandEvent& event )
{
// TODO: Implement OnBtnColor
    wxColourData data;
    wxColour clrtmp;
    data.SetChooseFull(true);
    data.SetColour( m_pSkin->GetElement(m_nThemeItem).m_Colour );
    wxColourDialog dialog( this , &data );
    if ( dialog.ShowModal () == wxID_OK )
    {
        m_pSkin->GetElement(m_nThemeItem).m_Colour = dialog.GetColourData().GetColour();
        ///更新主界面
        SendUpdateEvent();
    }
}

void MissTheme::OnSldAlignScrollThumbRelease( wxScrollEvent& event )
{
// TODO: Implement OnSldAlignScrollThumbRelease
    UpdateEdtAlignText();
    m_pSkin->GetElement(m_nThemeItem).m_Alignment = m_sldAlign->GetValue() / 2.0;
    ///更新主界面
    SendUpdateEvent();
}

void MissTheme::OnSpXChange( wxSpinEvent& event )
{
// TODO: Implement OnSpXChange
    m_pSkin->GetElement(m_nThemeItem).m_X = m_spX->GetValue();
    ///更新主界面
    SendUpdateEvent();
}

void MissTheme::OnSpYChange( wxSpinEvent& event )
{
// TODO: Implement OnSpYChange
    m_pSkin->GetElement(m_nThemeItem).m_Y = m_spY->GetValue();
    ///更新主界面
    SendUpdateEvent();
}

void MissTheme::EnableItemSet(bool bEnable)
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

void MissTheme::LoadThemeOption()
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

void MissTheme::UpdateEdtAlignText()
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

void MissTheme::SendUpdateEvent()
{
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(MissGlobal::UE_UPDATE);
    GetParent()->GetEventHandler()->ProcessEvent(send);
}
