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
	//int length;
	Percussion* data_p; // ударные 
	int length_p;
	Stringed* data_s; // струнные
	int length_s;
	Wind* data_w; // духовые
	int length_w;

public:
	Orchestra(): length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {} // конструктор без параметров

	Orchestra(const Orchestra& Or) {
		name = name;
		data_p = new Percussion[Or.length_p];
		length_p = Or.length_p;
		for (int i = 0; i < Or.length_p; i++)
			data_p[i] = Or.data_p[i];

		data_s = new Stringed[Or.length_s];
		length_s = Or.length_s;
		for (int i = 0; i < Or.length_s; i++)
			data_s[i] = Or.data_s[i];

		data_w = new Wind[Or.length_w];
		length_w = Or.length_w;
		for (int i = 0; i < Or.length_w; i++)
			data_w[i] = Or.data_w[i];
	}

	~Orchestra() {
		delete[] data_p; 
		delete[] data_s;
		delete[] data_w;
	}

	Orchestra& operator=(const Orchestra&);

	//int getLength() { return length; }

	string getName() { return name; }

	int getLength_p() { return length_p; }

	void creat_orchestra();

	void output_console();

	void selecting_type_instrument();

	void menu_selecting_type_instrument();

	Percussion& operator[](int index);
	
	void creat_percussion();

	void memory_allocation_percussion(Percussion&);

	

	 //// ввод информаци из файла
	 //void input_from_file(ifstream&);

	 //// вывод информаци в файл
	 //void output_to_file(ofstream&);

};

