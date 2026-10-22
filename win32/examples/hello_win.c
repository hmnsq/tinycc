//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#ضمن <windows.h>

#وصف_ڪريو APPNAME "HELLO_WIN"

حرف szAppName[] = APPNAME; // The name of this application
حرف szTitle[]   = APPNAME; // The title bar text
ثابت حرف *p_دري_متن;

فراغ Center_دري(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT پيغام, WPARAM wParam, LPARAM lParam)
{
    بدل (پيغام) {

        // ----------------------- first and last
        حالة WM_CREATE:
            Center_دري(hwnd);
            اكسر;

        حالة WM_DESTROY:
            Post_Quit_پيغام(0);
            اكسر;

        // ----------------------- get out of it...
        حالة WM_RBUTTONUP:
            Destroy_دري(hwnd);
            اكسر;

        حالة WM_KEYDOWN:
            إذا (VK_ESCAPE == wParam)
                Destroy_دري(hwnd);
            اكسر;

        // ----------------------- display our minimal info
        حالة WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            سيٽ_متن_Color(hdc, RGB(240,240,96));
            سيٽ_Bk_گهڻائي(hdc, TRANSPARENT);
            Draw_متن(hdc, p_دري_متن, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            پڇاڙي_Paint(hwnd, &ps);
            اكسر;
        }

        // ----------------------- let windows do all other stuff
        افتراضي:
            أرجع Def_دري_Proc(hwnd, پيغام, wParam, lParam);
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
        LPSTR lp_Cmd_سٽ,
        صحيح nCmdShow
        )
{
    نياپو_2 نياپو;
    WNDCLASS wc;
    HWND hwnd;

    p_دري_متن = lp_Cmd_سٽ[0] ? lp_Cmd_سٽ : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_يادگيري(&wc, حجم wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = ڀريو_Icon(عدم, IDI_APPLICATION);
    wc.hCursor       = ڀريو_Cursor(عدم, IDC_ARROW);

    إذا (FALSE == رجسٽر_Class(&wc))
        أرجع 0;

    // create the browser
    hwnd = Create_دري(
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
    طالما (Get_پيغام(&نياپو, عدم, 0, 0) > 0) {
        Translate_پيغام(&نياپو);
        Dispatch_پيغام(&نياپو);
    }

    أرجع نياپو.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

فراغ Center_دري(HWND hwnd_self)
{
    HWND hwnd_والد;
    RECT rw_self, rc_والد, rw_والد;
    صحيح xpos, ypos;

    hwnd_والد = Get_والد(hwnd_self);
    إذا (عدم == hwnd_والد)
        hwnd_والد = Get_Desktop_دري();

    Get_دري_Rect(hwnd_والد, &rw_والد);
    GetClientRect(hwnd_والد, &rc_والد);
    Get_دري_Rect(hwnd_self, &rw_self);

    xpos = rw_والد.کاٻو + (rc_والد.ساڄو + rw_self.کاٻو - rw_self.ساڄو) / 2;
    ypos = rw_والد.چوٽي + (rc_والد.bottom + rw_self.چوٽي - rw_self.bottom) / 2;

    سيٽ_دري_Pos(
        hwnd_self, عدم,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
