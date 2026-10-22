//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ضمن <windows.h>

#تعریف_کرو APPNAME "HELLO_WIN"

حرف szAppName[] = APPNAME; // The name of this application
حرف szTitle[]   = APPNAME; // The title bar text
ثابت حرف *p_کھڑکی_متن;

فراغ Center_کھڑکی(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT سنیہا, WPARAM wParam, LPARAM lParam)
{
    بدل (سنیہا) {

        // ----------------------- first and last
        حالة WM_CREATE:
            Center_کھڑکی(hwnd);
            اكسر;

        حالة WM_DESTROY:
            Post_Quit_سنیہا(0);
            اكسر;

        // ----------------------- get out of it...
        حالة WM_RBUTTONUP:
            Destroy_کھڑکی(hwnd);
            اكسر;

        حالة WM_KEYDOWN:
            إذا (VK_ESCAPE == wParam)
                Destroy_کھڑکی(hwnd);
            اكسر;

        // ----------------------- display our minimal info
        حالة WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            سیٹ_متن_Color(hdc, RGB(240,240,96));
            سیٹ_Bk_منوال(hdc, TRANSPARENT);
            Draw_متن(hdc, p_کھڑکی_متن, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            سرا_Paint(hwnd, &ps);
            اكسر;
        }

        // ----------------------- let windows do all other stuff
        افتراضي:
            أرجع Def_کھڑکی_Proc(hwnd, سنیہا, wParam, lParam);
    }
    أرجع 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
صحيح APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_سطر,
        صحيح nCmdShow
        )
{
    پیغام_2 پیغام;
    WNDCLASS wc;
    HWND hwnd;

    p_کھڑکی_متن = lp_Cmd_سطر[0] ? lp_Cmd_سطر : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_حافظہ(&wc, حجم wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = لدو_Icon(عدم, IDI_APPLICATION);
    wc.hCursor       = لدو_Cursor(عدم, IDC_ARROW);

    إذا (FALSE == رجسٹر_Class(&wc))
        أرجع 0;

    // create the browser
    hwnd = Create_کھڑکی(
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

    إذا (عدم == hwnd)
        أرجع 0;

    // Main message loop:
    طالما (Get_سنیہا(&پیغام, عدم, 0, 0) > 0) {
        Translate_سنیہا(&پیغام);
        Dispatch_سنیہا(&پیغام);
    }

    أرجع پیغام.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

فراغ Center_کھڑکی(HWND hwnd_self)
{
    HWND hwnd_ماپا;
    RECT rw_self, rc_ماپا, rw_ماپا;
    صحيح xpos, ypos;

    hwnd_ماپا = Get_ماپا(hwnd_self);
    إذا (عدم == hwnd_ماپا)
        hwnd_ماپا = Get_Desktop_کھڑکی();

    Get_کھڑکی_Rect(hwnd_ماپا, &rw_ماپا);
    GetClientRect(hwnd_ماپا, &rc_ماپا);
    Get_کھڑکی_Rect(hwnd_self, &rw_self);

    xpos = rw_ماپا.بایاں + (rc_ماپا.دایاں + rw_self.بایاں - rw_self.دایاں) / 2;
    ypos = rw_ماپا.چوٹی + (rc_ماپا.bottom + rw_self.چوٹی - rw_self.bottom) / 2;

    سیٹ_کھڑکی_Pos(
        hwnd_self, عدم,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
