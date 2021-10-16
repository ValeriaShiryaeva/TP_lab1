#pragma once
#include <string>
#include <cassert> // ��� assert()
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

	void creat(); 

	void memory_allocation( Orchestra&);

	void output_container_console();  

	void output_to_file(ofstream&);

	void delite_container();

	void change_container();

	void print_menu_change();

	void choosing_orchestra();
	
	int choosing_change_orchestra();

	void menu_change_orchestra();
	void print_menu_change_orchestra();

};

