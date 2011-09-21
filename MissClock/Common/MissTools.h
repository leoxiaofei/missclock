#ifndef MISSTOOLS_H
#define MISSTOOLS_H

class wxTopLevelWindow;
class wxCheckBox;

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

    class WeekDaysCheckBox
    {
    public:
        static void SetWeekDaysCheck(wxCheckBox *szWeekBox[7], int nWeekDay);
        static int  GetWeekDaysCheck(wxCheckBox *szWeekBox[7]);
    };

    void CopyToClipboard(const wxString& strText);
};

#endif // MISSTOOLS_H
