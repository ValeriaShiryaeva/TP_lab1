#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Percussion.h"
#include "Stringed.h"
#include "Wind.h"

using namespace std;

class Orchestra // класс оркестр
{
private:
	string name; // название оркестра
	int length;
	Percussion* data_p; // ударные 
	int length_p;
	Stringed* data_s; // струнные
	int length_s;
	Wind* data_w; // духовые
	int length_w;

public:
	Orchestra():length(0), length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {} // конструктор без параметров


	Percussion& operator[](int index);

	void creat_percussion(); 

	void output_percussion();

	 void input_keyboard();

	 void output_console();

	 void selecting_type_instrument();

	 void menu_selecting_type_instrument();

	 int getLength() { return length; }

	 string getName() { return name; }

	 void output_console_Orchestra_name();

	 // ввод информаци из файла
	 void input_from_file(ifstream&);

	 // вывод информаци в файл
	 void output_to_file(ofstream&);

};

