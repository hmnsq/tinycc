//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#شامل <windows.h>

#تعریف_کرو APPNAME "HELLO_WIN"

حرف szAppName[] = APPNAME; // The name of this application
حرف szTitle[]   = APPNAME; // The title bar text
ثابت حرف *p_کھڑکی_متن;

خالی Center_کھڑکی(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT پیغام_2, WPARAM wParam, LPARAM lParam)
{
    انتخاب (پیغام_2) {

        // ----------------------- first and last
        حالت WM_CREATE:
            Center_کھڑکی(hwnd);
            توڑو;

        حالت WM_DESTROY:
            Post_Quit_پیغام(0);
            توڑو;

        // ----------------------- get out of it...
        حالت WM_RBUTTONUP:
            Destroy_کھڑکی(hwnd);
            توڑو;

        حالت WM_KEYDOWN:
            اگر (VK_ESCAPE == wParam)
                Destroy_کھڑکی(hwnd);
            توڑو;

        // ----------------------- display our minimal info
        حالت WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            سیٹ_متن_Color(hdc, RGB(240,240,96));
            سیٹ_Bk_منوال(hdc, TRANSPARENT);
            Draw_متن(hdc, p_کھڑکی_متن, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            انتہا_Paint(hwnd, &ps);
            توڑو;
        }

        // ----------------------- let windows do all other stuff
        طےشدہ:
            واپس Def_کھڑکی_Proc(hwnd, پیغام_2, wParam, lParam);
    }
    واپس 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
صحیح APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE h_پچھلا_Instance,
        LPSTR lp_Cmd_سطر,
        صحیح nCmdShow
        )
{
    پیغام_3 پیغام;
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
    wc.hIcon         = بھرو_Icon(تہی, IDI_APPLICATION);
    wc.hCursor       = بھرو_Cursor(تہی, IDC_ARROW);

    اگر (FALSE == رجسٹر_Class(&wc))
        واپس 0;

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

    اگر (تہی == hwnd)
        واپس 0;

    // Main message loop:
    جب (Get_پیغام(&پیغام, تہی, 0, 0) > 0) {
        Translate_پیغام(&پیغام);
        Dispatch_پیغام(&پیغام);
    }

    واپس پیغام.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

خالی Center_کھڑکی(HWND hwnd_self)
{
    HWND hwnd_والد;
    RECT rw_self, rc_والد, rw_والد;
    صحیح xpos, ypos;

    hwnd_والد = Get_والد(hwnd_self);
    اگر (تہی == hwnd_والد)
        hwnd_والد = Get_Desktop_کھڑکی();

    Get_کھڑکی_Rect(hwnd_والد, &rw_والد);
    GetClientRect(hwnd_والد, &rc_والد);
    Get_کھڑکی_Rect(hwnd_self, &rw_self);

    xpos = rw_والد.بایاں + (rc_والد.دایاں + rw_self.بایاں - rw_self.دایاں) / 2;
    ypos = rw_والد.چوٹی + (rc_والد.bottom + rw_self.چوٹی - rw_self.bottom) / 2;

    سیٹ_کھڑکی_Pos(
        hwnd_self, تہی,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
