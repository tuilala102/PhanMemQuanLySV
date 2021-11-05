#pragma once
#pragma once
#include "M1_Them.h"

void list::editProfile(int index)
{
	textcolor(7);
	gotoxy(1, 3); 
	textcolor(3);
	printLabel("------SUA------", 50, 4);

	// print student's profile before edit
	textcolor(6);
	printLabel("STT", 13, 6);
	printLabel("Ma sinh vien", 20, 6);
	printLabel("Ho va ten", 47, 6);
	printLabel("Ma lop", 70, 6);
	printLabel("Ngay sinh", 85, 6);

	printLabel("DTB tich luy", 103, 6);
	studentList[index].display(0, false);
	gotoxy(14, 8); cout << index + 1;
	// print Name to center
	printLabel("                                    ", 34, 8);
	char* nametmp = new char[31];
	nametmp = studentList[index].getName().getFullName();
	gotoxy(49 - (strlen(nametmp) / 2), 8); cout << nametmp;

	// draw label and box allow user input student's profile
	textcolor(7);
	printLabel("Ma lop: ", 30, 11);
	box(60, 10, 93, 12);
	printLabel("Ma sinh vien (8 characters): ", 30, 14);
	box(60, 13, 93, 15);
	printLabel("Ho va ten: ", 30, 17);
	box(60, 16, 93, 18);
	printLabel("Ngay sinh (dd/mm/yyyy): ", 30, 20);
	box(60, 19, 93, 21);
	printLabel("DTB tich luy: ", 30, 23);
	box(60, 22, 93, 24);

	cursorType();

	char a;
	char* classID, * studentID, * datetmp, * scoretmp;
	date dateOfBirth;
	nameType Name;
	float score = 0;

	// input Ma lop until it's true
	classID = new char[10];
	while (true)
	{
		fflush(stdin);
		gotoxy(62, 11);
		if (enterKey(classID, 8))
		{
			if (strcmp(classID, "") == 0)
				break;
			else if (checkClassID(classID))
			{
				printLabel(classID, 62, 11);
				break;
			}
			// if classID is false, notify it's false
			else
			{
				textcolor(4);
				printLabel("Ma lop : CNTT1, CNTT2, BDATTT, ANHTTT, DTH", 35, 27);
				textcolor(7);
				printLabel("                              ", 62, 11);
			}
		}
		else return;
	}
	printLabel("                                                    ", 35, 27);

	// input studentID until it's true
	studentID = new char[10];
	while (true)
	{
		gotoxy(62, 14);
		if (enterKey(studentID, 10))
		{
			if (strcmp(studentID, "") == 0)
				break;
			else if (checkStudentID(studentID))
			{
				printLabel(studentID, 62, 14);
				break;
			}
			// if false, notify
			else
			{
				textcolor(4);
				printLabel("Ma sinh vien gom 8 ki tu. Va no la duy nhat!", 40, 27);

				textcolor(7);
				printLabel("                              ", 62, 14);
			}
		}
		else return;
	}
	printLabel("                                         ", 40, 27);

	// input Name, and auto format
	while (true)
	{
		gotoxy(62, 17);
		if (enterKey(nametmp, 30))
		{
			if (strcmp(nametmp, "") == 0)
				break;
			else if (Name.convertToName(nametmp))
			{
				printLabel("                               ", 62, 17);
				gotoxy(62, 17); cout << Name.getFullName();
				break;
			}
			// if Name has character special, notify and reenter
			else
			{
				textcolor(4);
				printLabel("Ho ten khong chua ki tu dac biet!", 47, 27);
				textcolor(7);
				printLabel("                               ", 62, 17);
			}
		}
		else return;
	}
	printLabel("                                       ", 47, 27);

	// input date of birth until it's true
	datetmp = new char[11];
	while (true)
	{
		gotoxy(62, 20);
		if (enterKey(datetmp, 10))
		{
			if (strcmp(datetmp, "") == 0)
				break;
			else if (dateOfBirth.convertToDate(datetmp)) break;
			else
			{
				textcolor(4);
				printLabel("Ngay sinh co dang: dd/mm/yyyy", 44, 27);
				textcolor(7);
				printLabel("                              ", 62, 20);
			}
		}
		else return;
	}
	printLabel("                                 ", 44, 27);

	scoretmp = new char[5];
	// input score until it's true
	while (true)
	{
		for (int i = 0; i < 5; ++i)
			scoretmp[i] = '\0';
		gotoxy(62, 23);
		if (enterKey(scoretmp, 4))
		{
			int dem = 0;
			bool acheck = true;
			for (int i = 0; i < (int)strlen(scoretmp); i++)
			{
				if ((scoretmp[i] < '0' || scoretmp[i] > '9') && scoretmp[i] != '.')
					acheck = false;
				if (scoretmp[i] == '.')
					dem++;
			}
			// nếu đúng đinh dạng thì chuyển scoretmp sang score float
			if (acheck == true && dem < 2)
			{
				score = convertToFloat(scoretmp);
			}
			// nếu có kí tự đặc biệt, hoặc có nhiều hơn 1 dấu chấm thì bắt nhập lại
			else
			{
				textcolor(4);
				printLabel("DTB khong chua ki tu dac biet!", 41, 27);
				textcolor(7);
				printLabel("                              ", 62, 23);
				continue;
			}

			if (score >= 0 && score <= 10) break;
			else
			{
				textcolor(4);
				printLabel(" DTB la so thuc tu 0 den 10! ", 45, 27);
				textcolor(7);
				printLabel("                              ", 62, 23);
			}
		}

		else return;

	}
	printLabel("                                ", 45, 27);

	// after input is done, select "save" button or "exit" button
	noCursorType();
	int choose = 1;
	while (true)
	{
		if (choose == 1)
			textcolor(64);
		else
			textcolor(7);
		box(35, 26, 48, 28);
		gotoxy(36, 27); cout << "    SAVE    ";

		if (choose == 2)
			textcolor(64);
		else
			textcolor(7);
		box(72, 26, 85, 28);
		gotoxy(73, 27); cout << "    EXIT    ";

		// input only arrow key and enter
		while (true)
		{
			a = _getch();
			if (a == -32 || a == 13)
				break;
		}
		// if it's arrow key, move button selected
		if (a == -32)
		{
			a = _getch();
			if (a == 75 && choose > 1)
				choose--;
			if (a == 77 && choose < 2)
				choose++;
		}
		// if it's enter, break
		else
			break;
	}

	// if select save, request enter password
	if (choose == 1)
	{
		// draw box allow enter pass
		textcolor(7);
		box(30, 10, 90, 20);
		for (int i = 11; i < 20; ++i)
		{
			gotoxy(31, i);
			cout << "                                                           ";
		}
		box(45, 14, 75, 16);
		textcolor(9);
		printLabel("PASSWORD:", 56, 12);
		char* pass = new char[30];
		// enter pass until entered cancel or pass correct
		while (true)
		{
			enterPass(pass, 47, 15);
			if (strcmp(pass, password) == 0)
			{
				printLabel("               ", 40, 18);
				break;
			}
			else if (strcmp(pass, "cancel") == 0)
			{
				printLabel("               ", 40, 18);
				break;
			}
			else
			{
				printLabel("                            ", 47, 15);
				textcolor(4);
				printLabel("Password wrong!", 53, 18);
				textcolor(7);
			}
		}
		// if pass correct, update student's profile and list to file
		if (strcmp(pass, password) == 0)
		{
			if (strcmp(classID, "") != 0)
				studentList[index].setClassID(classID);
			if (strcmp(studentID, "") != 0)
				studentList[index].setStudentID(studentID);
			if (strcmp(nametmp, "") != 0)
				studentList[index].setName(Name);
			if (strcmp(datetmp, "") != 0)
				studentList[index].setDateOfBirth(dateOfBirth);
			if ((int)strlen(scoretmp) != 0)
				studentList[index].setScore(score);
			outputToFile(); // cap nhat lai fife
			textcolor(12);
			printLabel("----SUCCESSFUL----", 51, 18);
			Sleep(1500);
		}
	}
	textcolor(7);
	gotoxy(1, 3); //cout << clearScreen;
}
