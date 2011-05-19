﻿///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/combobox.h>
#include <wx/menu.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/listbook.h>
#include <wx/dialog.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/spinctrl.h>
#include <wx/hyperlink.h>
#include <wx/choicebk.h>
#include <wx/radiobut.h>
#include <wx/toolbook.h>
class TextPanel;
class ProgramPanel;
#include <wx/textctrl.h>
#include <wx/filepicker.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnRightUp( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MissClock"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 481,466 ), long style = wxFRAME_TOOL_WINDOW|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MissOptionBase
///////////////////////////////////////////////////////////////////////////////
class MissOptionBase : public wxDialog 
{
	private:
	
	protected:
		wxListbook* m_lsbOption;
		wxPanel* m_panUI;
		wxStaticBoxSizer* sbSizerTheme;
		wxStaticText* m_lblChoiceTheme;
		wxChoice* m_choTheme;
		wxButton* m_btnModifyTheme;
		wxButton* m_btnUnDoSaveTheme;
		wxCheckBox* m_cbtnAllowZoom;
		wxStaticText* m_lblZoomOut;
		wxSlider* m_sldZoom;
		wxStaticText* m_lblZoomIn;
		wxStaticText* m_lblTransparency;
		wxSlider* m_sldOpacity;
		wxStaticText* m_lblOpacity;
		wxPanel* m_panSys;
		wxCheckBox* m_cbtnAutoRun;
		wxCheckBox* m_cbtnShadow;
		wxCheckBox* m_cbtnAudioChimer;
		wxCheckBox* m_cbtnShowClock;
		wxStaticText* m_lblNTP;
		wxComboBox* m_cobNTP;
		wxButton* m_btnNTP;
		wxPanel* m_panTmr;
		wxButton* m_btnAddTask;
		wxButton* m_btnAdditional;
		wxMenu* m_mnuAdditional;
		wxButton* m_btnModifyTask;
		wxButton* m_btnDeleteTask;
		wxNotebook* m_nbTimerSetting;
		wxPanel* m_panRemind;
		wxListCtrl* m_listRemind;
		wxPanel* m_panMemorialDay;
		wxListCtrl* m_listMemorialDay;
		wxPanel* m_panBacklog;
		wxListCtrl* m_listBacklog;
		wxPanel* m_panTask;
		wxListCtrl* m_listTask;
		wxPanel* m_panOverdue;
		wxListCtrl* m_listOverdue;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnThemeChoChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyThemeBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnUnDoSaveThemeClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomCbtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomSldChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnTransSldChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnNtpBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnAddTaskClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnAdditionaClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnModifyTaskClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnDeleteTaskClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNPTimerSettingChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MissOptionBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("选项"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 435,419 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MissOptionBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MissSetTimerBase
///////////////////////////////////////////////////////////////////////////////
class MissSetTimerBase : public wxDialog 
{
	private:
	
	protected:
		wxChoicebook* m_cbookDate;
		wxPanel* m_panAppoint;
		wxStaticText* m_lblAppoint;
		wxDatePickerCtrl* m_dpAppoint;
		wxPanel* m_panEDay;
		wxStaticText* m_lblStartDate;
		wxDatePickerCtrl* m_dpEDay;
		wxStaticText* m_lblE;
		wxSpinCtrl* m_spEDay;
		wxStaticText* m_lblEDay;
		wxPanel* m_panWeek;
		wxStaticText* m_lblEWeek;
		wxCheckBox* m_cbtnMon;
		wxCheckBox* m_cbtnTues;
		wxCheckBox* m_cbtnWed;
		wxCheckBox* m_cbtnThurs;
		
		wxCheckBox* m_cbtnFri;
		wxCheckBox* m_cbtnSar;
		wxCheckBox* m_cbtnSun;
		wxHyperlinkCtrl* m_hlWorkDay;
		wxPanel* m_panMonth;
		wxStaticText* m_lblEMonth;
		wxSpinCtrl* m_spMonth;
		wxStaticText* m_lblMonth;
		wxPanel* m_panYear;
		wxStaticText* m_lblYear;
		wxSpinCtrl* m_spYMonth;
		wxStaticText* m_lblYMonth;
		wxSpinCtrl* m_spYDay;
		wxStaticText* m_lblYDay;
		wxRadioButton* m_rbtnAppoint;
		wxSpinCtrl* m_spHour;
		wxStaticText* m_lblHour;
		wxSpinCtrl* m_spMin;
		wxStaticText* m_lblMin;
		wxCheckBox* m_cbtnRemindType;
		
		wxRadioButton* m_rbtnPStart;
		wxRadioButton* m_rbtnPClose;
		wxRadioButton* m_rbtnNothing;
		wxToolbook* m_tbRun;
		TextPanel* m_panTextRemind;
		ProgramPanel* m_panProgRemind;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnHLWorkDayClick( wxHyperlinkEvent& event ) { event.Skip(); }
		virtual void OnRbtnNothingClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MissSetTimerBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("定时"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 388,406 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MissSetTimerBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MissThemeBase
///////////////////////////////////////////////////////////////////////////////
class MissThemeBase : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_nbTheme;
		wxPanel* m_panSkin;
		wxStaticText* m_lblBGPath;
		wxTextCtrl* m_edtBGPath;
		wxButton* m_btnBGPath;
		wxStaticText* m_lblLocale;
		wxComboBox* m_cobLocale;
		wxListCtrl* m_lstItem;
		wxButton* m_btnAddItem;
		wxButton* m_btnDeleteItem;
		wxStaticText* m_lblName;
		wxTextCtrl* m_edtName;
		wxStaticText* m_lblShow;
		wxCheckBox* m_cbtnShow;
		wxStaticText* m_lblContent;
		wxTextCtrl* m_edtContent;
		wxButton* m_btnFont;
		wxButton* m_btnColor;
		wxStaticText* m_lblAlign;
		wxTextCtrl* m_edtAlign;
		wxSlider* m_sldAlign;
		wxStaticText* m_lblPos;
		wxStaticText* m_lblX;
		wxSpinCtrl* m_spX;
		wxStaticText* m_lblY;
		wxSpinCtrl* m_spY;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnBtnBGPathClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCobLocaleSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnlstItemDeselect( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstItemSelect( wxListEvent& event ) { event.Skip(); }
		virtual void OnBtnAddItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnDeleteItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEdtNameKillFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCbtnShowClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEdtContentKillFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnBtnFont( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSldAlignScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnSpXChange( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnSpYChange( wxSpinEvent& event ) { event.Skip(); }
		
	
	public:
		
		MissThemeBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("修改主题"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 435,416 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MissThemeBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MissFrameBase
///////////////////////////////////////////////////////////////////////////////
class MissFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_pTitle;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnEraseBackground( wxEraseEvent& event ) { event.Skip(); }
		virtual void OnPTitleLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPTitleOnPaint( wxPaintEvent& event ) { event.Skip(); }
		
	
	public:
		
		MissFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 253,176 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL|wxTRANSPARENT_WINDOW );
		~MissFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TextPanel
///////////////////////////////////////////////////////////////////////////////
class TextPanel : public wxPanel 
{
	private:
	
	protected:
	
	public:
		wxTextCtrl* m_edtContent;
		
		TextPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~TextPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ProgramPanel
///////////////////////////////////////////////////////////////////////////////
class ProgramPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_lblProgram;
		wxStaticText* m_lblParameter;
	
	public:
		wxFilePickerCtrl* m_fpProgram;
		wxTextCtrl* m_edtParameter;
		
		ProgramPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~ProgramPanel();
	
};

#endif //__GUIFrame__