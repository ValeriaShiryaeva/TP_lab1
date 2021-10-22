#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include"CoderDecoder.h"
#include "Orchestra.h" 
using namespace std;

class �eeper
{
private:
	int length;
	Orchestra* data;

public:
	�eeper();
	�eeper(int);
	�eeper(const �eeper&);
	~�eeper();

	�eeper& operator=(const �eeper&);
	Orchestra& operator[](int); 

	void setLength(int _length) {length = _length; }
	int getLength() { return length; }

	bool checkingFileName(string);

	// ������ � �����������
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

	// ������ � ���������
	int choosing_orchestra();
	void delite_one_orchestra(int);	
	void sorting_orchestra();
};

