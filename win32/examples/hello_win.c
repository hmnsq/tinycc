//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#അന്തര്ഭാവ <windows.h>

#define APPNAME "HELLO_WIN"

അക്ഷരം szAppName[] = APPNAME; // The name of this application
അക്ഷരം szTitle[]   = APPNAME; // The title bar text
സ്ഥിരം അക്ഷരം *pWindowText;

ശൂന്യം CenterWindow(HWND hWnd);

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
    തിരഞ്ഞെടുപ്പ് (message) {

        // ----------------------- first and last
        അവസ്ഥ WM_CREATE:
            CenterWindow(hwnd);
            നിർത്തുക;

        അവസ്ഥ WM_DESTROY:
            PostQuitMessage(0);
            നിർത്തുക;

        // ----------------------- get out of it...
        അവസ്ഥ WM_RBUTTONUP:
            DestroyWindow(hwnd);
            നിർത്തുക;

        അവസ്ഥ WM_KEYDOWN:
            എങ്കിൽ (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            നിർത്തുക;

        // ----------------------- display our minimal info
        അവസ്ഥ WM_PAINT:
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
            നിർത്തുക;
        }

        // ----------------------- let windows do all other stuff
        സ്ഥിരസ്ഥിതി:
            തിരികെ DefWindowProc(hwnd, message, wParam, lParam);
    }
    തിരികെ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
പൂർണ്ണസംഖ്യ APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_വരി,
        പൂർണ്ണസംഖ്യ nCmdShow
        )
{
    സന്ദേശം_2 സന്ദേശം;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_വരി[0] ? lp_Cmd_വരി : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, വലുപ്പം wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(ശൂന്യ, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(ശൂന്യ, IDC_ARROW);

    എങ്കിൽ (FALSE == RegisterClass(&wc))
        തിരികെ 0;

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

    എങ്കിൽ (ശൂന്യ == hwnd)
        തിരികെ 0;

    // Main message loop:
    ആകുമ്പോൾ (GetMessage(&സന്ദേശം, ശൂന്യ, 0, 0) > 0) {
        TranslateMessage(&സന്ദേശം);
        DispatchMessage(&സന്ദേശം);
    }

    തിരികെ സന്ദേശം.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

ശൂന്യം CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    പൂർണ്ണസംഖ്യ xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    എങ്കിൽ (ശൂന്യ == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.ഇടത് + (rc_parent.വലത് + rw_self.ഇടത് - rw_self.വലത്) / 2;
    ypos = rw_parent.മുകൾ + (rc_parent.bottom + rw_self.മുകൾ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, ശൂന്യ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
