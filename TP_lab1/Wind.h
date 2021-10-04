#pragma once
#include <string>

using namespace std;

class Wind  // духовые инструменты
{
private:
	string name; // название инструмента
	string name_manufacturer; // наименование производителя
	double cost; // стоимость инструмента
	string name_owner; // ФИО владельца
	int quantity; // количество единиц в оркестре
    string defects; // описание дефектов
};
