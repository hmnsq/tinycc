//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ضمن <windows.h>

#تعریف_کن APPNAME "HELLO_WIN"

حرف szAppName[] = APPNAME; // The name of this application
حرف szTitle[]   = APPNAME; // The title bar text
ثابت حرف *p_پنجره_متن;

فراغ Center_پنجره(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT پیام_2, WPARAM wParam, LPARAM lParam)
{
    بدل (پیام_2) {

        // ----------------------- first and last
        حالة WM_CREATE:
            Center_پنجره(hwnd);
            اكسر;

        حالة WM_DESTROY:
            Post_Quit_پیام(0);
            اكسر;

        // ----------------------- get out of it...
        حالة WM_RBUTTONUP:
            Destroy_پنجره(hwnd);
            اكسر;

        حالة WM_KEYDOWN:
            إذا (VK_ESCAPE == wParam)
                Destroy_پنجره(hwnd);
            اكسر;

        // ----------------------- display our minimal info
        حالة WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            مجموعه_متن_Color(hdc, RGB(240,240,96));
            مجموعه_Bk_نما(hdc, TRANSPARENT);
            Draw_متن(hdc, p_پنجره_متن, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            انتها_Paint(hwnd, &ps);
            اكسر;
        }

        // ----------------------- let windows do all other stuff
        افتراضي:
            أرجع Def_پنجره_Proc(hwnd, پیام_2, wParam, lParam);
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
    پیام_3 پیام;
    WNDCLASS wc;
    HWND hwnd;

    p_پنجره_متن = lp_Cmd_سطر[0] ? lp_Cmd_سطر : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_حافظه(&wc, حجم wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = بارگیری_Icon(عدم, IDI_APPLICATION);
    wc.hCursor       = بارگیری_Cursor(عدم, IDC_ARROW);

    إذا (FALSE == ثبات_Class(&wc))
        أرجع 0;

    // create the browser
    hwnd = Create_پنجره(
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
    طالما (Get_پیام(&پیام, عدم, 0, 0) > 0) {
        Translate_پیام(&پیام);
        Dispatch_پیام(&پیام);
    }

    أرجع پیام.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

فراغ Center_پنجره(HWND hwnd_self)
{
    HWND hwnd_والد;
    RECT rw_self, rc_والد, rw_والد;
    صحيح xpos, ypos;

    hwnd_والد = Get_والد(hwnd_self);
    إذا (عدم == hwnd_والد)
        hwnd_والد = Get_Desktop_پنجره();

    Get_پنجره_Rect(hwnd_والد, &rw_والد);
    GetClientRect(hwnd_والد, &rc_والد);
    Get_پنجره_Rect(hwnd_self, &rw_self);

    xpos = rw_والد.چپ + (rc_والد.راست + rw_self.چپ - rw_self.راست) / 2;
    ypos = rw_والد.بالاترین + (rc_والد.bottom + rw_self.بالاترین - rw_self.bottom) / 2;

    مجموعه_پنجره_Pos(
        hwnd_self, عدم,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
