#include "MissWxSQLite3.h"
#include "../Common/MissGlobal.h"
#include <wx/wxsqlite3.h>
#include <wx/datetime.h>

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
    query.Bind(8,data.strPlugInGUID);
    query.Bind(9,data.strTaskContent);
    query.Bind(10,nID);

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
    query.Bind(8,data.strPlugInGUID);
    query.Bind(9,data.strTaskContent);

    query.ExecuteUpdate();
}

void MissWxSQLite3::DeleteTaskData(int nID)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strDeleteTaskData);
    query.Bind(1,nID);
    query.ExecuteUpdate();
}

void MissWxSQLite3::VacuumDB()
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(s_strVacuumDB);
    query.ExecuteUpdate();
}

void MissWxSQLite3::QuestTaskData(int nType, std::vector<std::pair<int,MissGlobal::TaskData> >& mapData)
{
    assert(nType >= MissGlobal::QT_REMIND && nType <= MissGlobal::QT_ALL);

    wxSQLite3Statement query;
    wxSQLite3ResultSet result;
    switch(static_cast<MissGlobal::EQuestType>(nType))
    {
    case MissGlobal::QT_REMIND:
        query = m_pDB->PrepareStatement(s_strQuestTaskData +
            wxT(" WHERE TaskType = 0 AND DateType <> 4 AND (DateType <> 0 OR \
                (DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW','localtime')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_MEMORIAL_DAY:
        query = m_pDB->PrepareStatement(s_strQuestTaskData +
            wxT(" WHERE TaskType = 0 AND DateType = 4"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_BACKLOG:
        query = m_pDB->PrepareStatement(s_strQuestTaskData +
            wxT(" WHERE TaskType = 0 AND RemindType <> 0 AND (DateType <> 0 OR \
                (DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW','localtime')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_TASK:
        query = m_pDB->PrepareStatement(s_strQuestTaskData +
            wxT(" WHERE TaskType <> 0 AND (DateType <> 0 OR (DateType = 0 AND \
                DATETIME(TaskDate || ' ' || TaskTime) > DATETIME('NOW','localtime')))"));
        result = query.ExecuteQuery();
        break;
    case MissGlobal::QT_OVERDUE:
        query = m_pDB->PrepareStatement(s_strQuestTaskData +
            wxT(" WHERE DateType = 0 AND DATETIME(TaskDate || ' ' || TaskTime) <= DATETIME('NOW','localtime')"));
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
            GetTaskData(data,result);
            mapData.push_back(std::make_pair(result.GetInt(wxT("ID")),data));
        }
    }
    result.Finalize();
}

void MissWxSQLite3::QusetDayTask(const wxString& strDate, std::vector<MissGlobal::TaskData>& vecData)
{
    wxSQLite3Statement query = m_pDB->PrepareStatement(
        s_strQuestTaskData + wxT(" WHERE TaskDate = $TaskDate AND (RemindType <> 0 OR TimeType <> 0)"));
    query.Bind(1,strDate);
    wxSQLite3ResultSet result = query.ExecuteQuery();
    if(result.IsOk())
    {
        MissGlobal::TaskData data;
        while(result.NextRow())
        {
            GetTaskData(data,result);
            vecData.push_back(data);
        }
    }
    result.Finalize();
}

void MissWxSQLite3::QusetNextRemind(const wxString& strDate, const wxString& strTime,
                                    std::vector<MissGlobal::TaskData>& vecData)
{
    std::wcout<<strTime.c_str()<<std::endl;
    /*
           wxT(" WHERE TimeType = 0 AND TaskTime >= $TaskTime AND (\
           (DateType = 0 AND TaskDate = $TaskDate1) OR \
           (DateType = 1 AND TaskDate <= $TaskDate2 AND MOD(julianday($TaskDate3)-julianday(TaskDate),Every) = 0) OR \
           (DateType = 2 AND Every & POW(2,CAST(strftime('%w',$TaskDate4) AS INTEGER)) <> 0) OR \
           (DateType = 3 AND Every = strftime('%d',$TaskDate5)) OR \
           (DateType = 4 AND strftime('%m-%d',TaskDate) = strftime('%m-%d',$TaskDate6))) \
           ORDER BY TaskTime");
    */
    wxDateTime date;
    date.ParseDate(strDate);
    wxString strSQL = s_strQuestTaskData +
        wxT(" WHERE TimeType = 0 AND TaskTime >= $TaskTime1 AND (\
            (DateType = 0 AND TaskDate = $TaskDate2) OR \
            (DateType = 1 AND TaskDate <= $TaskDate3 AND (julianday($TaskDate4)-julianday(TaskDate)) % Every = 0) OR \
            (DateType = 2 AND (Every & $TaskWeek5) <> 0) OR \
            (DateType = 3 AND Every = $TaskDay6) OR \
            (DateType = 4 AND strftime('%m-%d',TaskDate) = $TaskDate7)) \
            ORDER BY TaskTime");
    wxSQLite3Statement query = m_pDB->PrepareStatement(strSQL);
    query.Bind(1,strTime);
    query.Bind(2,strDate);
    query.Bind(3,strDate);
    query.Bind(4,strDate);
    query.Bind(5,1<<static_cast<int>(date.GetWeekDay()));
    query.Bind(6,date.GetDay());
    query.Bind(7,date.Format(wxT("%m-%d")));

    wxSQLite3ResultSet result = query.ExecuteQuery();
    if(result.IsOk())
    {
        MissGlobal::TaskData data;
        wxString strMinTime;
        while(result.NextRow())
        {
            if(strMinTime.IsEmpty())
            {
                strMinTime = result.GetString(wxT("TaskTime"));
            }
            else if(strMinTime != result.GetString(wxT("TaskTime")))
            {
                break;
            }
            data.nDateType      = result.GetInt(wxT("DateType"));
            data.strTaskDate    = result.GetString(wxT("TaskDate"));
            data.nRemindType    = result.GetInt(wxT("RemindType"));
            data.nTimeType      = result.GetInt(wxT("TimeType"));
            data.strTaskTime    = result.GetString(wxT("TaskTime"));
            data.nEvery         = result.GetInt(wxT("Every"));
            data.nTaskType      = result.GetInt(wxT("TaskType"));
            data.strPlugInGUID  = result.GetString(wxT("PlugInGUID"));
            data.strTaskContent = result.GetString(wxT("TaskContent"));
            vecData.push_back(data);
        }
    }
    result.Finalize();

    ///wxDateTime类影响localtime内部静态变量的值
    time_t ttNow = time(NULL);
    localtime(&ttNow);
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
            GetTaskData(data,result);
            return true;
        }
    }
    return false;
}

bool MissWxSQLite3::GetTaskData(MissGlobal::TaskData& data, wxSQLite3ResultSet& result)
{
    data.nDateType      = result.GetInt(wxT("DateType"));
    data.strTaskDate    = result.GetString(wxT("TaskDate"));
    data.nRemindType    = result.GetInt(wxT("RemindType"));
    data.nTimeType      = result.GetInt(wxT("TimeType"));
    data.strTaskTime    = result.GetString(wxT("TaskTime"));
    data.nEvery         = result.GetInt(wxT("Every"));
    data.nTaskType      = result.GetInt(wxT("TaskType"));
    data.strPlugInGUID  = result.GetString(wxT("PlugInGUID"));
    data.strTaskContent = result.GetString(wxT("TaskContent"));
    return true;
}

void MissWxSQLite3::BeginTransaction()
{
    m_pDB->Begin();
}

void MissWxSQLite3::CommitTransaction()
{
    m_pDB->Commit();
}

void MissWxSQLite3::RollbackTransaction()
{
    m_pDB->Rollback();
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
\"PlugInGUID\"  TEXT,\
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
$PlugInGUID, \
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
PlugInGUID = $PlugInGUID, \
TaskContent = $TaskContent \
WHERE ID = $ID;"
);

const wxString MissWxSQLite3::s_strDeleteTaskData= wxT(
"DELETE FROM TaskData WHERE ID = $ID;"
);

const wxString MissWxSQLite3::s_strVacuumDB= wxT(
"VACUUM;"
);

const wxString MissWxSQLite3::s_strQuestTaskData= wxT(
"SELECT * FROM TaskData"
);

