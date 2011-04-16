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

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIFrame::OnLeftDown ) );
	this->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUIFrame::OnRightUp ) );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIFrame::OnLeftDown ) );
	this->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUIFrame::OnRightUp ) );
	
}

MissOptionBase::MissOptionBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_lsbOption = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_TOP );
	m_panTheme = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	sbSizerTheme = new wxStaticBoxSizer( new wxStaticBox( m_panTheme, wxID_ANY, wxT("主题") ), wxHORIZONTAL );
	
	m_lblChoiceTheme = new wxStaticText( m_panTheme, wxID_ANY, wxT("选择主题:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblChoiceTheme->Wrap( -1 );
	sbSizerTheme->Add( m_lblChoiceTheme, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxArrayString m_choThemeChoices;
	m_choTheme = new wxChoice( m_panTheme, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choThemeChoices, 0 );
	m_choTheme->SetSelection( 0 );
	sbSizerTheme->Add( m_choTheme, 0, wxALL, 5 );
	
	m_btnModifyTheme = new wxButton( m_panTheme, wxID_ANY, wxT("修改主题"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerTheme->Add( m_btnModifyTheme, 0, wxALL, 5 );
	
	m_btnUnDoSaveTheme = new wxButton( m_panTheme, wxID_ANY, wxT("撤销"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnUnDoSaveTheme->Hide();
	
	sbSizerTheme->Add( m_btnUnDoSaveTheme, 0, wxALL, 5 );
	
	bSizer5->Add( sbSizerTheme, 0, wxALL|wxEXPAND, 5 );
	
	m_nbTheme = new wxNotebook( m_panTheme, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_LEFT );
	m_panSkin = new wxPanel( m_nbTheme, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerBasicSet;
	sbSizerBasicSet = new wxStaticBoxSizer( new wxStaticBox( m_panSkin, wxID_ANY, wxT("基本设置") ), wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblBGPath = new wxStaticText( m_panSkin, wxID_ANY, wxT("背景图片:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblBGPath->Wrap( -1 );
	bSizer7->Add( m_lblBGPath, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtBGPath = new wxTextCtrl( m_panSkin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_edtBGPath->Enable( false );
	
	bSizer7->Add( m_edtBGPath, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnBGPath = new wxButton( m_panSkin, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_btnBGPath->Enable( false );
	
	bSizer7->Add( m_btnBGPath, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblLocale = new wxStaticText( m_panSkin, wxID_ANY, wxT("区域代码:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblLocale->Wrap( -1 );
	bSizer7->Add( m_lblLocale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cobLocale = new wxComboBox( m_panSkin, wxID_ANY, wxT("chs"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY );
	m_cobLocale->Append( wxT("chs") );
	m_cobLocale->Append( wxT("cht") );
	m_cobLocale->Append( wxT("ja") );
	m_cobLocale->Append( wxT("us") );
	m_cobLocale->Enable( false );
	
	bSizer7->Add( m_cobLocale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerBasicSet->Add( bSizer7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	sbSizerBasicSet->Add( bSizer8, 0, wxEXPAND, 5 );
	
	bSizer20->Add( sbSizerBasicSet, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerItemView;
	sbSizerItemView = new wxStaticBoxSizer( new wxStaticBox( m_panSkin, wxID_ANY, wxT("项目显示") ), wxVERTICAL );
	
	m_lstItem = new wxListCtrl( m_panSkin, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT );
	m_lstItem->Enable( false );
	
	sbSizerItemView->Add( m_lstItem, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnAddItem = new wxButton( m_panSkin, wxID_ANY, wxT("添加"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnAddItem->Enable( false );
	
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
	m_nbTheme->AddPage( m_panSkin, wxT("时钟"), false );
	
	bSizer5->Add( m_nbTheme, 1, wxEXPAND | wxALL, 5 );
	
	m_panTheme->SetSizer( bSizer5 );
	m_panTheme->Layout();
	bSizer5->Fit( m_panTheme );
	m_lsbOption->AddPage( m_panTheme, wxT("主题\n设置"), true );
	m_panUI = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerZoom;
	sbSizerZoom = new wxStaticBoxSizer( new wxStaticBox( m_panUI, wxID_ANY, wxT("缩放") ), wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cbtnAllowZoom = new wxCheckBox( m_panUI, wxID_ANY, wxT("允许缩放(不推荐)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbtnAllowZoom->SetValue(true); 
	bSizer15->Add( m_cbtnAllowZoom, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerZoom->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblZoomOut = new wxStaticText( m_panUI, wxID_ANY, wxT("x0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblZoomOut->Wrap( -1 );
	bSizer16->Add( m_lblZoomOut, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sldZoom = new wxSlider( m_panUI, wxID_ANY, 100, 50, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer16->Add( m_sldZoom, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblZoomIn = new wxStaticText( m_panUI, wxID_ANY, wxT("x2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblZoomIn->Wrap( -1 );
	bSizer16->Add( m_lblZoomIn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerZoom->Add( bSizer16, 0, wxALIGN_LEFT|wxEXPAND, 5 );
	
	bSizer2->Add( sbSizerZoom, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerTransparency;
	sbSizerTransparency = new wxStaticBoxSizer( new wxStaticBox( m_panUI, wxID_ANY, wxT("透明度") ), wxHORIZONTAL );
	
	m_lblTransparency = new wxStaticText( m_panUI, wxID_ANY, wxT("80%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblTransparency->Wrap( -1 );
	sbSizerTransparency->Add( m_lblTransparency, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sldOpacity = new wxSlider( m_panUI, wxID_ANY, 255, 50, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizerTransparency->Add( m_sldOpacity, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblOpacity = new wxStaticText( m_panUI, wxID_ANY, wxT("0%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblOpacity->Wrap( -1 );
	sbSizerTransparency->Add( m_lblOpacity, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer2->Add( sbSizerTransparency, 0, wxEXPAND|wxALL, 5 );
	
	m_panUI->SetSizer( bSizer2 );
	m_panUI->Layout();
	bSizer2->Fit( m_panUI );
	m_lsbOption->AddPage( m_panUI, wxT("界面\n设置"), false );
	m_panSys = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panSys, wxID_ANY, wxT("选项") ), wxVERTICAL );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_cbtnAutoRun = new wxCheckBox( m_panSys, wxID_ANY, wxT("开机自动运行"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnAutoRun, 0, wxALL, 5 );
	
	m_cbtnShadow = new wxCheckBox( m_panSys, wxID_ANY, wxT("有影无形"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnShadow, 0, wxALL, 5 );
	
	m_cbtnAudioChimer = new wxCheckBox( m_panSys, wxID_ANY, wxT("整点报时"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnAudioChimer, 0, wxALL, 5 );
	
	m_cbtnShowClock = new wxCheckBox( m_panSys, wxID_ANY, wxT("显示时钟"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnShowClock, 0, wxALL, 5 );
	
	sbSizer8->Add( gSizer2, 1, wxEXPAND, 5 );
	
	bSizer17->Add( sbSizer8, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panSys, wxID_ANY, wxT("校时(NTP)") ), wxHORIZONTAL );
	
	m_lblNTP = new wxStaticText( m_panSys, wxID_ANY, wxT("NTP:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblNTP->Wrap( -1 );
	sbSizer9->Add( m_lblNTP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cobNTP = new wxComboBox( m_panSys, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer9->Add( m_cobNTP, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnNTP = new wxButton( m_panSys, wxID_ANY, wxT("立即校时"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_btnNTP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer17->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	m_panSys->SetSizer( bSizer17 );
	m_panSys->Layout();
	bSizer17->Fit( m_panSys );
	m_lsbOption->AddPage( m_panSys, wxT("系统\n设置"), false );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_lsbOptionListView = m_lsbOption->GetListView();
	long m_lsbOptionFlags = m_lsbOptionListView->GetWindowStyleFlag();
	m_lsbOptionFlags = ( m_lsbOptionFlags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	m_lsbOptionListView->SetWindowStyleFlag( m_lsbOptionFlags );
	#endif
	
	bSizer1->Add( m_lsbOption, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizer1->Add( m_sdbSizer, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissOptionBase::OnInitDialog ) );
	m_choTheme->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MissOptionBase::OnThemeChoChange ), NULL, this );
	m_btnModifyTheme->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnModifyThemeBtnClick ), NULL, this );
	m_btnUnDoSaveTheme->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnUnDoSaveThemeClick ), NULL, this );
	m_btnBGPath->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnBGPathClick ), NULL, this );
	m_cobLocale->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MissOptionBase::OnCobLocaleSelect ), NULL, this );
	m_lstItem->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MissOptionBase::OnlstItemDeselect ), NULL, this );
	m_lstItem->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MissOptionBase::OnlstItemSelect ), NULL, this );
	m_btnAddItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddItem ), NULL, this );
	m_btnDeleteItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnDeleteItem ), NULL, this );
	m_edtName->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissOptionBase::OnEdtNameKillFocus ), NULL, this );
	m_cbtnShow->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnCbtnShowClick ), NULL, this );
	m_edtContent->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissOptionBase::OnEdtContentKillFocus ), NULL, this );
	m_btnFont->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnFont ), NULL, this );
	m_btnColor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnColor ), NULL, this );
	m_sldAlign->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MissOptionBase::OnSldAlignScrollThumbRelease ), NULL, this );
	m_spX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissOptionBase::OnSpXChange ), NULL, this );
	m_spY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissOptionBase::OnSpYChange ), NULL, this );
	m_cbtnAllowZoom->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnNTP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnCancel ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnOK ), NULL, this );
}

MissOptionBase::~MissOptionBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissOptionBase::OnInitDialog ) );
	m_choTheme->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MissOptionBase::OnThemeChoChange ), NULL, this );
	m_btnModifyTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnModifyThemeBtnClick ), NULL, this );
	m_btnUnDoSaveTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnUnDoSaveThemeClick ), NULL, this );
	m_btnBGPath->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnBGPathClick ), NULL, this );
	m_cobLocale->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MissOptionBase::OnCobLocaleSelect ), NULL, this );
	m_lstItem->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( MissOptionBase::OnlstItemDeselect ), NULL, this );
	m_lstItem->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( MissOptionBase::OnlstItemSelect ), NULL, this );
	m_btnAddItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddItem ), NULL, this );
	m_btnDeleteItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnDeleteItem ), NULL, this );
	m_edtName->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissOptionBase::OnEdtNameKillFocus ), NULL, this );
	m_cbtnShow->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnCbtnShowClick ), NULL, this );
	m_edtContent->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MissOptionBase::OnEdtContentKillFocus ), NULL, this );
	m_btnFont->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnFont ), NULL, this );
	m_btnColor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnColor ), NULL, this );
	m_sldAlign->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MissOptionBase::OnSldAlignScrollThumbRelease ), NULL, this );
	m_spX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissOptionBase::OnSpXChange ), NULL, this );
	m_spY->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MissOptionBase::OnSpYChange ), NULL, this );
	m_cbtnAllowZoom->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnNTP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnCancel ), NULL, this );
	m_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnOK ), NULL, this );
	
}

ModifySkinPanelBase::ModifySkinPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
}

ModifySkinPanelBase::~ModifySkinPanelBase()
{
}
