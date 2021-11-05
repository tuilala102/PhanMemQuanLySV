#pragma once
#include<math.h>
#include<cstring>
#include"list.h"

float convertToFloat(char tmp[]) // chuyen str-> float
{
	char a[4];
	// bo dau ".", lay phan so, chuyen sang int va chia cho 10^x
	int index = 4;
	for (int i = 0; i < 4; i++)
		if (tmp[i] == '.') index = i;

	for (int i = 0; i < index; i++)
		a[i] = tmp[i];

	for (int i = index + 1; i < 4; i++)
		a[i - 1] = tmp[i];

	int result = atoi(a);
	if (index == 4) return float(result);
	else 
		return float(result/ (pow(10, strlen(tmp) - 1 - index)));
}

// ktra Ma lop
bool list::checkClassID(char classID[])
{
	//strupr(classID); //in hoa
	if (strcmp(classID, CNTT1) == 0 || strcmp(classID, CNTT2) == 0
		|| strcmp(classID, BDATTT) == 0 || strcmp(classID, ANHTTT) == 0 || strcmp(classID, PTDL) == 0)
		return true;
	return false;
}

// ktra Ma sinh vien
bool list::checkStudentID(char studentID[])
{
	if (strlen(studentID) == 10)
	{
		//strupr(studentID); //in hoa
		for (int i = 0; i < (int)studentList.size(); i++)
			if (strcmp(studentID, studentList[i].getStudentID()) == 0)
				return false;
		return true;
	}
	return false;
}
// check lai thong tin SV them moi
bool list::verify(student tmp)
{
	char a;
	system("cls");
	
	textcolor(3);
	printLabel("----THEM MOI HO SO----", 50, 5);
	///////////////////////////////////////////
	textcolor(7);
	printLabel("Kiem tra lai:", 30, 5);
	printLabel("Name:        ", 50, 5); cout << tmp.getName().getFullName();
	printLabel("Ngay sinh:        ", 50, 8); tmp.getDateOfBirth().display();
	printLabel("Ma sinh vien:     ", 50, 11); cout << tmp.getStudentID();
	printLabel("Ma lop:           ", 50, 14); cout << tmp.getClassID();
	printLabel("DTB tich luy:     ", 50, 17); cout << tmp.getScore();
	printLabel("Continue? (y/n)  >> ", 30, 20);
	while (true)
	{
		a = _getch();
		if (a == 'y' || a == 'n') break;

	}
	cout << a;
	if (a == 'n') return false;
	else return true;
}


void list::inputFromFile()
{
	student tmp;
	
	ifstream ifs("data.dat", ios::binary);
	while (true)
	{
		ifs.read((char*)&tmp, sizeof(student));
		if (ifs.eof()) break;
		studentList.push_back(tmp);  //them vao cuoi
	}
	ifs.close();
}

void list::outputToFile()
{
	ofstream ofs("data.dat", ios::binary);
	for (int i = 0; i < (int)studentList.size(); ++i)
		ofs.write((char*)&studentList[i], sizeof(student));
	ofs.close();
}

