#include <iostream>
#include <fstream>
using namespace std;

#include "Orchestra.h"
#include "Кeeper.h"

Кeeper keeper;

void menu();
void print_menu();
void choosing_orchestra();
int repeat_input_number();
bool intSigned(const string& );
int input_number();

ofstream fout("Save_container.txt");; // запись данных в файл (сохранение данных в файл)
ifstream fin("Extract_container.txt");; // вывод данных из файла (восстановление данных из файла)

void main()
{
	setlocale(LC_ALL, "rus"); // вывод русского языка в консоли

	//Кeeper keeper(2);
	while (1)
	{
		menu(); // вывод меню на экран
	}
}


void menu() // обработка меню
{
	print_menu(); // вывод меню на экран
	int punkt_menu = input_number();
	switch (punkt_menu) // оператор switch 
	{
	case 1:
		keeper.creat();
		break;
	case 2:
		choosing_orchestra();
		break;
	case 3:
		keeper.output_container();
		break;
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
	int number = input_number() - 1;
	if (number <= keeper.getLength())
		keeper[number].selecting_type_instrument();
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "Ведите номер: " << endl;
		cin >> number_s;
		if (intSigned(number_s) == true)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "Введено не верное значение. Повторите ввод." << endl;
	}
}

bool intSigned(const string& s) // проверка на только цифры в сроке
{
	if (s.find_first_not_of("0123456789", 0) == string::npos)
		return true;
	else
		return false;
}





