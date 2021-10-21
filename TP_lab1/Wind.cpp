#include "Wind.h"

string W_string_signed = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string W_double_signed = "1234567890,";
int input_number();

Wind::Wind() : name("uncounted"), name_manufacturer("uncounted"), cost(0), name_owner("uncounted"), defects("uncounted") {
	cout << "The constructor is called Wind" << endl;
}

Wind::Wind(string _name,  string _name_manufacturer, double _cost, string _name_owner, string _defects) :
	name(_name),  name_manufacturer(_name_manufacturer), cost(_cost), name_owner(_name_owner), defects(_defects) {
	input_keyboard();
	cout << "The constructor with parameters is called Wind" << endl;
}

Wind::Wind(const Wind& Win) {
	name = Win.name;
	name_owner = Win.name_owner;
	cost = Win.cost;
	name_manufacturer = Win.name_manufacturer;
	defects = Win.defects;
	cout << "The copy constructor is called Wind" << endl;
}

Wind::~Wind() {
	cout << "Destructor called Wind" << endl;
}

void Wind::inputName() {
	string _name;
	while (1)
	{
		getline(cin, _name);
		getline(cin, _name);
		if (_name.find_first_not_of(W_string_signed) == string::npos)
		{
			name = _name;
			break;
		}
		else
			cout << "������� �� ������ �������� �����������, ��������� ����." << endl;
	}
}

void Wind::inputNameManufacturer() {
	string _name_manufacturer;
	while (1) {
		getline(cin, _name_manufacturer);
		if (_name_manufacturer.find_first_not_of(W_string_signed) == string::npos)
		{
			name_manufacturer = _name_manufacturer;
			break;
		}
		else
			cout << "������� �� ������ ������������ �������������, ��������� ����." << endl;
	}
}

void Wind::inputCost() {
	string _cost;
	while (1) {
		getline(cin, _cost);
		if (_cost.find_first_not_of(W_double_signed) == string::npos)
		{
			cost = stod(_cost);
			break;
		}
		else
			cout << "������� �������� ���� �����������, ��������� ����." << endl;
	}
}

void Wind::inputNameOwner() {
	string _name_owner;
	while (1) {
		getline(cin, _name_owner);
		if (_name_owner.find_first_not_of(W_string_signed) == string::npos)
		{
			name_owner = _name_owner;
			break;
		}
		else
			cout << "������� �� ������ ��� ���������, ��������� ����." << endl;
	}
}

void Wind::inputDefects() {
	string _defects;
	while (1) {
		getline(cin, _defects);
		if (_defects.find_first_not_of(W_string_signed) == string::npos)
		{
			defects = _defects;
			break;
		}
		else
			cout << "������� �� ������ ������� �������� ��������, ��������� ����." << endl;
	}
}

void Wind::inputFaleName(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("�������� �����������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			name = s;
			cout << "������� �������� �������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� �������� �������� �����������" << endl;
	}
	else
		cout << "�� ������� �������� �������� �����������" << endl;
}

void Wind::inputFaleNameManufacturer(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("������������ �������������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			name_manufacturer = s;
			cout << "������� �������� ������������� �������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� �������� ������������� �������� �����������" << endl;
	}
	else
		cout << "�� ������� �������� ������������� �������� �����������" << endl;
}

void Wind::inputFaleCost(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("��������� �����������:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_double_signed) == string::npos)
		{
			cost = stoi(s);
			cout << "������� ��������� �������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ��������� �������� �����������" << endl;
	}
	else
		cout << "�� ������� ��������� �������� �����������" << endl; 
}

void Wind::inputFaleNameOwner(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("��� ���������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos) {
			name_owner = s;
			cout << "������� ��� ��������� �������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ��� ��������� �������� �����������" << endl;
	}
	else
		cout << "�� ������� ��� ��������� �������� �����������" << endl;
}

void Wind::inputFaleDefects(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("������� �������� ��������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			defects = s;
			cout << "������� ������� �������� �������� ������� �����������" << endl;
		}
		else
			cout << "�� ����� �������� ������� �������� �������� ������� �����������" << endl;
	}
	else
		cout << "�� ������� ������� �������� �������� ������� �����������" << endl;
}

void Wind::input_keyboard() {
	cout << "������� �������� �����������" << endl;
	inputName();
	cout << "������� �������� �������������" << endl;
	inputNameManufacturer();
	cout << "������� ��������� �����������" << endl;
	inputCost();
	cout << "������� ��� ���������" << endl;
	inputNameOwner();
	cout << "������� ������� ��������� �������� ��������" << endl;
	inputDefects();
}

void Wind::input_from_file(ifstream& fin) {
	string s;
	if (s.find("�������"))
	{
		getline(fin, s);
		inputFaleName(fin);
		inputFaleNameManufacturer(fin);
		inputFaleCost(fin);
		inputFaleNameOwner(fin);
		inputFaleDefects(fin);
	}
	else
		cout << "�� ������� �� ������ ���������" << endl;
}

void Wind::output_console() {
	cout << "�������� �����������: " << name << endl;
	cout << "������������ �������������: " << name_manufacturer << endl;
	cout << "��������� �����������: " << cost << endl;
	cout << "��� ���������: " << name_owner << endl;
	cout << "������� �������� ��������: " << defects << endl;
}

void Wind::output_to_file(ofstream& fout) {
	fout << "�������� �����������: " << name << endl;
	fout << "������������ �������������: " << name_manufacturer << endl;
	fout << "��������� �����������: " << cost << endl;
	fout << "��� ���������: " << name_owner << endl;
	fout << "������� �������� ��������: " << defects << endl;
}

void Wind::coding_to_file(ofstream& fout) {
	fout << encrip("�������� �����������: ") << encrip(name) << endl;
	fout << encrip("������������ �������������: ") << encrip(name_manufacturer) << endl;
	fout << encrip("��������� �����������: ") << encrip(to_string(cost)) << endl;
	fout << encrip("��� ���������: ") << encrip(name_owner) << endl;
	fout << encrip("������� �������� ��������: ") << encrip(defects) << endl;
}

void Wind::change() {
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
				cout << "������� ����� ������������ ������������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputNameManufacturer();
				cout << "�������� ������������ ������������� ��������� �����������" << endl << endl;
				break;
			case 3:
				cout << "������� ����� ��������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "�������� ��������� ��������� �����������" << endl << endl;
				break;
			case 4:
				cout << "������� ����� ��� ��������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "�������� ��� ��������� ��������� �����������" << endl << endl;
				break;
			case 5:
				cout << "������� ����� ������� �������� �������� ��������� �����������" << endl;
				getline(cin, tmp);
				inputDefects();
				cout << "�������� ������� �������� �������� ��������� �����������" << endl << endl;
				break;
			}
			if (punkt_menu == 6)
				break;
		}
		else
			cout << "������ �� ������ �����. ��������� ����." << endl;
	}
}

void Wind::print_menu_change() {
	cout << "��� ������ ��������? " << endl;
	cout << "0. ������ �� ��������" << endl;
	cout << "1. �������� �����������" << endl;
	cout << "2. ������������ �������������" << endl;
	cout << "3. ��������� �����������" << endl;
	cout << "4. ��� ���������" << endl;
	cout << "5. ������� �������� ��������" << endl;
	cout << "6. ����� � ������� ����" << endl;
}