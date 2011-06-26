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
namespace MissGlobal
{
    struct TaskData;
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
        void InitMenu();
        void UpdateSize();
        void UpdateAlpha();
        void UpdateTheme();
        bool UpdateClock();
        void CheckTask();
        void LoadTask();
        void CheckAudioChimer();
        void OnMinUp();
        void ConnectSlot(Slots& slots, FrameFunc func);
        void DisConnectSlot(Slots& slots, FrameFunc func);
        void ReloadSkin();

        void UpdateShowClock();
        void UpdateTop();
        void UpdateShadow();
        void UpdateAudioChimer();

        void PopUpRemind(const std::vector<wxString>& vecContent);

    private:
        void OnTimer(wxTimerEvent& event);
        void OnTaskBarIconLeftUP(wxEvent& event);

        void OnmimTopSelected(wxCommandEvent& event);
        void OnmimOptionSelected(wxCommandEvent& event);
        void OnmimRemindSelected( wxCommandEvent& event );
        void OnmimShowSelected(wxCommandEvent& event);
        void OnmimPinSelected(wxCommandEvent& event);
        void OnmimShadowSelected(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnExit( wxCommandEvent& event );

        void OnOptionUiEvent(wxCommandEvent& event);

    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnLeftDown( wxMouseEvent& event );
        virtual void OnRightUp( wxMouseEvent& event );

    private:
        shared_ptr<MissTaskBarIcon>      m_pTaskBarIcon;
        shared_ptr<wxTimer>              m_pMainTimer;
        shared_ptr<MissSkin>             m_pSkin;
        shared_ptr<MissConfig>           m_pConfig;
        Slots                            sg_MinUp;
        HWND                             m_hWnd;
        BLENDFUNCTION                    m_Blend;
        SIZE                             m_SizeWindow;
        struct tm                       *m_tmNow;
        time_t                          m_ttNow;
        wxBitmap                         m_bpUI;
        unsigned int                   *m_pBitmap;
        int                              m_nPixCount;
        bool                             m_bRightMenu;
        bool                             m_bReloadSkin;
        std::vector<MissGlobal::TaskData> m_vecMinData;
};

#endif // MISSCLOCKMAIN_H
