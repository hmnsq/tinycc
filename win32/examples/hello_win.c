//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#అన్తర్భావ <windows.h>

#నిర్వచించు APPNAME "HELLO_WIN"

అక్షరం szAppName[] = APPNAME; // The name of this application
అక్షరం szTitle[]   = APPNAME; // The title bar text
స్థిరరాశి అక్షరం *p_కిటికీ_పాఠ్యం;

శూన్య Center_కిటికీ(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT సందేశం_2, WPARAM wParam, LPARAM lParam)
{
    ఎంపిక (సందేశం_2) {

        // ----------------------- first and last
        స్థితి WM_CREATE:
            Center_కిటికీ(hwnd);
            ఆపు;

        స్థితి WM_DESTROY:
            Post_Quit_సందేశం(0);
            ఆపు;

        // ----------------------- get out of it...
        స్థితి WM_RBUTTONUP:
            Destroy_కిటికీ(hwnd);
            ఆపు;

        స్థితి WM_KEYDOWN:
            ఒకవేళ (VK_ESCAPE == wParam)
                Destroy_కిటికీ(hwnd);
            ఆపు;

        // ----------------------- display our minimal info
        స్థితి WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            సమితి_పాఠ్యం_Color(hdc, RGB(240,240,96));
            సమితి_Bk_బహుళకం(hdc, TRANSPARENT);
            Draw_పాఠ్యం(hdc, p_కిటికీ_పాఠ్యం, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            చివర_Paint(hwnd, &ps);
            ఆపు;
        }

        // ----------------------- let windows do all other stuff
        అప్రమేయ:
            తిరిగి Def_కిటికీ_Proc(hwnd, సందేశం_2, wParam, lParam);
    }
    తిరిగి 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint for GUI Win32 apps
//
//----------------------------------------------------------------------------
పూర్ణాంకం APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lp_Cmd_పంక్తి,
        పూర్ణాంకం nCmdShow
        )
{
    సందేశం_3 సందేశం;
    WNDCLASS wc;
    HWND hwnd;

    p_కిటికీ_పాఠ్యం = lp_Cmd_పంక్తి[0] ? lp_Cmd_పంక్తి : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    Zero_జ్ఞాపకం(&wc, పరిమాణం wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = ఎక్కించు_Icon(ఖాళీ, IDI_APPLICATION);
    wc.hCursor       = ఎక్కించు_Cursor(ఖాళీ, IDC_ARROW);

    ఒకవేళ (FALSE == రిజిస్టరు_Class(&wc))
        తిరిగి 0;

    // create the browser
    hwnd = Create_కిటికీ(
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

    ఒకవేళ (ఖాళీ == hwnd)
        తిరిగి 0;

    // Main message loop:
    అయితే (Get_సందేశం(&సందేశం, ఖాళీ, 0, 0) > 0) {
        Translate_సందేశం(&సందేశం);
        Dispatch_సందేశం(&సందేశం);
    }

    తిరిగి సందేశం.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

శూన్య Center_కిటికీ(HWND hwnd_self)
{
    HWND hwnd_మాతృ;
    RECT rw_self, rc_మాతృ, rw_మాతృ;
    పూర్ణాంకం xpos, ypos;

    hwnd_మాతృ = Get_మాతృ(hwnd_self);
    ఒకవేళ (ఖాళీ == hwnd_మాతృ)
        hwnd_మాతృ = Get_Desktop_కిటికీ();

    Get_కిటికీ_Rect(hwnd_మాతృ, &rw_మాతృ);
    GetClientRect(hwnd_మాతృ, &rc_మాతృ);
    Get_కిటికీ_Rect(hwnd_self, &rw_self);

    xpos = rw_మాతృ.ఎడమ + (rc_మాతృ.కుడి + rw_self.ఎడమ - rw_self.కుడి) / 2;
    ypos = rw_మాతృ.శిఖరం + (rc_మాతృ.bottom + rw_self.శిఖరం - rw_self.bottom) / 2;

    సమితి_కిటికీ_Pos(
        hwnd_self, ఖాళీ,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
