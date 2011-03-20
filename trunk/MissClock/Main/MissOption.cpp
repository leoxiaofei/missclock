#include "MissOption.h"
#include <wx/dir.h>
#include <wx/filename.h>

MissOption::MissOption( wxWindow* parent )
:
MissOptionBase( parent )
{

}

void MissOption::OnInitDialog(wxInitDialogEvent& event)
{
    wxString diraddr = wxT("Skin\\");
    wxDir dir(diraddr);
    if ( !dir.IsOpened() )
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return;
    }
    wxString filename;
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
    while ( cont )
    {
        if(wxFileName::FileExists(diraddr+filename+wxT("\\ClockSkin.xml")))
        {
            m_choSkin->Append(filename);
        }
        cont = dir.GetNext(&filename);
    }
}

void MissOption::OnSkinChoChange( wxCommandEvent& event )
{
// TODO: Implement OnSkinChoChange
}

void MissOption::OnModifySkinBtnClick( wxCommandEvent& event )
{
// TODO: Implement OnModifySkinBtnClick
}

void MissOption::OnZoomCbtnClick( wxCommandEvent& event )
{
// TODO: Implement OnZoomCbtnClick
}

void MissOption::OnZoomSldChanged( wxScrollEvent& event )
{
// TODO: Implement OnZoomSldChanged
}

void MissOption::OnTransSldChanged( wxScrollEvent& event )
{
// TODO: Implement OnTransSldChanged
}

void MissOption::OnNtpBtnClick( wxCommandEvent& event )
{
// TODO: Implement OnNtpBtnClick
}

void MissOption::OnCancel( wxCommandEvent& event )
{
// TODO: Implement OnCancel
}

void MissOption::OnOK( wxCommandEvent& event )
{
// TODO: Implement OnOK
}
