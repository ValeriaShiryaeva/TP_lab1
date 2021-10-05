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
	Кeeper():length(0), data(nullptr) {} 

	Кeeper(int _length):length(_length) { 
		for (int i = 0; i < length; i++)
			creat();
	}

	Кeeper(const Кeeper& keeper) {
		data = new Orchestra[keeper.length];
		length = keeper.length;
		for (int i = 0; i < keeper.length; i++)
			data[i] = keeper.data[i];
	}

	~Кeeper() {	delete[] data;	}

	Кeeper& operator=(const Кeeper&);

	Orchestra& operator[](int index); // перегрузка оператора индексации

	int getLength() { return length; } // получение длинны массива

	void creat(); // создание контейнера	

	void memory_allocation( Orchestra&);

	void output_container(); // вывод содержимого контейнера 

	//void erase(); // деструктор всего массива
};

