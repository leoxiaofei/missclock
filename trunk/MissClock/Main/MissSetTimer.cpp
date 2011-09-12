#include "MissSetTimer.h"
//#include <wx/choicebk.h>
#include <wx/toolbar.h>
#include "../Common/MissGlobal.h"
#include "../Common/MissTools.h"
#include "../Data/MissWxSQLite3.h"

MissSetTimer::MissSetTimer( int nWeekDay, wxWindow* parent )
:
MissSetTimerBase( parent ),
m_nWeekDay(nWeekDay),
m_nDataID(-1)
{
    wxToolBarBase* toolbar = m_tbRun->GetToolBar();
    long lStyle = toolbar->GetWindowStyle();
    if (lStyle & wxTB_TEXT)
    {
        lStyle &= ~wxTB_TEXT;
    }
    toolbar->SetWindowStyle(lStyle);

    m_szWeekBox[0] = m_cbtnSun;
    m_szWeekBox[1] = m_cbtnMon;
	m_szWeekBox[2] = m_cbtnTues;
	m_szWeekBox[3] = m_cbtnWed;
	m_szWeekBox[4] = m_cbtnThurs;
	m_szWeekBox[5] = m_cbtnFri;
	m_szWeekBox[6] = m_cbtnSar;
}

void MissSetTimer::OnInitDialog(wxInitDialogEvent& event)
{
    wxDateTime dtTmp = wxDateTime::Now().Add(wxTimeSpan(0,1,0,0));
    m_spHour->SetValue(dtTmp.GetHour());
    m_spMin->SetValue(dtTmp.GetMinute());
}

void MissSetTimer::OnHLWorkDayClick(wxHyperlinkEvent& event)
{
    ///设置工作日
    MissTools::WeekDaysCheckBox::SetWeekDaysCheck(m_szWeekBox,m_nWeekDay);
}

void MissSetTimer::OnRbtnNothingClick(wxCommandEvent& event)
{
    m_cbtnRemindType->SetValue(true);
}

void MissSetTimer::GetTaskData(MissGlobal::TaskData& data)
{
    data.nEvery = 0;
    ///日期类型
    data.nDateType = m_cbookDate->GetSelection();
    switch(data.nDateType)
    {
    case 0:
        data.strTaskDate = m_dpAppoint->GetValue().FormatISODate();
        break;
    case 1:
        data.strTaskDate = m_dpEDay->GetValue().FormatISODate();
        data.nEvery = m_spEDay->GetValue();
        break;
    case 2:
        data.nEvery = MissTools::WeekDaysCheckBox::GetWeekDaysCheck(m_szWeekBox);
        //data.nEvery += m_cbtnSun  ->GetValue() ? 1 : 0;
        //data.nEvery += m_cbtnMon  ->GetValue() ? 10 : 0;
        //data.nEvery += m_cbtnTues ->GetValue() ? 100 : 0;
        //data.nEvery += m_cbtnWed  ->GetValue() ? 1000 : 0;
        //data.nEvery += m_cbtnThurs->GetValue() ? 10000 : 0;
        //data.nEvery += m_cbtnFri  ->GetValue() ? 100000 : 0;
        //data.nEvery += m_cbtnSar  ->GetValue() ? 1000000 : 0;
        break;
    case 3:
        data.nEvery = m_spMonth->GetValue();
        break;
    case 4:
        data.strTaskDate.Printf(wxT("%04d-%02d-%02d"),wxDateTime::Now().GetYear(),m_spYMonth->GetValue(),m_spYDay->GetValue());
        break;
    }

    ///时间类型
    data.nTimeType = m_rbtnAppoint->GetValue()?0:m_rbtnPStart->GetValue()?1:m_rbtnPClose->GetValue()?2:3;
    data.strTaskTime.Printf(wxT("%.2d:%.2d"),m_spHour->GetValue(),m_spMin->GetValue());

    ///是否在当天任务表中列出
    data.nRemindType = m_cbtnRemindType->GetValue();

    ///任务类型
    data.nTaskType = m_tbRun->GetSelection();
    switch(data.nTaskType)
    {
    case 0:   ///文字提醒任务
        data.strTaskContent = m_panTextRemind->m_edtContent->GetValue();
        break;
    case 1:   ///执行程序任务
        data.strTaskContent.Printf(wxT("\"%s\" %s"),m_panProgRemind->m_fpProgram->GetTextCtrlValue().c_str(),
                                   m_panProgRemind->m_edtParameter->GetValue().c_str());
        data.strTaskContent.Trim();
        break;
    }

}

