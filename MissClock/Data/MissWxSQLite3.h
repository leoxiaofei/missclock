#ifndef MISSWXSQLITE3_H
#define MISSWXSQLITE3_H

#include "MissDBL.h"

class wxSQLite3Database;

//typedef void (*DataFunc)(const MissGlobal::TaskData &data);

class MissWxSQLite3: public MissDBL
{
    public:
        MissWxSQLite3();
        virtual ~MissWxSQLite3();
        void UpdateTaskData(int nID, const MissGlobal::TaskData &data);
        void InsertTaskData(const MissGlobal::TaskData &data);
        void DeleteTaskData(int nID);
        void QuestTaskData(int nType, std::vector<std::pair<int,MissGlobal::TaskData> > &mapData);
        /*
        void SetCallBack(std::binder1st<DataFunc> & func)
        {
            m_Func = func;
        }
        */
    protected:
        wxSQLite3Database* InitDB();

    private:
        //std::binder1st<DataFunc> m_Func;
        shared_ptr<wxSQLite3Database> m_pDB;
        static const wxString s_strCreateTaskTable;
        static const wxString s_strInsertTaskData;
        static const wxString s_strUpdateTaskData;
        static const wxString s_strDeleteTaskData;
        static const wxString s_strQuestTaskData;
};

#endif // MISSWXSQLITE3_H
