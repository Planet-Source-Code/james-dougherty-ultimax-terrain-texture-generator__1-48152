
#include "XDefinition.h"

bool _stdcall DllMain(HANDLE hModule, DWORD Reason, LPVOID)
{
	switch(Reason)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH: 
		case DLL_THREAD_DETACH: 
		case DLL_PROCESS_DETACH: break;
	}
	return true;
}
