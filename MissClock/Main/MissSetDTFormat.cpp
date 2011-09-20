#include "MissSetDTFormat.h"

MissSetDTFormat::MissSetDTFormat( wxWindow* parent )
:
MissSetDTFormatBase( parent )
{
    long lStyle = GetWindowStyle();
    if (lStyle & wxRESIZE_BORDER)
    {
        lStyle &= ~wxRESIZE_BORDER;
    }
    SetWindowStyle(lStyle);
}

void MissSetDTFormat::OnActivate( wxActivateEvent& event )
{
// TODO: Implement OnActivate
    std::cout<<event.GetActive()<<"OnActivate"<<std::endl;
    if(!event.GetActive())
    {
        ///TODO:发送选择星期消息

    }
}

void MissSetDTFormat::OnCobDateTime(wxCommandEvent& event)
{
}
