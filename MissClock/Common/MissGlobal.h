#ifndef MISSGLOBAL_H
#define MISSGLOBAL_H

namespace MissGlobal
{
    enum EUiEvent{UE_UPDATE, UE_UPDATETHEME, UE_SAVETHEME, UE_ZOOMCHANGE, UE_ALPHACHANGE};
    enum EQuestType{QT_REMIND, QT_MEMORIAL_DAY, QT_BACKLOG, QT_TASK, QT_OVERDUE, QT_ALL};

    enum ETaskType{TT_Text, TT_Program, TT_SHOTDOWN};
    struct TaskData
    {
        int      nDateType;
        int      nTimeType;
        int      nRemindType;
        int      nEvery;
        int      nTaskType;
        wxString strTaskDate;
        wxString strTaskTime;
        wxString strTaskContent;
    };
    //extern
};

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCUI_EVENT, -1)
END_DECLARE_EVENT_TYPES()

#endif // MISSGLOBAL_H
