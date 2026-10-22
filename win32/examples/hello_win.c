//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ಅನ್ತರ್ಭಾವ <windows.h>

#ವ್ಯಾಖ್ಯಾನಿಸು APPNAME "HELLO_WIN"

ಅಕ್ಷರ szAppName[] = APPNAME; // The name of this application
ಅಕ್ಷರ szTitle[]   = APPNAME; // The title bar text
ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p_ಕಿಟಕಿ_ಪಠ್ಯ;

ಶೂನ್ಯ Center_ಕಿಟಕಿ(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT ಸಂದೇಶ_2, WPARAM wParam, LPARAM lParam)
{
    ಆಯ್ಕೆ (ಸಂದೇಶ_2) {

        // ----------------------- first and last
        ಸ್ಥಿತಿ WM_CREATE:
            Center_ಕಿಟಕಿ(hwnd);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ WM_DESTROY:
            Post_Quit_ಸಂದೇಶ(0);
            ನಿಲ್ಲಿಸು;

        // ----------------------- get out of it...
        ಸ್ಥಿತಿ WM_RBUTTONUP:
            Destroy_ಕಿಟಕಿ(hwnd);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ WM_KEYDOWN:
            ಆದರೆ (VK_ESCAPE == wParam)
                Destroy_ಕಿಟಕಿ(hwnd);
            ನಿಲ್ಲಿಸು;

        // ----------------------- display our minimal info
        ಸ್ಥಿತಿ WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            ಗಣ_ಪಠ್ಯ_Color(hdc, RGB(240,240,96));
            ಗಣ_Bk_ಬಹುಲಕ(hdc, TRANSPARENT);
            Draw_ಪಠ್ಯ(hdc, p_ಕಿಟಕಿ_ಪಠ್ಯ, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            ಕೊನೆ_Paint(hwnd, &ps);
            ನಿಲ್ಲಿಸು;
        }

        // ----------------------- let windows do all other stuff
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಹಿಂತಿರುಗಿ Def_ಕಿಟಕಿ_Proc(hwnd, ಸಂದೇಶ_2, wParam, lParam);
    }
    ಹಿಂತಿರುಗಿ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
ಪೂರ್ಣಾಂಕ APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_ಸಾಲು,
        ಪೂರ್ಣಾಂಕ nCmdShow
        )
{
    ಸಂದೇಶ_3 ಸಂದೇಶ;
    WNDCLASS wc;
    HWND hwnd;

    p_ಕಿಟಕಿ_ಪಠ್ಯ = lp_Cmd_ಸಾಲು[0] ? lp_Cmd_ಸಾಲು : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_ಸ್ಮರಣೆ(&wc, ಗಾತ್ರ wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = ತುಂಬು_Icon(ಖಾಲಿ, IDI_APPLICATION);
    wc.hCursor       = ತುಂಬು_Cursor(ಖಾಲಿ, IDC_ARROW);

    ಆದರೆ (FALSE == ರಿಜಿಸ್ಟರ್_Class(&wc))
        ಹಿಂತಿರುಗಿ 0;

    // create the browser
    hwnd = Create_ಕಿಟಕಿ(
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

    ಆದರೆ (ಖಾಲಿ == hwnd)
        ಹಿಂತಿರುಗಿ 0;

    // Main message loop:
    ಆಗ (Get_ಸಂದೇಶ(&ಸಂದೇಶ, ಖಾಲಿ, 0, 0) > 0) {
        Translate_ಸಂದೇಶ(&ಸಂದೇಶ);
        Dispatch_ಸಂದೇಶ(&ಸಂದೇಶ);
    }

    ಹಿಂತಿರುಗಿ ಸಂದೇಶ.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

ಶೂನ್ಯ Center_ಕಿಟಕಿ(HWND hwnd_self)
{
    HWND hwnd_ಪೋಷಕ;
    RECT rw_self, rc_ಪೋಷಕ, rw_ಪೋಷಕ;
    ಪೂರ್ಣಾಂಕ xpos, ypos;

    hwnd_ಪೋಷಕ = Get_ಪೋಷಕ(hwnd_self);
    ಆದರೆ (ಖಾಲಿ == hwnd_ಪೋಷಕ)
        hwnd_ಪೋಷಕ = Get_Desktop_ಕಿಟಕಿ();

    Get_ಕಿಟಕಿ_Rect(hwnd_ಪೋಷಕ, &rw_ಪೋಷಕ);
    GetClientRect(hwnd_ಪೋಷಕ, &rc_ಪೋಷಕ);
    Get_ಕಿಟಕಿ_Rect(hwnd_self, &rw_self);

    xpos = rw_ಪೋಷಕ.ಎಡ + (rc_ಪೋಷಕ.ಬಲ + rw_self.ಎಡ - rw_self.ಬಲ) / 2;
    ypos = rw_ಪೋಷಕ.ತುದಿ + (rc_ಪೋಷಕ.bottom + rw_self.ತುದಿ - rw_self.bottom) / 2;

    ಗಣ_ಕಿಟಕಿ_Pos(
        hwnd_self, ಖಾಲಿ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
