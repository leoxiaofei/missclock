#include "MissAbout.h"
#include "Version.h"

MissAbout::MissAbout( wxWindow* parent )
:
MissAboutBase( parent )
{
    //const wxIcon &icon = static_cast<wxTopLevelWindow*>(parent)->GetIcon();
    //m_bitmapSoftIcon->SetBitmap(icon);
    //m_bitmapSoftIcon->SetSizeHints(64,64);
    m_lblSoftName->SetLabel(m_lblSoftName->GetLabel() + wxString::Format(wxT(" 1.1.0.%d"),SVN_REVISION));
    CentreOnScreen();
}

void MissAbout::OnBtnUpdateClick( wxCommandEvent& event )
{
// TODO: Implement OnBtnUpdateClick
}
