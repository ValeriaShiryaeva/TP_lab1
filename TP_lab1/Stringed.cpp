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
			cout << "Введено не верное название инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное ФИО владельца, повторите ввод." << endl;
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
			cout << "Введено не верное наименование производителя, повторите ввод." << endl;
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
			cout << "Введена неверная цена инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное краткое описание, повторите ввод." << endl;
	}
}

void Stringed::inputFaleName(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Название инструмента:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			name = s;
			cout << "Считано название струнного инструмента" << endl;
		}
		else
			cout << "Не верно записано название струнного инструмента" << endl;
	}
	else
		cout << "Не найдено название струнного инструмента" << endl;
}

void Stringed::inputFaleNameOwner(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("ФИО владельца:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos) {
			name_owner = s;
			cout << "Считано ФИО владельца струнного инструмента" << endl;
		}
		else
			cout << "Не верно записано ФИО владельца струнного инструмента" << endl;
	}
	else
		cout << "Не найдено ФИО владельца струнного инструмента" << endl;
}

void Stringed::inputFaleNameManufacturer(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Наименование производителя:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			name_manufacturer = s;
			cout << "Считано название производителя струнного инструмента" << endl;
		}
		else
			cout << "Не верно записано название производителя струнного инструмента" << endl;
	}
	else
		cout << "Не найдено название производителя струнного инструмента" << endl;
}

void Stringed::inputFaleCost(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Стоимость инструмента:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_double_signed) == string::npos)
		{
			cost = stoi(s);
			cout << "Считана стоимость струнного иснтурмента" << endl;
		}
		else
			cout << "Не верно записана стоимость струнного инструмента" << endl;
	}
	else
		cout << "Не найдена стоимость струнного инструмента" << endl;
}

void Stringed::inputFaleDescription(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Краткое описание:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(S_string_signed) == string::npos)
		{
			description = s;
			cout << "Считано краткое описание струнного инструмента" << endl;
		}
		else
			cout << "Не верно написано краткое описание струнного инструмента" << endl;
	}
	else
		cout << "Не найдено краткое описание струнного инструмента" << endl;
}

void Stringed::input_keyboard() {
	cout << "Введите название инструмента" << endl;
	inputName();
	cout << "Введите ФИО владельца" << endl;
	inputNameOwner();
	cout << "Введите название производителя" << endl;
	inputNameManufacturer();
	cout << "Введите стоимость инструмента" << endl;
	inputCost();
	cout << "Введите краткое текстовое описание" << endl;
	inputDescription();
}

void Stringed::input_from_file(ifstream& fin) {
	string s;
	if (s.find("Струнный"))
	{
		getline(fin, s);
		inputFaleName(fin);
		inputFaleNameOwner(fin);
		inputFaleNameManufacturer(fin);
		inputFaleCost(fin);
		inputFaleDescription(fin);
	}
	else
		cout << "Не найдено ни одного струнного" << endl;
}

void Stringed::output_console() {
	cout << "Название инструмента: " << name << endl;
	cout << "ФИО владельца: " << name_owner << endl;
	cout << "Наименование производителя: " << name_manufacturer << endl;
	cout << "Стоимость инструмента: " << cost << endl;
	cout << "Краткое описание: " << description << endl;
}

void Stringed::output_to_file(ofstream& fout) {
	fout << "Название инструмента: " << name << endl;
	fout << "ФИО владельца: " << name_owner << endl;
	fout << "Наименование производителя: " << name_manufacturer << endl;
	fout << "Стоимость инструмента: " << cost << endl;
	fout << "Краткое описание: " << description << endl;
}

void Stringed::coding_to_file(ofstream& fout) {
	fout << encrip("Название инструмента: ") << encrip(name) << endl;
	fout << encrip("ФИО владельца: ") << encrip(name_owner) << endl;
	fout << encrip("Наименование производителя: ") << encrip(name_manufacturer) << endl;
	fout << encrip("Стоимость инструмента: ") << encrip(to_string(cost)) << endl;
	fout << encrip("Краткое описание: ") << encrip(description) << endl;
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
				cout << "Ничего не изменено" << endl << endl;
				break;
			case 1:
				cout << "Введите новое название струнного инструмента" << endl;
				getline(cin, tmp);
				inputName();
				cout << "Изменено название струнного инструмента" << endl << endl;
				break;
			case 2:
				cout << "Введите новое ФИО владельца струнного инструмента" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "Изменено ФИО владельца струнного инструмента" << endl << endl;
				break;
			case 3:
				cout << "Введите новое наименование производителя струнного инструмента" << endl;
				getline(cin, tmp);
				inputNameManufacturer();
				cout << "Изменено наименование производителя струнного инструмента" << endl << endl;
				break;
			case 4:
				cout << "Введите новую стоимость струнного инструмента" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "Изменена стоимость струнного инструмента" << endl << endl;
				break;
			case 5:
				cout << "Введите новое краткое описание струнного инструмента" << endl;
				getline(cin, tmp);
				inputDescription();
				cout << "Изменено краткое описание струнного инструмента" << endl << endl;
				break;
			}
			if (punkt_menu == 6)
				break;
		}
		else
			cout << "Введен не верный пункт. Повторите ввод." << endl;
	}
}

void Stringed::print_menu_change() {
	cout << "Что хотите изменить? " << endl;
	cout << "0. Ничего не изменять" << endl;
	cout << "1. Название инструмента" << endl;
	cout << "2. ФИО владельца" << endl;
	cout << "3. Наименование производителя" << endl;
	cout << "4. Стоимость инструмента" << endl;
	cout << "5. Краткое описание" << endl;
	cout << "6. Выход в главное меню" << endl;
}