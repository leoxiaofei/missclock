#ifndef MISSCTHEMEPLUGBASE_H
#define MISSCTHEMEPLUGBASE_H

#include <windef.h>

struct tm;
//typedef int HWND;

class MissCThemePlugBase
{
public:
    /** \brief
     *
     * \param hWnd 时钟窗口句柄，画图直接往这个句柄上画。
     * \return
     *
     */
    MissCThemePlugBase(HWND hWnd):m_hWnd(hWnd){};
    virtual ~MissCThemePlugBase(){};
    virtual void InitDll(const wchar_t* strDllPath) = 0;
    virtual bool HasOption(){return false;};
    virtual bool RunOption(){return false;};
    virtual void TimeUpDrawClock(const tm* tmNow) = 0;
    virtual void SetScale(const double& dZoom) = 0;
    virtual void SetOpacity(int nOpacity) = 0;
    virtual void LoadSkin() = 0;

protected:
    HWND m_hWnd;
};

#endif // MISSCTHEMEPLUGBASE_H
