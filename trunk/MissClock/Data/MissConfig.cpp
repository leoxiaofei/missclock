#include "../StdAfx.h"
#include "MissConfig.h"
#include <wx/fileconf.h>
#include <wx/wfstream.h>
//#include "MissSkin.h"
//#include "MissRemindSkin.h"

class MissConfig::MissConfigImpl
{
public:
    MissConfigImpl():
        m_ConfigName(wxT("MissConfig.ini"))
    {};

public:
    int m_Pin;                                  ///是否固定位置
    int m_Top;                                  ///是否置顶
    int m_AudioChimer;                          ///是否整点报时
    int m_ShowClock;                            ///是否显示时钟
    int m_Shadow;                               ///是否有影无形
    int m_Opacity;                              ///不透明度
    int m_WeekDay;                              ///工作日（二进制表示，第一位表示星期天，第二位表示星期一…）
    double m_Zoom;                              ///缩放 1表示不缩放
    wxPoint  m_Pos;                             ///位置坐标
    wxString m_NTP;                             ///NTP的地址
    wxString m_strPDateFormat;                  ///粘贴日期的格式
    wxString m_strPTimeFormat;                  ///粘贴时间的格式
    wxString m_strCThemeName;                   ///当前使用的时钟主题名称
    wxString m_strTThemeName;                   ///当前使用的任务主题名称
//    MissSkin m_CurrentSkin;                     ///当前时钟皮肤
//    MissRemindSkin m_CurrentRemindSkin;         ///当前提醒皮肤

