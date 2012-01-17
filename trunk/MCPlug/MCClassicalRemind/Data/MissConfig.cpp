#include "MissConfig.h"
#include "MissSkin.h"
#include <wx/fileconf.h>
#include <wx/wfstream.h>

class MissConfig::MissConfigImpl
{
public:
    MissConfigImpl():
        m_ConfigName(wxT("ThemeConfig.ini"))
    {};
    wxString m_strPath;                         ///配置文件路径
    wxString m_ConfigName;                      ///配置文件名
    shared_ptr<wxFileInputStream> m_pIStream;   ///文件流
    shared_ptr<wxFileConfig> m_pConfigFile;     ///配置文件读写器

    wxString m_strSkinName;                     ///当前使用的时钟皮肤名称
    MissSkin m_CurrentSkin;                     ///当前时钟皮肤
};

MissConfig::MissConfig():
    m_pImpl(new MissConfigImpl)
{
    //ctor
}

void MissConfig::InitConfigPath(const wxString& strPath)
{
    m_pImpl->m_strPath = strPath;
    wxString strConfigPath = strPath + m_pImpl->m_ConfigName;
    if(!wxFile::Exists(strConfigPath))
    {
        wxFile file;
        file.Create(strConfigPath);
        file.Close();
    }
    m_pImpl->m_pIStream = shared_ptr<wxFileInputStream>(new wxFileInputStream(strConfigPath));
    m_pImpl->m_pConfigFile = shared_ptr<wxFileConfig>(new wxFileConfig(*m_pImpl->m_pIStream));
    LoadIniFile();
}

MissConfig::~MissConfig()
{
    //dtor
}

MissSkin& MissConfig::GetCurrentSkin()
{
    return m_pImpl->m_CurrentSkin;
}

const wxString& MissConfig::GetSkinName()
{
    return m_pImpl->m_strSkinName;
}

const wxString& MissConfig::GetConfigPath()
{
    return m_pImpl->m_strPath;
}

void MissConfig::LoadIniFile()
{
    m_pImpl->m_strSkinName  = m_pImpl->m_pConfigFile->Read(wxT("时钟主题/皮肤"),wxT("Default"));
}

void MissConfig::SaveConfig()
{
    wxFileOutputStream oStream(m_pImpl->m_strPath + m_pImpl->m_ConfigName);
    m_pImpl->m_pConfigFile->Save(oStream);
}
