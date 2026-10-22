//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#समावेश <windows.h>

#घोषणा APPNAME "HELLO_WIN"

अक्षर szAppName[] = APPNAME; // The name of this application
अक्षर szTitle[]   = APPNAME; // The title bar text
स्थिर अक्षर *pWindowText;

व्योम CenterWindow(HWND hWnd);

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
    चयन (message) {

        // ----------------------- first and last
        हाल WM_CREATE:
            CenterWindow(hwnd);
            अवरोध;

        हाल WM_DESTROY:
            PostQuitMessage(0);
            अवरोध;

        // ----------------------- get out of it...
        हाल WM_RBUTTONUP:
            DestroyWindow(hwnd);
            अवरोध;

        हाल WM_KEYDOWN:
            अगर (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            अवरोध;

        // ----------------------- display our minimal info
        हाल WM_PAINT:
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
            अवरोध;
        }

        // ----------------------- let windows do all other stuff
        शेष:
            वापस DefWindowProc(hwnd, message, wParam, lParam);
    }
    वापस 0;
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
        HINSTANCE h_पूर्व_Instance,
        LPSTR lp_Cmd_पंक्ति,
        पूर्णांक nCmdShow
        )
{
    संदेश_2 संदेश;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lp_Cmd_पंक्ति[0] ? lp_Cmd_पंक्ति : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, माप wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(शून्य, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(शून्य, IDC_ARROW);

    अगर (FALSE == RegisterClass(&wc))
        वापस 0;

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

    अगर (शून्य == hwnd)
        वापस 0;

    // Main message loop:
    जबतक (GetMessage(&संदेश, शून्य, 0, 0) > 0) {
        TranslateMessage(&संदेश);
        DispatchMessage(&संदेश);
    }

    वापस संदेश.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

व्योम CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    पूर्णांक xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    अगर (शून्य == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.बायाँ + (rc_parent.दायाँ + rw_self.बायाँ - rw_self.दायाँ) / 2;
    ypos = rw_parent.शीर्ष + (rc_parent.bottom + rw_self.शीर्ष - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, शून्य,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
