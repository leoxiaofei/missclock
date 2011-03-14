/***************************************************************
 * Name:      MissClockMain.h
 * Purpose:   Defines Application Frame
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-03-13
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifndef MISSCLOCKMAIN_H
#define MISSCLOCKMAIN_H

#include "../Generated/GUIFrame.h"
#include <windef.h>
#include <wingdi.h>

class MissTaskBarIcon;
using std::tr1::shared_ptr;

class MissClockFrame: public GUIFrame
{
    typedef boost::signals2::signal<void (MissClockFrame*)> OnTimeUp;
    public:
        MissClockFrame(wxFrame *frame);
        ~MissClockFrame();

    protected:
        void InitUI();
        void InitEvent();
        void UpdateClock();
        void CheckTast();
        void CheckAudioChimer();

    private:
        void OnTimer(wxTimerEvent& event);

    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnLeftDown( wxMouseEvent& event );

    private:
        shared_ptr<MissTaskBarIcon> m_pTaskBarIcon;
        shared_ptr<wxTimer> m_pMainTimer;
        OnTimeUp sg_SecUp;
        OnTimeUp sg_MinUp;
        HWND m_hWnd;
        BLENDFUNCTION m_Blend;
        SIZE m_SizeWindow;
        struct tm *m_tmNow;
        time_t m_ttNow;
};

#endif // MISSCLOCKMAIN_H
