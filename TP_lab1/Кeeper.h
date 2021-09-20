//#pragma once
//#include <iostream>
//#include <string>
//#include <cassert> // для assert()
//using namespace std;
//
//class Кeeper
//{
//private:
//	int length;
//	int* data;
//
//public:
//	Кeeper():length(0), data(nullptr) {} // конструктор без параметров
//	Кeeper(int _length):length(_length) { // конструктор с параметрами
//
//		allocation_of_memory();
//
//		if (_length > 0)
//			data = new int[_length];
//		else
//			data = nullptr;
//	}
//
//	~Кeeper() {// декструктор (освобождение любой динамической памяти)
//		delete[] data;
//	}
//
//	void erase(); // деструктор всего массива
//
//	int& operator[](int index); // перегрузка оператора индексации
//
//	int getLength() { return length; } // получение длинны массива
//
//	void creat_container(); // создание контейнера	
//
//	void output_container(); // вывод содержимого контейнера 
//
//	int allocation_of_memory(); // проверка длины контейнера
//};
//
