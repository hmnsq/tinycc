//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ಅನ್ತರ್ಭಾವ <windows.h>

#define APPNAME "HELLO_WIN"

ವರ್ಣ szAppName[] = APPNAME; // The name of this application
ವರ್ಣ szTitle[]   = APPNAME; // The title bar text
ಧ್ರುವ ವರ್ಣ *pWindowText;

ಶೂನ್ಯ CenterWindow(HWND hWnd);

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
    ವಿಕಲ್ಪ (message) {

        // ----------------------- first and last
        ಪಕ್ಷ WM_CREATE:
            CenterWindow(hwnd);
            ಭಙ್ಗ;

        ಪಕ್ಷ WM_DESTROY:
            PostQuitMessage(0);
            ಭಙ್ಗ;

        // ----------------------- get out of it...
        ಪಕ್ಷ WM_RBUTTONUP:
            DestroyWindow(hwnd);
            ಭಙ್ಗ;

        ಪಕ್ಷ WM_KEYDOWN:
            ಯದಿ (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            ಭಙ್ಗ;

        // ----------------------- display our minimal info
        ಪಕ್ಷ WM_PAINT:
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
            ಭಙ್ಗ;
        }

        // ----------------------- let windows do all other stuff
        ಸ್ವಭಾವ:
            ಪ್ರತ್ಯಾಗಮ DefWindowProc(hwnd, message, wParam, lParam);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
ಪೂರ್ಣಾಙ್ಕ APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_ಸಾಲು,
        ಪೂರ್ಣಾಙ್ಕ nCmdShow
        )
{
    ಸಂದೇಶ_2 ಸಂದೇಶ;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_ಸಾಲು[0] ? lp_Cmd_ಸಾಲು : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, ಪರಿಮಾಣ wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(ರಿಕ್ತ, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(ರಿಕ್ತ, IDC_ARROW);

    ಯದಿ (FALSE == RegisterClass(&wc))
        ಪ್ರತ್ಯಾಗಮ 0;

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

    ಯದಿ (ರಿಕ್ತ == hwnd)
        ಪ್ರತ್ಯಾಗಮ 0;

    // Main message loop:
    ಯಾವತ್ (GetMessage(&ಸಂದೇಶ, ರಿಕ್ತ, 0, 0) > 0) {
        TranslateMessage(&ಸಂದೇಶ);
        DispatchMessage(&ಸಂದೇಶ);
    }

    ಪ್ರತ್ಯಾಗಮ ಸಂದೇಶ.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

ಶೂನ್ಯ CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    ಪೂರ್ಣಾಙ್ಕ xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    ಯದಿ (ರಿಕ್ತ == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.ಎಡ + (rc_parent.ಬಲ + rw_self.ಎಡ - rw_self.ಬಲ) / 2;
    ypos = rw_parent.ತುದಿ + (rc_parent.bottom + rw_self.ತುದಿ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, ರಿಕ್ತ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
