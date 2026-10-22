//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#अन्तर्भाव <windows.h>

#define APPNAME "HELLO_WIN"

वर्ण szAppName[] = APPNAME; // The name of this application
वर्ण szTitle[]   = APPNAME; // The title bar text
ध्रुव वर्ण *pWindowText;

शून्य CenterWindow(HWND hWnd);

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
    विकल्प (message) {

        // ----------------------- first and last
        पक्ष WM_CREATE:
            CenterWindow(hwnd);
            भङ्ग;

        पक्ष WM_DESTROY:
            PostQuitMessage(0);
            भङ्ग;

        // ----------------------- get out of it...
        पक्ष WM_RBUTTONUP:
            DestroyWindow(hwnd);
            भङ्ग;

        पक्ष WM_KEYDOWN:
            जइ (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            भङ्ग;

        // ----------------------- display our minimal info
        पक्ष WM_PAINT:
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
            भङ्ग;
        }

        // ----------------------- let windows do all other stuff
        स्वभाव:
            प्रत्यागम DefWindowProc(hwnd, message, wParam, lParam);
    }
    प्रत्यागम 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
पूर्णाङ्क APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_पङ्क्तिः,
        पूर्णाङ्क nCmdShow
        )
{
    सन्देशः_2 सन्देशः;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_पङ्क्तिः[0] ? lp_Cmd_पङ्क्तिः : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, परिमाण wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(रिक्त, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(रिक्त, IDC_ARROW);

    जइ (FALSE == RegisterClass(&wc))
        प्रत्यागम 0;

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

    जइ (रिक्त == hwnd)
        प्रत्यागम 0;

    // Main message loop:
    जाव (GetMessage(&सन्देशः, रिक्त, 0, 0) > 0) {
        TranslateMessage(&सन्देशः);
        DispatchMessage(&सन्देशः);
    }

    प्रत्यागम सन्देशः.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

शून्य CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    पूर्णाङ्क xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    जइ (रिक्त == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.वामः + (rc_parent.दक्षिणः + rw_self.वामः - rw_self.दक्षिणः) / 2;
    ypos = rw_parent.शिखरम् + (rc_parent.bottom + rw_self.शिखरम् - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, रिक्त,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
