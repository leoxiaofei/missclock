#include "MissTools.h"
#include <wx/toplevel.h>
#include <wx/checkbox.h>
#include <wx/clipbrd.h>

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

}
