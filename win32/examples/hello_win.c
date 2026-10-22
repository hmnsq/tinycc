//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#অন্তর্ভাৱ <windows.h>

#define APPNAME "HELLO_WIN"

ৱর্ণ szAppName[] = APPNAME; // The name of this application
ৱর্ণ szTitle[]   = APPNAME; // The title bar text
ধ্রুৱ ৱর্ণ *pWindowText;

শূন্য CenterWindow(HWND hWnd);

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
    ৱিকল্প (message) {

        // ----------------------- first and last
        পক্ষ WM_CREATE:
            CenterWindow(hwnd);
            ভঙ্গ;

        পক্ষ WM_DESTROY:
            PostQuitMessage(0);
            ভঙ্গ;

        // ----------------------- get out of it...
        পক্ষ WM_RBUTTONUP:
            DestroyWindow(hwnd);
            ভঙ্গ;

        পক্ষ WM_KEYDOWN:
            যদি (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            ভঙ্গ;

        // ----------------------- display our minimal info
        পক্ষ WM_PAINT:
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
            ভঙ্গ;
        }

        // ----------------------- let windows do all other stuff
        স্ৱভাৱ:
            ঘূৰাই DefWindowProc(hwnd, message, wParam, lParam);
    }
    ঘূৰাই 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
পূর্ণাঙ্ক APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_সাৰি,
        পূর্ণাঙ্ক nCmdShow
        )
{
    বাৰ্তা_2 বাৰ্তা;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_সাৰি[0] ? lp_Cmd_সাৰি : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, পরিমাণ wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(রিক্ত, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(রিক্ত, IDC_ARROW);

    যদি (FALSE == RegisterClass(&wc))
        ঘূৰাই 0;

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

    যদি (রিক্ত == hwnd)
        ঘূৰাই 0;

    // Main message loop:
    যেতিয়ালৈ (GetMessage(&বাৰ্তা, রিক্ত, 0, 0) > 0) {
        TranslateMessage(&বাৰ্তা);
        DispatchMessage(&বাৰ্তা);
    }

    ঘূৰাই বাৰ্তা.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

শূন্য CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    পূর্ণাঙ্ক xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    যদি (রিক্ত == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.বাম + (rc_parent.ডান + rw_self.বাম - rw_self.ডান) / 2;
    ypos = rw_parent.শীৰ্ষ + (rc_parent.bottom + rw_self.শীৰ্ষ - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, রিক্ত,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
