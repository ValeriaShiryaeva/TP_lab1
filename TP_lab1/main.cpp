#include <iostream>
using namespace std;

void menu();
void print_menu();

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
	cout << "	5. ����� �� ���������" << endl;
}