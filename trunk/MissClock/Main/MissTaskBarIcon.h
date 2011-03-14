#ifndef MISSTASKBARICON_H
#define MISSTASKBARICON_H

#include <wx/taskbar.h>


class MissTaskBarIcon : public wxTaskBarIcon
{
    public:
        /** Default constructor */
        MissTaskBarIcon();
        /** Default destructor */
        virtual ~MissTaskBarIcon();
    protected:
    private:
};

#endif // MISSTASKBARICON_H
