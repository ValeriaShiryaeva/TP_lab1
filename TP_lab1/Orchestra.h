#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Orchestra // ����� �������
{
protected:
	string name; // �������� �����������
	double cost; // ��������� �����������
	int quantity; // ���������� ������ � ��������
	string name_owner; // ��� ���������

public:

	// ���� ��������� � ����������
	 void input_keyboard();

	// ���� ��������� �� �����
	 void input_from_file(ifstream&);

	// �s��� ��������� � �������
	 void output_console();

	// ����� ��������� � ����
	 void output_to_file(ofstream&);
};

