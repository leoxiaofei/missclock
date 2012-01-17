#ifndef MISSGLOBAL_H
#define MISSGLOBAL_H

class MissTaskPlugBase;
class MissCThemePlugBase;
class wxDynamicLibrary;

namespace MissGlobal
{
    enum EUiEvent{UE_UPDATE, UE_UPDATETHEME, UE_SAVETHEME, UE_ZOOMCHANGE, UE_ALPHACHANGE};
    enum EQuestType{QT_REMIND, QT_MEMORIAL_DAY, QT_BACKLOG, QT_TASK, QT_OVERDUE, QT_ALL};
    enum ETaskType{TT_Text, TT_Program, TT_SHOTDOWN};
    enum EFormatType{FT_DATE,FT_TIME};

    extern const wxString s_strSWeek[];
    extern const wxString s_strSDateFormat[];
    extern const wxString s_strCDateFormat[];
    extern const wxString s_strSTimeFormat[];
    extern const wxString s_strCTimeFormat[];

    struct TaskData
    {
        int      nDateType;
        int      nTimeType;
        int      nRemindType;
        int      nEvery;
        int      nTaskType;
        wxString strPlugInGUID;
        wxString strTaskDate;
        wxString strTaskTime;
        wxString strTaskContent;

        wxString GetTDateDesc() const;
        wxString GetTTimeDesc() const;
        wxString GetTContentDesc() const;
    };

    struct ThemePlug
    {
        wxDynamicLibrary*    pDllHandle;
        MissCThemePlugBase*   pPlugObj;
    };
    extern ThemePlug g_ThemePlug;

    struct TaskPlug
    {
        wxDynamicLibrary*    pDllHandle;
        MissTaskPlugBase*    pPlugObj;
    };
    extern std::vector<TaskPlug> g_vecTaskPlug;
    MissTaskPlugBase* FindPlugByGUID(const wxString& strGUID);
};

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCUI_EVENT, -1)
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCDATA_EVENT, -1)
END_DECLARE_EVENT_TYPES()

#endif // MISSGLOBAL_H
