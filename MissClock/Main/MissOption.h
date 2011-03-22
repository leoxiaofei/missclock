﻿#ifndef __MissOption__
#define __MissOption__

/**
@file
Subclass of MissOptionBase, which is generated by wxFormBuilder.
*/

#include "../Generated/GUIFrame.h"

//// end generated include

class MissConfig;
class MissSkin;

/** Implementing MissOptionBase */
class MissOption : public MissOptionBase
{
	protected:
		// Handlers for MissOptionBase events.
		void OnInitDialog( wxInitDialogEvent& event );
		void OnThemeChoChange( wxCommandEvent& event );
		void OnModifyThemeBtnClick( wxCommandEvent& event );
		void OnZoomCbtnClick( wxCommandEvent& event );
		void OnZoomSldChanged( wxScrollEvent& event );
		void OnTransSldChanged( wxScrollEvent& event );
		void OnNtpBtnClick( wxCommandEvent& event );
		void OnCancel( wxCommandEvent& event );
		void OnOK( wxCommandEvent& event );

		void OnBtnBGPathClick( wxCommandEvent& event );
		void OnCobLocaleSelect( wxCommandEvent& event );
		void OnlstItemDeselect( wxListEvent& event );
		void OnlstItemSelect( wxListEvent& event );
		void OnBtnAddItem( wxCommandEvent& event );
		void OnBtnDeleteItem( wxCommandEvent& event );
		void OnEdtNameKillFocus( wxFocusEvent& event );
		void OnCbtnShowClick( wxCommandEvent& event );
		void OnEdtContentKillFocus( wxFocusEvent& event );
		void OnBtnFont( wxCommandEvent& event );
		void OnBtnColor( wxCommandEvent& event );
		void OnSldAlignScrollThumbRelease( wxScrollEvent& event );
		void OnSpXChange( wxSpinEvent& event );
		void OnSpYChange( wxSpinEvent& event );
	public:
		/** Constructor */
		MissOption( wxWindow* parent );

        void SetDataSrc(shared_ptr<MissConfig>& pConfig, shared_ptr<MissSkin>& pSkin);

    protected:
        wxArrayString GetSkinsName();
        void LoadThemeOption();
        void UpdateEdtAlignText();
        void EnableItemSet(bool bEnable);
    private:
		shared_ptr<MissConfig> m_pConfig;
		shared_ptr<MissSkin> m_pSkin;
		int m_nThemeItem;
	//// end generated class members

};

#endif // __MissOption__