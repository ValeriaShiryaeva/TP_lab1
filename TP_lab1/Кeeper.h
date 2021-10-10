#pragma once
#include <string>
#include <cassert> // äëÿ assert()
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

	void creat(); // ñîçäàíèå êîíòåéíåğà	

	void memory_allocation( Orchestra&);

	void output_container_console();  

	void output_to_file(ofstream&);
};

