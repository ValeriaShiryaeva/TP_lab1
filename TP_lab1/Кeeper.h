//#pragma once
//#include <iostream>
//#include <string>
//#include <cassert> // ��� assert()
//using namespace std;
//
//class �eeper
//{
//private:
//	int length;
//	int* data;
//
//public:
//	�eeper():length(0), data(nullptr) {} // ����������� ��� ����������
//	�eeper(int _length):length(_length) { // ����������� � �����������
//
//		allocation_of_memory();
//
//		if (_length > 0)
//			data = new int[_length];
//		else
//			data = nullptr;
//	}
//
//	~�eeper() {// ����������� (������������ ����� ������������ ������)
//		delete[] data;
//	}
//
//	void erase(); // ���������� ����� �������
//
//	int& operator[](int index); // ���������� ��������� ����������
//
//	int getLength() { return length; } // ��������� ������ �������
//
//	void creat_container(); // �������� ����������	
//
//	void output_container(); // ����� ����������� ���������� 
//
//	int allocation_of_memory(); // �������� ����� ����������
//};
//
