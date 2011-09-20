#include "MissToolBook.h"
#include <wx/toolbar.h>

MissToolBook::MissToolBook():
wxToolbook()
{
    //ctor
}

MissToolBook::MissToolBook(wxWindow* parent,
                           wxWindowID id,
                           const wxPoint& pos,
                           const wxSize& size,
                           long style,
                           const wxString& name):
wxToolbook(parent, id, pos, size, style, name)
{
    wxToolBarBase* toolbar = GetToolBar();
    long lStyle = toolbar->GetWindowStyle();
    if (lStyle & wxTB_TEXT)
    {
        lStyle &= ~wxTB_TEXT;
    }
    toolbar->SetWindowStyle(lStyle);
}
