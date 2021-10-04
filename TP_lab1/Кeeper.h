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
	�eeper():length(0), data(nullptr) {} // ����������� ��� ����������
	//�eeper(int _length):length(_length) { // ����������� � �����������
	//	cout << "�������� ��������" << endl;
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

	~�eeper() {// ����������� (������������ ����� ������������ ������)
		delete[] data;
	}

	//void erase(); // ���������� ����� �������

	Orchestra& operator[](int index); // ���������� ��������� ����������

	int getLength() { return length; } // ��������� ������ �������

	void creat_container(); // �������� ����������	

	void output_container(); // ����� ����������� ���������� 
};

