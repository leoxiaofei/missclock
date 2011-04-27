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
	
	m_lsbOption = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_LEFT );
	m_panUI = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	sbSizerTheme = new wxStaticBoxSizer( new wxStaticBox( m_panUI, wxID_ANY, wxT("主题") ), wxHORIZONTAL );
	
	m_lblChoiceTheme = new wxStaticText( m_panUI, wxID_ANY, wxT("选择主题:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblChoiceTheme->Wrap( -1 );
	sbSizerTheme->Add( m_lblChoiceTheme, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxArrayString m_choThemeChoices;
	m_choTheme = new wxChoice( m_panUI, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choThemeChoices, 0 );
	m_choTheme->SetSelection( 0 );
	sbSizerTheme->Add( m_choTheme, 0, wxALL, 5 );
	
	m_btnModifyTheme = new wxButton( m_panUI, wxID_ANY, wxT("修改主题"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerTheme->Add( m_btnModifyTheme, 0, wxALL, 5 );
	
	m_btnUnDoSaveTheme = new wxButton( m_panUI, wxID_ANY, wxT("撤销"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnUnDoSaveTheme->Hide();
	
	sbSizerTheme->Add( m_btnUnDoSaveTheme, 0, wxALL, 5 );
	
	bSizer2->Add( sbSizerTheme, 0, wxALL|wxEXPAND, 5 );
	
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
	m_lsbOption->AddPage( m_panUI, wxT("界面设置"), false );
	m_panSys = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panSys, wxID_ANY, wxT("选项") ), wxVERTICAL );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_cbtnAutoRun = new wxCheckBox( m_panSys, wxID_ANY, wxT("开机自动运行"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnAutoRun, 0, wxALL, 5 );
	
	m_cbtnShadow = new wxCheckBox( m_panSys, wxID_ANY, wxT("有影无形(鼠标穿透)"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	m_cobNTP = new wxComboBox( m_panSys, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer9->Add( m_cobNTP, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnNTP = new wxButton( m_panSys, wxID_ANY, wxT("立即校时"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_btnNTP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer17->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	m_panSys->SetSizer( bSizer17 );
	m_panSys->Layout();
	bSizer17->Fit( m_panSys );
	m_lsbOption->AddPage( m_panSys, wxT("系统设置"), false );
	m_panTmr = new wxPanel( m_lsbOption, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnAddTask = new wxButton( m_panTmr, wxID_ANY, wxT("添加"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_btnAddTask, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_btnAdditional = new wxButton( m_panTmr, wxID_ANY, wxT("↓"), wxDefaultPosition, wxSize( 20,-1 ), 0 );
	m_mnuAdditional = new wxMenu();
	wxMenuItem* m_mnuRemind;
	m_mnuRemind = new wxMenuItem( m_mnuAdditional, wxID_ANY, wxString( wxT("定时提醒") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuAdditional->Append( m_mnuRemind );
	
	wxMenuItem* m_mnuBirthday;
	m_mnuBirthday = new wxMenuItem( m_mnuAdditional, wxID_ANY, wxString( wxT("生日记录") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuAdditional->Append( m_mnuBirthday );
	
	wxMenuItem* m_mnuTodo;
	m_mnuTodo = new wxMenuItem( m_mnuAdditional, wxID_ANY, wxString( wxT("明日待办") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuAdditional->Append( m_mnuTodo );
	
	wxMenuItem* m_mnuShutdown;
	m_mnuShutdown = new wxMenuItem( m_mnuAdditional, wxID_ANY, wxString( wxT("定时关机") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuAdditional->Append( m_mnuShutdown );
	
	
	bSizer21->Add( m_btnAdditional, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_btnModifyTask = new wxButton( m_panTmr, wxID_ANY, wxT("修改"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_btnModifyTask, 0, wxALL, 5 );
	
	m_btnDeleteTask = new wxButton( m_panTmr, wxID_ANY, wxT("删除"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_btnDeleteTask, 0, wxALL, 5 );
	
	bSizer20->Add( bSizer21, 0, wxEXPAND, 5 );
	
	m_nbTimerSetting = new wxNotebook( m_panTmr, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panRemind = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl2 = new wxListCtrl( m_panRemind, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer22->Add( m_listCtrl2, 1, wxALL|wxEXPAND, 5 );
	
	m_panRemind->SetSizer( bSizer22 );
	m_panRemind->Layout();
	bSizer22->Fit( m_panRemind );
	m_nbTimerSetting->AddPage( m_panRemind, wxT("定时提醒"), true );
	m_panMemorialDay = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer221;
	bSizer221 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl21 = new wxListCtrl( m_panMemorialDay, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer221->Add( m_listCtrl21, 1, wxALL|wxEXPAND, 5 );
	
	m_panMemorialDay->SetSizer( bSizer221 );
	m_panMemorialDay->Layout();
	bSizer221->Fit( m_panMemorialDay );
	m_nbTimerSetting->AddPage( m_panMemorialDay, wxT("纪念日"), false );
	m_panBacklog = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl7 = new wxListCtrl( m_panBacklog, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer30->Add( m_listCtrl7, 1, wxALL|wxEXPAND, 5 );
	
	m_panBacklog->SetSizer( bSizer30 );
	m_panBacklog->Layout();
	bSizer30->Fit( m_panBacklog );
	m_nbTimerSetting->AddPage( m_panBacklog, wxT("待办事项"), false );
	m_panTask = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer222;
	bSizer222 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl22 = new wxListCtrl( m_panTask, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer222->Add( m_listCtrl22, 1, wxALL|wxEXPAND, 5 );
	
	m_panTask->SetSizer( bSizer222 );
	m_panTask->Layout();
	bSizer222->Fit( m_panTask );
	m_nbTimerSetting->AddPage( m_panTask, wxT("计划任务"), false );
	m_panOverdue = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer223;
	bSizer223 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl23 = new wxListCtrl( m_panOverdue, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	bSizer223->Add( m_listCtrl23, 1, wxALL|wxEXPAND, 5 );
	
	m_panOverdue->SetSizer( bSizer223 );
	m_panOverdue->Layout();
	bSizer223->Fit( m_panOverdue );
	m_nbTimerSetting->AddPage( m_panOverdue, wxT("过期项目"), false );
	
	bSizer20->Add( m_nbTimerSetting, 1, wxEXPAND | wxALL, 5 );
	
	m_panTmr->SetSizer( bSizer20 );
	m_panTmr->Layout();
	bSizer20->Fit( m_panTmr );
	m_lsbOption->AddPage( m_panTmr, wxT("定时设置"), true );
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
	m_cbtnAllowZoom->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnNTP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_btnAddTask->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddTaskClick ), NULL, this );
	m_btnAdditional->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAdditionaClick ), NULL, this );
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnClose ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnOK ), NULL, this );
}

MissOptionBase::~MissOptionBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissOptionBase::OnInitDialog ) );
	m_choTheme->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MissOptionBase::OnThemeChoChange ), NULL, this );
	m_btnModifyTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnModifyThemeBtnClick ), NULL, this );
	m_btnUnDoSaveTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnUnDoSaveThemeClick ), NULL, this );
	m_cbtnAllowZoom->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnNTP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_btnAddTask->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddTaskClick ), NULL, this );
	m_btnAdditional->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAdditionaClick ), NULL, this );
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnClose ), NULL, this );
	m_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnOK ), NULL, this );
	
	delete m_mnuAdditional; 
}

MissSetTimerBase::MissSetTimerBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("日期方式") ), wxVERTICAL );
	
	m_choicebook2 = new wxChoicebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panel13 = new wxPanel( m_choicebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( m_panel13, wxID_ANY, wxT("指定日期:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer28->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker1 = new wxDatePickerCtrl( m_panel13, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer28->Add( m_datePicker1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel13->SetSizer( bSizer28 );
	m_panel13->Layout();
	bSizer28->Fit( m_panel13 );
	m_choicebook2->AddPage( m_panel13, wxT("指定"), false );
	m_panel14 = new wxPanel( m_choicebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_choicebook2->AddPage( m_panel14, wxT("按天"), false );
	m_panel15 = new wxPanel( m_choicebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 5, 0, 10 );
	fgSizer2->SetFlexibleDirection( wxVERTICAL );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( m_panel15, wxID_ANY, wxT("选择每:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer2->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBox8 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期一"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBox9 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期二"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox9, 0, wxALL, 5 );
	
	m_checkBox10 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期三"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox10, 0, wxALL, 5 );
	
	m_checkBox11 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期四"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox11, 0, wxALL, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox12 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期五"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox12, 0, wxALL, 5 );
	
	m_checkBox13 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期六"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox13, 0, wxALL, 5 );
	
	m_checkBox14 = new wxCheckBox( m_panel15, wxID_ANY, wxT("星期天"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBox14, 0, wxALL, 5 );
	
	m_panel15->SetSizer( fgSizer2 );
	m_panel15->Layout();
	fgSizer2->Fit( m_panel15 );
	m_choicebook2->AddPage( m_panel15, wxT("按星期"), true );
	m_panel17 = new wxPanel( m_choicebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( m_panel17, wxID_ANY, wxT("每月:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer30->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrl7 = new wxSpinCtrl( m_panel17, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer30->Add( m_spinCtrl7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText23 = new wxStaticText( m_panel17, wxID_ANY, wxT("号"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer30->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel17->SetSizer( bSizer30 );
	m_panel17->Layout();
	bSizer30->Fit( m_panel17 );
	m_choicebook2->AddPage( m_panel17, wxT("按月"), false );
	m_panel18 = new wxPanel( m_choicebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( m_panel18, wxID_ANY, wxT("每年:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer31->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker2 = new wxDatePickerCtrl( m_panel18, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_SPIN );
	bSizer31->Add( m_datePicker2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel18->SetSizer( bSizer31 );
	m_panel18->Layout();
	bSizer31->Fit( m_panel18 );
	m_choicebook2->AddPage( m_panel18, wxT("按年"), false );
	sbSizer10->Add( m_choicebook2, 1, wxEXPAND | wxALL, 5 );
	
	bSizer24->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("时间方式") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_radioBtn5 = new wxRadioButton( this, wxID_ANY, wxT("准确时间:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_radioBtn5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_spinCtrl3 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer25->Add( m_spinCtrl3, 1, wxALL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("时"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer25->Add( m_staticText17, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_spinCtrl4 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer25->Add( m_spinCtrl4, 1, wxALL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("分"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer25->Add( m_staticText18, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	fgSizer1->Add( bSizer25, 1, wxEXPAND, 5 );
	
	m_radioBtn6 = new wxRadioButton( this, wxID_ANY, wxT("当前时间之后:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_radioBtn6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_spinCtrl6 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer26->Add( m_spinCtrl6, 0, wxALL, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("分"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer26->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer26, 1, wxEXPAND, 5 );
	
	m_radioBtn7 = new wxRadioButton( this, wxID_ANY, wxT("不弹出提醒:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_radioBtn7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer27->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox7 = new wxCheckBox( this, wxID_ANY, wxT("在当天计划任务中列出"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_checkBox7, 0, wxALL, 5 );
	
	fgSizer1->Add( bSizer27, 1, wxEXPAND, 5 );
	
	sbSizer9->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	bSizer24->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("内容") ), wxVERTICAL );
	
	m_tbRun = new wxToolbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT);
	wxImageList *m_pIL= new wxImageList(30,30,true,5);
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_tbRun->SetImageList(m_pIL);
	MyPanel1 *m_panA = new MyPanel1( m_tbRun );
	MyPanel2 *m_panB = new MyPanel2( m_tbRun );
	m_tbRun->AddPage(m_panA, wxT("测试1"),true,0);
	m_tbRun->AddPage(m_panB, wxT("测试2"),false,1);
	
	sbSizer11->Add( m_tbRun, 1, wxALL|wxEXPAND, 5 );
	
	bSizer24->Add( sbSizer11, 1, wxEXPAND|wxALL, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	bSizer24->Add( m_sdbSizer3, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer24 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MissSetTimerBase::~MissSetTimerBase()
{
}

MissThemeBase::MissThemeBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	m_nbTheme = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	m_panSkin = new wxPanel( m_nbTheme, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	m_nbTheme->AddPage( m_panSkin, wxT("时钟"), false );
	
	bSizer19->Add( m_nbTheme, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizer19->Add( m_sdbSizer, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissThemeBase::OnInitDialog ) );
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

MissFrameBase::MissFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_TRANSIENT );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_pTitle = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,20 ), wxTAB_TRAVERSAL );
	bSizer18->Add( m_pTitle, 0, wxALL|wxEXPAND, 0 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0|wxALWAYS_SHOW_SB|wxTRANSPARENT_WINDOW );
	m_staticText18->Wrap( -1 );
	m_staticText18->SetExtraStyle( wxWS_EX_TRANSIENT );
	
	bSizer18->Add( m_staticText18, 0, wxALL, 5 );
	
	this->SetSizer( bSizer18 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MissFrameBase::OnEraseBackground ) );
	m_pTitle->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MissFrameBase::OnPTitleLeftDown ), NULL, this );
	m_pTitle->Connect( wxEVT_PAINT, wxPaintEventHandler( MissFrameBase::OnPTitleOnPaint ), NULL, this );
}

MissFrameBase::~MissFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MissFrameBase::OnEraseBackground ) );
	m_pTitle->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MissFrameBase::OnPTitleLeftDown ), NULL, this );
	m_pTitle->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MissFrameBase::OnPTitleOnPaint ), NULL, this );
	
}

MyPanel1::MyPanel1( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( m_textCtrl6, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
}

MyPanel1::~MyPanel1()
{
}

MyPanel2::MyPanel2( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer34->Add( m_staticText25, 0, wxALL, 5 );
	
	m_filePicker1 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer34->Add( m_filePicker1, 0, wxALL, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
}

MyPanel2::~MyPanel2()
{
}
