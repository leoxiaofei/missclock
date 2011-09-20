#ifndef MISSTASKBARICON_H
#define MISSTASKBARICON_H

#include <wx/taskbar.h>

#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#endif

#define NIIF_INFO  0x00000001

class MissTaskBarIcon : public wxTaskBarIcon
{
    public:
        /** Default constructor */
        MissTaskBarIcon();
        /** Default destructor */
        virtual ~MissTaskBarIcon();

        bool ShowBalloon(wxString strTitle, wxString strMsg, int iconID = NIIF_INFO, unsigned int timeout = 3000);

    protected:
    private:
};

#endif // MISSTASKBARICON_H
