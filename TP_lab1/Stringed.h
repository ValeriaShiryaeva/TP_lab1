#pragma once
#include <string>

using namespace std;

class Stringed // струнные инструменты
{
private:
	string name; // название инструмента
	string name_owner; // ФИО владельца
	string name_manufacturer; // наименование производителя
	double cost; // стоимость инструмента
	int quantity; // количество единиц в оркестре
	string defects; // описание дефектов
};
