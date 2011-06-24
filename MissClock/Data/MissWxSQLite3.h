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
        void VacuumDB();
        void QuestTaskData(int nType, std::vector<std::pair<int,MissGlobal::TaskData> > &mapData);
        void QusetDayTask(const wxString &strDate, std::vector<MissGlobal::TaskData> &vecData);
        void QusetNextRemind(const wxString &strDate, const wxString &strTime,
                             std::vector<MissGlobal::TaskData> &vecData);
        bool GetTaskDataByID(int nID, MissGlobal::TaskData& data);
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
        static const wxString s_strVacuumDB;
        static const wxString s_strQuestTaskData;
};

#endif // MISSWXSQLITE3_H
