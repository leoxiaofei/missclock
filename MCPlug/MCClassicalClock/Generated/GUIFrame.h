///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/listctrl.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MissThemeBase
///////////////////////////////////////////////////////////////////////////////
class MissThemeBase : public wxDialog 
{
	private:
	
	protected:
		wxChoice* m_choSkin;
		wxButton* m_btnModify;
		wxButton* m_btnAdd;
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
		virtual void OnBtnModifyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnAddClick( wxCommandEvent& event ) { event.Skip(); }
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
		
		MissThemeBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("时钟主题设置"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 435,416 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MissThemeBase();
	
};

#endif //__GUIFrame__
