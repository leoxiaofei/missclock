#ifndef MISSTOOLS_H
#define MISSTOOLS_H

class wxTopLevelWindow;

namespace MissTools
{
    class AutoHideWindow
    {
    public:
        AutoHideWindow(wxTopLevelWindow* pWin);
        ~AutoHideWindow();

    private:
        wxTopLevelWindow* m_pWin;
    };
};

#endif // MISSTOOLS_H
