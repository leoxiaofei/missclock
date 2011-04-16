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
class MissSkin;
class MissConfig;

class MissClockFrame: public GUIFrame
{
    //typedef boost::signals2::signal<void (MissClockFrame*)> OnTimeUp;
    typedef void (MissClockFrame::*FrameFunc)(void) ;
    typedef std::vector<FrameFunc> Slots;
    public:
        MissClockFrame(wxFrame *frame);
        ~MissClockFrame();

    protected:
        void InitUI();
        void InitEvent();
        void InitMenu();
        void UpdateSize();
        void UpdateAlpha();
        void UpdateTheme();
        void UpdateClock();
        void CheckTask();
        void CheckAudioChimer();
        void OnMinUp();
        void ConnectSlot(Slots& slots, FrameFunc func);
        void DisConnectSlot(Slots& slots, FrameFunc func);

    private:
        void OnTimer(wxTimerEvent& event);
        void OnTaskBarIconLeftUP(wxEvent& event);
        void OnmimTopSelected(wxCommandEvent& event);
        void OnmimOptionSelected(wxCommandEvent& event);
        void OnmimShowSelected(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOptionUiEvent(wxCommandEvent& event);

    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnLeftDown( wxMouseEvent& event );
        virtual void OnRightUp( wxMouseEvent& event );

    private:
        shared_ptr<MissTaskBarIcon> m_pTaskBarIcon;
        shared_ptr<wxTimer> m_pMainTimer;
        shared_ptr<MissSkin> m_pSkin;
        shared_ptr<MissConfig> m_pConfig;
        Slots sg_SecUp;
        Slots sg_MinUp;
        HWND m_hWnd;
        BLENDFUNCTION m_Blend;
        SIZE m_SizeWindow;
        struct tm *m_tmNow;
        time_t m_ttNow;
        wxBitmap m_bpUI;
        unsigned int *m_pBitmap;
        int m_nPixCount;

    private:
        //菜单
        shared_ptr<wxMenu> m_pMainMenu;
        wxMenuItem* m_pmimAbout;
        wxMenuItem* m_pmimCopyDate;
        wxMenuItem* m_pmimSetTime;
        wxMenuItem* m_pmimRemind;
        wxMenuItem* m_pmimExit;
        wxMenuItem* m_pmimTop;
        wxMenuItem* m_pmimShow;
        wxMenuItem* m_pmimCopyTime;
        wxMenuItem* m_pmimPin;
        wxMenuItem* m_pmimShadow;
        wxMenuItem* m_pmimOption;
        //

        static const long ID_TIMER_MAIN;
        static const long ID_MENUITEM_PIN;
        static const long ID_MENUITEM_SHADOW;
        static const long ID_MENUITEM_TOP;
        static const long ID_MENUITEM_SHOW;
        static const long ID_MENUITEM_OPTION;
        static const long ID_MENUITEM_REMIND;
        static const long ID_MENUITEM_COPYDATE;
        static const long ID_MENUITEM_COPYTIME;
        static const long ID_MENUITEM_SETTIME;
        static const long ID_MENUITEM_ABOUT;
        static const long ID_MENUITEM_EXIT;
};

#endif // MISSCLOCKMAIN_H
