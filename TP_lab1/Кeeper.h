#pragma once
#include <string>
#include <cassert> // для assert()
#include "Orchestra.h" 
using namespace std;

class Кeeper
{
private:
	int length;
	Orchestra* data;

public:
	Кeeper():length(0), data(nullptr) {} // конструктор без параметров
	//Кeeper(int _length):length(_length) { // конструктор с параметрами
	//	cout << "Создание оркестра" << endl;
	//	length += 1;
	//	Orchestra Or;
	//	data = new Orchestra[1];
	//	if (_length > 0)
	//		data = new Orchestra[_length];
	//	else
	//		data = nullptr;
	//	//Or.input_keyboard();
	//	//Or.output_console();
	//}

	~Кeeper() {// декструктор (освобождение любой динамической памяти)
		delete[] data;
	}

	//void erase(); // деструктор всего массива

	Orchestra& operator[](int index); // перегрузка оператора индексации

	int getLength() { return length; } // получение длинны массива

	void creat_container(); // создание контейнера	

	void output_container(); // вывод содержимого контейнера 
};

