#ifndef MISSPLUGBASE_H
#define MISSPLUGBASE_H

#include <wx/string.h>

class wxWindow;
class wxImage;
class wxPanel;

class MissPlugBase
{
    public:
        MissPlugBase(const wxString &strPanelName, const wxString &strGUID):
            m_strPanelName(strPanelName),m_strGUID(strGUID){};
        virtual ~MissPlugBase(){};

        virtual void GetIcon(wxImage& image) = 0;
        virtual void InitPanel(wxWindow* parent) = 0;
        virtual void InitData(const wxString& strTaskContent) = 0;
        virtual wxString GetTaskContent() = 0;
        virtual void TimeUpRun(tm* tmNow, const wxString& strTaskContent) = 0;
        virtual wxString GetDescription(const wxString& strTaskContent) = 0;
        virtual void Release() = 0;
        const wxString &GetGUID(){return m_strGUID;};
        const wxString &GetPanelName(){return m_strPanelName;};
        wxPanel* GetPanel(){return m_pan;};

    protected:
        wxPanel* m_pan;

    private:
        wxString m_strPanelName;
        wxString m_strGUID;

};

#endif // MISSPLUGBASE_H
