#ifndef MISSTOOLBOOK_H
#define MISSTOOLBOOK_H

#include <wx/toolbook.h>

class MissToolBook : public wxToolbook
{
    public:
        MissToolBook();
        MissToolBook(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxString& name = wxEmptyString);
    protected:
    private:
};

#endif // MISSTOOLBOOK_H
