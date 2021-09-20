#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"

void menu();
void print_menu();

ofstream fout("Save_container.txt");; // ������ ������ � ���� (���������� ������ � ����)
ifstream fin("Extract_container.txt");; // ����� ������ �� ����� (�������������� ������ �� �����)

Orchestra orchestra;

void main()
{
	setlocale(LC_ALL, "rus"); // ����� �������� ����� � �������

	//orchestra.input_keyboard();
	orchestra.input_from_file(fin);
	orchestra.output_console();
	//orchestra.output_to_file(fout);

	//while (1)
	//{
	//	menu(); // ����� ���� �� �����
	//}
}


void menu() // ��������� ����
{
	print_menu(); // ����� ���� �� �����
	int punkt_menu;
	cout << "������� ����� ����:";
	cin >> punkt_menu;
	switch (punkt_menu) // �������� switch 
	{
	case 5: // ����� �� ���������
		exit(0);
	}
}

void print_menu() // ����� ���� �� �����
{
	cout << "�������� ����� ����:" << endl;
	cout << "	1. ������� ������ � ����" << endl;
	cout << "	5. ����� �� ���������" << endl;
}