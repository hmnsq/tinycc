//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#அந்தர்பாவ <windows.h>

#define APPNAME "HELLO_WIN"

எழுத்து szAppName[] = APPNAME; // The name of this application
எழுத்து szTitle[]   = APPNAME; // The title bar text
மாறிலி எழுத்து *pWindowText;

வெறுமை CenterWindow(HWND hWnd);

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
    தேர்வு (message) {

        // ----------------------- first and last
        நிலை WM_CREATE:
            CenterWindow(hwnd);
            நிறுத்து;

        நிலை WM_DESTROY:
            PostQuitMessage(0);
            நிறுத்து;

        // ----------------------- get out of it...
        நிலை WM_RBUTTONUP:
            DestroyWindow(hwnd);
            நிறுத்து;

        நிலை WM_KEYDOWN:
            எனில் (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            நிறுத்து;

        // ----------------------- display our minimal info
        நிலை WM_PAINT:
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
            நிறுத்து;
        }

        // ----------------------- let windows do all other stuff
        இயல்பு:
            திரும்பு DefWindowProc(hwnd, message, wParam, lParam);
    }
    திரும்பு 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
முழு APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_வரி,
        முழு nCmdShow
        )
{
    செய்தி_2 செய்தி;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_வரி[0] ? lp_Cmd_வரி : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, அளவு wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(வெற்று, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(வெற்று, IDC_ARROW);

    எனில் (FALSE == RegisterClass(&wc))
        திரும்பு 0;

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

    எனில் (வெற்று == hwnd)
        திரும்பு 0;

    // Main message loop:
    போது (GetMessage(&செய்தி, வெற்று, 0, 0) > 0) {
        TranslateMessage(&செய்தி);
        DispatchMessage(&செய்தி);
    }

    திரும்பு செய்தி.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

வெறுமை CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    முழு xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    எனில் (வெற்று == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.இடது + (rc_parent.வலது + rw_self.இடது - rw_self.வலது) / 2;
    ypos = rw_parent.உச்சி + (rc_parent.bottom + rw_self.உச்சி - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, வெற்று,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
