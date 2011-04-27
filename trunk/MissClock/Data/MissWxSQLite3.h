#ifndef MISSWXSQLITE3_H
#define MISSWXSQLITE3_H

class wxSQLite3Database;

class MissWxSQLite3
{
    public:
        MissWxSQLite3();
        virtual ~MissWxSQLite3();

    protected:
        wxSQLite3Database* InitDB();

    private:
        static const wxString s_strCreateTaskTable;
        wxSQLite3Database *m_db;
};

#endif // MISSWXSQLITE3_H
