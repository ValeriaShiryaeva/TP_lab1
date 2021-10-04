#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Percussion.h"
#include "Stringed.h"
#include "Wind.h"

using namespace std;

class Orchestra // ����� �������
{
private:
	string name; // �������� ��������
	int length;
	Percussion* data_p; // ������� 
	int length_p;
	Stringed* data_s; // ��������
	int length_s;
	Wind* data_w; // �������
	int length_w;

public:
	Orchestra():length(0), length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {} // ����������� ��� ����������


	Percussion& operator[](int index);

	void creat_percussion(); 

	void output_percussion();

	 void input_keyboard();

	 void output_console();

	 void selecting_type_instrument();

	 void menu_selecting_type_instrument();

	 int getLength() { return length; }

	 string getName() { return name; }

	 void output_console_Orchestra_name();

	 // ���� ��������� �� �����
	 void input_from_file(ifstream&);

	 // ����� ��������� � ����
	 void output_to_file(ofstream&);

};

