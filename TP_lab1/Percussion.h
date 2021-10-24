#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"CoderDecoder.h"

using namespace std;

class Percussion  // ударные инструменты
{
private:
	string type; // тип инструмента
	string name; // название инструмента
	double cost; // стоимость инструмента
	string name_owner; // ФИО владельца
	
public:

	Percussion();
	Percussion(string, string, double, string);
	Percussion(const Percussion&);
	~Percussion();

	void setType(string _type) { type = _type; }
	void setName(string _name) { name = _name; }
	void setCost(double _cost) { cost = _cost; }
	void setNameOwer(string _name_owner) { name_owner = _name_owner; }

	string getType() { return type; }
	string getName() { return name; }
	double getCost() { return cost; }
	string getNameOwer() { return name_owner; }

	void inputType();
	void inputName();
	void inputCost();
	void inputNameOwner();

	void inputFileType(ifstream&);
	void inputFileName(ifstream&);
	void inputFileCost(ifstream&);
	void inputFileNameOwner(ifstream&);

	void input_keyboard();
	void input_from_file(ifstream&);
	void output_console();
	void output_to_file(ofstream&);
	void coding_to_file(ofstream&);

	void change();
	void print_menu_change();
};