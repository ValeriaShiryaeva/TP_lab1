#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"
#include "Кeeper.h"

Кeeper keeper;

void menu();
void print_menu();
void choosing_orchestra();
int repeat_input_number_orchestra();
void input_number_orchestra();

ofstream fout("Save_container.txt");; // запись данных в файл (сохранение данных в файл)
ifstream fin("Extract_container.txt");; // вывод данных из файла (восстановление данных из файла)


void main()
{
	setlocale(LC_ALL, "rus"); // вывод русского языка в консоли

	while (1)
	{
		menu(); // вывод меню на экран
	}
}


void menu() // обработка меню
{
	print_menu(); // вывод меню на экран
	int punkt_menu;
	cout << "Введите пункт меню: ";
	cin >> punkt_menu; 
	cout << endl;
	switch (punkt_menu) // оператор switch 
	{
	case 1:
		keeper.creat_container();
		break;
	case 2:
		choosing_orchestra();
		break;
	case 3:
		keeper.output_container();
	case 5: // выход из программы
		exit(0);
	}
}

void print_menu() // вывод меню на экран
{
	cout << "Выберете пункт меню:" << endl;
	cout << "	1. Создать оркестр" << endl;
	cout << "	2. Создать инструмент оркестра" << endl;
	cout << "	3. Вывести на экран все содерживмое контейнера" << endl;
	cout << "	5. Выход из программы" << endl;
}

void choosing_orchestra() {
	cout << "Названия оркестров" << endl;
	for (int i = 0; i < keeper.getLength(); i++)
		cout << i + 1 << ". " << keeper[i].getName() << endl;
	input_number_orchestra();
}

void input_number_orchestra() {
	int number_orchestra;
	cout << "Ведите номер оркестра, в который хотите добавить инструмент: " << endl;
	cin >> number_orchestra;
	if (number_orchestra - 1 <= keeper.getLength())
		keeper[number_orchestra].selecting_type_instrument();
	else
		repeat_input_number_orchestra();
}

int repeat_input_number_orchestra() {
	cout << "Введено не верное название оркестра. Выберите действие:" << endl;
	cout << "1. Повторить вввод названия оркестра" << endl;
	cout << "2. Выйти из программы" << endl;
	cout << "Введите номер действия: " << endl;
	int punkt;
	cin >> punkt;
	switch (punkt) // оператор switch 
	{
	case 1:
		input_number_orchestra();
	case 2:
		exit(0);
	}
}





