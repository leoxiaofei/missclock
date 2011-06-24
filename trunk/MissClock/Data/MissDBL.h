#ifndef MISSDBL_H
#define MISSDBL_H

namespace MissGlobal
{
    struct TaskData;
}

class MissDBL
{
    public:
        MissDBL();
        virtual ~MissDBL();

        virtual void UpdateTaskData(int nID, const MissGlobal::TaskData &data) = 0;
        virtual void InsertTaskData(const MissGlobal::TaskData &data) = 0;
        virtual void DeleteTaskData(int nID) = 0;
        virtual void QuestTaskData(int nType, std::vector<std::pair<int,MissGlobal::TaskData> > &mapData) = 0;
        virtual void VacuumDB() = 0;
    protected:
    private:
};

#endif // MISSDBL_H
