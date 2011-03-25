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
        void OnBtnUnDoSaveThemeClick( wxCommandEvent& event );
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

        enum EUiEvent{UE_UPDATE, UE_CHANGETHEME, UE_SAVETHEME, UE_RELOADTHEME};

    protected:
        wxArrayString GetSkinsName();
        void LoadThemeOption();
        void UpdateEdtAlignText();
        void EnableItemSet(bool bEnable);
        void SendUpdateEvent();

    private:
		shared_ptr<MissConfig> m_pConfig;
		shared_ptr<MissSkin> m_pSkin;
		int m_nThemeItem;
		bool m_bThemeModify;
	//// end generated class members

};

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCUI_EVENT, -1)
END_DECLARE_EVENT_TYPES()
//wxDECLARE_EVENT(wxEVT_SELECTED_CHANGED, wxCommandEvent)
#endif // __MissOption__
