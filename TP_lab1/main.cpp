#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"
#include "�eeper.h"

�eeper keeper;

void menu();
void print_menu();
void choosing_orchestra();
int repeat_input_number_orchestra();
void input_number_orchestra();

ofstream fout("Save_container.txt");; // ������ ������ � ���� (���������� ������ � ����)
ifstream fin("Extract_container.txt");; // ����� ������ �� ����� (�������������� ������ �� �����)


void main()
{
	setlocale(LC_ALL, "rus"); // ����� �������� ����� � �������

	while (1)
	{
		menu(); // ����� ���� �� �����
	}
}


void menu() // ��������� ����
{
	print_menu(); // ����� ���� �� �����
	int punkt_menu;
	cout << "������� ����� ����: ";
	cin >> punkt_menu; 
	cout << endl;
	switch (punkt_menu) // �������� switch 
	{
	case 1:
		keeper.creat_container();
		break;
	case 2:
		choosing_orchestra();
		break;
	case 3:
		keeper.output_container();
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
	input_number_orchestra();
}

void input_number_orchestra() {
	int number_orchestra;
	cout << "������ ����� ��������, � ������� ������ �������� ����������: " << endl;
	cin >> number_orchestra;
	if (number_orchestra - 1 <= keeper.getLength())
		keeper[number_orchestra].selecting_type_instrument();
	else
		repeat_input_number_orchestra();
}

int repeat_input_number_orchestra() {
	cout << "������� �� ������ �������� ��������. �������� ��������:" << endl;
	cout << "1. ��������� ����� �������� ��������" << endl;
	cout << "2. ����� �� ���������" << endl;
	cout << "������� ����� ��������: " << endl;
	int punkt;
	cin >> punkt;
	switch (punkt) // �������� switch 
	{
	case 1:
		input_number_orchestra();
	case 2:
		exit(0);
	}
}





