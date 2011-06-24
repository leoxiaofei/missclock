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
	
	m_pMainMenu = new wxMenu();
	m_pmimPin = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("固定位置(&P)") ) , wxEmptyString, wxITEM_CHECK );
	m_pMainMenu->Append( m_pmimPin );
	
	m_pmimShadow = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("有影无形(&h)") ) , wxEmptyString, wxITEM_CHECK );
	m_pMainMenu->Append( m_pmimShadow );
	
	m_pmimTop = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("总在最前(&T)") ) , wxEmptyString, wxITEM_CHECK );
	m_pMainMenu->Append( m_pmimTop );
	
	m_pmimShow = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("显示时钟(&C)") ) , wxEmptyString, wxITEM_CHECK );
	m_pMainMenu->Append( m_pmimShow );
	
	wxMenuItem* m_pmimOption;
	m_pmimOption = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("选项(&O)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimOption );
	
	wxMenuItem* m_pmimRemind;
	m_pmimRemind = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("提醒管理(&R)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimRemind );
	
	wxMenuItem* m_pmimCopyDate;
	m_pmimCopyDate = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("复制日期(&D)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimCopyDate );
	
	wxMenuItem* m_pmimCopyTime;
	m_pmimCopyTime = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("复制时间(&i)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimCopyTime );
	
	wxMenuItem* m_pmimSetTime;
	m_pmimSetTime = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("校时(&S)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimSetTime );
	
	wxMenuItem* m_pmimAbout;
	m_pmimAbout = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("关于(&A)...") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimAbout );
	
	wxMenuItem* m_pmimExit;
	m_pmimExit = new wxMenuItem( m_pMainMenu, wxID_ANY, wxString( wxT("退出(&x)") ) , wxEmptyString, wxITEM_NORMAL );
	m_pMainMenu->Append( m_pmimExit );
	
	
	
	// Connect Events
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIFrame::OnLeftDown ) );
	this->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUIFrame::OnRightUp ) );
	this->Connect( m_pmimPin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimPinSelected ) );
	this->Connect( m_pmimShadow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimShadowSelected ) );
	this->Connect( m_pmimTop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimTopSelected ) );
	this->Connect( m_pmimShow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimShowSelected ) );
	this->Connect( m_pmimOption->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimOptionSelected ) );
	this->Connect( m_pmimRemind->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimRemindSelected ) );
	this->Connect( m_pmimCopyDate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimCopyDateSelected ) );
	this->Connect( m_pmimCopyTime->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimCopyTimeSelected ) );
	this->Connect( m_pmimSetTime->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimSetTimeSelected ) );
	this->Connect( m_pmimAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Connect( m_pmimExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExit ) );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIFrame::OnLeftDown ) );
	this->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUIFrame::OnRightUp ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimPinSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimShadowSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimTopSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimShowSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimOptionSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimRemindSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimCopyDateSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimCopyTimeSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnmimSetTimeSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExit ) );
	
	delete m_pMainMenu; 
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
	
	m_cbtnAudioChimer = new wxCheckBox( m_panSys, wxID_ANY, wxT("整点报时"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnAudioChimer, 0, wxALL, 5 );
	
	m_cbtnPin = new wxCheckBox( m_panSys, wxID_ANY, wxT("固定位置"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnPin, 0, wxALL, 5 );
	
	m_cbtnShadow = new wxCheckBox( m_panSys, wxID_ANY, wxT("有影无形(鼠标穿透)"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnShadow, 0, wxALL, 5 );
	
	m_cbtnTop = new wxCheckBox( m_panSys, wxID_ANY, wxT("总在最前"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnTop, 0, wxALL, 5 );
	
	m_cbtnShowClock = new wxCheckBox( m_panSys, wxID_ANY, wxT("显示时钟"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnShowClock, 0, wxALL, 5 );
	
	sbSizer8->Add( gSizer2, 1, wxEXPAND, 5 );
	
	bSizer17->Add( sbSizer8, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerSync;
	sbSizerSync = new wxStaticBoxSizer( new wxStaticBox( m_panSys, wxID_ANY, wxT("同步") ), wxVERTICAL );
	
	bSizer17->Add( sbSizerSync, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panSys, wxID_ANY, wxT("其他设置") ), wxVERTICAL );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnWeekSet = new wxButton( m_panSys, wxID_ANY, wxT("工作日"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( m_btnWeekSet, 0, wxALL, 5 );
	
	sbSizer12->Add( bSizer36, 1, wxEXPAND, 5 );
	
	bSizer17->Add( sbSizer12, 0, wxEXPAND|wxALL, 5 );
	
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
	m_lsbOption->AddPage( m_panSys, wxT("系统设置"), true );
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
	
	m_listRemind = new wxListCtrl( m_panRemind, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_VRULES );
	bSizer22->Add( m_listRemind, 1, wxALL|wxEXPAND, 5 );
	
	m_panRemind->SetSizer( bSizer22 );
	m_panRemind->Layout();
	bSizer22->Fit( m_panRemind );
	m_nbTimerSetting->AddPage( m_panRemind, wxT("定时提醒"), true );
	m_panMemorialDay = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer221;
	bSizer221 = new wxBoxSizer( wxVERTICAL );
	
	m_listMemorialDay = new wxListCtrl( m_panMemorialDay, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_VRULES );
	bSizer221->Add( m_listMemorialDay, 1, wxALL|wxEXPAND, 5 );
	
	m_panMemorialDay->SetSizer( bSizer221 );
	m_panMemorialDay->Layout();
	bSizer221->Fit( m_panMemorialDay );
	m_nbTimerSetting->AddPage( m_panMemorialDay, wxT("纪念日"), false );
	m_panBacklog = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	m_listBacklog = new wxListCtrl( m_panBacklog, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_VRULES );
	bSizer30->Add( m_listBacklog, 1, wxALL|wxEXPAND, 5 );
	
	m_panBacklog->SetSizer( bSizer30 );
	m_panBacklog->Layout();
	bSizer30->Fit( m_panBacklog );
	m_nbTimerSetting->AddPage( m_panBacklog, wxT("待办事项"), false );
	m_panTask = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer222;
	bSizer222 = new wxBoxSizer( wxVERTICAL );
	
	m_listTask = new wxListCtrl( m_panTask, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_VRULES );
	bSizer222->Add( m_listTask, 1, wxALL|wxEXPAND, 5 );
	
	m_panTask->SetSizer( bSizer222 );
	m_panTask->Layout();
	bSizer222->Fit( m_panTask );
	m_nbTimerSetting->AddPage( m_panTask, wxT("定时程序"), false );
	m_panOverdue = new wxPanel( m_nbTimerSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer223;
	bSizer223 = new wxBoxSizer( wxVERTICAL );
	
	m_listOverdue = new wxListCtrl( m_panOverdue, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_VRULES );
	bSizer223->Add( m_listOverdue, 1, wxALL|wxEXPAND, 5 );
	
	m_panOverdue->SetSizer( bSizer223 );
	m_panOverdue->Layout();
	bSizer223->Fit( m_panOverdue );
	m_nbTimerSetting->AddPage( m_panOverdue, wxT("过期项目"), false );
	
	bSizer20->Add( m_nbTimerSetting, 1, wxEXPAND|wxALL, 0 );
	
	m_panTmr->SetSizer( bSizer20 );
	m_panTmr->Layout();
	bSizer20->Fit( m_panTmr );
	m_lsbOption->AddPage( m_panTmr, wxT("定时设置"), false );
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
	m_lsbOption->Connect( wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED, wxListbookEventHandler( MissOptionBase::OnLsbOptionPageChanged ), NULL, this );
	m_choTheme->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MissOptionBase::OnThemeChoChange ), NULL, this );
	m_btnModifyTheme->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnModifyThemeBtnClick ), NULL, this );
	m_btnUnDoSaveTheme->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnUnDoSaveThemeClick ), NULL, this );
	m_cbtnAllowZoom->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnWeekSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnWeekSetClick ), NULL, this );
	m_btnNTP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_btnAddTask->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddTaskClick ), NULL, this );
	m_btnAdditional->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAdditionaClick ), NULL, this );
	m_btnModifyTask->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnModifyTaskClick ), NULL, this );
	m_btnDeleteTask->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnDeleteTaskClick ), NULL, this );
	m_nbTimerSetting->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MissOptionBase::OnNBTimerSettingChanged ), NULL, this );
	m_listRemind->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listMemorialDay->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listBacklog->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listTask->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listOverdue->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnOK ), NULL, this );
}

