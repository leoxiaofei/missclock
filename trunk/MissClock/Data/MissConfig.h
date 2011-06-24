#ifndef MISSCONFIG_H
#define MISSCONFIG_H

class MissConfig
{
    class MissConfigImpl;
    public:
        MissConfig();
        virtual ~MissConfig();

    public:
        void            SetPos(const wxPoint & ptPos);
        void            SetZoom(const double & dZoom);
        void            SetOpacity(int nOpacity);
        void            SetSkinName(const wxString& strName);
        void            SetShowClock(bool bShow);
        void            SetShadow(bool bShadow);
        void            SetAudioChimer(bool bEnable);
        void            SetTop(bool bTop);
        void            SetPin(bool bPin);
        void            SetWeekDay(int nWeekDay);
        void            SetNTP(const wxString& strNTP);

        void            SaveOption();
        void            SavePos();
        void            SaveShowClock();
        void            SaveShadow();
        void            SaveTop();
        void            SavePin();

    public:
        void            LoadIniFile();
        const wxPoint&  GetPos();
        bool            GetPin();
        bool            GetTop();
        bool            GetShowClock();
        bool            GetShadow();
        bool            GetAudioChimer();
        const wxString& GetSkinName();
        const wxString& GetNTP();
        int             GetOpacity();
        double          GetZoom();
        int             GetWeekDay();

    protected:
        void SaveConfig();

    private:
        shared_ptr<MissConfigImpl> m_pImpl;
};

#endif // MISSCONFIG_H
