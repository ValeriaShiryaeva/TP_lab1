#include <iostream>
#include <fstream>
#include<windows.h>
#include <stdio.h>
using namespace std;

#include "Orchestra.h"
#include "�eeper.h"

�eeper keeper;

void menu();
void print_menu();
void menu_output();
void print_menu_output();
bool intSigned(const string&);
int input_number();

ifstream fin("Extract_container.txt"); // ����� ������ �� ����� (�������������� ������ �� �����)

void main()
{
	setlocale(LC_ALL, "rus"); 
	while (1)
		menu();
}

void menu(){
	print_menu();
	int punkt_menu = input_number();
	if (punkt_menu <= 6 && punkt_menu > 0) {
		switch (punkt_menu)
		{
		case 1:
			keeper.creat();
			break;
		case 2:
			if (keeper.getLength() == 0)
				cout << "�� �� ������ ������� ����������, ������� �������� �������" << endl;
			else
				keeper[keeper.choosing_orchestra() - 1].selecting_type_instrument();
			break;
		case 3:
			menu_output();
			break;
		case 4:
			if (keeper.getLength() == 0)
				cout << "�� �� ������ ������� ��������� � ��� ����������. ��������� ������" << endl;
			else
				keeper.delite_container();
			break;
		case 5:
			if (keeper.getLength() == 0)
				cout << "�� �� ������ ������ ��������. ��������� ������" << endl;
			else
				keeper.change_container();
			break;
		case 6: // ����� �� ���������
			exit(0);
		}
	} 
	else
		cout << "������ �� ������ �����. " << endl;	
}

void print_menu() // ����� ���� �� �����
{
	cout << "�������� ����� ����:" << endl;
	cout << "	1. ������� �������" << endl;
	cout << "	2. ������� ���������� ��������" << endl;
	cout << "	3. ������� ���������� ����������" << endl;
	cout << "	4. ������� ���������� ����������" << endl;
	cout << "	5. �������� ���������� ����������" << endl;
	cout << "	6. ����� �� ���������" << endl;
}

void print_menu_output() {
	cout << "��������, ���� ������� ����������" << endl;
	cout << "1. � �������" << endl;
	cout << "2. � ����" << endl;
}

void menu_output() {
	print_menu_output();
	while (1)
	{
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2)
		{
			switch (punkt_menu)
			{
			case 1:
				keeper.output_container_console();
				break;
			case 2:
				ofstream fout("Save_container.txt");
				keeper.output_to_file(fout);
				cout << "������ �������� � ����" << endl;
				fout.close();
				break;
			}
			break;
		}		
	}	
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

