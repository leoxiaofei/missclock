#include "main.h"
#include "MissClockThemePlug.h"

// a sample exported function
bool DLL_EXPORT CreateCThemePlug(void ** pobj, HWND hWnd)
{
    *pobj = new MissClockThemePlug(hWnd);
    return *pobj != NULL;
}

const wchar_t* DLL_EXPORT ShowGUID()
{
    return L"481B463D-C4A2-44D4-A6BA-75DF573828B0";
}

const wchar_t* DLL_EXPORT GetThemeName()
{
    return L"经典主题";
}
