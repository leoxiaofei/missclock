#include "MissDDE.h"

namespace MissDDE
{

MissServer::MissServer(): wxServer(),
m_connection(NULL)
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
        m_connection->Disconnect();
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
    wxMessageBox(wxString(data),item);
    return wxConnection::OnPoke(topic, item, data, size, format);
}

bool MissConnection::OnDisconnect()
{
    ///TODO:发消息告诉外面，连接断开了。
    std::cout<<"MissConnection::OnDisconnect"<<std::endl;
    return true;
}


}
