#ifndef MISSDDE_H
#define MISSDDE_H

#include "wx/ipc.h"

namespace MissDDE
{
class MissConnection : public wxConnection
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
    MissServer();
    ~MissServer();
    void Disconnect();
    bool IsConnected() { return m_connection != NULL; };
    MissConnection *GetConnection() { return m_connection; };
    //void Advise();
    //bool CanAdvise() { return m_connection != NULL && !m_connection->m_sAdvise.IsEmpty(); };
    wxConnectionBase *OnAcceptConnection(const wxString& topic);

protected:
    MissConnection     *m_connection;
};

}

#endif // MISSDDE_H
