//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#అన్తర్భావ <windows.h>

శూన్య hello_func (శూన్య);
__declspec(dllimport) బాహ్య స్థిరరాశి అక్షరం *hello_దత్తాంశం;

పూర్ణాంకం WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_పంక్తి,
    పూర్ణాంకం       nCmdShow)
{
    hello_దత్తాంశం = "Hello World!";
    hello_func();
    తిరిగి 0;
}
