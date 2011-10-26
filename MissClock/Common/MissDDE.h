#ifndef MISSDDE_H
#define MISSDDE_H

#include "wx/ipc.h"

namespace MissDDE
{
class MissConnection : public wxConnection, public wxEvtHandler
{
public:
    MissConnection();
    ~MissConnection();

    //virtual bool OnExecute(const wxString& topic, wxChar *data, int size, wxIPCFormat format);
    //virtual wxChar *OnRequest(const wxString& topic, const wxString& item, int *size, wxIPCFormat format);
    virtual bool OnPoke(const wxString& topic, const wxString& item, wxChar *data, int size, wxIPCFormat format);
    //virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
    //virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
    //virtual bool Advise(const wxString& item, wxChar *data, int size = -1, wxIPCFormat format = wxIPC_TEXT);
    virtual bool OnDisconnect();
//protected:
    //void Log(const wxString& command, const wxString& topic, const wxString& item, wxChar *data, int size, wxIPCFormat format);
//public:
//    wxString        m_sAdvise;
//protected:
//    wxString        m_sRequestDate;
//    char            m_achRequestBytes[3];
};

class MissServer: public wxServer
{
public:
    MissServer(wxFrame *frmMain);
    ~MissServer();
    void Disconnect();
    bool IsConnected() { return m_connection != NULL; };
    MissConnection *GetConnection() { return m_connection; };
    //void Advise();
    //bool CanAdvise() { return m_connection != NULL && !m_connection->m_sAdvise.IsEmpty(); };
    wxConnectionBase *OnAcceptConnection(const wxString& topic);

private:
    MissConnection     *m_connection;
    wxFrame            *m_frmMain;
};

}

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCTOOLTIP_EVENT, -1)
    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MCDDE_EVENT, -1)
END_DECLARE_EVENT_TYPES()

#endif // MISSDDE_H
