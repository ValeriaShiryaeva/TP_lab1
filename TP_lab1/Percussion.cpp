#include "Percussion.h"

string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string numbers_double = "1234567890."; // ������� �� � ���������� �����

int input_number();

Percussion::Percussion() : type("uncounted"), name("uncounted"), cost(0), name_owner("uncounted") {}

Percussion::Percussion(string _type, string _name, double _cost, int _quantity, string _name_owner) :
	type(_type), name(_name), cost(_cost), name_owner(_name_owner) {
	input_keyboard();
}

void Percussion::input_keyboard() {
	cout << "������� ��� �������� �����������" << endl;
	string tmp;
	getline(cin, tmp); // cinignor ������� ������-��
	inputType();
	cout << "������� �������� �����������" << endl;
	inputName();
	cout << "������� ���� �����������" << endl;
	inputCost();
	cout << "������� ��� ���������" << endl;
	inputNameOwner();
	cout << endl;
}

void Percussion::inputType() {
	string _type;
	while (1) {
		getline(cin, _type);
		if (_type.find_first_not_of(letters_symbols) == string::npos)
		{
			setType(_type);
			break;
		}
		else
			cout << "������ �������� ��� �������� �����������, ��������� ����." << endl;
	}
}

void Percussion::inputName() {
	string _name;
	while (1)
	{
		getline(cin, _name);
		if (_name.find_first_not_of(letters_symbols) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "������� �� ������ �������� �����������, ��������� ����." << endl;
	}
}

void Percussion::inputCost() {
	string _cost;
	while (1) {
		getline(cin, _cost);
		if (_cost.find_first_not_of(numbers_double) == string::npos)
		{
			double tmp = stod(_cost);
			setCost(tmp);
			break;
		}
		else
			cout << "������� �������� ���� �����������, ��������� ����." << endl;
	}
}

void Percussion::inputNameOwner() {
	string _name_owner;
	while (1) {
		getline(cin, _name_owner);
		if (_name_owner.find_first_not_of(letters_symbols) == string::npos)
		{
			setNameOwer(_name_owner);
			break;
		}
		else
			cout << "������� �� ������ ��� ���������, ��������� ����." <<endl;
	}
}


void Percussion::output_console() {
	cout << "��� �����������: " << getType() << endl;
	cout << "�������� �����������: " << getName() << endl;
	cout << "��������� �����������: " << getCost() << endl;
	cout << "��� ���������: " << getNameOwer() << endl;
}

void Percussion::output_to_file(ofstream& fout) {
	fout << "��� �����������: " << getType() << endl;
	fout << "�������� �����������: " << getName() << endl;
	fout << "��������� �����������: " << getCost() << endl;
	fout << "��� ���������: " << getNameOwer();
}

void Percussion::change() {
	print_menu_change();
	string tmp;
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu == 0 || punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4 || punkt_menu == 5)
		{
			switch (punkt_menu) // �������� switch 
			{
			case 0:
				cout << "������ �� ��������" << endl << endl;
				break;
			case 1:
				cout << "������� ����� ��� �������� �����������" << endl;
				getline(cin, tmp);
				inputType();
				cout << "������� ��� �������� �����������" << endl << endl;
				break;
			case 2:
				cout << "������� ����� �������� �������� �����������" << endl;
				getline(cin, tmp);
				inputName();
				cout << "�������� �������� �������� �����������" << endl << endl;
				break;
			case 3:
				cout << "������� ����� ��������� �������� �����������" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "�������� ��������� �������� �����������" << endl << endl;
				break;
			case 4:
				cout << "������� ����� ��� ��������� �������� �����������" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "�������� ��� ��������� �������� �����������" << endl << endl;
				break;
			}
			if (punkt_menu == 5)
				break;
				
		}
		else
			cout << "������� �� ������ �����. ";		
	}
	
}

void Percussion::print_menu_change() {
	cout << "��� ������ ��������? "<< endl;
	cout << "0. ������ �� ��������" << endl;
	cout << "1. ��� �����������" << endl;
	cout << "2. �������� �����������"  << endl;
	cout << "3. ��������� �����������"  << endl;
	cout << "4. ��� ���������"  << endl;
	cout << "5. ����� � ������� ����" << endl;
}



