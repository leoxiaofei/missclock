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


class MissTaskBarIcon;
//class MissSkin;
//class MissRemindSkin;
class MissConfig;
class MissOption;

namespace MissGlobal
{
    struct TaskData;
}
namespace MissDDE
{
    class MissServer;
    class MissConnection;
}

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
        void InitThemePlugin();
        bool LoadThemePlugin(const wxString& strPath);
        void InitTaskPlugin();
        void LoadTaskPlugin(const wxString& strPath);
        void InitDDE();
        void UpdateMenu();
        void UpdateSize();
        void UpdateAlpha();
        void UpdateTheme();
        void UpdateClock();
        void CheckTask();
        void LoadTask(int nNextMin = 1);
        void LoadDayTask();
        void CheckAudioChimer();
        void OnMinUp();
        void ConnectSlot(Slots& slots, FrameFunc func);
        void DisConnectSlot(Slots& slots, FrameFunc func);
        void ReloadSkin();
        bool RunSetTime(const wxString& strNTP);

        void UpdateShowClock();
        void UpdateTop();
        void UpdateShadow();
        void UpdateAudioChimer();

        void PopUpRemind(const std::vector<wxString>& vecContent);
        void RunStartupTask(int nType);

    public:
        void ConnectDDEEvent(MissDDE::MissConnection* connect);

    private:
        void OnTimer(wxTimerEvent& event);
        void OnTaskBarIconLeftUP(wxEvent& event);

        void OnmimTopSelected(wxCommandEvent& event);
        void OnmimOptionSelected(wxCommandEvent& event);
        void OnmimRemindSelected( wxCommandEvent& event );
        void OnmimShowSelected(wxCommandEvent& event);
        void OnmimPinSelected(wxCommandEvent& event);
        void OnmimShadowSelected(wxCommandEvent& event);
        void OnmimCopyDateSelected( wxCommandEvent& event );
        void OnmimCopyTimeSelected( wxCommandEvent& event );
        void OnmimSetTimeSelected( wxCommandEvent& event );

        void OnAbout(wxCommandEvent& event);
        void OnExit( wxCommandEvent& event );

        void OnOptionUiEvent(wxCommandEvent& event);
        void OnDataEvent(wxCommandEvent& event);
        void OnSetTimeEvent(wxCommandEvent& event);
        void OnToolTipEvent(wxCommandEvent& event);
        void OnDDEEvent(wxCommandEvent& event);

    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnLeftDown( wxMouseEvent& event );
        virtual void OnRightUp( wxMouseEvent& event );

    private:
        shared_ptr<MissTaskBarIcon>      m_pTaskBarIcon;
        shared_ptr<wxTimer>              m_pMainTimer;
        shared_ptr<MissDDE::MissServer>  m_pDdeServer;
       // MissSkin                        *m_pSkin;
        MissConfig                      *m_pConfig;
        Slots                            sg_MinUp;
        HWND                             m_hWnd;


        tm                              *m_tmNow;
        time_t                           m_ttNow;

//        bool                             m_bRightMenu;
        bool                             m_bReloadSkin;
        std::vector<MissGlobal::TaskData> m_vecMinData;
        std::vector<MissGlobal::TaskData> m_vecDayData;
        MissOption*                      m_pOptionDlg;
};

#endif // MISSCLOCKMAIN_H
