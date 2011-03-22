#include "../StdAfx.h"
#include "MissConfig.h"
#include <wx/fileconf.h>
#include <wx/wfstream.h>


class MissConfig::MissConfigImpl
{
public:
    MissConfigImpl():
        m_ConfigName(wxT("MissConfig.ini"))
    {};

public:
    int m_Pin;                                 //是否固定位置
    int m_Top;                                 //是否置顶
    int m_Repeater;                            //是否整点报时
    int m_ShowClock;                           //是否显示时钟
    int m_Shadow;                              //是否有影无形
    int m_Opacity;                             //不透明度
    double m_Zoom;                             //缩放 1表示不缩放
    wxPoint  m_Pos;                            //位置坐标
    wxString m_NTP;                            //NTP的地址
    wxString m_SkinName;                       //当前使用的皮肤名称
    wxString m_ConfigName;                     //配置文件名
    shared_ptr<wxFileInputStream> m_pIStream;  //文件流
    shared_ptr<wxFileConfig> m_pConfigFile;    //配置文件读写器

};

MissConfig::MissConfig():
    m_pImpl(new MissConfigImpl)
{
    //ctor
    if(!wxFile::Exists(m_pImpl->m_ConfigName))
    {
        wxFile file;
        file.Create(m_pImpl->m_ConfigName);
        file.Close();
    }
    m_pImpl->m_pIStream = shared_ptr<wxFileInputStream>(new wxFileInputStream(m_pImpl->m_ConfigName));
    m_pImpl->m_pConfigFile = shared_ptr<wxFileConfig>(new wxFileConfig(*m_pImpl->m_pIStream));
    LoadIniFile();

}

MissConfig::~MissConfig()
{
    //dtor
}

void MissConfig::LoadIniFile()
{
    m_pImpl->m_Pos.x     = m_pImpl->m_pConfigFile->Read(wxT("位置/X"),0l);
    m_pImpl->m_Pos.y     = m_pImpl->m_pConfigFile->Read(wxT("位置/Y"),0l);
    m_pImpl->m_Pin       = m_pImpl->m_pConfigFile->Read(wxT("选项/是否固定"),0l);
    m_pImpl->m_Top       = m_pImpl->m_pConfigFile->Read(wxT("选项/是否置顶"),0l);
    m_pImpl->m_ShowClock = m_pImpl->m_pConfigFile->Read(wxT("选项/显示时钟"),1l);
    m_pImpl->m_Shadow    = m_pImpl->m_pConfigFile->Read(wxT("选项/有影无形"),0l);
    m_pImpl->m_Repeater  = m_pImpl->m_pConfigFile->Read(wxT("选项/整点报时"),1l);
    m_pImpl->m_SkinName  = m_pImpl->m_pConfigFile->Read(wxT("界面/主题"),wxT("Default"));
    m_pImpl->m_NTP       = m_pImpl->m_pConfigFile->Read(wxT("选项/NTP"),wxT("203.129.68.14"));
    m_pImpl->m_Opacity   = m_pImpl->m_pConfigFile->Read(wxT("界面/不透明度"),0xFFl);

    if( m_pImpl->m_Opacity < 50 || m_pImpl->m_Opacity > 255 )
    {
        m_pImpl->m_Opacity = 255;
    }

    m_pImpl->m_pConfigFile->Read(wxT("界面/缩放大小"),&m_pImpl->m_Zoom,1.0);

    if( m_pImpl->m_Zoom < 0.5 || m_pImpl->m_Zoom > 2.0 )
    {
        m_pImpl->m_Zoom = 1.0;
    }
}

void MissConfig::SaveConfig()
{
    wxFileOutputStream oStream(m_pImpl->m_ConfigName);
    m_pImpl->m_pConfigFile->Save(oStream);
}

void MissConfig::SetPos(wxPoint& ptPos)
{
    m_pImpl->m_Pos = ptPos;
}

wxPoint& MissConfig::GetPos()
{
    return m_pImpl->m_Pos;
}

bool MissConfig::GetPin()
{
    return m_pImpl->m_Pin;
}

bool MissConfig::GetTop()
{
    return m_pImpl->m_Top;
}

bool MissConfig::GetShowClock()
{
    return m_pImpl->m_ShowClock;
}

bool MissConfig::GetShadow()
{
    return m_pImpl->m_Shadow;
}

bool MissConfig::GetRepeater()
{
    return m_pImpl->m_Repeater;
}

wxString& MissConfig::GetSkinName()
{
    return m_pImpl->m_SkinName;
}

wxString& MissConfig::GetNTP()
{
    return m_pImpl->m_NTP;
}

int MissConfig::GetOpacity()
{
    return m_pImpl->m_Opacity;
}

double MissConfig::GetZoom()
{
    return m_pImpl->m_Zoom;
}