    wxString m_ConfigName;                      ///配置文件名
    shared_ptr<wxFileInputStream> m_pIStream;   ///文件流
    shared_ptr<wxFileConfig> m_pConfigFile;     ///配置文件读写器

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
    m_pImpl->m_Pos.x          = m_pImpl->m_pConfigFile->Read(wxT("位置/X"),0l);
    m_pImpl->m_Pos.y          = m_pImpl->m_pConfigFile->Read(wxT("位置/Y"),0l);
    m_pImpl->m_Pin            = m_pImpl->m_pConfigFile->Read(wxT("选项/是否固定"),0l);
    m_pImpl->m_Top            = m_pImpl->m_pConfigFile->Read(wxT("选项/是否置顶"),0l);
    m_pImpl->m_ShowClock      = m_pImpl->m_pConfigFile->Read(wxT("选项/显示时钟"),1l);
    m_pImpl->m_Shadow         = m_pImpl->m_pConfigFile->Read(wxT("选项/有影无形"),0l);
    m_pImpl->m_AudioChimer    = m_pImpl->m_pConfigFile->Read(wxT("选项/整点报时"),1l);
    m_pImpl->m_WeekDay        = m_pImpl->m_pConfigFile->Read(wxT("选项/工作日"),62l);
    m_pImpl->m_strCThemeName  = m_pImpl->m_pConfigFile->Read(wxT("界面/时钟主题"),wxT("Default"));
    m_pImpl->m_strTThemeName  = m_pImpl->m_pConfigFile->Read(wxT("界面/任务主题"),wxT("Default"));
    m_pImpl->m_NTP            = m_pImpl->m_pConfigFile->Read(wxT("选项/NTP"),wxT("203.129.68.14"));
    m_pImpl->m_Opacity        = m_pImpl->m_pConfigFile->Read(wxT("界面/不透明度"),0xFFl);
    m_pImpl->m_strPDateFormat = m_pImpl->m_pConfigFile->Read(wxT("选项/复制日期格式"),wxT("%Y-%m-%d"));
    m_pImpl->m_strPTimeFormat = m_pImpl->m_pConfigFile->Read(wxT("选项/复制时间格式"),wxT("%H:%M:%S"));

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

void MissConfig::SavePos()
{
    m_pImpl->m_pConfigFile->Write(wxT("位置/X"), m_pImpl->m_Pos.x);
    m_pImpl->m_pConfigFile->Write(wxT("位置/Y"), m_pImpl->m_Pos.y);
    SaveConfig();
}

void MissConfig::SaveShowClock()
{
    m_pImpl->m_pConfigFile->Write(wxT("选项/显示时钟"), m_pImpl->m_ShowClock);
    SaveConfig();
}

void MissConfig::SaveShadow()
{
    m_pImpl->m_pConfigFile->Write(wxT("选项/有影无形"), m_pImpl->m_Shadow);
    SaveConfig();
}

void MissConfig::SaveTop()
{
    m_pImpl->m_pConfigFile->Write(wxT("选项/是否置顶"), m_pImpl->m_Top);
    SaveConfig();
}

void MissConfig::SavePin()
{
    m_pImpl->m_pConfigFile->Write(wxT("选项/是否固定"), m_pImpl->m_Pin);
    SaveConfig();
}

void MissConfig::SaveOption()
{
    m_pImpl->m_pConfigFile->Write(wxT("选项/是否固定"),m_pImpl->m_Pin);
    m_pImpl->m_pConfigFile->Write(wxT("选项/是否置顶"),m_pImpl->m_Top);
    m_pImpl->m_pConfigFile->Write(wxT("选项/显示时钟"),m_pImpl->m_ShowClock);
    m_pImpl->m_pConfigFile->Write(wxT("选项/有影无形"),m_pImpl->m_Shadow);
    m_pImpl->m_pConfigFile->Write(wxT("选项/整点报时"),m_pImpl->m_AudioChimer);
    m_pImpl->m_pConfigFile->Write(wxT("选项/工作日"),m_pImpl->m_WeekDay);
    m_pImpl->m_pConfigFile->Write(wxT("选项/复制日期格式"),m_pImpl->m_strPDateFormat);
    m_pImpl->m_pConfigFile->Write(wxT("选项/复制时间格式"),m_pImpl->m_strPTimeFormat);

    m_pImpl->m_pConfigFile->Write(wxT("界面/时钟主题"),m_pImpl->m_strCThemeName);
    m_pImpl->m_pConfigFile->Write(wxT("界面/任务主题"),m_pImpl->m_strTThemeName);
    m_pImpl->m_pConfigFile->Write(wxT("选项/NTP"),m_pImpl->m_NTP);
    m_pImpl->m_pConfigFile->Write(wxT("界面/不透明度"),m_pImpl->m_Opacity);
    m_pImpl->m_pConfigFile->Write(wxT("界面/缩放大小"),m_pImpl->m_Zoom);
    SaveConfig();
}

void MissConfig::SetPos(const wxPoint& ptPos)
{
    m_pImpl->m_Pos = ptPos;
}

void MissConfig::SetCThemeName(const wxString& strName)
{
    m_pImpl->m_strCThemeName = strName;
}

void MissConfig::SetTThemeName(const wxString& strName)
{
    m_pImpl->m_strTThemeName = strName;
}

void MissConfig::SetNTP(const wxString& strNTP)
{
    m_pImpl->m_NTP = strNTP;
}

void MissConfig::SetShowClock(bool bShow)
{
    m_pImpl->m_ShowClock = bShow;
}

void MissConfig::SetShadow(bool bShadow)
{
    m_pImpl->m_Shadow = bShadow;
}

void MissConfig::SetAudioChimer(bool bEnable)
{
     m_pImpl->m_AudioChimer = bEnable;
}

void MissConfig::SetTop(bool bTop)
{
    m_pImpl->m_Top = bTop;
}

void MissConfig::SetPin(bool bPin)
{
    m_pImpl->m_Pin = bPin;
}

const wxPoint& MissConfig::GetPos()
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

bool MissConfig::GetAudioChimer()
{
    return m_pImpl->m_AudioChimer;
}

const wxString& MissConfig::GetCThemeName()
{
    return m_pImpl->m_strCThemeName;
}

const wxString& MissConfig::GetTThemeName()
{
    return m_pImpl->m_strTThemeName;
}

const wxString& MissConfig::GetNTP()
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

void MissConfig::SetWeekDay(int nWeekDay)
{
    m_pImpl->m_WeekDay = nWeekDay;
}

int MissConfig::GetWeekDay()
{
    return m_pImpl->m_WeekDay;
}

void MissConfig::SetZoom(const double& dZoom)
{
    m_pImpl->m_Zoom = dZoom;
}

void MissConfig::SetOpacity(int nOpacity)
{
    m_pImpl->m_Opacity = nOpacity;
}
/*
MissSkin& MissConfig::GetCurrentSkin()
{
//    return m_pImpl->m_CurrentSkin;
}

MissRemindSkin& MissConfig::GetCurrentRemindSkin()
{
//    return m_pImpl->m_CurrentRemindSkin;
}
*/
void MissConfig::SetPDateFormat(const wxString& strFormat)
{
    m_pImpl->m_strPDateFormat = strFormat;
}

void MissConfig::SetPTimeFormat(const wxString& strFormat)
{
    m_pImpl->m_strPTimeFormat = strFormat;
}

const wxString& MissConfig::GetPDateFormat()
{
    return m_pImpl->m_strPDateFormat;
}

const wxString& MissConfig::GetPTimeFormat()
{
    return m_pImpl->m_strPTimeFormat;
}
