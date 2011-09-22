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

namespace MissGlobal
{
    struct TaskData;
}

/** Implementing MissOptionBase */
class MissOption : public MissOptionBase
{
	protected:
		// Handlers for MissOptionBase events.
		void OnInitDialog( wxInitDialogEvent& event );
		void OnThemeChoChange( wxCommandEvent& event );
		void OnModifyThemeBtnClick( wxCommandEvent& event );
        //void OnBtnUnDoSaveThemeClick( wxCommandEvent& event );
		void OnZoomCbtnClick( wxCommandEvent& event );
		void OnZoomSldChanged( wxScrollEvent& event );
		void OnTransSldChanged( wxScrollEvent& event );
		void OnNtpBtnClick( wxCommandEvent& event );
        void OnBtnAddTaskClick( wxCommandEvent& event );
		void OnBtnAdditionaClick( wxCommandEvent& event );
		void OnBtnModifyTaskClick( wxCommandEvent& event );
		void OnBtnDeleteTaskClick( wxCommandEvent& event );
		//void OnCancel( wxCommandEvent& event );
		void OnOK( wxCommandEvent& event );
        void OnNBTimerSettingChanged( wxNotebookEvent& event );
        void OnLsbOptionPageChanged( wxListbookEvent& event );
        void OnListRemindItemActivated( wxListEvent& event );
        void OnBtnWeekSetClick( wxCommandEvent& event );
        void OnBtnDateFormatSetClick( wxCommandEvent& event );
        void OnBtnTimeFormatSetClick( wxCommandEvent& event );
        //void OnOptionClose( wxCloseEvent& event );
        ///自定义消息
        void OnSetWeekDaysEvent(wxCommandEvent& event);
        void OnSetDTFormatEvent(wxCommandEvent& event);

	public:
		/** Constructor */
		MissOption( wxWindow* parent );
		~MissOption();
        //void SetDataSrc(shared_ptr<MissConfig>& pConfig, shared_ptr<MissSkin>& pSkin);

    protected:
        wxArrayString GetSkinsName();
        void SetZoomState(bool bEnable);
        void UpdataTimerSettingList(int nType, bool bClear = false);
        void InsertListData(wxListCtrl* plist, int nItemIndex,
                             const std::pair<int,MissGlobal::TaskData>& item);
        void ModifyTaskData(int nID);
        void UpdateListData();
    private:
		MissConfig* m_pConfig;
		//shared_ptr<MissSkin> m_pSkin;

        wxListCtrl* m_pLists[5];
        int         m_nWeekDay;
        wxString    m_strPDateFormat;
        wxString    m_strPTimeFormat;
	//// end generated class members

};


//wxDECLARE_EVENT(wxEVT_SELECTED_CHANGED, wxCommandEvent)
#endif // __MissOption__