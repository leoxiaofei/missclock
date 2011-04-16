#ifndef MISSCONFIG_H
#define MISSCONFIG_H

class MissConfig
{
    class MissConfigImpl;
    public:
        MissConfig();
        virtual ~MissConfig();

    public:
        void            SaveOption();
        void            SetPos(const wxPoint & ptPos);
        void            SetZoom(const double & dZoom);
        void            SetOpacity(int nOpacity);
    public:
        const wxPoint&  GetPos();
        bool            GetPin();
        bool            GetTop();
        bool            GetShowClock();
        bool            GetShadow();
        bool            GetRepeater();
        const wxString& GetSkinName();
        const wxString& GetNTP();
        int             GetOpacity();
        double          GetZoom();

    protected:
        void LoadIniFile();
        void SaveConfig();

    private:
        shared_ptr<MissConfigImpl> m_pImpl;
};

#endif // MISSCONFIG_H
