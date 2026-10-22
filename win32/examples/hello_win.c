//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#অন্তর্ভাব <windows.h>

#define APPNAME "HELLO_WIN"

অক্ষর szAppName[] = APPNAME; // The name of this application
অক্ষর szTitle[]   = APPNAME; // The title bar text
ধ্রুবক অক্ষর *pWindowText;

শূন্য CenterWindow(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    নির্বাচন (message) {

        // ----------------------- first and last
        ক্ষেত্র WM_CREATE:
            CenterWindow(hwnd);
            বিরতি;

        ক্ষেত্র WM_DESTROY:
            PostQuitMessage(0);
            বিরতি;

        // ----------------------- get out of it...
        ক্ষেত্র WM_RBUTTONUP:
            DestroyWindow(hwnd);
            বিরতি;

        ক্ষেত্র WM_KEYDOWN:
            যদি (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            বিরতি;

        // ----------------------- display our minimal info
        ক্ষেত্র WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            SetTextColor(hdc, RGB(240,240,96));
            SetBkMode(hdc, TRANSPARENT);
            DrawText(hdc, pWindowText, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            EndPaint(hwnd, &ps);
            বিরতি;
        }

        // ----------------------- let windows do all other stuff
        পূর্বনির্ধারিত:
            ফেরত DefWindowProc(hwnd, message, wParam, lParam);
    }
    ফেরত 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
পূর্ণসংখ্যা APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE h_পূর্ব_Instance,
        LPSTR lp_Cmd_সারি,
        পূর্ণসংখ্যা nCmdShow
        )
{
    বার্তা_2 বার্তা;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_সারি[0] ? lp_Cmd_সারি : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, আকার wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(ফাঁকা, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(ফাঁকা, IDC_ARROW);

    যদি (FALSE == RegisterClass(&wc))
        ফেরত 0;

    // create the browser
    hwnd = CreateWindow(
        szAppName,
        szTitle,
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        360,//CW_USEDEFAULT,
        240,//CW_USEDEFAULT,
        0,
        0,
        hInstance,
        0);

    যদি (ফাঁকা == hwnd)
        ফেরত 0;

    // Main message loop:
    যখন (GetMessage(&বার্তা, ফাঁকা, 0, 0) > 0) {
        TranslateMessage(&বার্তা);
        DispatchMessage(&বার্তা);
    }

    ফেরত বার্তা.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

শূন্য CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    পূর্ণসংখ্যা xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    যদি (ফাঁকা == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.বাম + (rc_parent.ডান + rw_self.বাম - rw_self.ডান) / 2;
    ypos = rw_parent.শীর্ষ + (rc_parent.bottom + rw_self.শীর্ষ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, ফাঁকা,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
