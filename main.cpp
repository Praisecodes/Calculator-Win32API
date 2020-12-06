#ifndef UNICODE
#define UNICODE
#endif // UNICODE

#include <windows.h>
#include <stdlib.h>
#include <string>
using namespace std;

/****************************************************************
*Macros Declared for the functions of the buttons in the program*
****************************************************************/
#define button_one 1
#define button_two 2
#define button_three 3
#define button_four 4
#define button_five 5
#define button_six 6
#define button_seven 7
#define button_eight 8
#define button_nine 9
#define button_zero 10
#define button_divide 11
#define button_times 12
#define button_plus 13
#define button_minus 14
#define button_equal 15
#define button_clear 16
///End of macro declaration.

LRESULT CALLBACK wind(HWND,UINT,WPARAM,LPARAM);
void screen(HWND);

///Window handlers for the controls used in the program
HWND display,button1,button2,button3,button4,button5,button6,button7,button8,button9,button0,scrren;

char out[1000];
int firstSet,secondSet,Result;
int sign;

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR arg, int ncmdshow)
{
    const wchar_t name[] = L"praise";

    WNDCLASS wc = {};
    wc.hbrBackground = CreateSolidBrush(RGB(50,50,50));
    wc.hInstance = hinst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = name;
    wc.lpfnWndProc = wind;

    RegisterClass(&wc);

    CreateWindowEx(0,name, L"Calculator v1.0",WS_MINIMIZEBOX|WS_VISIBLE|WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,250,350,NULL,
                   NULL,hinst,NULL);

    MSG mas = {};

    while(GetMessage(&mas,NULL,0,0))
    {
        TranslateMessage(&mas);
        DispatchMessage(&mas);
    }
    return 0;
}

