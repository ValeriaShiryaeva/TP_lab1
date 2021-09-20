#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Orchestra // класс оркестр
{
protected:
	string name; // название инструмента
	double cost; // стоимость инструмента
	int quantity; // количество единиц в оркестре
	string name_owner; // имя владельца

public:

	// ввод информаци с клавиатуры
	 void input_keyboard();

	// ввод информаци из файла
	 void input_from_file(ifstream&);

	// вsвод информаци в консоль
	 void output_console();

	// вывод информаци в файл
	 void output_to_file(ofstream&);
};

