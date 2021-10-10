#include "Percussion.h"

Percussion::Percussion() : type("uncounted"), name("uncounted"), cost(0), name_owner("uncounted") {}

Percussion::Percussion(string _type, string _name, double _cost, int _quantity, string _name_owner) :
	type(_type), name(_name), cost(_cost), name_owner(_name_owner) {
	input_keyboard();
}

void Percussion::input_keyboard() {

	string _type, _name, _cost, _name_owner;

	cout << "Введите тип ударного инструмента" << endl;
	getline(cin, _type); // cinignor сделать почему-то
	while (1) {
		getline(cin, _type);
		if (_type.find_first_not_of(letters_symbols) == string::npos)
		{
			setType(_type);
			break;
		}
		else
			cout << "Введен неверный тип ударного инструмента, повторите ввод: ";
	}
	

	cout << "Введите название инструмента" << endl;
	while (1)
	{
		getline(cin, _name);
		if (_name.find_first_not_of(letters_symbols) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "Введено не верное название инструмента, повторите ввод: ";
	}

	cout << "Введите цену инструмента" << endl;
	while (1) {
		getline(cin, _cost);
		if (_cost.find_first_not_of(numbers_double) == string::npos)
		{
			double tmp = stod(_cost);
			setCost(tmp);
			break;
		}
		else
			cout << "Введена неверная цена инструмента, повторите ввод: ";
	}
	
	cout << "Введите имя владельца" << endl;
	while (1) {
		getline(cin, _name_owner);
		if (_name_owner.find_first_not_of(letters_symbols) == string::npos)
		{
			setNameOwer(_name_owner);
			break;
		}
		else
			cout << "Введено не верное имя владельца, повторите ввод: ";
	}
	cout << endl;
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



