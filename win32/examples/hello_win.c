//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#अन्तर्भाव <windows.h>

#परिभाषय APPNAME "HELLO_WIN"

वर्ण szAppName[] = APPNAME; // The name of this application
वर्ण szTitle[]   = APPNAME; // The title bar text
ध्रुव वर्ण *p_गवाक्षः_Text;

शून्य Center_गवाक्षः(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT सन्देशः_2, WPARAM wParam, LPARAM lParam)
{
    विकल्प (सन्देशः_2) {

        // ----------------------- first and last
        पक्ष WM_CREATE:
            Center_गवाक्षः(hwnd);
            भङ्ग;

        पक्ष WM_DESTROY:
            Post_Quit_सन्देशः(0);
            भङ्ग;

        // ----------------------- get out of it...
        पक्ष WM_RBUTTONUP:
            Destroy_गवाक्षः(hwnd);
            भङ्ग;

        पक्ष WM_KEYDOWN:
            यदि (VK_ESCAPE == wParam)
                Destroy_गवाक्षः(hwnd);
            भङ्ग;

        // ----------------------- display our minimal info
        पक्ष WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            समुच्चयः_Text_Color(hdc, RGB(240,240,96));
            समुच्चयः_Bk_बहुलकम्(hdc, TRANSPARENT);
            DrawText(hdc, p_गवाक्षः_Text, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            अन्तः_Paint(hwnd, &ps);
            भङ्ग;
        }

        // ----------------------- let windows do all other stuff
        स्वभाव:
            प्रत्यागम Def_गवाक्षः_Proc(hwnd, सन्देशः_2, wParam, lParam);
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
        HINSTANCE h_पूर्व_Instance,
        LPSTR lp_Cmd_पङ्क्तिः,
        पूर्णाङ्क nCmdShow
        )
{
    सन्देशः_3 सन्देशः;
    WNDCLASS wc;
    HWND hwnd;

    p_गवाक्षः_Text = lp_Cmd_पङ्क्तिः[0] ? lp_Cmd_पङ्क्तिः : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_स्मृतिः(&wc, परिमाण wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = आरोपय_Icon(रिक्त, IDI_APPLICATION);
    wc.hCursor       = आरोपय_Cursor(रिक्त, IDC_ARROW);

    यदि (FALSE == पञ्जिकाकोशः_Class(&wc))
        प्रत्यागम 0;

    // create the browser
    hwnd = Create_गवाक्षः(
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

    यदि (रिक्त == hwnd)
        प्रत्यागम 0;

    // Main message loop:
    यावत् (Get_सन्देशः(&सन्देशः, रिक्त, 0, 0) > 0) {
        Translate_सन्देशः(&सन्देशः);
        Dispatch_सन्देशः(&सन्देशः);
    }

    प्रत्यागम सन्देशः.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

शून्य Center_गवाक्षः(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    पूर्णाङ्क xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    यदि (रिक्त == hwnd_parent)
        hwnd_parent = Get_Desktop_गवाक्षः();

    Get_गवाक्षः_Rect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    Get_गवाक्षः_Rect(hwnd_self, &rw_self);

    xpos = rw_parent.वामः + (rc_parent.दक्षिणः + rw_self.वामः - rw_self.दक्षिणः) / 2;
    ypos = rw_parent.शिखरम् + (rc_parent.bottom + rw_self.शिखरम् - rw_self.bottom) / 2;

    समुच्चयः_गवाक्षः_Pos(
        hwnd_self, रिक्त,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
