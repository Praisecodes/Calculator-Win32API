#ifndef UNICODE
#define UNICODE
#endif // UNICODE

#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;

//Main Window Procedure
LRESULT CALLBACK window(HWND, UINT, WPARAM, LPARAM);

//Functions for different windows in the program
void screen(HWND);
void buttons(HWND);

//character to display numbers to the screen
char out[1000];

//Window handlers for windows in the program
HWND one,two,three,four,five,six,seven,eight,nine,zero,plus,divide,minus,times,scr,clear,equal;

//Macros for buttons to function
#define btn_one 1
#define btn_two 2
#define btn_three 3
#define btn_four 4
#define btn_five 5
#define btn_six 6
#define btn_seven 7
#define btn_eight 8
#define btn_nine 9
#define btn_zero 10
#define btn_plus 11
#define btn_divide 12
#define btn_times 13
#define btn_minus 14
#define btn_clear 15
#define btn_equal 16

//Variable for checking operator(sign)
char sign;

//Variables for holding numbers
int firstSet = 0, Secondset = 0, Result = 0;

//Program main function where the window procedure is called
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR args, int nCmdShow)
{
	const wchar_t name[] = L"name";
	WNDCLASS wc = {};

	wc.hbrBackground = CreateSolidBrush(RGB(64, 64, 64));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hinst;
	wc.lpszClassName = name;
	wc.lpfnWndProc = window;

	RegisterClass(&wc);

	CreateWindowEx(0,
		name,
		L"Calculator",
		WS_VISIBLE | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 296, 400, NULL, NULL, hinst, NULL);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

//The window procedure which is called from the main function
LRESULT CALLBACK window(HWND hwnd, UINT mas, WPARAM wp, LPARAM lp)
{
	switch (mas)
	{
		//case to handle every command (that is every action carried out onButtonClick)
	case WM_COMMAND:
	{
		switch (wp)
		{
			//Case to handle when one is clicked
		case btn_one:
			{
				char one[] = "1";
				strcat_s(out,one);
				SetWindowTextA(scr, out);
			}
			break;
			//Case to handle when two is clicked
		case btn_two:
			{
				char one[] = "2";
				strcat_s(out, one);
				SetWindowTextA(scr, out);
			}
			break;
			//Case to handle when three is clicked
		case btn_three:
			{
				char one[] = "3";
				strcat_s(out, one);
				SetWindowTextA(scr, out);
			}
			break;
			//Case to handle when four is clicked
		case btn_four:
			{
				char one[] = "4";
				strcat_s(out, one);
				SetWindowTextA(scr, out);
			}
			break;
			//Case to handle when five is clicked
		case btn_five:
		{
			char one[] = "5";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when six is clicked
		case btn_six:
		{
			char one[] = "6";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when seven is clicked
		case btn_seven:
		{
			char one[] = "7";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when eight is clicked
		case btn_eight:
		{
			char one[] = "8";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when nine is clicked
		case btn_nine:
		{
			char one[] = "9";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when zero is clicked
		case btn_zero:
		{
			char const* one = "0";
			strcat_s(out, one);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the clear button(C) is clicked
		case btn_clear:
		{
			char clear[] = "";
			strcpy_s(out,clear);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the plus button(+) is clicked
		case btn_plus:
		{
			sign = '+';
			firstSet = stoi(out);
			char clear[] = "";
			strcpy_s(out, clear);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the minus button(-) is clicked
		case btn_minus:
		{
			sign = '-';
			firstSet = stoi(out);
			char clear[] = "";
			strcpy_s(out, clear);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the divide button(/) is clicked
		case btn_divide:
		{
			sign = '/';
			firstSet = stoi(out);
			char clear[] = "";
			strcpy_s(out, clear);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the multiplication button(X) is clicked
		case btn_times:
		{
			sign = '*';
			firstSet = stoi(out);
			char clear[] = "";
			strcpy_s(out, clear);
			SetWindowTextA(scr, out);
		}
		break;
		//Case to handle when the equal button(=) is clicked
		case btn_equal:
		{
			Secondset = stoi(out);
			char clear[] = "";
			//This statement is carried out when the plus button is clicked
			if (sign == '+')
			{
				Result = firstSet + Secondset;
				string show = to_string(Result);
				char const* chars = show.c_str();
				strcpy_s(out, chars);
				SetWindowTextA(scr, out);
			}
			//This statement is carried out when the minus button is clicked
			if (sign == '-')
			{
				Result = firstSet - Secondset;
				string show = to_string(Result);
				char const* chars = show.c_str();
				strcpy_s(out, chars);
				SetWindowTextA(scr, out);
			}
			//This statement is carried out when the multiplication button is clicked
			if (sign == '*')
			{
				Result = firstSet * Secondset;
				string show = to_string(Result);
				char const* chars = show.c_str();
				strcpy_s(out, chars);
				SetWindowTextA(scr, out);
			}
			//This statement is carried out when the division button is clicked
			if (sign == '/')
			{
				//This statement is carried out whenever the division by zero is tried
				if (Secondset == 0)
				{
					MessageBox(NULL, L"ERROR: Cannot divide by zero", L"ERROR: ZERO DIVISION", MB_OK);
					strcpy_s(out, clear);
					SetWindowTextA(scr, out);
				}
				else {
					Result = firstSet / Secondset;
					string show = to_string(Result);
					char const* chars = show.c_str();
					strcpy_s(out, chars);
					SetWindowTextA(scr, out);
				}
			}
		}
		}
		break;
	}
	//Case to handle the creation of the controls on the GUI
	case WM_CREATE:
		screen(hwnd);
		buttons(hwnd);
		break;
	//Case to handle the destruction(that is, closing) of the GUI
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, mas, wp, lp);
	}
	return 0;
}

//Function called in the window procedure to help create the static control(screen) on the GUI
void screen(HWND srn_handler)
{
	scr = CreateWindowEx(0,L"STATIC", NULL, WS_CHILDWINDOW|WS_VISIBLE|WS_BORDER|SS_RIGHT,0,0,280,42,srn_handler,NULL,NULL,NULL);
}

//Function called in the window procedure to help create the buttons on the GUI
void buttons(HWND btn_handler)
{
	//Buttons for 1, 2, 3, +
	one = CreateWindowEx(0, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 42, 70, 80, btn_handler, (HMENU)btn_one, NULL, NULL);
	two = CreateWindowEx(0, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 42, 70, 80, btn_handler, (HMENU)btn_two, NULL, NULL);
	three = CreateWindowEx(0, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 42, 70, 80, btn_handler, (HMENU)btn_three, NULL, NULL);
	CreateWindowEx(0, L"BUTTON", L"+", WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 42, 70, 80, btn_handler, (HMENU)btn_plus, NULL, NULL);
	//Buttons for 4, 5, 6, -
	four = CreateWindowEx(0, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 122, 70, 80, btn_handler, (HMENU)btn_four, NULL, NULL);
	five = CreateWindowEx(0, L"BUTTON", L"5", WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 122, 70, 80, btn_handler, (HMENU)btn_five, NULL, NULL);
	six = CreateWindowEx(0, L"BUTTON", L"6", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 122, 70, 80, btn_handler, (HMENU)btn_six, NULL, NULL);
	CreateWindowEx(0, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 122, 70, 80, btn_handler, (HMENU)btn_minus, NULL, NULL);
	//Buttons for 7, 8, 9, X
	seven = CreateWindowEx(0, L"BUTTON", L"7", WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 202, 70, 80, btn_handler, (HMENU)btn_seven, NULL, NULL);
	eight = CreateWindowEx(0, L"BUTTON", L"8", WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 202, 70, 80, btn_handler, (HMENU)btn_eight, NULL, NULL);
	nine = CreateWindowEx(0, L"BUTTON", L"9", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 202, 70, 80, btn_handler, (HMENU)btn_nine, NULL, NULL);
	times = CreateWindowEx(0, L"BUTTON", L"X", WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 202, 70, 80, btn_handler, (HMENU)btn_times, NULL, NULL);
	//Buttons for C, 0, =, /.
	clear = CreateWindowEx(0, L"BUTTON", L"C", WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 282, 70, 80, btn_handler, (HMENU)btn_clear, NULL, NULL);
	zero = CreateWindowEx(0, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 282, 70, 80, btn_handler, (HMENU)btn_zero, NULL, NULL);
	CreateWindowEx(0, L"BUTTON", L"=", WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 282, 70, 80, btn_handler, (HMENU)btn_equal, NULL, NULL);
	divide = CreateWindowEx(0, L"BUTTON", L"/", WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 282, 70, 80, btn_handler, (HMENU)btn_divide, NULL, NULL);
}
