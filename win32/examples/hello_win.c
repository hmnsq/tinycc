//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ضمن <windows.h>

#تعریف_کړه APPNAME "HELLO_WIN"

حرف szAppName[] = APPNAME; // The name of this application
حرف szTitle[]   = APPNAME; // The title bar text
ثابت حرف *p_کړکۍ_متن;

فراغ Center_کړکۍ(HWND hWnd);

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
    بدل (پیغام_2) {

        // ----------------------- first and last
        حالة WM_CREATE:
            Center_کړکۍ(hwnd);
            اكسر;

        حالة WM_DESTROY:
            Post_Quit_پیغام(0);
            اكسر;

        // ----------------------- get out of it...
        حالة WM_RBUTTONUP:
            Destroy_کړکۍ(hwnd);
            اكسر;

        حالة WM_KEYDOWN:
            إذا (VK_ESCAPE == wParam)
                Destroy_کړکۍ(hwnd);
            اكسر;

        // ----------------------- display our minimal info
        حالة WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            سېټ_متن_Color(hdc, RGB(240,240,96));
            سېټ_Bk_ډېرپېښ(hdc, TRANSPARENT);
            Draw_متن(hdc, p_کړکۍ_متن, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            پای_ټکی_Paint(hwnd, &ps);
            اكسر;
        }

        // ----------------------- let windows do all other stuff
        افتراضي:
            أرجع Def_کړکۍ_Proc(hwnd, پیغام_2, wParam, lParam);
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
        LPSTR lp_Cmd_کرښه,
        صحيح nCmdShow
        )
{
    پیغام_3 پیغام;
    WNDCLASS wc;
    HWND hwnd;

    p_کړکۍ_متن = lp_Cmd_کرښه[0] ? lp_Cmd_کرښه : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_حافظه(&wc, حجم wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = بارول_Icon(عدم, IDI_APPLICATION);
    wc.hCursor       = بارول_Cursor(عدم, IDC_ARROW);

    إذا (FALSE == ثبتوونکی_Class(&wc))
        أرجع 0;

    // create the browser
    hwnd = Create_کړکۍ(
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
    طالما (Get_پیغام(&پیغام, عدم, 0, 0) > 0) {
        Translate_پیغام(&پیغام);
        Dispatch_پیغام(&پیغام);
    }

    أرجع پیغام.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

فراغ Center_کړکۍ(HWND hwnd_self)
{
    HWND hwnd_پلار;
    RECT rw_self, rc_پلار, rw_پلار;
    صحيح xpos, ypos;

    hwnd_پلار = Get_پلار(hwnd_self);
    إذا (عدم == hwnd_پلار)
        hwnd_پلار = Get_Desktop_کړکۍ();

    Get_کړکۍ_Rect(hwnd_پلار, &rw_پلار);
    GetClientRect(hwnd_پلار, &rc_پلار);
    Get_کړکۍ_Rect(hwnd_self, &rw_self);

    xpos = rw_پلار.کیڼ + (rc_پلار.ښی + rw_self.کیڼ - rw_self.ښی) / 2;
    ypos = rw_پلار.سر + (rc_پلار.bottom + rw_self.سر - rw_self.bottom) / 2;

    سېټ_کړکۍ_Pos(
        hwnd_self, عدم,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
