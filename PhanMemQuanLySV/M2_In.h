#pragma once
#include "list.h"
#include "M2_Sua.h"
#include "M2_Xoa.h"
#include <iostream>

void list::delOrEdit(int index)
{
	char a;
	int choose = 1;

	// tao box cho phep NSD chon Xoa hoac Sua hoac Exit
	textcolor(16);
	box(30, 10, 90, 20);
	for (int i = 11; i < 20; i++)
	{
		gotoxy(31, i);
		//cout<<"
	}
	printLabel("Nhap lua chon ?", 40, 13);
	while (true)
	{
		if (choose == 1)
			textcolor(64);
		else
			textcolor(16);
		box(35, 16, 48, 18);
		gotoxy(36, 17); cout << "   Xoa   ";

		if (choose == 2)
			textcolor(64);
		else
			textcolor(16);
		box(53, 16, 66, 18);
		gotoxy(54, 17); cout << "    Sua    ";

		if (choose == 3)
			textcolor(64);
		else
			textcolor(16);
		box(71, 16, 84, 18);
		gotoxy(72, 17); cout << "    EXIT    ";

		// cho phep nhap phim mui ten va phim --Enter--
		while (true)
		{
			a = _getch();
			if (a == -32 || a == 13)
				break;
		}

		// neu nhap phim mui ten
		if (a == -32)
		{
			a = _getch();
			if (a == 75 && choose > 1)
				choose--;
			if (a == 77 && choose < 3)
				choose++;
		}
		// neu nhap --Enter--, EXIT va goi ham Xoa hoac Sua hoac In ra danh sach
		else
			break;
	}
	if (choose == 1)
		deleteStudent(index);
	else if (choose == 2)
		editProfile(index);
	else
		return;
}

int list::printList(bool check, int& index)
{
	char a;
	int page = 1;
	index = 0;

	//in 1 trang = 10 sinh vien

	while (true)
	{
		int count = studentList.size();
		// ve bang
		textcolor(7); gotoxy(1, 3);
		tableof_MenuIn();

		// in thong tin SV ra bang
		for (int i = (page - 1) * 10; i < count && i < page * 10; i++)
		{
			if (i == index)
				studentList[i].display(i, true);
			else
				studentList[i].display(i, false);
		}

		// in trang tiep theo hoac trang truoc    //eg:  "<- Trang 2/10 ->"
		gotoxy(62, 28); cout << page << "/" << ceil((float)count / 10);
		if (page < ceil((float)count / 10)) cout << " ->";
		if (page != 1)
			printLabel("<-", 54, 28);

		
		if (check == false)   // in Danh sach SV ko sd ham Search
		{
			cout << endl << "Nhan --Esc-- de ve Main Menu...";
			while (true)
			{
				a = _getch();

				// neu nhan Esc
				if (a == 27)
					return a;
				// nhan Enter de xoa hoac sua
				else if (a == 13)
				{
					delOrEdit(index);
					break;
				}
				// neu nhan "<-", quay lai trang truoc 
				else if ((a == 75) && page > 1)
				{
					page--;
					index = (page - 1) * 10;
					break;
				}
				// nhan mui ten len
				else if (a == 72)
				{
					if (index == 0)
						continue;
					else if (index == (page - 1) * 10)
					{
						page--;
						index--;
						break;
					}
					else
					{
						studentList[index].display(index, false);
						index--;
						studentList[index].display(index, true);
					}
				}
				// neu nhan "->", den trang tiep theo
				else if ((a == 77) && page < ceil((float)count / 10))
				{
					page++;
					index = (page - 1) * 10;
					break;
				}
				// nhan mui ten xuong 
				else if (a == 80)
				{
					if (index == count - 1)
						continue;
					else if (index == page * 10 - 1)
					{
						page++;
						index++;
						break;
					}
					else
					{
						studentList[index].display(index, false);
						index++;
						studentList[index].display(index, true);
					}
				}
			}
		}

		
		else  // in Danh sach SV sd ham Search
		{
			noCursorType();
			printLabel("Nhan --Esc-- de quay lai Main Menu", 1, 29);
			gotoxy(38, 2);
			while (true)
			{
				a = _getch();
				
				if (a == -32)
				{
					a = _getch();
					// "<-" trang truoc
					if ((a == 75) && page > 1)
					{
						page--;
						index = (page - 1) * 10;
						break;
					}
					// mui ten len
					else if (a == 72)
					{
						if (index == 0)
							continue;
						else if (index == (page - 1) * 10)
						{
							index--;
							page--;
							break;
						}
						else
						{
							studentList[index].display(index, false);
							index--;
							studentList[index].display(index, true);
						}
					}
					// "->" trang tiep theo
					else if ((a == 77) && page < ceil((float)count / 10))
					{
						page++;
						index = (page - 1) * 10;
						break;
					}
					// mui ten xuong
					else if (a == 80)
					{
						if (index == count - 1)
							continue;
						else if (index == page * 10 - 1)
						{
							index++;
							page++;
							break;
						}
						else
						{
							studentList[index].display(index, false);
							index++;
							studentList[index].display(index, true);
						}
					}
				}
				// phim khac
				else if (a == 27 || a == 8 || a == ' ' || a == 13) return a;
				else if (a >= 46 && a <= 57) return a;
				else if (a >= 65 && a <= 90) return a;
				else if (a >= 97 && a <= 122) return a;
			}
		}
	}
	return a;
}
	
