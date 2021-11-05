#pragma once
#include <iomanip>
#include <cstring>

using namespace std;

class nameType
{
private:
	char firstName[9];
	char middleName[14];
	char lastName[9];
	char fullName[30];
	void move(char[], int);

public:
	nameType();
	char* getFirstName();
	char* getMiddleName();
	char* getLastName();
	char* getFullName();
	bool convertToName(char[]);
};

nameType::nameType() 
{
	firstName[0] = '0';
	middleName[0] = '0';
	lastName[0] = '0';
	fullName[0] = '0';
}

// xoa 1 ki tu tai vi tri  p
void nameType::move(char arr[], int p)
{
	int length = strlen(arr);
	for (int i = p; i < length - 1; i++)
		arr[i] = arr[i + 1];
	arr[length - 1] = '\0';
}

// ham getter 
char* nameType::getFirstName()
{
	return firstName;
}
char* nameType::getMiddleName()
{
	return middleName;
}
char* nameType::getLastName()
{
	return lastName;
}
char* nameType::getFullName()
{
	return fullName;
}

// ham dinh dang lai Ho ten
bool nameType::convertToName(char arr[])
{
	fullName[0] = firstName[0] = lastName[0] = middleName[0] = '\0';
	for (int i = 0; i < (int)strlen(arr); i++)
	{

		 // Ho ten co chua ki tu dac biet, return false
		if ((arr[i] < 65 || arr[i] >90) && (arr[i] < 97 || arr[i] > 122) && (arr[i] != ' '))
			return false;
		else if (arr[i] == ' ' && arr[i + 1] == ' ') // Name co 2 ' ' khoang trang, thi xoa 1 ' '
		{
			move(arr, i + 1);
			i--;
		}
		   // neu sau ' ' la chu cai thuong, chuyen thanh chu cai in hoa
		else if (arr[i] == ' ' && (arr[i + 1] >= 97 && arr[i + 1] <= 122)) arr[i + 1] -= 32;
	}

	   // neu ket thuc la ' ', thi xoa khoang trang
	if (arr[strlen(arr) - 1] == ' ')    arr[strlen(arr) - 1] = '\0';

	  // neu bat dau la chu cai thuong, chuyen thanh chu cai in hoa
	if (arr[0] >= 97 && arr[0] <= 122)
		arr[0] -= 32;

	  // neu bat dau la ' ', thi xoa khoang trang
	else if (arr[0] == ' ')
		move(arr, 0);

	// lay fullName = arr (after format)
	for (int i = 0; i < 30; i++)
		fullName[i] = arr[i];

	// chi so vi tri ' ' khoang trang
	int index1 = 0, index2 = 0;

	// lay vi tri ' ' thu 1
	for (int i = 0; i < (int)strlen(arr); i++)
		if (fullName[i] == ' ')
		{
			index1 = index2 = i;
			break;
		}

	// lay vi tri ' ' thu 2
	for (int i = (int)strlen(arr)-1; i> index1; i--)
		if (fullName[i] == ' ')
		{
			index2 = i;
			break;
		}

	// lay lastName (Ho)
	for (int i = 0; i < index1; i++)
		lastName[i] = fullName[i];
	lastName[index1] = '\0';

	// lay middleName (Ten dem)
	for (int i = index1 + 1; i < index2; i++)
	{
		middleName[i - (index1 + 1)] = fullName[i];
	}
	middleName[index2 - (index1 + 1)] = '\0';

	// lay firstName (Ten)
	for (int i = index2 + 1; i < (int)strlen(fullName); ++i)
		firstName[i - (index2 + 1)] = fullName[i];
	firstName[(int)strlen(fullName) - (index2 + 1)] = '\0';

	return true;
}
