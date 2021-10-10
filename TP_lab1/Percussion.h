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
	string name_owner; // ��� ���������

	string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
	string numbers_double = "1234567890."; // ������� �� � ���������� �����
public:

	Percussion();
	Percussion(string, string, double, int, string);
	~Percussion() = default;

	void setType(string _type) { type = _type; }
	void setName(string _name) { name = _name; }
	void setCost(double _cost) { cost = _cost; }
	void setNameOwer(string _name_owner) { name_owner = _name_owner; }

	string getType() { return type; }
	string getName() { return name; }
	double getCost() { return cost; }
	string getNameOwer() { return name_owner; }

	void input_keyboard();
	void output_console();

	void output_to_file(ofstream& fout);
};