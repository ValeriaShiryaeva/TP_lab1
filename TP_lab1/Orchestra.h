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
	Percussion* data_p; // ударные 
	int length_p;
	Stringed* data_s; // струнные
	int length_s;
	Wind* data_w; // духовые
	int length_w;

	string letters_symbols = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";

public:
	Orchestra();
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

	void creat_orchestra();

	void output_console();

	void selecting_type_instrument();

	void menu_selecting_type_instrument();

	Percussion& operator[](int index);
	
	void creat_percussion();

	void memory_allocation_percussion(Percussion&);

	void output_to_file(ofstream&);

	void selecting_change_instrument();

	int choosing_percussion();

	void print_percussion();

	void inputName();

	void selecting_delite_instrument();
	void delite_one_percussion(int);

	 //void input_from_file(ifstream&);
	 //void output_to_file(ofstream&);

};

