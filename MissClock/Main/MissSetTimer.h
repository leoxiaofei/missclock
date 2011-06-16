﻿#ifndef __MissSetTimer__
#define __MissSetTimer__

/**
@file
Subclass of MissSetTimerBase, which is generated by wxFormBuilder.
*/

#include "../Generated/GUIFrame.h"

//// end generated include

namespace MissGlobal
{
    struct TaskData;
}

/** Implementing MissSetTimerBase */
class MissSetTimer : public MissSetTimerBase
{
	public:
		/** Constructor */
		MissSetTimer( wxWindow* parent );
	//// end generated class members
	public:
	    void ImportTaskDataToModify(const MissGlobal::TaskData& data);
        void GetTaskData(MissGlobal::TaskData& data);

	protected:
	    void OnInitDialog( wxInitDialogEvent& event );
    	void OnHLWorkDayClick( wxHyperlinkEvent& event );
    	void OnRbtnNothingClick( wxCommandEvent& event );

    private:
        wxCheckBox *m_pWeekBox[7];
};

#endif // __MissSetTimer__
