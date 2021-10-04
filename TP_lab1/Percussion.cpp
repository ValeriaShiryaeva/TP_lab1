#include "Percussion.h"

string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string numbers = "1234567890."; // ������� �� � ���������� �����


void Percussion::input_keyboard() {

	string _type, _name, _cost, _name_owner;

	quantity ++;

	cout << "������� ��� �������� �����������" << endl;
	getline(cin, _type); // cinignor ������� ������-��
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
	if (_cost.find_first_not_of(numbers) == string::npos)
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
}

void Percussion::output_console() {
	cout << "��� �����������: " << type << endl;
	cout << "�������� �����������: " << name << endl;
	cout << "��������� �����������: " << cost << endl;
	cout << "����������� ������ � ��������: " << quantity << endl;
	cout << "��� ���������: " << name_owner << endl;
}



