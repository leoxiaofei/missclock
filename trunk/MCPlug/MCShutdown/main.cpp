#include "main.h"
#include "MissShutdownPlug.h"

// a sample exported function
bool DLL_EXPORT CreatePlugObject(void ** pobj)
{
    *pobj = new MissShutdownPlug;
    return *pobj != NULL;
}
