#include "MissOption.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include "../Data/MissConfig.h"
#include "../Common/MissGlobal.h"
#include "MissTheme.h"
#include "MissSetTimer.h"
#include "../Data/MissWxSQLite3.h"
#include "../Common/MissTools.h"
#include "MissSetWeekDay.h"

//wxDEFINE_EVENT(wxEVT_MCUI_EVENT, wxCommandEvent);

MissOption::MissOption(wxWindow* parent)
    :
    MissOptionBase(parent)
{
    m_pLists[MissGlobal::QT_REMIND] = m_listRemind;
    m_pLists[MissGlobal::QT_MEMORIAL_DAY] = m_listMemorialDay;
    m_pLists[MissGlobal::QT_BACKLOG] = m_listBacklog;
    m_pLists[MissGlobal::QT_TASK] = m_listTask;
    m_pLists[MissGlobal::QT_OVERDUE] = m_listOverdue;

    CentreOnScreen();
}

MissOption::~MissOption()
{
    std::cout << "~MissOption()" << std::endl;
}

void MissOption::SetDataSrc(shared_ptr<MissConfig>& pConfig, shared_ptr<MissSkin>& pSkin)
{
    m_pConfig = pConfig;
    m_pSkin = pSkin;

    m_nWeekDay = m_pConfig->GetWeekDay();
}

