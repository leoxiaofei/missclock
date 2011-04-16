#include "MissSoundThread.h"
#include <wx/sound.h>
#include "../Data/MissRes.h"

MissSoundThread::MissSoundThread(int hour)
    :
    m_Hour(hour)
{
    //ctor
}
#ifdef __WXDEBUG__
MissSoundThread::~MissSoundThread()
{
    std::cout << "~MissClockFrame()" << std::endl;
}
#endif

void *MissSoundThread::Entry ()
{
    wxSound wsHead,wsHour;
    MissRes::Instance()->GetReswxSound(wxT("head.wav"), wsHead);
    MissRes::Instance()->GetReswxSound(wxString::Format(wxT("bs%.2d.wav"),m_Hour), wsHour);
    wsHead.Play(wxSOUND_SYNC);
    wsHour.Play(wxSOUND_SYNC);
    //file.Printf(wxT("bs%.2d.wav"), m_Hour);
    //wxSound(wxT("Repeater\\head.wav")).Play(wxSOUND_SYNC);
    //wxSound(file).Play(wxSOUND_SYNC);
    //Sleep(5000);
    return NULL;
}

