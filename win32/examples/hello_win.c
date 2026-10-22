//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#شامل <windows.h>

#define APPNAME "HELLO_WIN"

نویسه szAppName[] = APPNAME; // The name of this application
نویسه szTitle[]   = APPNAME; // The title bar text
ثابت نویسه *pWindowText;

تهی CenterWindow(HWND hWnd);

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
    انتخاب (message) {

        // ----------------------- first and last
        حالت WM_CREATE:
            CenterWindow(hwnd);
            بشکن;

        حالت WM_DESTROY:
            PostQuitMessage(0);
            بشکن;

        // ----------------------- get out of it...
        حالت WM_RBUTTONUP:
            DestroyWindow(hwnd);
            بشکن;

        حالت WM_KEYDOWN:
            اگر (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            بشکن;

        // ----------------------- display our minimal info
        حالت WM_PAINT:
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
            بشکن;
        }

        // ----------------------- let windows do all other stuff
        پیشفرض:
            بازگشت DefWindowProc(hwnd, message, wParam, lParam);
    }
    بازگشت 0;
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
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_سطر,
        صحیح nCmdShow
        )
{
    پیام_2 پیام;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_سطر[0] ? lp_Cmd_سطر : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, اندازه wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(پوچ, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(پوچ, IDC_ARROW);

    اگر (FALSE == RegisterClass(&wc))
        بازگشت 0;

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

    اگر (پوچ == hwnd)
        بازگشت 0;

    // Main message loop:
    وقتی (GetMessage(&پیام, پوچ, 0, 0) > 0) {
        TranslateMessage(&پیام);
        DispatchMessage(&پیام);
    }

    بازگشت پیام.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

تهی CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    صحیح xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    اگر (پوچ == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.چپ + (rc_parent.راست + rw_self.چپ - rw_self.راست) / 2;
    ypos = rw_parent.بالاترین + (rc_parent.bottom + rw_self.بالاترین - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, پوچ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
