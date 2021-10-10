#include "Percussion.h"

Percussion::Percussion() : type("uncounted"), name("uncounted"), cost(0), name_owner("uncounted") {}

Percussion::Percussion(string _type, string _name, double _cost, int _quantity, string _name_owner) :
	type(_type), name(_name), cost(_cost), name_owner(_name_owner) {
	input_keyboard();
}

void Percussion::input_keyboard() {

	string _type, _name, _cost, _name_owner;

	cout << "������� ��� �������� �����������" << endl;
	getline(cin, _type); // cinignor ������� ������-��
	while (1) {
		getline(cin, _type);
		if (_type.find_first_not_of(letters_symbols) == string::npos)
		{
			setType(_type);
			break;
		}
		else
			cout << "������ �������� ��� �������� �����������, ��������� ����: ";
	}
	

	cout << "������� �������� �����������" << endl;
	while (1)
	{
		getline(cin, _name);
		if (_name.find_first_not_of(letters_symbols) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "������� �� ������ �������� �����������, ��������� ����: ";
	}

	cout << "������� ���� �����������" << endl;
	while (1) {
		getline(cin, _cost);
		if (_cost.find_first_not_of(numbers_double) == string::npos)
		{
			double tmp = stod(_cost);
			setCost(tmp);
			break;
		}
		else
			cout << "������� �������� ���� �����������, ��������� ����: ";
	}
	
	cout << "������� ��� ���������" << endl;
	while (1) {
		getline(cin, _name_owner);
		if (_name_owner.find_first_not_of(letters_symbols) == string::npos)
		{
			setNameOwer(_name_owner);
			break;
		}
		else
			cout << "������� �� ������ ��� ���������, ��������� ����: ";
	}
	cout << endl;
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



