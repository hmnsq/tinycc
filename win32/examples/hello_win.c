//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#અન્તર્ભાવ <windows.h>

#define APPNAME "HELLO_WIN"

અક્ષર szAppName[] = APPNAME; // The name of this application
અક્ષર szTitle[]   = APPNAME; // The title bar text
અચલ અક્ષર *pWindowText;

શૂન્ય CenterWindow(HWND hWnd);

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
    પસંદગી (message) {

        // ----------------------- first and last
        સ્થિતિ WM_CREATE:
            CenterWindow(hwnd);
            તોડો;

        સ્થિતિ WM_DESTROY:
            PostQuitMessage(0);
            તોડો;

        // ----------------------- get out of it...
        સ્થિતિ WM_RBUTTONUP:
            DestroyWindow(hwnd);
            તોડો;

        સ્થિતિ WM_KEYDOWN:
            જો (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            તોડો;

        // ----------------------- display our minimal info
        સ્થિતિ WM_PAINT:
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
            તોડો;
        }

        // ----------------------- let windows do all other stuff
        મૂળભૂત:
            પાછા DefWindowProc(hwnd, message, wParam, lParam);
    }
    પાછા 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
પૂર્ણાંક APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_લીટી,
        પૂર્ણાંક nCmdShow
        )
{
    સંદેશ_2 સંદેશ;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_લીટી[0] ? lp_Cmd_લીટી : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, કદ wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(ખાલી, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(ખાલી, IDC_ARROW);

    જો (FALSE == RegisterClass(&wc))
        પાછા 0;

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

    જો (ખાલી == hwnd)
        પાછા 0;

    // Main message loop:
    જ્યારે (GetMessage(&સંદેશ, ખાલી, 0, 0) > 0) {
        TranslateMessage(&સંદેશ);
        DispatchMessage(&સંદેશ);
    }

    પાછા સંદેશ.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

શૂન્ય CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    પૂર્ણાંક xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    જો (ખાલી == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.ડાબું + (rc_parent.જમણું + rw_self.ડાબું - rw_self.જમણું) / 2;
    ypos = rw_parent.ટોચ + (rc_parent.bottom + rw_self.ટોચ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, ખાલી,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
