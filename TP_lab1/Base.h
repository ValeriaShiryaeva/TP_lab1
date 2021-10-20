#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Base
{
public:
	Base() { cout << "The constructor is called Base" << endl; }
	~Base() { cout << "Destructor called Base" << endl; }
	virtual void input_from_file(ifstream&) = 0;
	virtual void output_console() = 0;
	virtual void output_to_file(ofstream&) = 0;
	virtual void coding_to_file(ofstream&) = 0;
	
};