void MissSetTimer::ImportTaskDataToModify(int nDataID, const MissGlobal::TaskData& data)
{
    m_nDataID = nDataID;
    ///日期类型
    m_cbookDate->SetSelection(data.nDateType);
    switch(data.nDateType)
    {
    case 0:
        {
            wxDateTime dtTmp;
            dtTmp.ParseDate(data.strTaskDate);
            m_dpAppoint->SetValue(dtTmp);
        }
        break;
    case 1:
        {
            wxDateTime dtTmp;
            dtTmp.ParseDate(data.strTaskDate);
            m_dpEDay->SetValue(dtTmp);
            m_spEDay->SetValue(data.nEvery);
        }
        break;
    case 2:
        {
            MissTools::WeekDaysCheckBox::SetWeekDaysCheck(m_szWeekBox, data.nEvery);
            /*
            int exist, every = data.nEvery;
            for (int loop = 0; loop != 7 && every != 0; ++loop, every /= 10)
            {
                exist = every % 10;
                if ( exist )
                {
                    switch (loop)
                    {
                    case 0:
                        m_cbtnSun->SetValue(true);
                        break;
                    case 1:
                        m_cbtnMon->SetValue(true);
                        break;
                    case 2:
                        m_cbtnTues->SetValue(true);
                        break;
                    case 3:
                        m_cbtnWed->SetValue(true);
                        break;
                    case 4:
                        m_cbtnThurs->SetValue(true);
                        break;
                    case 5:
                        m_cbtnFri->SetValue(true);
                        break;
                    case 6:
                        m_cbtnSar->SetValue(true);
                        break;
                    }
                }
            }
            */
        }
        break;
    case 3:
        {
             m_spMonth->SetValue(data.nEvery);
        }
        break;
    case 4:
        {
            wxDateTime dtTmp;
            dtTmp.ParseDate(data.strTaskDate);
            m_spYMonth->SetValue(dtTmp.GetMonth());
            m_spYDay->SetValue(dtTmp.GetDay());
        }
        break;
    }

    ///时间类型
    wxDateTime dtTmp;
    dtTmp.ParseTime(data.strTaskTime);
    m_spHour->SetValue(dtTmp.GetHour());
    m_spMin->SetValue(dtTmp.GetMinute());
    switch(data.nTimeType)
    {
    case 0:
        m_rbtnAppoint->SetValue(true);
        break;
    case 1:
        m_rbtnPStart->SetValue(true);
        break;
    case 2:
        m_rbtnPClose->SetValue(true);
        break;
    case 3:
        m_rbtnNothing->SetValue(true);
        break;
    }

    ///是否在当天任务表中列出
    m_cbtnRemindType->SetValue(data.nRemindType);

    ///任务类型
    m_tbRun->SetSelection(data.nTaskType);
    switch(data.nTaskType)
    {
    case 0:
        m_panTextRemind->m_edtContent->SetValue(data.strTaskContent);
        break;
    case 1:
        {
            wxString strAddr,strArgument;
            strAddr = data.strTaskContent;
            bool exist = strAddr.Find(wxT("\" "));
            if( wxNOT_FOUND == exist )
            {
                strAddr = strAddr.Mid(1,strAddr.length()-2);
            }
            else
            {
                strArgument = strAddr.Mid(exist+2);
                strAddr = strAddr.Mid(1,exist-1);
            }
            m_panProgRemind->m_fpProgram->SetPath( strAddr );
            m_panProgRemind->m_edtParameter->SetValue( strArgument );
        }
        break;
    }
}

void MissSetTimer::OnOKButtonClick(wxCommandEvent& event)
{
    MissGlobal::TaskData data;
    GetTaskData(data);
    try
    {
        MissWxSQLite3 sql;
        if(m_nDataID == -1)
        {
            ///新建数据
            sql.InsertTaskData(data);
        }
        else
        {
            ///更新数据
            sql.UpdateTaskData(m_nDataID,data);
        }
    }
    catch(...)
    {

    }
    EndModal(wxID_OK);
}