MissOptionBase::~MissOptionBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissOptionBase::OnInitDialog ) );
	m_lsbOption->Disconnect( wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED, wxListbookEventHandler( MissOptionBase::OnLsbOptionPageChanged ), NULL, this );
	m_choTheme->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MissOptionBase::OnThemeChoChange ), NULL, this );
	m_btnModifyTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnModifyThemeBtnClick ), NULL, this );
	m_btnUnDoSaveTheme->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnUnDoSaveThemeClick ), NULL, this );
	m_cbtnAllowZoom->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MissOptionBase::OnZoomCbtnClick ), NULL, this );
	m_sldZoom->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnZoomSldChanged ), NULL, this );
	m_sldOpacity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MissOptionBase::OnTransSldChanged ), NULL, this );
	m_btnWeekSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnWeekSetClick ), NULL, this );
	m_btnNTP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnNtpBtnClick ), NULL, this );
	m_btnAddTask->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAddTaskClick ), NULL, this );
	m_btnAdditional->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnAdditionaClick ), NULL, this );
	m_btnModifyTask->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnModifyTaskClick ), NULL, this );
	m_btnDeleteTask->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MissOptionBase::OnBtnDeleteTaskClick ), NULL, this );
	m_nbTimerSetting->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MissOptionBase::OnNBTimerSettingChanged ), NULL, this );
	m_listRemind->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listMemorialDay->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listBacklog->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listTask->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
	m_listOverdue->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MissOptionBase::OnListRemindItemActivated ), NULL, this );
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
	
	m_cbookDate = new wxChoicebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panAppoint = new wxPanel( m_cbookDate, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblAppoint = new wxStaticText( m_panAppoint, wxID_ANY, wxT("指定日期:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblAppoint->Wrap( -1 );
	bSizer28->Add( m_lblAppoint, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dpAppoint = new wxDatePickerCtrl( m_panAppoint, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer28->Add( m_dpAppoint, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panAppoint->SetSizer( bSizer28 );
	m_panAppoint->Layout();
	bSizer28->Fit( m_panAppoint );
	m_cbookDate->AddPage( m_panAppoint, wxT("指定"), true );
	m_panEDay = new wxPanel( m_cbookDate, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer351;
	bSizer351 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblStartDate = new wxStaticText( m_panEDay, wxID_ANY, wxT("开始日期:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblStartDate->Wrap( -1 );
	bSizer351->Add( m_lblStartDate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dpEDay = new wxDatePickerCtrl( m_panEDay, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer351->Add( m_dpEDay, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_lblE = new wxStaticText( m_panEDay, wxID_ANY, wxT("每:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblE->Wrap( -1 );
	bSizer351->Add( m_lblE, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_spEDay = new wxSpinCtrl( m_panEDay, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 1, 99, 1 );
	bSizer351->Add( m_spEDay, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblEDay = new wxStaticText( m_panEDay, wxID_ANY, wxT("天"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblEDay->Wrap( -1 );
	bSizer351->Add( m_lblEDay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panEDay->SetSizer( bSizer351 );
	m_panEDay->Layout();
	bSizer351->Fit( m_panEDay );
	m_cbookDate->AddPage( m_panEDay, wxT("按天"), false );
	m_panWeek = new wxPanel( m_cbookDate, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 5, 0, 10 );
	fgSizer2->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_lblEWeek = new wxStaticText( m_panWeek, wxID_ANY, wxT("选择每:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblEWeek->Wrap( -1 );
	fgSizer2->Add( m_lblEWeek, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnMon = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期一"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnMon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnTues = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期二"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnTues, 0, wxALL, 5 );
	
	m_cbtnWed = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期三"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnWed, 0, wxALL, 5 );
	
	m_cbtnThurs = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期四"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnThurs, 0, wxALL, 5 );
	
	
	fgSizer2->Add( 0, 0, 0, 0, 0 );
	
	m_cbtnFri = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期五"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnFri, 0, wxALL, 5 );
	
	m_cbtnSar = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期六"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnSar, 0, wxALL, 5 );
	
	m_cbtnSun = new wxCheckBox( m_panWeek, wxID_ANY, wxT("星期天"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_cbtnSun, 0, wxALL, 5 );
	
	m_hlWorkDay = new wxHyperlinkCtrl( m_panWeek, wxID_ANY, wxT("工作日"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	
	m_hlWorkDay->SetHoverColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_hlWorkDay->SetNormalColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	m_hlWorkDay->SetVisitedColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	m_hlWorkDay->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer2->Add( m_hlWorkDay, 0, wxALL, 5 );
	
	m_panWeek->SetSizer( fgSizer2 );
	m_panWeek->Layout();
	fgSizer2->Fit( m_panWeek );
	m_cbookDate->AddPage( m_panWeek, wxT("按周"), false );
	m_panMonth = new wxPanel( m_cbookDate, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblEMonth = new wxStaticText( m_panMonth, wxID_ANY, wxT("每月:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblEMonth->Wrap( -1 );
	bSizer30->Add( m_lblEMonth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spMonth = new wxSpinCtrl( m_panMonth, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 1, 31, 1 );
	bSizer30->Add( m_spMonth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_lblMonth = new wxStaticText( m_panMonth, wxID_ANY, wxT("号"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblMonth->Wrap( -1 );
	bSizer30->Add( m_lblMonth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panMonth->SetSizer( bSizer30 );
	m_panMonth->Layout();
	bSizer30->Fit( m_panMonth );
	m_cbookDate->AddPage( m_panMonth, wxT("按月"), false );
	m_panYear = new wxPanel( m_cbookDate, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblYear = new wxStaticText( m_panYear, wxID_ANY, wxT("每年:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblYear->Wrap( -1 );
	bSizer31->Add( m_lblYear, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spYMonth = new wxSpinCtrl( m_panYear, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 1, 12, 1 );
	bSizer31->Add( m_spYMonth, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_lblYMonth = new wxStaticText( m_panYear, wxID_ANY, wxT("月"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblYMonth->Wrap( -1 );
	bSizer31->Add( m_lblYMonth, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spYDay = new wxSpinCtrl( m_panYear, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 1, 31, 1 );
	bSizer31->Add( m_spYDay, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_lblYDay = new wxStaticText( m_panYear, wxID_ANY, wxT("日"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblYDay->Wrap( -1 );
	bSizer31->Add( m_lblYDay, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panYear->SetSizer( bSizer31 );
	m_panYear->Layout();
	bSizer31->Fit( m_panYear );
	m_cbookDate->AddPage( m_panYear, wxT("按年"), false );
	sbSizer10->Add( m_cbookDate, 1, wxEXPAND | wxALL, 5 );
	
	bSizer24->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("时间方式") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 6, 0, 0 );
	fgSizer3->AddGrowableCol( 4 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_rbtnAppoint = new wxRadioButton( this, wxID_ANY, wxT("准确时间:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbtnAppoint->SetValue( true ); 
	fgSizer3->Add( m_rbtnAppoint, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	m_spHour = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer3->Add( m_spHour, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_lblHour = new wxStaticText( this, wxID_ANY, wxT("时"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblHour->Wrap( -1 );
	fgSizer3->Add( m_lblHour, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_spMin = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer3->Add( m_spMin, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_lblMin = new wxStaticText( this, wxID_ANY, wxT("分"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblMin->Wrap( -1 );
	fgSizer3->Add( m_lblMin, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cbtnRemindType = new wxCheckBox( this, wxID_ANY, wxT("在当天任务中列出"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_cbtnRemindType, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizer3->Add( bSizer26, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	sbSizer9->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbtnPStart = new wxRadioButton( this, wxID_ANY, wxT("本程序启动时"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_rbtnPStart, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rbtnPClose = new wxRadioButton( this, wxID_ANY, wxT("本程序退出时"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbtnPClose->SetToolTip( wxT("强制关闭除外") );
	
	bSizer35->Add( m_rbtnPClose, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rbtnNothing = new wxRadioButton( this, wxID_ANY, wxT("不执行提醒"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_rbtnNothing, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer51->Add( bSizer35, 1, wxEXPAND, 5 );
	
	sbSizer9->Add( bSizer51, 1, wxEXPAND, 5 );
	
	bSizer24->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("内容") ), wxVERTICAL );
	
	m_tbRun = new wxToolbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT);
	m_panTextRemind = new TextPanel( m_tbRun );
	m_panProgRemind = new ProgramPanel( m_tbRun );
	wxImageList *m_pIL= new wxImageList(30,30,true,5);
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_pIL->Add(wxBitmap(30,30,32 ));
	m_tbRun->SetImageList(m_pIL);
	m_tbRun->AddPage(m_panTextRemind, wxT("文字提示"),true,0);
	m_tbRun->AddPage(m_panProgRemind , wxT("程序执行"),false,1);
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
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissSetTimerBase::OnInitDialog ) );
	m_hlWorkDay->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MissSetTimerBase::OnHLWorkDayClick ), NULL, this );
	m_rbtnNothing->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MissSetTimerBase::OnRbtnNothingClick ), NULL, this );
}

MissSetTimerBase::~MissSetTimerBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MissSetTimerBase::OnInitDialog ) );
	m_hlWorkDay->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MissSetTimerBase::OnHLWorkDayClick ), NULL, this );
	m_rbtnNothing->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MissSetTimerBase::OnRbtnNothingClick ), NULL, this );
	
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
	bSizer19->Add( m_sdbSizer, 0, wxEXPAND|wxALL, 5 );
	
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

TextPanel::TextPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	m_edtContent = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( m_edtContent, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	bSizer33->Fit( this );
}

TextPanel::~TextPanel()
{
}

ProgramPanel::ProgramPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblProgram = new wxStaticText( this, wxID_ANY, wxT("程序:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblProgram->Wrap( -1 );
	bSizer34->Add( m_lblProgram, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_fpProgram = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("选择一个程序"), wxT("*.exe"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer34->Add( m_fpProgram, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer38->Add( bSizer34, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lblParameter = new wxStaticText( this, wxID_ANY, wxT("参数:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblParameter->Wrap( -1 );
	bSizer40->Add( m_lblParameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_edtParameter = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_edtParameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer38->Add( bSizer40, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer38 );
	this->Layout();
	bSizer38->Fit( this );
}

ProgramPanel::~ProgramPanel()
{
}

MissSetWeekDayBase::MissSetWeekDayBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 4, 0, 0 );
	
	m_cbtnMon = new wxCheckBox( this, wxID_ANY, wxT("星期一"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnMon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnTues = new wxCheckBox( this, wxID_ANY, wxT("星期二"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnTues, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnWed = new wxCheckBox( this, wxID_ANY, wxT("星期三"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnWed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnThurs = new wxCheckBox( this, wxID_ANY, wxT("星期四"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnThurs, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnFri = new wxCheckBox( this, wxID_ANY, wxT("星期五"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnFri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnSar = new wxCheckBox( this, wxID_ANY, wxT("星期六"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnSar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cbtnSun = new wxCheckBox( this, wxID_ANY, wxT("星期天"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_cbtnSun, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	this->SetSizer( gSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( MissSetWeekDayBase::OnActivate ) );
}

MissSetWeekDayBase::~MissSetWeekDayBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( MissSetWeekDayBase::OnActivate ) );
	
}
