#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"
#include "�eeper.h"

�eeper keeper;

void menu();
void print_menu();
void choosing_orchestra();
int repeat_input_number();
bool intSigned(const string& );
int input_number();

ofstream fout("Save_container.txt");; // ������ ������ � ���� (���������� ������ � ����)
ifstream fin("Extract_container.txt");; // ����� ������ �� ����� (�������������� ������ �� �����)

void main()
{
	setlocale(LC_ALL, "rus"); // ����� �������� ����� � �������

	//�eeper keeper(2);
	while (1)
	{
		menu(); // ����� ���� �� �����
	}
}


void menu() // ��������� ����
{
	print_menu(); // ����� ���� �� �����
	int punkt_menu = input_number();
	switch (punkt_menu) // �������� switch 
	{
	case 1:
		keeper.creat();
		break;
	case 2:
		choosing_orchestra();
		break;
	case 3:
		keeper.output_container();
		break;
	case 5: // ����� �� ���������
		exit(0);
	}
}

void print_menu() // ����� ���� �� �����
{
	cout << "�������� ����� ����:" << endl;
	cout << "	1. ������� �������" << endl;
	cout << "	2. ������� ���������� ��������" << endl;
	cout << "	3. ������� �� ����� ��� ����������� ����������" << endl;
	cout << "	5. ����� �� ���������" << endl;
}

void choosing_orchestra() {
	cout << "�������� ���������" << endl;
	for (int i = 0; i < keeper.getLength(); i++)
		cout << i + 1 << ". " << keeper[i].getName() << endl;
	int number = input_number() - 1;
	if (number <= keeper.getLength())
		keeper[number].selecting_type_instrument();
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "������ �����: " << endl;
		cin >> number_s;
		if (intSigned(number_s) == true)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "������� �� ������ ��������. ��������� ����." << endl;
	}
}

bool intSigned(const string& s) // �������� �� ������ ����� � �����
{
	if (s.find_first_not_of("0123456789", 0) == string::npos)
		return true;
	else
		return false;
}





