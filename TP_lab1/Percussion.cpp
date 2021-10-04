#include "Percussion.h"

string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string numbers = "1234567890."; // вынести их в нормальное место


void Percussion::input_keyboard() {

	string _type, _name, _cost, _name_owner;

	quantity ++;

	cout << "Введите тип ударного инструмента" << endl;
	getline(cin, _type); // cinignor сделать почему-то
	getline(cin, _type); 
	if (_type.find_first_not_of(letters_symbols) == string::npos)
		type = _type;
	else
		type = "uncounted";

	cout << "Введите название инструмента" << endl;
	getline(cin, _name);
	if (_name.find_first_not_of(letters_symbols) == string::npos)
		name = _name;
	else
		name = "uncounted";

	cout << "Введите цену инструмента" << endl;
	getline(cin, _cost);
	if (_cost.find_first_not_of(numbers) == string::npos)
	{
		double tmp = stod(_cost);
		cost = tmp;
	}
	else
		cost = 0;

	cout << "Введите имя владельца" << endl;
	getline(cin, _name_owner);
	if (_name_owner.find_first_not_of(letters_symbols) == string::npos)
		name_owner = _name_owner;
	else
		name_owner = "uncounted";
}

void Percussion::output_console() {
	cout << "Тип инструмента: " << type << endl;
	cout << "Название инструмента: " << name << endl;
	cout << "Стоимость иснтрумента: " << cost << endl;
	cout << "Колличество единиц в оркестре: " << quantity << endl;
	cout << "ФИО владельца: " << name_owner << endl;
}



