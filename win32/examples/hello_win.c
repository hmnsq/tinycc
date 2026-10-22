//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#अन्तर्भाव <windows.h>

#define APPNAME "HELLO_WIN"

अक्षर szAppName[] = APPNAME; // The name of this application
अक्षर szTitle[]   = APPNAME; // The title bar text
स्थिरांक अक्षर *pWindowText;

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
    निवड (message) {

        // ----------------------- first and last
        स्थिती WM_CREATE:
            CenterWindow(hwnd);
            थांबा;

        स्थिती WM_DESTROY:
            PostQuitMessage(0);
            थांबा;

        // ----------------------- get out of it...
        स्थिती WM_RBUTTONUP:
            DestroyWindow(hwnd);
            थांबा;

        स्थिती WM_KEYDOWN:
            जर (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            थांबा;

        // ----------------------- display our minimal info
        स्थिती WM_PAINT:
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
            थांबा;
        }

        // ----------------------- let windows do all other stuff
        पूर्वनिर्धारित:
            परत DefWindowProc(hwnd, message, wParam, lParam);
    }
    परत 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
पूर्णांक APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_ओळ,
        पूर्णांक nCmdShow
        )
{
    संदेश_2 संदेश;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_ओळ[0] ? lp_Cmd_ओळ : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, आकार wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(रिक्त, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(रिक्त, IDC_ARROW);

    जर (FALSE == RegisterClass(&wc))
        परत 0;

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

    जर (रिक्त == hwnd)
        परत 0;

    // Main message loop:
    पर्यंत (GetMessage(&संदेश, रिक्त, 0, 0) > 0) {
        TranslateMessage(&संदेश);
        DispatchMessage(&संदेश);
    }

    परत संदेश.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

शून्य CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    पूर्णांक xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    जर (रिक्त == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.डावा + (rc_parent.उजवा + rw_self.डावा - rw_self.उजवा) / 2;
    ypos = rw_parent.शीर्ष + (rc_parent.bottom + rw_self.शीर्ष - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, रिक्त,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
