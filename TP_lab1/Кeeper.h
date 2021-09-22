#pragma once
//#include <iostream>
#include <string>
#include <cassert> // ��� assert()
#include "Orchestra.h" 
using namespace std;

class �eeper
{
private:
	int length;
	Orchestra* data;

public:
	�eeper():length(0), data(nullptr) {} // ����������� ��� ����������
	�eeper(int _length):length(_length) { // ����������� � �����������

		allocation_of_memory();

		if (_length > 0)
			data = new Orchestra[_length];
		else
			data = nullptr;
	}

	~�eeper() {// ����������� (������������ ����� ������������ ������)
		delete[] data;
	}

	void erase(); // ���������� ����� �������

	Orchestra& operator[](int index); // ���������� ��������� ����������

	Orchestra& operator>> (Orchestra&);
	Orchestra& operator<< (Orchestra&);

	int getLength() { return length; } // ��������� ������ �������

	void creat_container(); // �������� ����������	

	void output_container(); // ����� ����������� ���������� 

	Orchestra& allocation_of_memory(); // �������� ����� ����������
};

