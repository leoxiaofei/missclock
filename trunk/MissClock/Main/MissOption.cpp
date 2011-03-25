#include "MissOption.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include "../Data/MissConfig.h"
#include "../Data/MissSkin.h"
#include <wx/fontdlg.h>
#include <wx/colordlg.h>
#include <wx/filedlg.h>

DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCUI_EVENT);
//wxDEFINE_EVENT(wxEVT_MCUI_EVENT, wxCommandEvent);

MissOption::MissOption(wxWindow* parent)
    :
    MissOptionBase(parent),
    m_nThemeItem(0),
    m_bThemeModify(false)
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
    //EnableItemSet(false);
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
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(UE_CHANGETHEME);
    send.SetString(event.GetString());
    GetEventHandler()->ProcessEvent(send);
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

    //如果当前是修改主题状态
    if(m_bThemeModify)
    {
        long item = -1;
        item = m_lstItem->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        if ( item != -1 )
        {
            //取消选中状态
            m_lstItem->SetItemState(item, 0, wxLIST_STATE_SELECTED|wxLIST_STATE_FOCUSED);

            /*
            选中Item
            wxListCtrl->SetItemState(item, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
            */
        }
        //保存主题设置
        wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
        send.SetInt(UE_SAVETHEME);
        GetEventHandler()->ProcessEvent(send);
    }

    m_sdbSizerOK->Enable(m_bThemeModify);
    m_sdbSizerCancel->Enable(m_bThemeModify);
    m_choTheme->Enable(m_bThemeModify);
    m_bThemeModify = !m_bThemeModify;
    m_btnModifyTheme->SetLabel(m_bThemeModify?wxT("保存主题"):wxT("修改主题"));
    m_btnUnDoSaveTheme->Show(m_bThemeModify);
    sbSizerTheme->RecalcSizes();
    m_edtBGPath->Enable(m_bThemeModify);
    m_btnBGPath->Enable(m_bThemeModify);
    m_cobLocale->Enable(m_bThemeModify);
    m_lstItem->Enable(m_bThemeModify);
    m_btnAddItem->Enable(m_bThemeModify);
}

void MissOption::OnBtnUnDoSaveThemeClick(wxCommandEvent& event)
{
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(UE_RELOADTHEME);
    GetEventHandler()->ProcessEvent(send);
    LoadThemeOption();

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
    wxFileDialog fdgBGPic(this, _("Select file"), wxEmptyString, wxEmptyString,
                          _("PNG Files(*.png)|*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition,
                          wxDefaultSize, _T("wxFileDialog"));
    if ( fdgBGPic.ShowModal() == wxID_OK )
    {
        wxString bgPicAddr = wxString::Format(wxT("%s\\Skin\\%s\\"),wxGetCwd().c_str(),
                                              m_pConfig->GetSkinName().c_str());

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
        //更新主界面
        SendUpdateEvent();
    }
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

void MissOption::OnBtnDeleteItem(wxCommandEvent& event)
{
    m_pSkin->DelElement(m_nThemeItem);
    m_lstItem->DeleteItem(m_nThemeItem);
    for ( int ix=0; ix < m_lstItem->GetItemCount(); ++ix )
    {
        m_lstItem->SetItem(ix,0,wxString::Format(wxT("%d"),ix));
    }
    //更新界面
    SendUpdateEvent();
}

void MissOption::OnEdtNameKillFocus(wxFocusEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Name = m_edtName->GetValue();
    m_lstItem->SetItem(m_nThemeItem,1,m_edtName->GetValue());
}

void MissOption::OnCbtnShowClick(wxCommandEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Show = m_cbtnShow->GetValue();
    //更新主界面
    SendUpdateEvent();
}

void MissOption::OnEdtContentKillFocus(wxFocusEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Content = m_edtContent->GetValue().ToAscii();
    //更新主界面
    SendUpdateEvent();
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
        SendUpdateEvent();
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
        SendUpdateEvent();
    }
}

void MissOption::OnSldAlignScrollThumbRelease(wxScrollEvent& event)
{
    UpdateEdtAlignText();
    m_pSkin->GetElement(m_nThemeItem).m_Alignment = m_sldAlign->GetValue() / 2.0;
    //更新主界面
    SendUpdateEvent();
}

void MissOption::OnSpXChange(wxSpinEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_X = m_spX->GetValue();
    //更新主界面
    SendUpdateEvent();
}

void MissOption::OnSpYChange(wxSpinEvent& event)
{
    m_pSkin->GetElement(m_nThemeItem).m_Y = m_spY->GetValue();
    //更新主界面
    SendUpdateEvent();
}

void MissOption::SendUpdateEvent()
{
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(UE_UPDATE);
    GetEventHandler()->ProcessEvent(send);
}