LRESULT CALLBACK wind(HWND hwnd,UINT mag,WPARAM wp,LPARAM lp)
{
    switch(mag)
    {
    case WM_CREATE:
        /*********************
        For calculator screen*
        *********************/
        screen(hwnd);
        /*********************************************
        *These buttons for the numbers 1, 2, 3 and +.*
        *********************************************/
        button1 = CreateWindowEx(0,L"BUTTON",L"1",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,0,42,61,70,hwnd,(HMENU)button_one,NULL,NULL);
        button2 = CreateWindowEx(0,L"BUTTON",L"2",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,61,42,61,70,hwnd,(HMENU)button_two,NULL,NULL);
        button3 = CreateWindowEx(0,L"BUTTON",L"3",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,122,42,61,70,hwnd,(HMENU)button_three,NULL,NULL);
        CreateWindowEx(0,L"BUTTON",L"+",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,183,42,61,70,hwnd,(HMENU)button_plus,NULL,NULL);
        /*********************************************
        *These buttons for the numbers 4, 5, 6 and -.*
        *********************************************/
        button4 = CreateWindowEx(0,L"BUTTON",L"4",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,0,112,61,70,hwnd,(HMENU)button_four,NULL,NULL);
        button5 = CreateWindowEx(0,L"BUTTON",L"5",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,61,112,61,70,hwnd,(HMENU)button_five,NULL,NULL);
        button6 = CreateWindowEx(0,L"BUTTON",L"6",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,122,112,61,70,hwnd,(HMENU)button_six,NULL,NULL);
        CreateWindowEx(0,L"BUTTON",L"-",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,183,112,61,70,hwnd,(HMENU)button_minus,NULL,NULL);
        /*********************************************
        *These buttons for the numbers 7, 8, 9 and X.*
        *********************************************/
        button7 = CreateWindowEx(0,L"BUTTON",L"7",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,0,182,61,70,hwnd,(HMENU)button_seven,NULL,NULL);
        button8 = CreateWindowEx(0,L"BUTTON",L"8",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,61,182,61,70,hwnd,(HMENU)button_eight,NULL,NULL);
        button9 = CreateWindowEx(0,L"BUTTON",L"9",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,122,182,61,70,hwnd,(HMENU)button_nine,NULL,NULL);
        CreateWindowEx(0,L"BUTTON",L"X",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,183,182,61,70,hwnd,(HMENU)button_times,NULL,NULL);
        /*****************************************
        *These buttons for these:- C, 0, = and /.*
        *****************************************/
        CreateWindowEx(0,L"BUTTON",L"C",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,0,252,61,70,hwnd,(HMENU)button_clear,NULL,NULL);
        button0 = CreateWindowEx(0,L"BUTTON",L"0",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,61,252,61,70,hwnd,(HMENU)button_zero,NULL,NULL);
        CreateWindowEx(0,L"BUTTON",L"=",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,122,252,61,70,hwnd,(HMENU)button_equal,NULL,NULL);
        CreateWindowEx(0,L"BUTTON",L"/",WS_CHILD|WS_VISIBLE|BS_SOLID|BS_FLAT,183,252,61,70,hwnd,(HMENU)button_divide,NULL,NULL);
        break;
        case WM_COMMAND:
        switch(wp)
        {
            /*********************************************************
            *case to handle the command passed to the number 1 button*
            *********************************************************/
        case button_one:
            {
                char one[] = "1";
                strcat(out,one);
                SetWindowTextA(scrren,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 2 button*
            *********************************************************/
        case button_two:
            {
                char one[30];
                GetWindowTextA(button2,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 3 button*
            *********************************************************/
        case button_three:
            {
                char one[30];
                GetWindowTextA(button3,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 4 button*
            *********************************************************/
            case button_four:
            {
                char one[30];
                GetWindowTextA(button4,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 5 button*
            *********************************************************/
            case button_five:
            {
                char one[30];
                GetWindowTextA(button5,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 6 button*
            *********************************************************/
            case button_six:
            {
                char one[30];
                GetWindowTextA(button6,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 7 button*
            *********************************************************/
            case button_seven:
            {
                char one[30];
                GetWindowTextA(button7,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 8 button*
            *********************************************************/
            case button_eight:
            {
                char one[30];
                GetWindowTextA(button8,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 9 button*
            *********************************************************/
            case button_nine:
            {
                char one[30];
                GetWindowTextA(button9,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /*********************************************************
            *case to handle the command passed to the number 0 button*
            *********************************************************/
            case button_zero:
            {
                char one[30];
                GetWindowTextA(button0,one,30);
                strcat(out,one);
                SetWindowTextA(display,out);
            }
            break;
            /********************************
            *case to handle the clear button*
            ********************************/
            case button_clear:
            {
                char clewa[] = "";
                strcpy(out,clewa);
                screen(hwnd);
                SetWindowTextA(scrren,out);
            }
            break;
            /*******************************
            *case to handle the plus button*
            *******************************/
            case button_plus:
                {
                    char clewa[] = "";
                    sign = 1;
                    firstSet = stoi(out);
                    strcpy(out,clewa);
                    SetWindowTextA(scrren,out);
                }
                break;
            /********************************
            *case to handle the minus button*
            ********************************/
            case button_minus:
                {
                    char clewa[] = "";
                    sign = 2;
                    firstSet = stoi(out);
                    strcpy(out,clewa);
                    SetWindowTextA(scrren,out);
                }
                break;
            /*********************************
            *case to handle the divide button*
            *********************************/
            case button_divide:
                {
                    char clewa[] = "";
                    sign = 3;
                    firstSet = stoi(out);
                    strcpy(out,clewa);
                    SetWindowTextA(scrren,out);
                }
                break;
            /********************************
            *case to handle the times button*
            ********************************/
            case button_times:
                {
                    char clewa[] = "";
                    sign = 4;
                    firstSet = stoi(out);
                    strcpy(out,clewa);
                    SetWindowTextA(scrren,out);
                }
                break;
        }
        return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd,mag,wp,lp);
    }
    return 0;
}

void screen(HWND scrr)
{
    /****************************************************
    *For the calculator screen or rather static control.*
    ****************************************************/
    scrren = display = CreateWindowEx(0,L"STATIC",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|SS_RIGHT,0,0,244,42,scrr,NULL,NULL,NULL);
}
