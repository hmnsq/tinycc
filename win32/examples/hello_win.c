//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#include <windows.h>

#define APPNAME "HELLO_WIN"

var_na szAppName[] = APPNAME; // The name of this application
var_na szTitle[]   = APPNAME; // The title bar text
const var_na *pWindowText;

void CenterWindow(HWND hWnd);

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
    switch (message) {

        // ----------------------- first and last
        pak_sa WM_CREATE:
            CenterWindow(hwnd);
            bha_nga;

        pak_sa WM_DESTROY:
            PostQuitMessage(0);
            bha_nga;

        // ----------------------- get out of it...
        pak_sa WM_RBUTTONUP:
            DestroyWindow(hwnd);
            bha_nga;

        pak_sa WM_KEYDOWN:
            ᯀᯮᯝ (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            bha_nga;

        // ----------------------- display our minimal info
        pak_sa WM_PAINT:
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
            bha_nga;
        }

        // ----------------------- let windows do all other stuff
        default:
            ᯀᯮᯞ DefWindowProc(hwnd, message, wParam, lParam);
    }
    ᯀᯮᯞ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
puur_naa_nka APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        puur_naa_nka nCmdShow
        )
{
    MSG msg;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lpCmdLine[0] ? lpCmdLine : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, parimaa_na wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    ᯀᯮᯝ (FALSE == RegisterClass(&wc))
        ᯀᯮᯞ 0;

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

    ᯀᯮᯝ (NULL == hwnd)
        ᯀᯮᯞ 0;

    // Main message loop:
    ᯀᯬᯝ (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ᯀᯮᯞ msg.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

void CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    puur_naa_nka xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    ᯀᯮᯝ (NULL == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.left + (rc_parent.right + rw_self.left - rw_self.right) / 2;
    ypos = rw_parent.top + (rc_parent.bottom + rw_self.top - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, NULL,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
