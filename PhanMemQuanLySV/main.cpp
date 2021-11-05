#include <time.h>
#include <ctype.h>
#include "list.h"
#include "menu.h"

using namespace std;

// Account = Password = "admin" 
 
bool logIn()
{
	DisableResizeWindow();
	textcolor(7);
	system("cls");
	textcolor(102); //mau vang
	box(29, 4, 91, 22);

	textcolor(9);
	printLabel("LOG IN", 55, 7);
	textcolor(7);
	printLabel("Account*:", 40, 11);
	printLabel("Password*: ", 40, 15);

	textcolor(112);
	printLabel("                             ", 51, 10);
	printLabel("                             ", 51, 11);
	printLabel("                             ", 51, 12);
	printLabel("                             ", 51, 14);
	printLabel("                             ", 51, 15);
	printLabel("                             ", 51, 16);

	// nhap account, password
	char acc[30], pass[30];

	gotoxy(52, 11);
	if (enterKey(acc, 30))
	{
		enterPass(pass, 52, 15);
	}

	if (strcmp(acc, account) == 0 && strcmp(pass, password) == 0) return true;
	else return false;
}
int main()
{
	/*while (!logIn())
	{
		textcolor(7);
		system("cls");
		textcolor(4);
		printLabel("Account and passwork are incorrect!", 40, 15);
	}*/
	list list;
	list.inputFromFile();
	menu menu;
	noCursorType();
	menu.mainMenu(&list);

	return 0;
}
