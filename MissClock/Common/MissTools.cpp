#include "MissTools.h"
#include <wx/toplevel.h>

namespace MissTools
{

AutoHideWindow::AutoHideWindow(wxTopLevelWindow* pWin):
    m_pWin(pWin)
{
    m_pWin->SetTransparent(0);
}

AutoHideWindow::~AutoHideWindow()
{
    m_pWin->SetTransparent(255);
}

}
