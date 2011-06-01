#include "MissWxSQLite3.h"
#include "wx/wxsqlite3.h"
#include "../Common/MissGlobal.h"

MissWxSQLite3::MissWxSQLite3()
{
    //ctor
    wxSQLite3Database::InitializeSQLite();
    assert(wxSQLite3Database::HasEncryptionSupport());
    m_pDB = shared_ptr<wxSQLite3Database>(InitDB());
}

MissWxSQLite3::~MissWxSQLite3()
{
    //dtor
}

wxSQLite3Database* MissWxSQLite3::InitDB()
{
    wxString strDBName = wxGetCwd() + wxT("/TaskDB.db3");
    wxSQLite3Database* db = new wxSQLite3Database();
    db->Open(strDBName,wxEmptyString);
    if(!db->TableExists(wxT("TaskData")))
    {
        db->ExecuteUpdate(s_strCreateTaskTable);
    }
    return db;
}

void MissWxSQLite3::UpdateTaskData(int nID, const MissGlobal::TaskData& data)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strUpdateTaskData);
    query.Bind(1,data.nDateType);
    query.Bind(2,data.strTaskDate);
    query.Bind(3,data.nRemindType);
    query.Bind(4,data.nTimeType);
    query.Bind(5,data.strTaskTime);
    query.Bind(6,data.nEvery);
    query.Bind(7,data.nTaskType);
    query.Bind(8,data.strTaskContent);
    query.Bind(9,nID);

    query.ExecuteUpdate();
}

void MissWxSQLite3::InsertTaskData(const MissGlobal::TaskData& data)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strInsertTaskData);
    query.Bind(1,data.nDateType);
    query.Bind(2,data.strTaskDate);
    query.Bind(3,data.nRemindType);
    query.Bind(4,data.nTimeType);
    query.Bind(5,data.strTaskTime);
    query.Bind(6,data.nEvery);
    query.Bind(7,data.nTaskType);
    query.Bind(8,data.strTaskContent);

    query.ExecuteUpdate();
}

void MissWxSQLite3::DeleteTaskData(int nID)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strDeleteTaskData);
    query.Bind(1,nID);
    query.ExecuteUpdate();
}

void MissWxSQLite3::QuestTaskData(int nType, std::vector<std::pair<int,MissGlobal::TaskData> >& mapData)
{
    assert(nType >= MissGlobal::QT_REMIND && nType <= MissGlobal::QT_ALL);

    wxSQLite3Statement query;
    wxSQLite3ResultSet result;
    wxString strSql;
    switch(static_cast<MissGlobal::EQuestType>(nType))
    {
    case MissGlobal::QT_REMIND:
        query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE TaskType = 0 AND DateType <> 4 AND (DateType <> 0 OR (DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_MEMORIAL_DAY:
        query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE TaskType = 0 AND DateType = 4"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_BACKLOG:
        query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE TaskType = 0 AND RemindType <> 0 AND (DateType <> 0 OR (DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_TASK:
        query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE TaskType <> 0 AND (DateType <> 0 OR (DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_OVERDUE:
        query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) <= DATETIME('NOW')"));
        result = query.ExecuteQuery();
        break;
    default:
        query = m_pDB->PrepareStatement(s_strQuestTaskData);
        result = query.ExecuteQuery();
        break;
    }

    if(result.IsOk())
    {
        MissGlobal::TaskData data;
        while(result.NextRow())
        {
            data.nDateType      = result.GetInt(wxT("DateType"));
            data.strTaskDate    = result.GetString(wxT("TaskDate"));
            data.nRemindType    = result.GetInt(wxT("RemindType"));
            data.nTimeType      = result.GetInt(wxT("TimeType"));
            data.strTaskTime    = result.GetString(wxT("TaskTime"));
            data.nEvery         = result.GetInt(wxT("Every"));
            data.nTaskType      = result.GetInt(wxT("TaskType"));
            data.strTaskContent = result.GetString(wxT("TaskContent"));
            mapData.push_back(std::make_pair(result.GetInt(wxT("ID")),data));
        }
    }

    result.Finalize();
}

bool MissWxSQLite3::GetTaskDataByID(int nID, MissGlobal::TaskData& data)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strQuestTaskData + wxT(" WHERE ID = $ID"));
    query.Bind(1,nID);
    wxSQLite3ResultSet result = query.ExecuteQuery();
    if(result.IsOk())
    {
        if(!result.Eof())
        {
            data.nDateType      = result.GetInt(wxT("DateType"));
            data.strTaskDate    = result.GetString(wxT("TaskDate"));
            data.nRemindType    = result.GetInt(wxT("RemindType"));
            data.nTimeType      = result.GetInt(wxT("TimeType"));
            data.strTaskTime    = result.GetString(wxT("TaskTime"));
            data.nEvery         = result.GetInt(wxT("Every"));
            data.nTaskType      = result.GetInt(wxT("TaskType"));
            data.strTaskContent = result.GetString(wxT("TaskContent"));
            return true;
        }
    }
    return false;
}

const wxString MissWxSQLite3::s_strCreateTaskTable = wxT(
"CREATE TABLE \"TaskData\" (\
\"ID\"  INTEGER PRIMARY KEY NOT NULL,\
\"DateType\"  INTEGER,\
\"TaskDate\"  TEXT,\
\"RemindType\"  INTEGER,\
\"TimeType\"  INTEGER,\
\"TaskTime\"  TEXT,\
\"Every\"  INTEGER,\
\"TaskType\"  INTEGER,\
\"TaskContent\"  TEXT);"
);

const wxString MissWxSQLite3::s_strInsertTaskData = wxT(
"INSERT INTO TaskData VALUES (\
NULL, \
$DateType, \
$TaskDate, \
$RemindType, \
$TimeType, \
$TaskTime, \
$Every, \
$TaskType, \
$TaskContent);"
);

const wxString MissWxSQLite3::s_strUpdateTaskData = wxT(
"UPDATE TaskData SET \
DateType = $DateType, \
TaskDate = $TaskDate, \
RemindType = $RemindType, \
TimeType = $TimeType, \
TaskTime = $TaskTime, \
Every = $Every, \
TaskType = $TaskType, \
TaskContent = $TaskContent\
WHERE ID = $ID;"
);

const wxString MissWxSQLite3::s_strDeleteTaskData= wxT(
"DELETE FROM TaskData WHERE ID = $ID;"
);

const wxString MissWxSQLite3::s_strQuestTaskData= wxT(
"SELECT * FROM TaskData"
);