void list::addStudent()
{
	char a;
	char* classID, * studentID, * nametmp, * datetmp, * pass, * scoretmp;
	date dateOfBirth;
	nameType Name;
	float score;

	//////////////// ===================== nhap thong tin SV ===================== //////////////
	while (true)
	{
		cursorType();	// turn on cursor
		system("cls");
	
		gotoxy(5, 2);
		cout << "DS SV hien co: " << studentList.size();
		// ve menu them moi ho so
		Menu_Them();


		 //===================== nhap Ma lop =====================
		classID = new char[10];
		while (true)
		{
			fflush(stdin); // xoa bo nho dem
			gotoxy(62, 8);
			if (enterKey(classID, 8))
			{
				if (checkClassID(classID))
				{
					printLabel(classID, 62, 8);
					break;
				}
				else		// neu Ma lop sai, nhap lai
				{
					textcolor(4);
					printLabel("Ma lop la 1 trong 5 lop: CNTT1, CNTT2, BDATTT, ANHTTT, PTDL", 35, 24);
					textcolor(7);
					printLabel("                              ", 62, 8);
				}
			}
			else return;

		}
		printLabel("                                                                    ", 35, 24);

		      //===================== nhap Ma sinh vien =====================
		studentID = new char[10];
		while (true)
		{
			gotoxy(62, 11);
			if (enterKey(studentID, 8))
			{
				if (checkStudentID(studentID))
				{
					printLabel(studentID, 62, 11);
					break;
				}
				else	// neu Ma SV sai, nhap lai
				{
					textcolor(4);
					printLabel("Ma sinh vien gom 8 ki tu. Va no la duy nhat!", 40, 24);

					textcolor(7);
					printLabel("                              ", 62, 11);
				}
			}
			else return;
		}
		printLabel("                                                   ", 40, 24);

		       //===================== nhap ho ten SV =====================
		nametmp = new char[31];
		while (true)
		{
			gotoxy(62, 14);
			if (enterKey(nametmp, 30))
			{
				if (Name.convertToName(nametmp))
				{
					printLabel("                               ", 62, 14);
					gotoxy(62, 14); cout << Name.getFullName();
					break;
				}
				else	// neu Ho ten chua ki tu dac biet, nhap lai
				{
					textcolor(4);
					printLabel("Ho ten khong chua ki tu dac biet!", 47, 24);
					textcolor(7);
					printLabel("                               ", 62, 14);
				}
			}
			else return;

		}
		printLabel("                                      ", 47, 24);

		           //===================== nhap Ngay sinh =====================
		datetmp = new char[11];
		while (true)
		{
			gotoxy(62, 17);
			if (enterKey(datetmp, 10))
			{
				if (dateOfBirth.convertToDate(datetmp)) break;
				else
				{
					textcolor(4);
					printLabel("Ngay sinh co dang: dd/mm/yyyy", 44, 24);
					textcolor(7);
					printLabel("                              ", 62, 17);
				}
			}
			else return;
		}
		printLabel("                                   ", 44, 24);

		
		     //===================== nhap DTB tich luy =====================
		scoretmp = new char[5];
		while (true)
		{
			gotoxy(62, 20);
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
				// neu dung dinh dang, chuyen scoretmp -> score float
				if (acheck == true && dem < 2)
				{
					score = convertToFloat(scoretmp);
				}
				// neu co ki tu dac biet, hoac nhieu hon 1 dau '.' , thi nhap lai
				else
				{
					textcolor(4);
					printLabel("DTB khong chua ki tu dac biet!", 41, 24);
					textcolor(7);
					printLabel("                              ", 62, 20);
					continue;
				}
				if (score >= 0 && score <= 10) break;
				else
				{
					textcolor(4);
					printLabel("    DTB la so thuc tu 0 den 10!   ", 41, 24);
					textcolor(7);
					printLabel("                              ", 62, 20);
				}
			}
			else return;
		}
		printLabel("                                         ", 41, 24);


		// ================= Tao 1 doi tuong Sinh vien =======================
		student student(classID, studentID, Name, dateOfBirth, score);

		// verify and if say "yes", program push_back to list, else cancel
		if (verify(student))
		{
			pass = new char[30];
			printLabel("Nhap password: ", 30, 22);
			while (true)
			{
				enterPass(pass, 50, 22);
				if (strcmp(pass, password) == 0)
				{
					printLabel("               ", 40, 24);
					break;
				}
				else if (strcmp(pass, "cancel") == 0)
				{
					printLabel("               ", 40, 24);
					break;
				}
				else
				{
					printLabel("                              ", 50, 22);
					textcolor(4);
					printLabel("password sai! Hay nhap lai!", 40, 24);
					textcolor(7);
				}
			}
			if (strcmp(pass, password) == 0)
			{
				studentList.push_back(student);		// them vao list
				outputToFile();    // cap nhat lai file
				textcolor(12);
				printLabel("------SUCCESSFUL------", 54, 24);
				cout << endl << endl;
				textcolor(7);	//  "Them moi ho so" hoan thanh
			}
			else
			{
				textcolor(12);
				printLabel("------CANCELED------", 54, 24);
				cout << endl << endl;
				textcolor(7);	//  "Them moi ho so" hoan thanh
			}

		}
		else
		{
			textcolor(12);
			printLabel("------CANCELED------", 54, 24);
			cout << endl << endl;
			textcolor(7);	//  "Them moi ho so" hoan thanh
		}
		noCursorType();	   // turn off cursor

		// exit or continue?
		cout << "Nhan  --Esc--  de quay lai Main Menu, nhan  --Enter--  de them SV khac...";
		while (true)	 // neu nhan Enter
		{
			a = _getch();
			if (a == 13 || a == 27) break;
		}
		if (a == 27) break;	 // neu nhan Esc 
	}
}
