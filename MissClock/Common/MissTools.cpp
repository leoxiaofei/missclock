#include "MissTools.h"
#include <wx/toplevel.h>
#include <wx/checkbox.h>
#include <wx/clipbrd.h>
#include <shlobj.h>
#include <wx/filename.h>

namespace MissTools
{

AutoHideWindow::AutoHideWindow(wxTopLevelWindow* pWin):
    m_pWin(pWin)
{
    m_pWin->SetTransparent(0);
    wxYield();
}

AutoHideWindow::~AutoHideWindow()
{
    m_pWin->SetTransparent(255);
}

void WeekDaysCheckBox::SetWeekDaysCheck(wxCheckBox *szWeekBox[7], int nWeekDay)
{
    for(int ix = 0; ix != 7; ++ix)
    {
        if(nWeekDay & (1<<ix))
        {
            szWeekBox[ix]->SetValue(true);
        }
    }
}

int WeekDaysCheckBox::GetWeekDaysCheck(wxCheckBox *szWeekBox[7])
{
    int nRet(0);
    for(int ix = 0; ix != 7; ++ix)
    {
        if(szWeekBox[ix]->GetValue())
        {
            nRet |= (1<<ix);
        }
    }
    return nRet;
}

void CopyToClipboard(const wxString& strText)
{
    if (wxTheClipboard->Open())
    {
        wxTextDataObject *word = new wxTextDataObject( strText );
        wxTheClipboard->SetData( word );
        wxTheClipboard->Close();
    }
}

void GetAutoRunPath(wxString& strRunPath)
{
    WCHAR szPath[MAX_PATH];
	SHGetFolderPath(NULL,CSIDL_STARTUP,NULL,0,szPath);
	strRunPath.Printf(wxT("%s\\迷失日历时钟.lnk"),szPath);
}

bool GetAutoRun()
{
    wxString StartupPath;
    GetAutoRunPath(StartupPath);
	return wxFileName::FileExists(StartupPath);
}

void SetAutoRun(bool bAutoRun)
{
    wxString StartupPath;
    GetAutoRunPath(StartupPath);
    bool bHasAutoRun = wxFileName::FileExists(StartupPath);
    if(bHasAutoRun != bAutoRun)
    {
        if(bAutoRun)
        {
            ::CoInitialize(NULL);

            //创建2个接口
            IShellLink *pShellLink;
            //HRESULT hr=spShellLink.CoCreateInstance(CLSID_ShellLink);
            ::CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,IID_IShellLink,(void**)&pShellLink);

            IPersistFile *pPersistFile;

            //取得此EXE的文件名及路径
            WCHAR FileName[MAX_PATH];
            ZeroMemory(FileName, MAX_PATH);
            GetModuleFileName(NULL, FileName, MAX_PATH);

            pShellLink->SetPath(FileName);
            pShellLink->SetWorkingDirectory(wxGetCwd());
            pShellLink->SetDescription(_T("迷失日历时钟，集时钟日历显示，整点报时，定时提醒，主题更换于一体。"));
            pShellLink->QueryInterface(IID_IPersistFile, (void **)&pPersistFile);

                //取得桌面的全路径
                //LPITEMIDLIST pidl;
                //hr = SHGetSpecialFolderLocation(NULL, CSIDL_STARTUP, &pidl);

                //创建快捷方式
                //CComBSTR strLinkFilePath(szPath);
                //strLinkFilePath.Append(_T("\\迷失日历时钟.lnk"));
            pPersistFile->Save(StartupPath, TRUE);

            pPersistFile->Release();
            pShellLink->Release();

            ::CoUninitialize();
        }
        else
        {
            ::wxRemoveFile(StartupPath);
        }
    }

}

}