void MissOption::OnInitDialog(wxInitDialogEvent& event)
{
    m_choTheme->Append(GetSkinsName());
    m_choTheme->SetStringSelection(m_pConfig->GetSkinName());

    m_cbtnAllowZoom->SetValue(m_pConfig->GetZoom() != 1.0);
    m_sldZoom->SetValue(static_cast<int>(m_pConfig->GetZoom() * 100));
    SetZoomState(m_cbtnAllowZoom->GetValue());
    m_sldOpacity->SetValue(m_pConfig->GetOpacity());

    for(int e = MissGlobal::QT_REMIND; e < MissGlobal::QT_ALL; ++e )
    {
        m_pLists[e]->InsertColumn(0,_T("ID"),wxLIST_FORMAT_LEFT,0);
        m_pLists[e]->InsertColumn(1,_T("编号"),wxLIST_FORMAT_LEFT,40);
        m_pLists[e]->InsertColumn(2,_T("提醒日期"),wxLIST_FORMAT_LEFT,72);
        m_pLists[e]->InsertColumn(3,_T("提醒时间"),wxLIST_FORMAT_LEFT,72);
        m_pLists[e]->InsertColumn(4,_T("主题内容"),wxLIST_FORMAT_LEFT,220);
    }

    m_cbtnAudioChimer->SetValue(m_pConfig->GetAudioChimer());
    m_cbtnShowClock->SetValue(m_pConfig->GetAudioChimer());
    m_cbtnShadow->SetValue(m_pConfig->GetShadow());
    m_cbtnTop->SetValue(m_pConfig->GetTop());
    m_cbtnPin->SetValue(m_pConfig->GetPin());
    m_cobNTP->SetValue(m_pConfig->GetNTP());
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
    MissTools::AutoHideWindow HideWin(this);
    MissTheme ThemeDlg(this);
    ThemeDlg.SetDataSrc(m_pSkin);
    if(ThemeDlg.ShowModal() == wxID_OK)
    {
        ///保存主题设置
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
    if(!m_cbtnAllowZoom->GetValue() && m_pConfig->GetZoom() != 1.0)
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
    m_pConfig->SetWeekDay(m_nWeekDay);
    m_pConfig->SetShowClock(m_cbtnShowClock->GetValue());
    m_pConfig->SetAudioChimer(m_cbtnAudioChimer->GetValue());
    m_pConfig->SetShadow(m_cbtnShadow->GetValue());
    m_pConfig->SetTop(m_cbtnTop->GetValue());
    m_pConfig->SetPin(m_cbtnPin->GetValue());
    m_pConfig->SetNTP(m_cobNTP->GetValue());
    m_pConfig->SaveOption();
    EndModal(wxID_OK);
}
/*
void MissOption::OnOptionClose(wxCloseEvent& event)
{
    EndModal(wxID_CANCEL);
}
*/
void MissOption::OnBtnAddTaskClick(wxCommandEvent& event)
{
    MissTools::AutoHideWindow HideWin(this);
    MissSetTimer SetTimerDlg(m_nWeekDay,this);
    if(SetTimerDlg.ShowModal() == wxID_OK)
    {

        ///清空所有列表中的值
        for(int e = MissGlobal::QT_REMIND; e < MissGlobal::QT_ALL; ++e )
        {
            m_pLists[e]->DeleteAllItems();
        }
        ///更新当前列表的值
        int nList = m_nbTimerSetting->GetSelection();
        UpdataTimerSettingList(nList);
    }
}

void MissOption::OnBtnAdditionaClick(wxCommandEvent& event)
{
    m_btnAddTask->PopupMenu( m_mnuAdditional, wxPoint(0,m_btnAddTask->GetSize().GetHeight()));
}

void MissOption::OnBtnDeleteTaskClick(wxCommandEvent& event)
{
    int nList = m_nbTimerSetting->GetSelection();
    long item = -1;
    long nID( -1 );
    std::vector<int> vecDelete;
    while(1)
    {
        item = m_pLists[nList]->GetNextItem(item,
                                     wxLIST_NEXT_ALL,
                                     wxLIST_STATE_SELECTED);
        if ( item == -1 )
            break;
        if(m_pLists[nList]->GetItemText(item).ToLong(&nID))
        {
            vecDelete.push_back(nID);
            //m_pLists[nList]->DeleteItem(item);
        }
    }

    if(!vecDelete.empty())
    {
        try
        {
            MissWxSQLite3 sql;
            for(std::vector<int>::iterator itor = vecDelete.begin(); itor != vecDelete.end(); ++itor)
            {
                sql.DeleteTaskData(*itor);
            }
        }
        catch(...)
        {

        }
    }

    ///从其他列表删除该项（防止其他列表中出现已删除的项）
    wxString strID;
    for(std::vector<int>::iterator itor = vecDelete.begin(); itor != vecDelete.end(); ++itor)
    {
        strID.Printf(wxT("%d"),*itor);
        for(int e = MissGlobal::QT_REMIND; e < MissGlobal::QT_ALL; ++e )
        {
            item = m_pLists[e]->FindItem(-1,strID);
            if(item != -1)
            {
                m_pLists[e]->DeleteItem(item);
            }
        }
    }
}

void MissOption::OnBtnModifyTaskClick(wxCommandEvent& event)
{
    int nList = m_nbTimerSetting->GetSelection();
    if(nList != -1)
    {
        long nID( -1 ), item( -1 );
        item = m_pLists[nList]->GetNextItem(item,
                                     wxLIST_NEXT_ALL,
                                     wxLIST_STATE_SELECTED);
        if ( item != -1 && m_pLists[nList]->GetItemText(item).ToLong(&nID))
        {
            ModifyTaskData(nID);
        }
    }
}

void MissOption::OnListRemindItemActivated(wxListEvent& event)
{
    int nItemIndex = event.GetIndex();
    int nList = m_nbTimerSetting->GetSelection();
    long nID(-1);
    if(nList != -1 && m_pLists[nList]->GetItemText(nItemIndex).ToLong(&nID))
    {
        ModifyTaskData(nID);
    }
}

void MissOption::OnNBTimerSettingChanged(wxNotebookEvent& event)
{
    int nIndex = event.GetSelection();
    std::cout<<nIndex<<std::endl;
    if(nIndex > -1)
    {
        UpdataTimerSettingList(nIndex);
    }
    event.Skip();
}

void MissOption::OnLsbOptionPageChanged(wxListbookEvent& event)
{
    ///切换到“定时设置”选项卡的时候
    if(event.GetSelection() == 2)
    {
        int nIndex = m_nbTimerSetting->GetSelection();
        UpdataTimerSettingList(nIndex);
    }
}

void MissOption::UpdataTimerSettingList(int nType, bool bClear /* = false*/)
{
    assert(nType >= MissGlobal::QT_REMIND && nType <= MissGlobal::QT_ALL);
    ///如果是重新加载，先清空列表
    if(bClear)
    {
        m_pLists[nType]->DeleteAllItems();
    }
    ///如果列表为空，读取数据库加载数据
    if(m_pLists[nType]->GetItemCount() == 0)
    {
        std::vector<std::pair<int,MissGlobal::TaskData> > vecData;
        try
        {
            MissWxSQLite3 sql;
            sql.QuestTaskData(nType,vecData);
        }
        catch(...)
        {
            return;
        }
        for(std::vector<std::pair<int,MissGlobal::TaskData> >::size_type ix = 0;
         ix != vecData.size(); ++ix)
        {
            InsertListData(m_pLists[nType],ix, vecData[ix]);
        }
    }
}

void MissOption::InsertListData(wxListCtrl* list, int nItemIndex,
                                const std::pair<int, MissGlobal::TaskData>& item)
{
    list->InsertItem(nItemIndex, wxEmptyString);
    list->SetItem(nItemIndex,0,wxString::Format(wxT("%d"),item.first));
    list->SetItem(nItemIndex,1,wxString::Format(wxT("%d"),nItemIndex+1));
    list->SetItem(nItemIndex,2,item.second.GetTDateDesc());
    list->SetItem(nItemIndex,3,item.second.GetTTimeDesc());
    list->SetItem(nItemIndex,4,item.second.GetTContentDesc());
}

void MissOption::ModifyTaskData(int nID)
{
    MissGlobal::TaskData data;
    bool bSuccess(false);
    try
    {
        MissWxSQLite3 sql;
        bSuccess = sql.GetTaskDataByID(nID,data);
    }
    catch(...)
    {
        return;
    }

    if(bSuccess)
    {
        MissTools::AutoHideWindow HideWin(this);
        MissSetTimer SetTimerDlg(m_nWeekDay, this);
        SetTimerDlg.ImportTaskDataToModify(nID,data);
        if(SetTimerDlg.ShowModal() == wxID_OK)
        {
            ///保存
        }
    }
}

void MissOption::OnBtnWeekSetClick(wxCommandEvent& event)
{
    MissSetWeekDay *pWeekDaySetting = new MissSetWeekDay(m_nWeekDay, this);
    pWeekDaySetting->Connect(wxEVT_MCWD_EVENT, wxCommandEventHandler(MissOption::OnSetWeekDaysEvent), NULL, this);
    pWeekDaySetting->Move(m_btnWeekSet->GetScreenRect().GetBottomLeft());
    pWeekDaySetting->Show();
}

void MissOption::OnSetWeekDaysEvent(wxCommandEvent& event)
{
    m_nWeekDay = event.GetInt();
    std::cout<<m_nWeekDay<<std::endl;
}

