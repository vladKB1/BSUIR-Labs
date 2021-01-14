// ProjectWinAPI.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ProjectWinAPI.h"
#include "vector"

#define MAX_LOADSTRING 100

#define CLEAR_BUTTON 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define BLACK 6
#define WHITE 7

using namespace std;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

struct Obj {
    POINT fi;
    POINT se; 
    int color;
    int width;
};

vector<Obj> objects;
int penColor = RGB(0, 0, 0);
int penWidth = 3;



// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECTWINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECTWINAPI));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECTWINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECTWINAPI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   HMENU menu = GetMenu(hWnd);
   AppendMenu(menu, MF_ENABLED, CLEAR_BUTTON, L"Clear");
   
   HMENU menuWidth = CreatePopupMenu();
   AppendMenu(menuWidth, MF_ENABLED, 11, L"1");
   AppendMenu(menuWidth, MF_ENABLED, 12, L"2");
   AppendMenu(menuWidth, MF_ENABLED, 13, L"3");
   AppendMenu(menuWidth, MF_ENABLED, 14, L"4");
   AppendMenu(menuWidth, MF_ENABLED, 15, L"5");
   AppendMenu(menuWidth, MF_ENABLED, 16, L"6");   
   AppendMenu(menu, MF_POPUP | MF_STRING, (UINT)menuWidth, L"Width");

   HMENU menuColor = CreatePopupMenu();
   AppendMenu(menuColor, MF_ENABLED, RED, L"Red");
   AppendMenu(menuColor, MF_ENABLED, GREEN, L"Green");
   AppendMenu(menuColor, MF_ENABLED, BLUE, L"Blue");
   AppendMenu(menuColor, MF_ENABLED, YELLOW, L"Yellow");
   AppendMenu(menuColor, MF_ENABLED, BLACK, L"Black");
   AppendMenu(menuColor, MF_ENABLED, WHITE, L"White");
   AppendMenu(menu, MF_POPUP | MF_STRING, (UINT)menuColor, L"Color"); 

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC hdc;
    static HPEN Pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    static BOOL fDraw = FALSE;    

    switch (message)
    {
        case WM_COMMAND: {
            int wmId = LOWORD(wParam);          

            switch (wmId)
            {
                case CLEAR_BUTTON:
                    objects.clear();
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;


                case 11:
                    penWidth = 1;
                    break;
                case 12:
                    penWidth = 2;
                    break;
                case 13:
                    penWidth = 3;
                    break;
                case 14:
                    penWidth = 4;
                    break;
                case 15:
                    penWidth = 5;
                    break;
                case 16:
                    penWidth = 6;
                    break;


                case RED:
                    penColor = RGB(255, 0, 0);
                    break;
                case GREEN:
                    penColor = RGB(0, 255, 0);
                    break;
                case BLUE:
                    penColor = RGB(0, 0, 255);
                    break;
                case YELLOW:
                    penColor = RGB(255, 255, 0);
                    break;
                case BLACK:
                    penColor = RGB(0, 0, 0);
                    break;
                case WHITE:
                    penColor = RGB(255, 255, 255);
                    break;


                case IDM_ABOUT:
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                case IDM_EXIT:
                    DestroyWindow(hWnd);
                    break;
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
        }
       
        case WM_LBUTTONDOWN: {
            fDraw = TRUE;
            Obj line;
            line.fi = { LOWORD(lParam), HIWORD(lParam) };   
            line.width = penWidth;
            line.color = penColor;            
            objects.push_back(line);
            break;
        }      

        case WM_LBUTTONUP: {
            if (fDraw)
            {              
                int last = objects.size() - 1;
                objects[last].se = { LOWORD(lParam), HIWORD(lParam) };    
                
                InvalidateRect(hWnd, NULL, TRUE);               
            }
            fDraw = FALSE;
            break;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            for (int i = 0; i < objects.size(); i++) { 
                HPEN pen = CreatePen(PS_SOLID, objects[i].width, objects[i].color);
                HGDIOBJ last = SelectObject(hdc, pen);
               
                MoveToEx(hdc, objects[i].fi.x, objects[i].fi.y, NULL);
                LineTo(hdc, objects[i].se.x, objects[i].se.y);

                SelectObject(hdc, last);  
                DeleteObject(pen);
            }

            EndPaint(hWnd, &ps);
            break;
        }

        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }        

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}