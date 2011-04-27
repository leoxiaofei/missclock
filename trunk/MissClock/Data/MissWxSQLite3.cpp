#include "MissWxSQLite3.h"
#include "wx/wxsqlite3.h"

MissWxSQLite3::MissWxSQLite3()
{
    //ctor
    wxSQLite3Database::InitializeSQLite();
    assert(wxSQLite3Database::HasEncryptionSupport());
    m_db = InitDB();
}

MissWxSQLite3::~MissWxSQLite3()
{
    //dtor
}

wxSQLite3Database* MissWxSQLite3::InitDB()
{
    wxString strDBName = wxGetCwd() + wxT("/TaskDB.db3");
    wxSQLite3Database* db = new wxSQLite3Database();
    db->Open(strDBName,wxT("aaaccc"));
    if(!db->TableExists(wxT("TaskData")))
    {
        db->ExecuteUpdate(s_strCreateTaskTable);
    }
    return db;
}

const wxString MissWxSQLite3::s_strCreateTaskTable = wxT(
"CREATE TABLE \"TaskData\" (\
\"ID\"  INTEGER PRIMARY KEY NOT NULL,\
\"DateType\"  INTEGER,\
\"TaskDate\"  TEXT,\
\"TimeType\"  INTEGER,\
\"TaskTime\"  TEXT,\
\"Every\"  INTEGER,\
\"TaskType\"  INTEGER,\
\"TaskContent\"  TEXT\
);");
