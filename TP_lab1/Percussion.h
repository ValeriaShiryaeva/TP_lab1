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
	//template <typename T>
	void input_keyboard();
	void output_console();
};

/*template <typename T>
void Percussion::input_keyboard() {

	string _type, _name, _cost, _name_owner;

	quantity += 1;

	cout << "������� ��� �������� �����������" << endl;
	getline(cin, _type);
	getline(cin, _type);
	if (_type.find_first_not_of(letters_symbols) == string::npos)
		type = _type;
	else
		type = "uncounted";

	cout << "������� �������� �����������" << endl;
	getline(cin, _name);
	if (_name.find_first_not_of(letters_symbols) == string::npos)
		name = _name;
	else
		name = "uncounted";

	cout << "������� ���� �����������" << endl;
	getline(cin, _cost);
	if (_cost.find_first_not_of(letters_symbols) == string::npos)
	{
		double tmp = stod(_cost);
		cost = tmp;
	}
	else
		cost = 0;

	cout << "������� ��� ���������" << endl;
	getline(cin, _name_owner);
	if (_name_owner.find_first_not_of(letters_symbols) == string::npos)
		name_owner = _name_owner;
	else
		name_owner = "uncounted";
}*/