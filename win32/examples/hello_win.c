//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ଅନ୍ତର୍ଭାଵ <windows.h>

#define APPNAME "HELLO_WIN"

ଅକ୍ଷର szAppName[] = APPNAME; // The name of this application
ଅକ୍ଷର szTitle[]   = APPNAME; // The title bar text
ଅଚଳ ଅକ୍ଷର *pWindowText;

ଶୂନ୍ୟ CenterWindow(HWND hWnd);

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
    ବାଛ (message) {

        // ----------------------- first and last
        ସ୍ଥିତି WM_CREATE:
            CenterWindow(hwnd);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି WM_DESTROY:
            PostQuitMessage(0);
            ଭାଙ୍ଗ;

        // ----------------------- get out of it...
        ସ୍ଥିତି WM_RBUTTONUP:
            DestroyWindow(hwnd);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି WM_KEYDOWN:
            ଯଦି (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            ଭାଙ୍ଗ;

        // ----------------------- display our minimal info
        ସ୍ଥିତି WM_PAINT:
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
            ଭାଙ୍ଗ;
        }

        // ----------------------- let windows do all other stuff
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଫେରନ୍ତୁ DefWindowProc(hwnd, message, wParam, lParam);
    }
    ଫେରନ୍ତୁ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
ପୂର୍ଣ୍ଣସଂଖ୍ୟା APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_ଧାଡ଼ି,
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା nCmdShow
        )
{
    ସନ୍ଦେଶ_2 ସନ୍ଦେଶ;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_ଧାଡ଼ି[0] ? lp_Cmd_ଧାଡ଼ି : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, ଆକାର wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(ଖାଲି, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(ଖାଲି, IDC_ARROW);

    ଯଦି (FALSE == RegisterClass(&wc))
        ଫେରନ୍ତୁ 0;

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

    ଯଦି (ଖାଲି == hwnd)
        ଫେରନ୍ତୁ 0;

    // Main message loop:
    ଯେତେବେଳେ (GetMessage(&ସନ୍ଦେଶ, ଖାଲି, 0, 0) > 0) {
        TranslateMessage(&ସନ୍ଦେଶ);
        DispatchMessage(&ସନ୍ଦେଶ);
    }

    ଫେରନ୍ତୁ ସନ୍ଦେଶ.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

ଶୂନ୍ୟ CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    ଯଦି (ଖାଲି == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.ବାମ + (rc_parent.ଡାହାଣ + rw_self.ବାମ - rw_self.ଡାହାଣ) / 2;
    ypos = rw_parent.ଶୀର୍ଷ + (rc_parent.bottom + rw_self.ଶୀର୍ଷ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, ଖାଲି,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
