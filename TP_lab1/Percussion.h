#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Percussion  // ������� �����������
{
private:
	string type; // ��� �����������
	string name; // �������� �����������
	double cost; // ��������� �����������
	int quantity; // ���������� ������ � ��������
	string name_owner; // ��� ���������

public:

	Percussion() : type("uncounted"), name("uncounted"), cost(0), quantity(0), name_owner("uncounted") {}

	Percussion(string _type, string _name, double _cost, int _quantity, string _name_owner) :
		type(_type), name(_name), cost(_cost), quantity(_quantity), name_owner(_name_owner) {
			input_keyboard();
	}

	//template <typename T>
	void input_keyboard();
	void output_console();
};