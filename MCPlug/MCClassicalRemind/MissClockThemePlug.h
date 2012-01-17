#ifndef MISSCLOCKTHEMEPLUG_H
#define MISSCLOCKTHEMEPLUG_H

#include "../Common/MissCThemePlugBase.h"
#include <wingdi.h>
#include <wx/bitmap.h>

class MissSkin;

class MissClockThemePlug : public MissCThemePlugBase
{
public:
    MissClockThemePlug(HWND hWnd);
    virtual ~MissClockThemePlug();

    void InitDll(const wchar_t* strDllPath);

    bool HasOption()
    {
        return true;
    };

    bool RunOption();
    void TimeUpDrawClock(const tm* tmNow);
    void SetScale(const double& dZoom);
    void SetOpacity(int nOpacity);

    void LoadSkin();

protected:
    BLENDFUNCTION      m_Blend;
    double             m_dZoom;
    SIZE               m_SizeWindow;

    wxBitmap           m_bpUI;
    unsigned int      *m_pBitmap;
    int                m_nPixCount;
    MissSkin          *m_pSkin;

private:

};

#endif // MISSCLOCKTHEMEPLUG_H
