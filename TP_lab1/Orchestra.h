#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"Base.h"
#include "Percussion.h"
#include "Stringed.h"
#include "Wind.h"

using namespace std;

class Orchestra: public Base // класс оркестр
{
private:
	string name; // название оркестра
	Percussion* data_p; // ударные 
	int length_p;
	Stringed* data_s; // струнные
	int length_s;
	Wind* data_w; // духовые
	int length_w;

public:
	Orchestra();
	Orchestra(string, int, int, int);
	Orchestra(const Orchestra&);
	~Orchestra();

	Orchestra& operator=(const Orchestra&);

	void setName(string _name) { name = _name; }
	void setLength_p(int _length_p) { length_p = _length_p; }
	void setLength_s(int _length_s) { length_s = _length_s; }
	void setLength_w(int _length_w) { length_w = _length_w; }

	string getName() { return name; }
	int getLength_p() { return length_p; }
	int getLength_s() { return length_p; }
	int getLength_w() { return length_p; }

	// работа с оркестром
	void creat_orchestra();
	void input_from_file(ifstream&);
	void inputName();
	void inputFaleName(ifstream&);
	int inputFaleLenght_p(ifstream&);
	int inputFaleLenght_s(ifstream&);
	int inputFaleLenght_w(ifstream&);
	void output_console();
	void output_to_file(ofstream&);
	void coding_to_file(ofstream&);

	void menu_selecting_type_instrument();
	void selecting_type_instrument();
	void selecting_change_instrument();
	void selecting_delite_instrument();

	// работа с Percussion
	//Percussion& operator[](int index);
	void creat_percussion();
	void memory_allocation_percussion(Percussion&);
	
	int choosing_percussion();
	void print_percussion();
	void delite_one_percussion(int);

	// работа с Stringed
	//Stringed& operator[](int index);
	void creat_stringed();
	void memory_allocation_stringed(Stringed&);

	int choosing_stringed();
	void print_stringed();
	void delite_one_stringed(int);
};

