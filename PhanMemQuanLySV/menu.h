#pragma once
#include "DoHoa.h"
#include "list.h"
#include "M1_Them.h"
#include "M2_In.h"


using namespace std;

class menu
{
private:
	int choose1, choose2;
	char a;
public:
	void mainMenu(list *list);
	void addStudent(list*);
	void printList(list);
	void sort(list*);
	void search(list);
	void statistic(list);
};

// man hinh menu chinh
void menu::mainMenu(list *list)
{
	textcolor(7);
	choose1 = 1;
	system("cls");
	while (true)
	{
		textcolor(30);
		printLabel("PHAN MEM QUAN LY SINH VIEN", 47, 2);
		textcolor(26);
		box(40, 4, 80, 26);
		textcolor(3);
		printLabel("----MENU----", 55, 6);

		if (choose1 == 1) textcolor(31);
		else textcolor(6);
		printLabel("    THEM MOI HO SO    ", 50, 10);
		if (choose1 == 2) textcolor(31);
		else textcolor(6);
		printLabel("     IN DANH SACH     ", 50, 12);
		if (choose1 == 3) textcolor(31);
		else textcolor(6);
		printLabel("       SAP XEP        ", 50, 14);
		if (choose1 == 4) textcolor(31);
		else textcolor(6);
		printLabel("       TIM KIEM       ", 50, 16);
		if (choose1 == 5) textcolor(31);
		else textcolor(6);
		printLabel("       THONG KE       ", 50, 18);
		if (choose1 == 6) textcolor(31);
		else textcolor(6);
		printLabel("         EXIT        ", 50, 20);
		textcolor(7);
		printLabel("-----------------------------",46 , 23);
		printLabel("Truong Thi La_ CNTT1", 50, 24);

		// nhap ban phim de dieu khien
		a = _getch();
		if (a == 13) break;								// neu nhap "enter" -> vao muc duoc chon
		else if (a == 72 && choose1 > 1) choose1--;		// "len	"
		else if (a == 80 && choose1 < 6) choose1++;		// "xuong"
	}

	
	// choose1 goi ham tuong ung
	switch (choose1)
	{
	case 1:
		addStudent(list);
		break;
	case 2:
		printList(*list);
		break;
	case 3:
		sort(list);
		break;
	case 4:
		search(*list);
		break;
	case 5:
		statistic(*list);
		break;
	case 6:
		textcolor(4);
		printLabel("SEE YOU AGAIN !!!", 53, 28);
		textcolor(7);
		exit(0);
	}
}

// Ham them moi ho so
void menu::addStudent(list* list)
{
	system("cls");
	list->addStudent(); // goi ham "addStudent"
	mainMenu(list); // sau do tro ve Main Menu
}

// Ham in danh sach SV
void menu::printList(list list)
{
	int index = 0;
	system("cls");
	
	printLabel("Nhan --Enter-- de xoa hoac sua thong tin SV...", 1, 1);
	textcolor(3);
	printLabel("-----IN DANH SACH SINH VIEN-----", 45, 2);
	list.printList(false, index);   // M2
	mainMenu(&list);
}

