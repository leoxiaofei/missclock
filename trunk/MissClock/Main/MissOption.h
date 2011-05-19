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
        void OnBtnAddTaskClick( wxCommandEvent& event );
		void OnBtnAdditionaClick( wxCommandEvent& event );
		//void OnCancel( wxCommandEvent& event );
		void OnOK( wxCommandEvent& event );
        void OnNPTimerSettingChanged( wxNotebookEvent& event );

	public:
		/** Constructor */
		MissOption( wxWindow* parent );
        void SetDataSrc(shared_ptr<MissConfig>& pConfig, shared_ptr<MissSkin>& pSkin);



    protected:
        wxArrayString GetSkinsName();
        void SetZoomState(bool bEnable);
        //void ChangeModifyState();

    private:
		shared_ptr<MissConfig> m_pConfig;
		shared_ptr<MissSkin> m_pSkin;

	//// end generated class members

};


//wxDECLARE_EVENT(wxEVT_SELECTED_CHANGED, wxCommandEvent)
#endif // __MissOption__