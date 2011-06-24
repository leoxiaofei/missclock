#include "MissSetWeekDay.h"
#include "../Common/MissTools.h"

DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCWD_EVENT);

MissSetWeekDay::MissSetWeekDay( int nWeekDay, wxWindow* parent )
:
MissSetWeekDayBase( parent )
{
    long lStyle = GetWindowStyle();
    if (lStyle & wxRESIZE_BORDER)
    {
        lStyle &= ~wxRESIZE_BORDER;
    }
    SetWindowStyle(lStyle);

    m_szWeekBox[0] = m_cbtnSun;
    m_szWeekBox[1] = m_cbtnMon;
	m_szWeekBox[2] = m_cbtnTues;
	m_szWeekBox[3] = m_cbtnWed;
	m_szWeekBox[4] = m_cbtnThurs;
	m_szWeekBox[5] = m_cbtnFri;
	m_szWeekBox[6] = m_cbtnSar;

    ///设置初始工作日
    MissTools::WeekDaysCheckBox::SetWeekDaysCheck(m_szWeekBox, nWeekDay);
}

void MissSetWeekDay::OnActivate(wxActivateEvent& event)
{
    std::cout<<event.GetActive()<<"OnActivate"<<std::endl;
    if(!event.GetActive())
    {
        ///TODO:发送选择星期消息
        int nWeekDay = MissTools::WeekDaysCheckBox::GetWeekDaysCheck(m_szWeekBox);
        wxCommandEvent send(wxEVT_MCWD_EVENT,GetId());
        send.SetInt(nWeekDay);
        GetEventHandler()->ProcessEvent(send);

        delete this;
    }
}
