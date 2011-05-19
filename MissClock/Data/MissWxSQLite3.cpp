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
    db->Open(strDBName);
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
\"TaskContent\"  TEXT\
);");

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
$TaskContent);");

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
