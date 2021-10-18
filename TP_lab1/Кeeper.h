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

	void creat(); 
	void memory_allocation(Orchestra&);

	void output_container_console();
	void output_to_file();
	void input_from_file();
	void coding_to_file();

	int choosing_orchestra();

	void delite_container();
	void print_menu_delite();

	void delite_one_orchestra(int);

	void change_container();
	void print_menu_change();
	void print_menu_change_orchestra();

	
};

