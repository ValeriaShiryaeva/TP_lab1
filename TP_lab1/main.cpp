#include <iostream>
using namespace std;

void menu();
void print_menu();

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
	cout << "	5. Выход из программы" << endl;
}