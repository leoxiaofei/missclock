#include "MissOption.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include "../Data/MissConfig.h"
#include "../Common/MissGlobal.h"
#include "MissTheme.h"
#include "MissSetTimer.h"

//wxDEFINE_EVENT(wxEVT_MCUI_EVENT, wxCommandEvent);

MissOption::MissOption(wxWindow* parent)
    :
    MissOptionBase(parent)
{
    CentreOnScreen();
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


    m_cbtnAllowZoom->SetValue(m_pConfig->GetZoom() != 1.0);
    m_sldZoom->SetValue(static_cast<int>(m_pConfig->GetZoom() * 100));
    SetZoomState(m_cbtnAllowZoom->GetValue());
}

void MissOption::SetZoomState(bool bEnable)
{
    m_sldZoom->Enable(bEnable);
    if(!bEnable)
    {
        m_sldZoom->SetValue(100);
    }
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
    m_pConfig->SetSkinName(event.GetString());
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(MissGlobal::UE_UPDATETHEME);
    GetEventHandler()->ProcessEvent(send);
}

void MissOption::OnModifyThemeBtnClick(wxCommandEvent& event)
{
// TODO: Implement OnModifySkinBtnClick
    MissTheme ThemeDlg(this);
    ThemeDlg.SetDataSrc(m_pSkin);
    if(ThemeDlg.ShowModal() == wxID_OK)
    {
        //保存主题设置
        wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
        send.SetInt(MissGlobal::UE_SAVETHEME);
        GetEventHandler()->ProcessEvent(send);
    }

    /*
    if(m_bThemeModify)
    {
        long item = -1;
        item = m_lstItem->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        if ( item != -1 )
        {
            //取消选中状态
            m_lstItem->SetItemState(item, 0, wxLIST_STATE_SELECTED|wxLIST_STATE_FOCUSED);


            //选中Item
            //wxListCtrl->SetItemState(item, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);

        }
    }
    */
}
/*
void MissOption::ChangeModifyState()
{
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
*/
void MissOption::OnBtnUnDoSaveThemeClick(wxCommandEvent& event)
{
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(MissGlobal::UE_UPDATETHEME);
    GetEventHandler()->ProcessEvent(send);
}

void MissOption::OnZoomCbtnClick(wxCommandEvent& event)
{
// TODO: Implement OnZoomCbtnClick
    SetZoomState(m_cbtnAllowZoom->GetValue());
    if(!m_cbtnAllowZoom->GetValue())
    {
        m_pConfig->SetZoom(1.0);
        wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
        send.SetInt(MissGlobal::UE_ZOOMCHANGE);
        GetEventHandler()->ProcessEvent(send);
    }
}

void MissOption::OnZoomSldChanged(wxScrollEvent& event)
{
// TODO: Implement OnZoomSldChanged
    m_pConfig->SetZoom(m_sldZoom->GetValue() * 0.01);
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(MissGlobal::UE_ZOOMCHANGE);
    GetEventHandler()->ProcessEvent(send);
}

void MissOption::OnTransSldChanged(wxScrollEvent& event)
{
// TODO: Implement OnTransSldChanged
    m_pConfig->SetOpacity(m_sldOpacity->GetValue());
    wxCommandEvent send(wxEVT_MCUI_EVENT,GetId());
    send.SetInt(MissGlobal::UE_ALPHACHANGE);
    GetEventHandler()->ProcessEvent(send);
}

void MissOption::OnNtpBtnClick(wxCommandEvent& event)
{
// TODO: Implement OnNtpBtnClick
}

/*
void MissOption::OnCancel(wxCommandEvent& event)
{
// TODO: Implement OnCancel
    EndModal(wxID_CANCEL);
}
*/

void MissOption::OnOK(wxCommandEvent& event)
{
// TODO: Implement OnOK
    EndModal(wxID_OK);
}

void MissOption::OnBtnAddTaskClick(wxCommandEvent& event)
{
    MissSetTimer SetTimerDlg(this);
    SetTimerDlg.ShowModal();
}

void MissOption::OnBtnAdditionaClick(wxCommandEvent& event)
{
    m_btnAddTask->PopupMenu( m_mnuAdditional, wxPoint(0,m_btnAddTask->GetSize().GetHeight()));
}
