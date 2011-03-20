///////////////////////////////////////////////////////////////////////////
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
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/combobox.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>

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
		wxStaticText* m_lblChoiceSkin;
		wxChoice* m_choSkin;
		wxButton* m_btnModifySkin;
		wxCheckBox* m_cbtnAllowZoom;
		wxStaticText* m_lblZoomOut;
		wxSlider* m_sldZoom;
		wxStaticText* m_lblZoomIn;
		wxStaticText* m_lblTransparency;
		wxSlider* m_sldTransparency;
		wxStaticText* m_lblOpacity;
		wxPanel* m_panSys;
		wxCheckBox* m_cbtnAutoRun;
		wxCheckBox* m_cbtnShadow;
		wxCheckBox* m_cbtnAudioChimer;
		wxCheckBox* m_cbtnShowClock;
		wxStaticText* m_lblNTP;
		wxComboBox* m_cobNTP;
		wxButton* m_btnNTP;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnSkinChoChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifySkinBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomCbtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZoomSldChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnTransSldChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnNtpBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MissOptionBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("选项"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 376,367 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MissOptionBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ModifySkinBase
///////////////////////////////////////////////////////////////////////////////
class ModifySkinBase : public wxDialog 
{
	private:
	
	protected:
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
		wxStdDialogButtonSizer* m_sdbModify;
		wxButton* m_sdbModifyOK;
		wxButton* m_sdbModifyCancel;
	
	public:
		
		ModifySkinBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("修改时钟主题"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 401,409 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ModifySkinBase();
	
};

#endif //__GUIFrame__
