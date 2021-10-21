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
			cout << "Введено не верное название инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное наименование производителя, повторите ввод." << endl;
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
			cout << "Введена неверная цена инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное ФИО владельца, повторите ввод." << endl;
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
			cout << "Введено не верное краткое описание дефектов, повторите ввод." << endl;
	}
}

void Wind::inputFaleName(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Название инструмента:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			name = s;
			cout << "Считано название духового инструмента" << endl;
		}
		else
			cout << "Не верно записано название духового инструмента" << endl;
	}
	else
		cout << "Не найдено название духового инструмента" << endl;
}

void Wind::inputFaleNameManufacturer(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Наименование производителя:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			name_manufacturer = s;
			cout << "Считано название производителя духового инструмента" << endl;
		}
		else
			cout << "Не верно записано название производителя духового инструмента" << endl;
	}
	else
		cout << "Не найдено название производителя духового инструмента" << endl;
}

void Wind::inputFaleCost(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Стоимость инструмента:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_double_signed) == string::npos)
		{
			cost = stoi(s);
			cout << "Считана стоимость духового иснтурмента" << endl;
		}
		else
			cout << "Не верно записана стоимость духового инструмента" << endl;
	}
	else
		cout << "Не найдена стоимость духового инструмента" << endl; 
}

void Wind::inputFaleNameOwner(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("ФИО владельца:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos) {
			name_owner = s;
			cout << "Считано ФИО владельца духового инструмента" << endl;
		}
		else
			cout << "Не верно записано ФИО владельца духового инструмента" << endl;
	}
	else
		cout << "Не найдено ФИО владельца духового инструмента" << endl;
}

void Wind::inputFaleDefects(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("Краткое описание дефектов:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(W_string_signed) == string::npos)
		{
			defects = s;
			cout << "Считано краткое описание дефектов духовго инструмента" << endl;
		}
		else
			cout << "Не верно написано краткое описание дефектов духовго инструмента" << endl;
	}
	else
		cout << "Не найдено краткое описание дефектов духовго инструмента" << endl;
}

void Wind::input_keyboard() {
	cout << "Введите название инструмента" << endl;
	inputName();
	cout << "Введите название производителя" << endl;
	inputNameManufacturer();
	cout << "Введите стоимость инструмента" << endl;
	inputCost();
	cout << "Введите ФИО владельца" << endl;
	inputNameOwner();
	cout << "Введите краткое текстовое описание дефектов" << endl;
	inputDefects();
}

void Wind::input_from_file(ifstream& fin) {
	string s;
	if (s.find("Духовой"))
	{
		getline(fin, s);
		inputFaleName(fin);
		inputFaleNameManufacturer(fin);
		inputFaleCost(fin);
		inputFaleNameOwner(fin);
		inputFaleDefects(fin);
	}
	else
		cout << "Не найдено ни одного духовного" << endl;
}

void Wind::output_console() {
	cout << "Название инструмента: " << name << endl;
	cout << "Наименование производителя: " << name_manufacturer << endl;
	cout << "Стоимость инструмента: " << cost << endl;
	cout << "ФИО владельца: " << name_owner << endl;
	cout << "Краткое описание дефектов: " << defects << endl;
}

void Wind::output_to_file(ofstream& fout) {
	fout << "Название инструмента: " << name << endl;
	fout << "Наименование производителя: " << name_manufacturer << endl;
	fout << "Стоимость инструмента: " << cost << endl;
	fout << "ФИО владельца: " << name_owner << endl;
	fout << "Краткое описание дефектов: " << defects << endl;
}

void Wind::coding_to_file(ofstream& fout) {
	fout << encrip("Название инструмента: ") << encrip(name) << endl;
	fout << encrip("Наименование производителя: ") << encrip(name_manufacturer) << endl;
	fout << encrip("Стоимость инструмента: ") << encrip(to_string(cost)) << endl;
	fout << encrip("ФИО владельца: ") << encrip(name_owner) << endl;
	fout << encrip("Краткое описание дефектов: ") << encrip(defects) << endl;
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
				cout << "Ничего не изменено" << endl << endl;
				break;
			case 1:
				cout << "Введите новое название духовного инструмента" << endl;
				getline(cin, tmp);
				inputName();
				cout << "Изменено название духовного инструмента" << endl << endl;
				break;
			case 2:
				cout << "Введите новое наименование производителя духовного инструмента" << endl;
				getline(cin, tmp);
				inputNameManufacturer();
				cout << "Изменено наименование производителя духовного инструмента" << endl << endl;
				break;
			case 3:
				cout << "Введите новую стоимость духовного инструмента" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "Изменена стоимость духовного инструмента" << endl << endl;
				break;
			case 4:
				cout << "Введите новое ФИО владельца духовного инструмента" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "Изменено ФИО владельца духовного инструмента" << endl << endl;
				break;
			case 5:
				cout << "Введите новое краткое описание дефектов духовного инструмента" << endl;
				getline(cin, tmp);
				inputDefects();
				cout << "Изменено краткое описание дефектов духовного инструмента" << endl << endl;
				break;
			}
			if (punkt_menu == 6)
				break;
		}
		else
			cout << "Введен не верный пункт. Повторите ввод." << endl;
	}
}

void Wind::print_menu_change() {
	cout << "Что хотите изменить? " << endl;
	cout << "0. Ничего не изменять" << endl;
	cout << "1. Название инструмента" << endl;
	cout << "2. Наименование производителя" << endl;
	cout << "3. Стоимость инструмента" << endl;
	cout << "4. ФИО владельца" << endl;
	cout << "5. Краткое описание дефектов" << endl;
	cout << "6. Выход в главное меню" << endl;
}