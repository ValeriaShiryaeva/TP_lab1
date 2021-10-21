#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"CoderDecoder.h"
using namespace std;

class Wind  // духовые инструменты
{
private:
	string name; // название инструмента
	string name_manufacturer; // наименование производителя
	double cost; // стоимость инструмента
	string name_owner; // ФИО владельца
    string defects; // описание дефектов
public:
	Wind();
	Wind(string, string, double, string, string);
	Wind(const Wind&);
	~Wind();

	void setName(string _name) { name = _name; }
	void setNameManufacturer(string _name_manufacturer) { name_manufacturer = _name_manufacturer; }
	void setCost(double _cost) { cost = _cost; }
	void setNameOwer(string _name_owner) { name_owner = _name_owner; }
	void setDefects(string _defects) { defects = _defects; }

	string getName() { return name; }
	string setNameManufacturer() { return name_manufacturer; }
	double getCost() { return cost; }
	string getNameOwer() { return name_owner; }
	string getDefects() { return defects; }

	void inputName();
	void inputNameManufacturer();
	void inputCost();
	void inputNameOwner();
	void inputDefects();

	void inputFaleName(ifstream&);
	void inputFaleNameManufacturer(ifstream&);
	void inputFaleCost(ifstream&);
	void inputFaleNameOwner(ifstream&);
	void inputFaleDefects(ifstream&);

	void input_keyboard();
	void input_from_file(ifstream&);
	void output_console();
	void output_to_file(ofstream&);
	void coding_to_file(ofstream&);

	void change();
	void print_menu_change();
};

