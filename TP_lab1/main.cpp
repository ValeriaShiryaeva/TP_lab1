#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"

void menu();
void print_menu();

ofstream fout("Save_container.txt");; // запись данных в файл (сохранение данных в файл)
ifstream fin("Extract_container.txt");; // вывод данных из файла (восстановление данных из файла)

Orchestra orchestra;

void main()
{
	setlocale(LC_ALL, "rus"); // вывод русского языка в консоли

	//orchestra.input_keyboard();
	orchestra.input_from_file(fin);
	orchestra.output_console();
	//orchestra.output_to_file(fout);

	//while (1)
	//{
	//	menu(); // вывод меню на экран
	//}
}


void menu() // обработка меню
{
	print_menu(); // вывод меню на экран
	int punkt_menu;
	cout << "Введите пункт меню:";
	cin >> punkt_menu;
	switch (punkt_menu) // оператор switch 
	{
	case 5: // выход из программы
		exit(0);
	}
}

void print_menu() // вывод меню на экран
{
	cout << "Выберете пункт меню:" << endl;
	cout << "	1. Введите данные в файл" << endl;
	cout << "	5. Выход из программы" << endl;
}