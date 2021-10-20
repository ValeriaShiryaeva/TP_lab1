#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

#include "Orchestra.h"
#include "Кeeper.h"

Кeeper keeper;

void menu();
void print_menu();
void menu_output();
void print_menu_output();
bool intSigned(const string&);
int input_number();

int main()
{
	setlocale(LC_ALL, "rus"); 
	while (1)
		menu();
}

void menu(){
	print_menu();
	int punkt_menu = input_number();
	if (punkt_menu <= 9 && punkt_menu > 0) {
		switch (punkt_menu)
		{
		case 1:
			keeper.creat();
			break;
		case 2:
			if (keeper.getLength() == 0)
				cout << "Вы не можете создать инструмент, сначала создайте оркестр" << endl;
			else
				keeper[keeper.choosing_orchestra() - 1].selecting_type_instrument();
			break;
		case 3:
			keeper.input_from_file();
			break;
		case 4:
			menu_output();
			break;
		case 5:
			if (keeper.getLength() == 0)
				cout << "Вы не можете удалить контейнер и его содержимое. Контейнер пустой" << endl;
			else
				keeper.delite_container();
			break;
		case 6:
			if (keeper.getLength() == 0)
				cout << "Вы не можете ничего изменить. Контейнер пустой" << endl;
			else
				keeper.change_container();
			break;
		case 7:
			keeper.coding_to_file();
			break;
		case 8: 
			keeper.decoding_to_file();
			break;
		case 9: 
			exit(0);
		}
	} 
	else
		cout << "Введен не верный пункт меню. " << endl;
}

void print_menu() // вывод меню на экран
{
	cout << "Выберете пункт меню:" << endl;
	cout << "	1. Создать оркестр" << endl;
	cout << "	2. Создать инструмент оркестра" << endl;
	cout << "	3. Считать данные из файла" << endl;
	cout << "	4. Вывести содержимое контейнера" << endl;
	cout << "	5. Удалить содержимое контейнера" << endl;
	cout << "	6. Изменить содержимое контейнера" << endl;
	cout << "	7. Закодировать содержимое контейнера в файл" << endl;
	cout << "	8. Раскодировать содержимое файла в файл" << endl;
	cout << "	9. Выход из программы" << endl;
}

void print_menu_output() {
	cout << "Выберите, куда вывести информацию" << endl;
	cout << "1. В консоль" << endl;
	cout << "2. В файл" << endl;
}

void menu_output() {
	print_menu_output();
	while (1)
	{
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2)
		{
			switch (punkt_menu)
			{
			case 1:
				keeper.output_to_console();
				break;
			case 2:
				keeper.output_to_file();
				break;
			}
			break;
		}
		else
			cout << "Введен не верный номер пункта. ";
	}	
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "Введите: " << endl;
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

bool intSigned(const string& s) 
{
	if (s.find_first_not_of("0123456789", 0) == string::npos)
		return true;
	else
		return false;
}

