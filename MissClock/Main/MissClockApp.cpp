/***************************************************************
 * Name:      MissClockApp.cpp
 * Purpose:   Code for Application Class
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-03-13
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MissClockApp.h"
#include "MissClockMain.h"
#include <wx/filesys.h>
#include <wx/fs_zip.h>
#include <mSystem.hpp>

IMPLEMENT_APP(MissClockApp);

bool MissClockApp::OnInit()
{
    wxSetWorkingDirectory(Miss::GetAppExePath());

    wxImage::AddHandler( new wxPNGHandler );
    wxFileSystem::AddHandler(new wxZipFSHandler);

    MissClockFrame* frame = new MissClockFrame(0L);
    frame->SetIcon(wxICON(RC_CLOCK_ICON)); // To Set App Icon
    frame->Show();
    ///内存清理
    //SetProcessWorkingSetSize(GetCurrentProcess(),-1,-1);
    return true;
}
