#pragma once
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
	�eeper():length(0), data(nullptr) {} 

	�eeper(int _length):length(_length) { 
		for (int i = 0; i < length; i++)
			creat();
	}

	�eeper(const �eeper& keeper) {
		data = new Orchestra[keeper.length];
		length = keeper.length;
		for (int i = 0; i < keeper.length; i++)
			data[i] = keeper.data[i];
	}

	~�eeper() {	delete[] data;	}

	�eeper& operator=(const �eeper&);

	Orchestra& operator[](int index); // ���������� ��������� ����������

	int getLength() { return length; } // ��������� ������ �������

	void creat(); // �������� ����������	

	void memory_allocation( Orchestra&);

	void output_container(); // ����� ����������� ���������� 

	//void erase(); // ���������� ����� �������
};

