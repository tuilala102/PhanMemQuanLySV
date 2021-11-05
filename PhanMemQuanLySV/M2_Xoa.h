
#pragma once
#include "list.h"

void list::deleteStudent(int index)
{
	cursorType();
	char a;
	student st = studentList[index];
	textcolor(7);

	// clear screen
	gotoxy(1, 3);

	textcolor(3);
	printLabel("------XOA------", 49, 4);

	// kiem tra lai, co muon xoa hay ko?
	textcolor(7);
	printLabel("Kiem tra lai:", 30, 6);
	printLabel("Ho va ten:           ", 50, 7); cout << st.getName().getFullName();
	printLabel("Ngay sinh:     ", 50, 10); st.getDateOfBirth().display();
	printLabel("Ma sinh vien:        ", 50, 13); cout << st.getStudentID();
	printLabel("Ma lop:          ", 50, 16); cout << st.getClassID();
	printLabel("DIB tich luy:             ", 50, 19); cout << st.getScore();
	printLabel("Continue? (y/n) >> ", 30, 22);

	// yes or no
	while (true)
	{
		a = _getch();
		if (a == 'y' || a == 'n')
			break;
	}
	cout << a;

	// neu tra loi "no"
	if (a == 'n')
	{
		textcolor(12);
		printLabel("----CANCELED----", 54, 26);
		cout << endl << endl;
		textcolor(7);	
	}

	// neu tra loi "yes"
	else
	{
		printLabel("Enter your password: ", 30, 24);
		char* pass = new char[30];
		while (true)
		{
			enterPass(pass, 50, 24);
			if (strcmp(pass, password) == 0)
			{
				printLabel("               ", 40, 26);
				break;
			}
			else if (strcmp(pass, "cancel") == 0)
			{
				printLabel("               ", 40, 26);
				break;
			}
			// notify wrong if password wrong
			else
			{
				printLabel("                              ", 50, 24);
				textcolor(4);
				printLabel("password wrong!", 40, 26);
				textcolor(7);
			}
		}

		// if pass correct-> delete and update list to file
		if (strcmp(pass, password) == 0)
		{
			studentList.erase(studentList.begin() + index);		// delete from list
			outputToFile(); // cap nhat lai file
			textcolor(12);
			printLabel("----SUCCESSFUL----", 54, 26);
			cout << endl << endl;
			textcolor(7);	// notify "add student" is done
		}
		// if enter "cancel" -> cancel
		else
		{
			textcolor(12);
			printLabel("----CANCELED----", 54, 26);
			cout << endl << endl;
			textcolor(7);	// notify "add student" is done
		}
	}
	noCursorType();
	system("pause");
}