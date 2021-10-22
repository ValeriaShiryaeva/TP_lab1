#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include"CoderDecoder.h"
#include "Orchestra.h" 
using namespace std;

class Êeeper
{
private:
	int length;
	Orchestra* data;

public:
	Êeeper();
	Êeeper(int);
	Êeeper(const Êeeper&);
	~Êeeper();

	Êeeper& operator=(const Êeeper&);
	Orchestra& operator[](int); 

	void setLength(int _length) {length = _length; }
	int getLength() { return length; }

	bool checkingFileName(string);

	// Ğàáîòà ñ êîíòåéíåğîì
	void creat(); 
	void memory_allocation(Orchestra&);

	void input_from_file();
	void output_to_console();
	void output_to_file();
	void coding_to_file();
	void decoding_to_file();
	void change_container();
	void print_menu_change();
	void delite_container();
	void print_menu_delite();
	void menu_sorting();
	void print_menu_sorting();

	// Ğàáîòà ñ îğêåñòğîì
	int choosing_orchestra();
	void delite_one_orchestra(int);	
	void sorting_orchestra();
};

