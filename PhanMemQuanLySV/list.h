#pragma once

#include <vector>
#include <fstream>
#include "date.h"
#include "nameType.h"
#include "DoHoa.h"

#define account "admin"                  
#define password "admin" 

#define CNTT1 "CNTT1"
#define CNTT2 "CNTT2"
#define BDATTT "BDATTT"
#define ANHTTT "ANHTTT"
#define PTDL "PTDL"

 // class "sinh vien"
class student
{
private:
	char classID[10], studentID[10];
	nameType Name;
	date dateOfBirth;
	float score;
public:
	student();
	student(char[], char[], nameType, date, float);

	void setClassID(char[]);
	void setStudentID(char[]);
	void setName(nameType);
	void setDateOfBirth(date);
	void setScore(float);

	char* getClassID();
	char* getStudentID();
	nameType getName();  
	date getDateOfBirth();
	float getScore();

	void display(int, bool);
};

student::student() {
	classID[0] = char(0);
	studentID[0] = char(0);
	this->Name = nameType();
	this->dateOfBirth = date();
	this->score = 0.0;
};
	
student::student(char classID[], char studentID[], nameType Name, date dateOfBirth, float score)
{
	for (int i = 0; i < 9; ++i)
	{
		this->classID[i] = classID[i];
		this->studentID[i] = studentID[i];
	}
	this->Name = Name;
	this->dateOfBirth = dateOfBirth;
	this->score = score;
}

void student::setClassID(char classID[])
{
	for (int i = 0; i < 10; ++i)
		this->classID[i] = classID[i];
}
void student::setStudentID(char studentID[])
{
	for (int i = 0; i < 10; ++i)
		this->studentID[i] = studentID[i];
}
void student::setName(nameType Name)
{
	this->Name = Name;
}
void student::setDateOfBirth(date dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}
void student::setScore(float score)
{
	this->score = score;
}


char* student::getClassID()
{
	return classID;
}
char* student::getStudentID()
{
	return studentID;
}
nameType student::getName()
{
	return Name;
}
date student::getDateOfBirth()
{
	return dateOfBirth;
}
float student::getScore()
{
	return score;
}


void student::display(int i, bool check)
{
	// Sinh vien duoc chon, hien mau khac
	if (check == true)
		textcolor(4);
	else
		textcolor(7);

	// y la toa do duoc hien thi ung voi so thu tu i+1
	int y = 8 + (i % 10) * 2;
	gotoxy(13, y); cout << i + 1;
	printLabel(studentID, 21, y);
	gotoxy(34, y); cout << Name.getLastName() << " " << Name.getMiddleName();
	printLabel(Name.getFirstName(), 56, y);
	printLabel(classID, 71, y);
	gotoxy(86, y); dateOfBirth.display();
	gotoxy(104, y); cout << score;
	textcolor(7);
}



// class list sinh vien
class list
{
private:
	vector<student> studentList;
	bool checkClassID(char[]);
	bool checkStudentID(char[]);
	bool verify(student);

public:
	void delOrEdit(int);
	void outputToFile();
	void inputFromFile();
	list();
	void addStudent();
	void editProfile(int);
	void deleteStudent(int);
	int printList(bool, int&);
	//void sort(int, int);
	//void search(int, int);
	//void statistic();*/
	vector<student>* getList() { return &studentList; };
};

list::list()
{}

