#include "Stringed.h"

string S_string_signed = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string S_double_signed = "1234567890,";
int input_number();

Stringed::Stringed() : name("uncounted"), name_owner("uncounted"), name_manufacturer("uncounted"),  cost(0), description("uncounted") {
	cout << "The constructor is called Stringed" << endl;
}

Stringed::Stringed(string _name, string _name_owner, string _name_manufacturer, double _cost, string _description) :
	name(_name), name_owner(_name_owner), name_manufacturer(_name_manufacturer), cost(_cost), description(_description) {
	input_keyboard();
	cout << "The constructor with parameters is called Stringed" << endl;
}

Stringed::Stringed(const Stringed& Str) {
	name = Str.name;
	name_owner = Str.name_owner;
	name_manufacturer = Str.name_manufacturer;
	cost = Str.cost;
	description = Str.description;
	cout << "The copy constructor is called Stringed" << endl;
}

Stringed::~Stringed() {
	cout << "Destructor called Stringed" << endl;
}

void Stringed::inputName() {
	string _name;
	while (1)
	{
		getline(cin, _name);
		getline(cin, _name);
		if (_name.find_first_not_of(S_string_signed) == string::npos)
		{
			name = _name;
			break;
		}
		else
			cout << "������� �� ������ �������� �����������, ��������� ����." << endl;
	}
}

void Stringed::inputNameOwner() {
	string _name_owner;
	while (1) {
		getline(cin, _name_owner);
		if (_name_owner.find_first_not_of(S_string_signed) == string::npos)
		{
			name_owner = _name_owner;
			break;
		}
		else
			cout << "������� �� ������ ��� ���������, ��������� ����." << endl;
	}
}

void Stringed::inputNameManufacturer() {
	string _name_manufacturer;
	while (1) {
		getline(cin, _name_manufacturer);
		if (_name_manufacturer.find_first_not_of(S_string_signed) == string::npos)
		{
			name_manufacturer = _name_manufacturer;
			break;
		}
		else
			cout << "������� �� ������ ������������ �������������, ��������� ����." << endl;
	}
}

void Stringed::inputCost() {
	string _cost;
	while (1) {
		getline(cin, _cost);
		if (_cost.find_first_not_of(S_double_signed) == string::npos)
		{
			cost = stod(_cost);
			break;
		}
		else
			cout << "������� �������� ���� �����������, ��������� ����." << endl;
	}
}

void Stringed::inputDescription() {
	string _description;
	while (1) {
		getline(cin, _description);
		if (_description.find_first_not_of(S_string_signed) == string::npos)
		{
			description = _description;
			break;
		}
		else
			cout << "������� �� ������ ������� ��������, ��������� ����." << endl;
	}
}

void Stringed::inputFaleName(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("�������� �����������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			name = s;
			cout << "������� �������� ��������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� �������� ��������� �����������" << endl;
	}
	else
		cout << "�� ������� �������� ��������� �����������" << endl;
}

void Stringed::inputFaleNameOwner(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("��� ���������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos) {
			name_owner = s;
			cout << "������� ��� ��������� ��������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ��� ��������� ��������� �����������" << endl;
	}
	else
		cout << "�� ������� ��� ��������� ��������� �����������" << endl;
}

void Stringed::inputFaleNameManufacturer(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("������������ �������������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			name_manufacturer = s;
			cout << "������� �������� ������������� ��������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� �������� ������������� ��������� �����������" << endl;
	}
	else
		cout << "�� ������� �������� ������������� ��������� �����������" << endl;
}

void Stringed::inputFaleCost(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("��������� �����������:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_double_signed) == string::npos)
		{
			cost = stoi(s);
			cout << "������� ��������� ��������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ��������� ��������� �����������" << endl;
	}
	else
		cout << "�� ������� ��������� ��������� �����������" << endl;
}

void Stringed::inputFaleDescription(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("������� ��������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			description = s;
			cout << "������� ������� �������� ��������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ������� �������� ��������� �����������" << endl;
	}
	else
		cout << "�� ������� ������� �������� ��������� �����������" << endl;
}

void Stringed::input_keyboard() {
	cout << "������� �������� �����������" << endl;
	inputName();
	cout << "������� ��� ���������" << endl;
	inputNameOwner();
	cout << "������� �������� �������������" << endl;
	inputNameManufacturer();
	cout << "������� ��������� �����������" << endl;
	inputCost();
	cout << "������� ������� ��������� ��������" << endl;
	inputDescription();
}

void Stringed::input_from_file(ifstream& fin) {
	string s;
	if (s.find("��������"))
	{
		getline(fin, s);
		inputFaleName(fin);
		inputFaleNameOwner(fin);
		inputFaleNameManufacturer(fin);
		inputFaleCost(fin);
		inputFaleDescription(fin);
	}
	else
		cout << "�� ������� �� ������ ���������" << endl;
}

void Stringed::output_console() {
	cout << "�������� �����������: " << name << endl;
	cout << "��� ���������: " << name_owner << endl;
	cout << "������������ �������������: " << name_manufacturer << endl;
	cout << "��������� �����������: " << cost << endl;
	cout << "������� ��������: " << description << endl;
}

void Stringed::output_to_file(ofstream& fout) {
	fout << "�������� �����������: " << name << endl;
	fout << "��� ���������: " << name_owner << endl;
	fout << "������������ �������������: " << name_manufacturer << endl;
	fout << "��������� �����������: " << cost << endl;
	fout << "������� ��������: " << description << endl;
}

void Stringed::coding_to_file(ofstream& fout) {
	fout << encrip("�������� �����������: ") << encrip(name) << endl;
	fout << encrip("��� ���������: ") << encrip(name_owner) << endl;
	fout << encrip("������������ �������������: ") << encrip(name_manufacturer) << endl;
	fout << encrip("��������� �����������: ") << encrip(to_string(cost)) << endl;
	fout << encrip("������� ��������: ") << encrip(description) << endl;
}

void Stringed::change() {
	print_menu_change();
	string tmp;
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu >= 0 && punkt_menu <= 6)
		{
			switch (punkt_menu)
			{
			case 0:
				cout << "������ �� ��������" << endl << endl;
				break;
			case 1:
				cout << "������� ����� �������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputName();
				cout << "�������� �������� ��������� �����������" << endl << endl;
				break;
			case 2:
				cout << "������� ����� ��� ��������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "�������� ��� ��������� ��������� �����������" << endl << endl;
				break;
			case 3:
				cout << "������� ����� ������������ ������������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputNameManufacturer();
				cout << "�������� ������������ ������������� ��������� �����������" << endl << endl;
				break;
			case 4:
				cout << "������� ����� ��������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "�������� ��������� ��������� �����������" << endl << endl;
				break;
			case 5:
				cout << "������� ����� ������� �������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputDescription();
				cout << "�������� ������� �������� ��������� �����������" << endl << endl;
				break;
			}
			if (punkt_menu == 6)
				break;
		}
		else
			cout << "������ �� ������ �����. ��������� ����." << endl;
	}
}

void Stringed::print_menu_change() {
	cout << "��� ������ ��������? " << endl;
	cout << "0. ������ �� ��������" << endl;
	cout << "1. �������� �����������" << endl;
	cout << "2. ��� ���������" << endl;
	cout << "3. ������������ �������������" << endl;
	cout << "4. ��������� �����������" << endl;
	cout << "5. ������� ��������" << endl;
	cout << "6. ����� � ������� ����" << endl;
}