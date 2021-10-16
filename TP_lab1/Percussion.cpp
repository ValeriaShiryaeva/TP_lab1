#include "Percussion.h"

string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string numbers_double = "1234567890."; // вынести их в нормальное место

int input_number();

Percussion::Percussion() : type("uncounted"), name("uncounted"), cost(0), name_owner("uncounted") {}

Percussion::Percussion(string _type, string _name, double _cost, int _quantity, string _name_owner) :
	type(_type), name(_name), cost(_cost), name_owner(_name_owner) {
	input_keyboard();
}

void Percussion::input_keyboard() {
	cout << "Введите тип ударного инструмента" << endl;
	string tmp;
	getline(cin, tmp); // cinignor сделать почему-то
	inputType();
	cout << "Введите название инструмента" << endl;
	inputName();
	cout << "Введите цену инструмента" << endl;
	inputCost();
	cout << "Введите имя владельца" << endl;
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
			cout << "Введен неверный тип ударного инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное название инструмента, повторите ввод." << endl;
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
			cout << "Введена неверная цена инструмента, повторите ввод." << endl;
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
			cout << "Введено не верное имя владельца, повторите ввод." <<endl;
	}
}


void Percussion::output_console() {
	cout << "Тип инструмента: " << getType() << endl;
	cout << "Название инструмента: " << getName() << endl;
	cout << "Стоимость иснтрумента: " << getCost() << endl;
	cout << "ФИО владельца: " << getNameOwer() << endl;
}

void Percussion::output_to_file(ofstream& fout) {
	fout << "Тип инструмента: " << getType() << endl;
	fout << "Название инструмента: " << getName() << endl;
	fout << "Стоимость иснтрумента: " << getCost() << endl;
	fout << "ФИО владельца: " << getNameOwer();
}

void Percussion::change() {
	print_menu_change();
	string tmp;
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu == 0 || punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4 || punkt_menu == 5)
		{
			switch (punkt_menu) // оператор switch 
			{
			case 0:
				cout << "Ничего не изменено" << endl << endl;
				break;
			case 1:
				cout << "Введите новый тип ударного инструмента" << endl;
				getline(cin, tmp);
				inputType();
				cout << "Изменен тип ударного инструмента" << endl << endl;
				break;
			case 2:
				cout << "Введите новое название ударного инструмента" << endl;
				getline(cin, tmp);
				inputName();
				cout << "Изменено название ударного инструмента" << endl << endl;
				break;
			case 3:
				cout << "Введите новую стоимость ударного инструмента" << endl;
				getline(cin, tmp);
				inputCost();
				cout << "Изменена стоимость ударного инструмента" << endl << endl;
				break;
			case 4:
				cout << "Введите новое ФИО владельца ударного инструмента" << endl;
				getline(cin, tmp);
				inputNameOwner();
				cout << "Изменено ФИО владельца ударного инструмента" << endl << endl;
				break;
			}
			if (punkt_menu == 5)
				break;
				
		}
		else
			cout << "Введено не верный номер. ";		
	}
	
}

void Percussion::print_menu_change() {
	cout << "Что хотите изменить? "<< endl;
	cout << "0. Ничего не изменять" << endl;
	cout << "1. Тип инструмента" << endl;
	cout << "2. Название инструмента"  << endl;
	cout << "3. Стоимость инструмента"  << endl;
	cout << "4. ФИО владельца"  << endl;
	cout << "5. Выход в главное меню" << endl;
}



