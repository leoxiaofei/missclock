#ifndef MISSCONFIG_H
#define MISSCONFIG_H

class MissSkin;

class MissConfig
{
    class MissConfigImpl;
    public:
        static MissConfig& GetInstance()
        {
            static MissConfig theSingleton;
            return theSingleton;
        }

    private:
        MissConfig();
        virtual ~MissConfig();
        MissConfig(const MissConfig&);
        MissConfig& operator=(const MissConfig&);

    public:
        void              InitConfigPath(const wxString& strPath);
        MissSkin&         GetCurrentSkin();
        const wxString&   GetSkinName();
        const wxString&   GetConfigPath();
    public:
        void            LoadIniFile();


    protected:
        void SaveConfig();

    private:
        shared_ptr<MissConfigImpl> m_pImpl;
};

#endif // MISSCONFIG_H
