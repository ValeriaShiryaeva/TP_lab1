#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"CoderDecoder.h"
using namespace std;

class Stringed // струнные инструменты
{
private:
	string name; // название инструмента
	string name_owner; // ФИО владельца
	string name_manufacturer; // наименование производителя
	double cost; // стоимость инструмента
	string description; // краткое описание инструмента
public:
	Stringed();
	Stringed(string, string, string, double, string);
	Stringed(const Stringed&);
	~Stringed();

	void setName(string _name) { name = _name; }
	void setNameOwer(string _name_owner) { name_owner = _name_owner; }
	void setNameManufacturer(string _name_manufacturer) { name_manufacturer = _name_manufacturer; }
	void setCost(double _cost) { cost = _cost; }
	void settDescription(string _description) { description = _description; }

	string getName() { return name; }
	string getNameOwer() { return name_owner; }
	string setNameManufacturer() { return name_manufacturer; }
	double getCost() { return cost; }
	string settDescription() { return description; }

	void inputName();
	void inputNameOwner();
	void inputNameManufacturer();
	void inputCost();
	void inputDescription();

	void inputFaleName(ifstream&);
	void inputFaleNameOwner(ifstream&);
	void inputFaleNameManufacturer(ifstream&);
	void inputFaleCost(ifstream&);
	void inputFaleDescription(ifstream&);

	void input_keyboard();
	void input_from_file(ifstream&);
	void output_console();
	void output_to_file(ofstream& fout);
	void coding_to_file(ofstream& fout);

	void change();
	void print_menu_change();
};