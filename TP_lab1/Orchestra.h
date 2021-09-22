#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Orchestra // класс оркестр
{
protected:
	string name; // название оркестра
	int quantity; // количество единиц в оркестре


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

