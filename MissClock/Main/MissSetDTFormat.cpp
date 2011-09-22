#include "MissSetDTFormat.h"
#include "../Common/MissGlobal.h"

DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCDTF_EVENT);

MissSetDTFormat::MissSetDTFormat(int nType,const wxString& strFormat, wxWindow* parent )
:
MissSetDTFormatBase( parent ),
m_nType(nType)
{
    long lStyle = GetWindowStyle();
    if (lStyle & wxRESIZE_BORDER)
    {
        lStyle &= ~wxRESIZE_BORDER;
    }
    SetWindowStyle(lStyle);

    switch(m_nType)
    {
    case MissGlobal::FT_DATE:
        m_cobDateTime->Append(wxArrayString(3,MissGlobal::s_strSDateFormat));
        break;
    case MissGlobal::FT_TIME:
        m_cobDateTime->Append(wxArrayString(4,MissGlobal::s_strSTimeFormat));
        break;
    }
    m_cobDateTime->Append(wxT("自定义"));
    m_edtDateTime->SetValue(strFormat);
    m_cobDateTime->SetSelection(GetSelectByFormatString(strFormat));
}

void MissSetDTFormat::OnActivate( wxActivateEvent& event )
{
// TODO: Implement OnActivate
    std::cout<<event.GetActive()<<"OnActivate"<<std::endl;
    if(!event.GetActive())
    {
        ///TODO:发送选择星期消息
        wxCommandEvent send(wxEVT_MCDTF_EVENT,GetId());
        send.SetInt(m_nType);
        send.SetString(m_edtDateTime->GetValue());
        GetEventHandler()->ProcessEvent(send);

        delete this;
    }
}

void MissSetDTFormat::OnCobDateTime(wxCommandEvent& event)
{
    std::cout<<event.GetSelection()<<std::endl;
    const wxString *szCDateTime = m_nType == MissGlobal::FT_DATE ?
        MissGlobal::s_strCDateFormat:MissGlobal::s_strCTimeFormat;

    unsigned int nSelected = event.GetSelection();
    if(m_cobDateTime->GetCount() == nSelected + 1)
    {
        m_edtDateTime->SetEditable(true);
        m_edtDateTime->SetFocus();
    }
    else
    {
        m_edtDateTime->SetEditable(false);
        m_edtDateTime->SetValue(szCDateTime[nSelected]);
    }
}

void MissSetDTFormat::OnDateTimeText(wxCommandEvent& event)
{
    char str[100];
    time_t nTime = time(NULL);
    tm *tmNow = localtime(&nTime);
    strftime (str,100, m_edtDateTime->GetValue().mb_str(),tmNow);
    m_edtExample->SetValue( wxString(str,wxConvLocal) );

}

int MissSetDTFormat::GetSelectByFormatString(const wxString& strFormat)
{
    int nRet = -1;
    if(m_nType == MissGlobal::FT_DATE)
    {
        for(int ix = 0; ix != 3; ++ix)
        {
            if(strFormat == MissGlobal::s_strCDateFormat[ix])
            {
                nRet = ix;
            }
        }
    }
    else
    {
        for(int ix = 0; ix != 4; ++ix)
        {
            if(strFormat == MissGlobal::s_strCTimeFormat[ix])
            {
                nRet = ix;
            }
        }
    }
    if(nRet == -1)
    {
        nRet = m_cobDateTime->GetCount() - 1;
    }
    return nRet;
}
