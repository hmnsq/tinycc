//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPNAME "HELLO_WIN"

ਅੱਖਰ szAppName[] = APPNAME; // The name of this application
ਅੱਖਰ szTitle[]   = APPNAME; // The title bar text
ਅਚਲ ਅੱਖਰ *p_ਖਿੜਕੀ_ਪਾਠ;

ਖਾਲੀ Center_ਖਿੜਕੀ(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT ਸੁਨੇਹਾ_2, WPARAM wParam, LPARAM lParam)
{
    ਚੋਣ (ਸੁਨੇਹਾ_2) {

        // ----------------------- first and last
        ਹਾਲਤ WM_CREATE:
            Center_ਖਿੜਕੀ(hwnd);
            ਰੋਕੋ;

        ਹਾਲਤ WM_DESTROY:
            Post_Quit_ਸੁਨੇਹਾ(0);
            ਰੋਕੋ;

        // ----------------------- get out of it...
        ਹਾਲਤ WM_RBUTTONUP:
            Destroy_ਖਿੜਕੀ(hwnd);
            ਰੋਕੋ;

        ਹਾਲਤ WM_KEYDOWN:
            ਜੇ (VK_ESCAPE == wParam)
                Destroy_ਖਿੜਕੀ(hwnd);
            ਰੋਕੋ;

        // ----------------------- display our minimal info
        ਹਾਲਤ WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            ਸੈੱਟ_ਪਾਠ_Color(hdc, RGB(240,240,96));
            ਸੈੱਟ_Bk_ਬਹੁਲਕ(hdc, TRANSPARENT);
            Draw_ਪਾਠ(hdc, p_ਖਿੜਕੀ_ਪਾਠ, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            ਸਿਰਾ_Paint(hwnd, &ps);
            ਰੋਕੋ;
        }

        // ----------------------- let windows do all other stuff
        ਮੂਲ:
            ਵਾਪਸ Def_ਖਿੜਕੀ_Proc(hwnd, ਸੁਨੇਹਾ_2, wParam, lParam);
    }
    ਵਾਪਸ 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
ਪੂਰਨ APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_ਸਤਰ,
        ਪੂਰਨ nCmdShow
        )
{
    ਸੁਨੇਹਾ_3 ਸੁਨੇਹਾ;
    WNDCLASS wc;
    HWND hwnd;

    p_ਖਿੜਕੀ_ਪਾਠ = lp_Cmd_ਸਤਰ[0] ? lp_Cmd_ਸਤਰ : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_ਸਮ੍ਰਿਤੀ(&wc, ਆਕਾਰ wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = ਲੱਦੋ_Icon(ਨਿਰਾ, IDI_APPLICATION);
    wc.hCursor       = ਲੱਦੋ_Cursor(ਨਿਰਾ, IDC_ARROW);

    ਜੇ (FALSE == ਰਜਿਸਟਰ_Class(&wc))
        ਵਾਪਸ 0;

    // create the browser
    hwnd = Create_ਖਿੜਕੀ(
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

    ਜੇ (ਨਿਰਾ == hwnd)
        ਵਾਪਸ 0;

    // Main message loop:
    ਜਦੋਂ (Get_ਸੁਨੇਹਾ(&ਸੁਨੇਹਾ, ਨਿਰਾ, 0, 0) > 0) {
        Translate_ਸੁਨੇਹਾ(&ਸੁਨੇਹਾ);
        Dispatch_ਸੁਨੇਹਾ(&ਸੁਨੇਹਾ);
    }

    ਵਾਪਸ ਸੁਨੇਹਾ.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

ਖਾਲੀ Center_ਖਿੜਕੀ(HWND hwnd_self)
{
    HWND hwnd_ਮਾਪਾ;
    RECT rw_self, rc_ਮਾਪਾ, rw_ਮਾਪਾ;
    ਪੂਰਨ xpos, ypos;

    hwnd_ਮਾਪਾ = Get_ਮਾਪਾ(hwnd_self);
    ਜੇ (ਨਿਰਾ == hwnd_ਮਾਪਾ)
        hwnd_ਮਾਪਾ = Get_Desktop_ਖਿੜਕੀ();

    Get_ਖਿੜਕੀ_Rect(hwnd_ਮਾਪਾ, &rw_ਮਾਪਾ);
    GetClientRect(hwnd_ਮਾਪਾ, &rc_ਮਾਪਾ);
    Get_ਖਿੜਕੀ_Rect(hwnd_self, &rw_self);

    xpos = rw_ਮਾਪਾ.ਖੱਬਾ + (rc_ਮਾਪਾ.ਸੱਜਾ + rw_self.ਖੱਬਾ - rw_self.ਸੱਜਾ) / 2;
    ypos = rw_ਮਾਪਾ.ਸਿਖਰ + (rc_ਮਾਪਾ.bottom + rw_self.ਸਿਖਰ - rw_self.bottom) / 2;

    ਸੈੱਟ_ਖਿੜਕੀ_Pos(
        hwnd_self, ਨਿਰਾ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
