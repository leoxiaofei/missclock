///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

MCShutdown::MCShutdown( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_rBoxShutdownChoices[] = { wxT("关机"), wxT("重启"), wxT("注销") };
	int m_rBoxShutdownNChoices = sizeof( m_rBoxShutdownChoices ) / sizeof( wxString );
	m_rBoxShutdown = new wxRadioBox( this, wxID_ANY, wxT("定时"), wxDefaultPosition, wxDefaultSize, m_rBoxShutdownNChoices, m_rBoxShutdownChoices, 1, wxRA_SPECIFY_ROWS );
	m_rBoxShutdown->SetSelection( 0 );
	bSizer1->Add( m_rBoxShutdown, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

MCShutdown::~MCShutdown()
{
}
