//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#అన్తర్భావ <windows.h>

__declspec(dllexport) స్థిరరాశి అక్షరం *hello_దత్తాంశం = "(not set)";

__declspec(dllexport) శూన్య hello_func (శూన్య)
{
    సందేశం_Box (0, hello_దత్తాంశం, "From DLL", MB_ICONINFORMATION);
}
