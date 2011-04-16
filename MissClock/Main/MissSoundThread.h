#ifndef MissSoundThread_H
#define MissSoundThread_H

#include <wx/thread.h>
//#include "MissClockMain.h"

class MissSoundThread : public wxThread
{
    public:
        MissSoundThread(int hour);
        virtual void *Entry();
        //virtual void OnExit();

    #ifdef __WXDEBUG__
        ~MissSoundThread();
    #endif

    private:
        int m_Hour;
};

#endif // MissSoundThread_H