// Ham ve menu Sap xep
void menu::sort(list* list)
{
	choose1 = 1;
	system("cls");
	while (true)
	{
		textcolor(3);
		printLabel("-----SAP XEP-----", 52, 5);

		textcolor(3);
		printLabel("CHON THUAT TOAN", 23, 7);
		if (choose1 == 1) textcolor(31);
		else textcolor(6);

		printLabel("    Selection Sort    ", 20, 11);
		if (choose1 == 2) textcolor(31);
		else textcolor(6);

		printLabel("    Insertion Sort    ", 20, 13);
		if (choose1 == 3) textcolor(31);
		else textcolor(6);

		printLabel("       QuickSort      ", 20, 15);
		if (choose1 == 4) textcolor(31);
		else textcolor(6);

		printLabel("      Merge Sort      ", 20, 17);

		a = _getch();
		if (a == 13) break;
		else if (a == 72 && choose1 > 1) choose1--;
		else if (a == 80 && choose1 < 4) choose1++;
	}

	choose2 = 1;
	while (true)
	{
		textcolor(3);
		printLabel("THEO TU KHOA", 85, 7);
		
		if (choose2 == 1) textcolor(31);
		else textcolor(6);

		printLabel("         Ma lop        ", 80, 11);
		if (choose2 == 2) textcolor(31);
		else textcolor(6);

		printLabel("     Ma sinh vien      ", 80, 13);
		if (choose2 == 3) textcolor(31);
		else textcolor(6);

		printLabel("       Ho va ten       ", 80, 15);
		if (choose2 == 4) textcolor(31);
		else textcolor(6);

		printLabel("       Ngay sinh       ", 80, 17);
		if (choose2 == 5) textcolor(31);
		else textcolor(6);

		printLabel("     DTB tich luy      ", 80, 19);
		if (choose2 == 6) textcolor(31);
		else textcolor(6);

		printLabel("         EXIT         ", 80, 21);

		a = _getch();
		if (a == 13) break;
		else if (a == 72 && choose2 > 1) choose2--;
		else if (a == 80 && choose2 < 6) choose2++;
	}

	if (choose2 == 6)
	{
		textcolor(7);
		mainMenu(list);
	}
	else
	{
	
	}
}

//Ve menu Tim Kiem
void menu::search(list list)
{
	choose1 = 1;
	system("cls");
	while (true)
	{
		textcolor(3);
		printLabel("----TIM KIEM----", 50, 5);

		textcolor(3);
		printLabel("THUAT TOAN TIM KIEM", 23, 7);
		if (choose1 == 1) textcolor(31);
		else textcolor(6);
		printLabel("     Tim kiem tuan tu     ", 20, 11);
		if (choose1 == 2) textcolor(31);
		else textcolor(6);
		printLabel("     Tim kiem nhi phan    ", 20, 13);
		a = _getch();
		if (a == 13) break;
		else if (a == 72 && choose1 > 1) choose1--;
		else if (a == 80 && choose1 < 2) choose1++;
	}

	choose2 = 1;
	while (true)
	{
		textcolor(3);
		printLabel("THEO TU KHOA", 85, 7);

		if (choose2 == 1) textcolor(31);
		else textcolor(6);

		printLabel("         Ma lop        ", 80, 11);
		if (choose2 == 2) textcolor(31);
		else textcolor(6);

		printLabel("     Ma sinh vien      ", 80, 13);
		if (choose2 == 3) textcolor(31);
		else textcolor(6);

		printLabel("       Ho va ten       ", 80, 15);
		if (choose2 == 4) textcolor(31);
		else textcolor(6);

		printLabel("       Ngay sinh       ", 80, 17);
		if (choose2 == 5) textcolor(31);
		else textcolor(6);

		printLabel("     DTB tich luy      ", 80, 19);
		if (choose2 == 6) textcolor(31);
		else textcolor(6);

		printLabel("         EXIT         ", 80, 21);

		a = _getch();
		if (a == 13) break;
		else if (a == 72 && choose2 > 1) choose2--;
		else if (a == 80 && choose2 < 6) choose2++;
	}

	if (choose2 == 6)
	{
		textcolor(7);
		mainMenu(&list);
	}
	else
	{
		system("cls");
		printLabel("TIM KIEM >> ", 20, 1);
		switch (choose1)
		{
		case 1:
			cout << "Tiem kiem tuan tu >> ";
			break;
		case 2:
			cout << "Tim kiem nhi phan >> ";
			break;
		}
		switch (choose2)
		{
		case 1:
			cout << "Ma lop >> ";
			break;
		case 2:
			cout << "Ma sinh vien >> ";
			break;
		case 3:
			cout << "Ho va ten >> ";
			break;
		case 4:
			cout << "Ngay sinh >> ";
			break;
		case 5:
			cout << "DTB tich luy >> ";
			break;
		}
		printLabel("Nhap tu khoa: ", 20, 2);
		/*list.search(choose1, choose2);
		mainMenu(&list);*/
	}
}

// ve menu thong ke
void menu::statistic(list list)
{
	textcolor(7);
	system("cls");
	textcolor(3);
	printLabel("-----THONG KE-----", 52, 3);
	//list.statistic();
	mainMenu(&list);
}
