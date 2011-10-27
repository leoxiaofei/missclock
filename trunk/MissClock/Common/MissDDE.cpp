#include "MissDDE.h"
#include "../Main/MissClockMain.h"

namespace MissDDE
{

MissServer::MissServer(wxFrame *frmMain): wxServer(),
m_connection(NULL),
m_frmMain(frmMain)
{
}

MissServer::~MissServer()
{
    Disconnect();
}

void MissServer::Disconnect()
{
    if (m_connection)
    {
        m_connection->wxDDEConnection::Disconnect();
        delete m_connection;
        m_connection = NULL;
    }
}

wxConnectionBase* MissServer::OnAcceptConnection(const wxString& topic)
{
    std::cout<<"OnAcceptConnection"<<topic<<std::endl;
    if ( topic == wxT("ToolTip")/*IPC_TOPIC*/ )
    {
        std::cout<<"new MissConnection"<<std::endl;
        m_connection = new MissConnection();
        static_cast<MissClockFrame *>(m_frmMain)->ConnectDDEEvent(m_connection);
        return m_connection;
    }
    // unknown topic
    return NULL;
}

MissConnection::MissConnection(): wxConnection()
{
}

MissConnection::~MissConnection()
{
}

bool MissConnection::OnPoke(const wxString& topic, const wxString& item, wxChar* data, int size, wxIPCFormat format)
{
    ///TODO:这里处理消息
    std::cout<<"OnPoke"<<std::endl;
    //std::wcout<<size<<std::endl;
    //std::wcout<<wxString(data,size).c_str()<<std::endl;
    //wxMessageBox(wxString(data,size),item);
    if(topic == wxT("ToolTip"))
    {
        wxCommandEvent send(wxEVT_MCTOOLTIP_EVENT,0);
        send.SetString(item);
        send.SetClientData(static_cast<void *>(data));
        ProcessEvent(send);
    }
    return wxConnection::OnPoke(topic, item, data, size, format);
}

bool MissConnection::OnDisconnect()
{
    ///TODO:发消息告诉外面，连接断开了。
    wxCommandEvent send(wxEVT_MCDDE_EVENT,0);
    ProcessEvent(send);
    std::cout<<"MissConnection::OnDisconnect"<<std::endl;
    return true;
}

}

DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCTOOLTIP_EVENT);
DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCDDE_EVENT);
