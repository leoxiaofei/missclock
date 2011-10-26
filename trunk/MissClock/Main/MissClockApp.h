/***************************************************************
 * Name:      MissClockApp.h
 * Purpose:   Defines Application Class
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-03-13
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifndef MISSCLOCKAPP_H
#define MISSCLOCKAPP_H

#include <wx/app.h>

class MissClockFrame;

class MissClockApp : public wxApp
{
    public:
        virtual bool OnInit();
        MissClockFrame* GetFrame() { return m_frame; };
    private:
        MissClockFrame* m_frame;
};

DECLARE_APP(MissClockApp)

#endif // MISSCLOCKAPP_H
