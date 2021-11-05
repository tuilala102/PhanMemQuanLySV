#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


// ==================================== COPY ====================================

// Ham ngan k cho thay doi man hinh console bang chuot
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
// Ham thay doi kich co khung cmd
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Ham tat con tro
void noCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Ham bat con tro
void cursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Ham dich chuyen con tro den toa do (x,y)
void gotoxy(SHORT x, SHORT y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Ham xoa man hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}



// ==================================== BY MYSELF ====================================

// Ham in ra chuoi tai vi tri (x,y)
void printLabel(string a, int x, int y)
{
	gotoxy(x, y);
	cout << a;
}

// ve duong thang don tu (x1,y1) den (x2,y2)
void singleLine(int x1, int y1, int x2, int y2)
{
	// duong nam ngang
	if (y1 == y2)
	{
		gotoxy(x1, y1);
		for (int i = x1; i <= x2; ++i)
			cout << (char)196;
	}

	// duong thang dung
	if (x1 == x2)
		for (int i = y1; i <= y2; ++i)
		{
			gotoxy(x1, i);
			cout << (char)179;
		}
}

// ve duong thang kep tu (x1,y1) den (x2,y2)
void doubleLine(int x1, int y1, int x2, int y2)
{
	// duong nam ngang
	if (y1 == y2)
	{
		gotoxy(x1, y1);
		for (int i = x1; i <= x2; ++i)
			cout << (char)205;
	}

	// duong thang dung
	if (x1 == x2)
		for (int i = y1; i <= y2; ++i)
		{
			gotoxy(x1, i);
			cout << (char)186;
		}
}

// ve bang in danh sach SV
void tableof_MenuIn()
{
	textcolor(9);
	DisableResizeWindow();

	// ve 4 vien ngoai
	doubleLine(11, 3, 110, 3);
	doubleLine(11, 3, 11, 27);
	doubleLine(11, 27, 110, 27);
	doubleLine(110, 3, 110, 27);

	// ve cac duong chia cot
	singleLine(17, 3, 17, 27);
	singleLine(32, 3, 32, 27);
	singleLine(65, 3, 65, 27);
	singleLine(82, 3, 82, 27);
	singleLine(100, 3, 100, 27);

	// ve cac duong chia hang
	for (int i = 7; i <= 25; i += 2)
	{
		singleLine(11, i, 110, i);
	}

	// hoan thanh 4 goc bang
	gotoxy(11, 3); cout << (char)201;
	gotoxy(11, 27); cout << (char)200;
	gotoxy(110, 3); cout << (char)187;
	gotoxy(110, 27); cout << (char)188;

	// hoan thanh cac diem cua vien 
		// vien ngang
	gotoxy(17, 3); cout << (char)209;
	gotoxy(32, 3); cout << (char)209;
	gotoxy(65, 3); cout << (char)209;
	gotoxy(82, 3); cout << (char)209;
	gotoxy(100, 3); cout << (char)209;
	gotoxy(17, 27); cout << (char)207;
	gotoxy(32, 27); cout << (char)207;
	gotoxy(65, 27); cout << (char)207;
	gotoxy(82, 27); cout << (char)207;
	gotoxy(100, 27); cout << (char)207;

		// vien doc
	for (int i = 7; i <= 25; i += 2)
	{
		gotoxy(11, i); cout << (char)199;
		gotoxy(110, i); cout << (char)182;
	}

	// hoan thanh cac giao diem 
	for (int i = 7; i <= 25; i += 2)
	{
		gotoxy(17, i); cout << (char)197;
		gotoxy(32, i); cout << (char)197;
		gotoxy(65, i); cout << (char)197;
		gotoxy(82, i); cout << (char)197;
		gotoxy(100, i); cout << (char)197;
	}

	textcolor(14);
	printLabel("STT", 13, 5);
	printLabel("Ma Sinh Vien", 20, 5);
	printLabel("Ho Ten", 47, 5);
	printLabel("Ma Lop", 70, 5);
	printLabel("Ngay Sinh", 85, 5);
	printLabel("DTB ", 103, 5);

	textcolor(7);
	printLabel("Page ", 57, 28);
	cout << endl << endl;  
}

//ve hcn tu (x1,y1) den (x2,y2)
void box(int x1, int y1, int x2, int y2)
{
	singleLine(x1, y1, x2, y1);
	singleLine(x1, y2, x2, y2);
	singleLine(x1, y1, x1, y2);
	singleLine(x2, y1, x2, y2);

	gotoxy(x1, y1); cout << (char)218;
	gotoxy(x2, y2); cout << (char)217;
	gotoxy(x2, y1); cout << (char)191;
	gotoxy(x1, y2); cout << (char)192;
}

// cho phep nhap 1 chuoi vao mang, toi da size ki tu
bool enterKey(char s[], int size)
{
	for (int i = 0; i <= size; ++i)
		s[i] = '\0';
	char a;
	int index = 0;
	while (true)
	{
		a = _getch();

		if (a == 13)        // 13 = CR- phim Enter
			break;
		else if (a == 27)  //  27 = ESC- EXIT
			return false;
		else if (a == 8 && index == 0); // 8= BS- Backspace - Xoa nguoc
		else if (a == 8 && index > 0)
		{
			index--;
			s[index] = '\0';
			cout << "\b \b";
		}
		else
		{
			if (index < size)
			{
				s[index] = a;
				cout << (char)a;
				index++;
			}

		}
	}
	return true;
}

// nhap password tai vi tri (x,y)
void enterPass(char pass[], int x, int y)
{
	gotoxy(x, y);
	int i = 0;
	char a;

	while (true)
	{ 
		a = _getch();  // neu "enter", thi ket thuc
		if (a == 13)
			break;
		else if (a == 8 && i >= 1) // neu "backspace", thi xoa ki tu cuoi
			{
				i--;
				printLabel(" ", x + i, y);
				gotoxy(x + i, y);
			}
			else if (a == 8 && i == 0);
				else
				{
					pass[i] = a;
					cout << "*";
					i++;
				}
	}
	pass[i] = '\0'; // end
}

// ve man hinh them moi ho so
void Menu_Them()
{
	DisableResizeWindow();
	textcolor(46);
	box(15, 3, 105, 27);
	textcolor(3);
	printLabel("----THEM MOI HO SO----", 50, 5);

	textcolor(7);
	printLabel("Ma lop: ", 30, 8);
	box(60, 7, 93, 9);

	printLabel("Ma sinh vien (8 ky tu): ", 30, 11);
	box(60, 10, 93, 12);

	printLabel("Name: ", 30, 14);
	box(60, 13, 93, 15);

	printLabel("Ngay sinh (dd/mm/yyyy): ", 30, 17);
	box(60, 16, 93, 18);

	printLabel("DTB tich luy: ", 30, 20);
	box(60, 19, 93, 21);
}
