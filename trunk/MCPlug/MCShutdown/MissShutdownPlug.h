#ifndef MISSSHUTDOWNPLUG_H
#define MISSSHUTDOWNPLUG_H

#include "../Common/MissPlugBase.h"

class MissShutdownPlug : public MissPlugBase
{
    public:
        MissShutdownPlug();
        virtual ~MissShutdownPlug();

        void GetIcon(wxImage& image);
        void InitPanel(wxWindow* parent);
        void InitData(const wxString& strTaskContent);
        wxString GetTaskContent();
        wxString GetDescription(const wxString& strTaskContent);
        void TimeUpRun(tm* tmNow, const wxString& strTaskContent);
        void Release();
        bool HasShortcutMenu();

    protected:
        bool AdjustToken();

    private:
        static wxString s_strDescription[];
};

#endif // MISSSHUTDOWNPLUG_H
