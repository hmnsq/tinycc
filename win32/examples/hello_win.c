//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#include <windows.h>

#define APPNAME "HELLO_WIN"

char szAppName[] = APPNAME; // The name of this application
char szTitle[]   = APPNAME; // The title bar text
const char *pWindowText;

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
        case WM_CREATE:
            CenterWindow(hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        // ----------------------- get out of it...
        case WM_RBUTTONUP:
            DestroyWindow(hwnd);
            break;

        case WM_KEYDOWN:
            만약 (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            break;

        // ----------------------- display our minimal info
        case WM_PAINT:
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
            break;
        }

        // ----------------------- let windows do all other stuff
        default:
            반환 DefWindowProc(hwnd, message, wParam, lParam);
    }
    반환 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
정수 APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        정수 nCmdShow
        )
{
    MSG msg;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lpCmdLine[0] ? lpCmdLine : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, sizeof wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    만약 (FALSE == RegisterClass(&wc))
        반환 0;

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

    만약 (NULL == hwnd)
        반환 0;

    // Main message loop:
    동안 (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    반환 msg.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

void CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    정수 xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    만약 (NULL == hwnd_parent)
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
