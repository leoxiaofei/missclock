///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
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

MissThemeBase::MissThemeBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("皮肤") ), wxHORIZONTAL );
	
	wxArrayString m_choSkinChoices;
	m_choSkin = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choSkinChoices, 0 );
	m_choSkin->SetSelection( 0 );
	sbSizer4->Add( m_choSkin, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnModify = new wxButton( this, wxID_ANY, wxT("修改"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_btnModify, 0, wxALL, 5 );
	
	m_btnAdd = new wxButton( this, wxID_ANY, wxT("新建"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_btnAdd, 0, wxALL, 5 );
	
	bSizer19->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	m_panSkin = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerBasicSet;
	sbSizerBasicSet = new wxStaticBoxSizer( new wxStaticBox( m_panSkin, wxID_ANY, wxT("基本设置") ), wxHORIZONTAL );
	
	m_lblBGPath = new wxStaticText( m_panSkin, wxID_ANY, wxT("背景图片:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblBGPath->Wrap( -1 );
	sbSizerBasicSet->Add( m_lblBGPath, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtBGPath = new wxTextCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sbSizerBasicSet->Add( m_edtBGPath, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnBGPath = new wxButton( m_panSkin, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	sbSizerBasicSet->Add( m_btnBGPath, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblLocale = new wxStaticText( m_panSkin, wxID_ANY, wxT("区域代码:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblLocale->Wrap( -1 );
	sbSizerBasicSet->Add( m_lblLocale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cobLocale = new wxComboBox( m_panSkin, wxID_ANY, wxT("chs"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY );
	m_cobLocale->Append( wxT("chs") );
	m_cobLocale->Append( wxT("cht") );
	m_cobLocale->Append( wxT("ja") );
	m_cobLocale->Append( wxT("us") );
	sbSizerBasicSet->Add( m_cobLocale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer20->Add( sbSizerBasicSet, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerItemView;
	sbSizerItemView = new wxStaticBoxSizer( new wxStaticBox( m_panSkin, wxID_ANY, wxT("项目显示") ), wxVERTICAL );
	
	m_lstItem = new wxListCtrl( m_panSkin, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT );
	sbSizerItemView->Add( m_lstItem, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnAddItem = new wxButton( m_panSkin, wxID_ANY, wxT("添加"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_btnAddItem, 0, wxALL, 5 );
	
	m_btnDeleteItem = new wxButton( m_panSkin, wxID_ANY, wxT("删除"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnDeleteItem->Enable( false );
	
	bSizer18->Add( m_btnDeleteItem, 0, wxALL, 5 );
	
	sbSizerItemView->Add( bSizer18, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer6->Add( sbSizerItemView, 1, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizerItemSet;
	sbSizerItemSet = new wxStaticBoxSizer( new wxStaticBox( m_panSkin, wxID_ANY, wxT("设置") ), wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblName = new wxStaticText( m_panSkin, wxID_ANY, wxT("名称:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblName->Wrap( -1 );
	bSizer14->Add( m_lblName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtName = new wxTextCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_edtName->Enable( false );
	
	bSizer14->Add( m_edtName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblShow = new wxStaticText( m_panSkin, wxID_ANY, wxT("是否显示:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblShow->Wrap( -1 );
	bSizer13->Add( m_lblShow, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnShow = new wxCheckBox( m_panSkin, wxID_ANY, wxT("显示"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbtnShow->Enable( false );
	
	bSizer13->Add( m_cbtnShow, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer13, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblContent = new wxStaticText( m_panSkin, wxID_ANY, wxT("显示内容:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblContent->Wrap( -1 );
	bSizer12->Add( m_lblContent, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtContent = new wxTextCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_edtContent->Enable( false );
	
	bSizer12->Add( m_edtContent, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnFont = new wxButton( m_panSkin, wxID_ANY, wxT("字体"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnFont->Enable( false );
	
	bSizer11->Add( m_btnFont, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnColor = new wxButton( m_panSkin, wxID_ANY, wxT("颜色"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnColor->Enable( false );
	
	bSizer11->Add( m_btnColor, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblAlign = new wxStaticText( m_panSkin, wxID_ANY, wxT("对齐:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblAlign->Wrap( -1 );
	bSizer10->Add( m_lblAlign, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtAlign = new wxTextCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_edtAlign->Enable( false );
	
	bSizer10->Add( m_edtAlign, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sldAlign = new wxSlider( m_panSkin, wxID_ANY, 1, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_sldAlign->Enable( false );
	
	bSizer10->Add( m_sldAlign, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblPos = new wxStaticText( m_panSkin, wxID_ANY, wxT("位置:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblPos->Wrap( -1 );
	bSizer9->Add( m_lblPos, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblX = new wxStaticText( m_panSkin, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblX->Wrap( -1 );
	bSizer9->Add( m_lblX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spX = new wxSpinCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0 );
	m_spX->Enable( false );
	
	bSizer9->Add( m_spX, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblY = new wxStaticText( m_panSkin, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblY->Wrap( -1 );
	bSizer9->Add( m_lblY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spY = new wxSpinCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0 );
	m_spY->Enable( false );
	
	bSizer9->Add( m_spY, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerItemSet->Add( bSizer9, 1, wxEXPAND, 5 );
	
	bSizer6->Add( sbSizerItemSet, 1, wxEXPAND|wxLEFT, 5 );
	
	bSizer20->Add( bSizer6, 1, wxEXPAND|wxALL, 5 );
	
	m_panSkin->SetSizer( bSizer20 );
	m_panSkin->Layout();
	bSizer20->Fit( m_panSkin );
	bSizer19->Add( m_panSkin, 1, wxEXPAND, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizer19->Add( m_sdbSizer, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissThemeBase::OnInitDialog ) );
	m_btnModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnModifyClick ), NULL, this );
	m_btnAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnAddClick ), NULL, this );
	m_btnBGPath->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnBGPathClick ), NULL, this );
	m_cobLocale->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MissThemeBase::OnCobLocaleSelect ), NULL, this );
	m_lstItem->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MissThemeBase::OnlstItemDeselect ), NULL, this );
	m_lstItem->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MissThemeBase::OnlstItemSelect ), NULL, this );
	m_btnAddItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnAddItem ), NULL, this );
	m_btnDeleteItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnDeleteItem ), NULL, this );
	m_edtName->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissThemeBase::OnEdtNameKillFocus ), NULL, this );
	m_cbtnShow->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissThemeBase::OnCbtnShowClick ), NULL, this );
	m_edtContent->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissThemeBase::OnEdtContentKillFocus ), NULL, this );
	m_btnFont->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnFont ), NULL, this );
	m_btnColor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnColor ), NULL, this );
	m_sldAlign->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MissThemeBase::OnSldAlignScrollThumbRelease ), NULL, this );
	m_spX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissThemeBase::OnSpXChange ), NULL, this );
	m_spY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissThemeBase::OnSpYChange ), NULL, this );
}

MissThemeBase::~MissThemeBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissThemeBase::OnInitDialog ) );
	m_btnModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnModifyClick ), NULL, this );
	m_btnAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnAddClick ), NULL, this );
	m_btnBGPath->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnBGPathClick ), NULL, this );
	m_cobLocale->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MissThemeBase::OnCobLocaleSelect ), NULL, this );
	m_lstItem->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MissThemeBase::OnlstItemDeselect ), NULL, this );
	m_lstItem->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MissThemeBase::OnlstItemSelect ), NULL, this );
	m_btnAddItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnAddItem ), NULL, this );
	m_btnDeleteItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnDeleteItem ), NULL, this );
	m_edtName->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissThemeBase::OnEdtNameKillFocus ), NULL, this );
	m_cbtnShow->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissThemeBase::OnCbtnShowClick ), NULL, this );
	m_edtContent->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissThemeBase::OnEdtContentKillFocus ), NULL, this );
	m_btnFont->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnFont ), NULL, this );
	m_btnColor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissThemeBase::OnBtnColor ), NULL, this );
	m_sldAlign->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MissThemeBase::OnSldAlignScrollThumbRelease ), NULL, this );
	m_spX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissThemeBase::OnSpXChange ), NULL, this );
	m_spY->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissThemeBase::OnSpYChange ), NULL, this );
	
}
