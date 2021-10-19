#include "Orchestra.h"

int input_number();

string _string_signed = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string _int_signed = "123456789";

Orchestra::Orchestra() : name("no"), length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {
	cout << "The constructor is called Orchestra" << endl;
}

 // доделать для 2х других инструментов
Orchestra::Orchestra(string _name, int _length_p, int _length_s, int _length_w) : 
	name(_name), length_p(_length_p), length_s(_length_s), length_w(_length_w) {
	for (int i = 0; i < length_p; i++)
		creat_percussion();
	cout << "The constructor with parameters is called Orchestra" << endl;
}

Orchestra::Orchestra(const Orchestra& Or) {
	name = name;
	data_p = new Percussion[Or.length_p];
	length_p = Or.length_p;
	for (int i = 0; i < Or.length_p; i++)
		data_p[i] = Or.data_p[i];

	data_s = new Stringed[Or.length_s];
	length_s = Or.length_s;
	for (int i = 0; i < Or.length_s; i++)
		data_s[i] = Or.data_s[i];

	data_w = new Wind[Or.length_w];
	length_w = Or.length_w;
	for (int i = 0; i < Or.length_w; i++)
		data_w[i] = Or.data_w[i];
	cout << "The copy constructor is called Orchestra" << endl;
}

Orchestra::~Orchestra() {
	delete[] data_p;
	data_p = nullptr;
	length_p = 0;
	delete[] data_s;
	data_s = nullptr;
	length_s = 0;
	delete[] data_w;
	data_w = nullptr;
	length_w = 0;
	cout << "Destructor called Orchestra" << endl;
}

Percussion& Orchestra::operator[](int index) {
	if (index >= 0 && index < getLength_p());
	return data_p[index];
}

Orchestra& Orchestra::operator=(const Orchestra& Or)
{
	if (this == &Or)
		return *this;
	setName(Or.name);

	delete[] data_p;
	data_p = new Percussion[Or.length_p];
	setLength_p(Or.length_p);
	for (int i = 0; i < Or.length_p; i++)
		data_p[i] = Or.data_p[i];

	delete[] data_s;
	data_s = new Stringed[Or.length_s];
	setLength_s(Or.length_s);
	for (int i = 0; i < Or.length_s; i++)
		data_s[i] = Or.data_s[i];

	delete[] data_w;
	data_w = new Wind[Or.length_w];
	setLength_w(Or.length_w);
	for (int i = 0; i < Or.length_w; i++)
		data_w[i] = Or.data_w[i];

	return *this;
}

void Orchestra::creat_orchestra() {
	inputName();
	selecting_type_instrument();
}

void Orchestra::inputName() {
	string _name;
	cout << "Введите название оркестра" << endl;
	getline(cin, _name);
	while (1) {
		getline(cin, _name);
		if (_name.find_first_not_of(_string_signed) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "Не верное название оркестра, повторите ввод" << endl;
	}
}

void Orchestra::output_console() {
	cout << "Инструменты оркестра " << getName() << endl;
	cout << "Ударные" << endl;
	cout << "Колличество ударных в оркестре: " << getLength_p() << endl;
	for (int i = 0; i < getLength_p(); i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}
	cout << endl;
}

void Orchestra::output_to_file(ofstream& fout) {
	fout << "Название оркестра: " << name << endl;
	fout << "Ударные" << endl;
	fout << "Колличество ударных: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << "Ударный " << i + 1 << endl;
		data_p[i].output_to_file(fout);
	}
	fout << endl;
}

void Orchestra::selecting_type_instrument() {
	menu_selecting_type_instrument();
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
		{
			switch (punkt_menu) 
			{
			case 1:
				creat_percussion();
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		}
	}
}

void Orchestra::menu_selecting_type_instrument() {
	cout << "Выберите инструмент:" << endl;
	cout << "1. Ударный" << endl;
	cout << "2. Струнный" << endl;
	cout << "3. Духовой" << endl;
}

void Orchestra::creat_percussion() {
	Percussion Per;
	Per.input_keyboard();
	memory_allocation_percussion(Per);
}

void Orchestra::memory_allocation_percussion(Percussion& Per) {
	Percussion* tmp = data_p;
	length_p++;
	cout << length_p << endl;
	data_p = new Percussion[length_p];
	for (int i = 0; i < length_p - 1; i++)
		data_p[i] = tmp[i];
	data_p[length_p - 1] = Per;
}

void Orchestra::selecting_change_instrument() {
	menu_selecting_type_instrument();
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
		{
			switch (punkt_menu) // оператор switch 
			{
			case 1:
				if (getLength_p() == 0)
					cout << "Количество ударных равно 0, нельзя изменить" << endl;
				else
				{
					data_p[choosing_percussion() - 1].change();
					cout << "Инструмент оркеста изменен" << endl;
				}
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		}
	}
}

int Orchestra::choosing_percussion() {
	print_percussion();
	cout << "Выбор ударного инструмента. ";
	int number_percussion = input_number();
	while (1) {
		if (number_percussion <= getLength_p() && number_percussion != 0)
			return number_percussion;
		else {
			cout << "Введен неверный номер ударного инструмента. Повторите ввод" << endl;
			number_percussion = input_number();
		}
	}
}

void Orchestra::selecting_delite_instrument() {
	menu_selecting_type_instrument();
	while (1) {
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
		{
			switch (punkt_menu) // оператор switch 
			{
			case 1:
				if (getLength_p() == 0)
					cout << "Количество ударных равно 0, нельзя удалить" << endl;
				else
				{
					delite_one_percussion(choosing_percussion() - 1);
					cout << "Инструмент оркеста удален" << endl;
				}
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		}
	}
}

void Orchestra::delite_one_percussion(int number) {
	Percussion* tmp = new Percussion[length_p - 1];
	int t = 0;
	for (int i = 0; i < length_p; i++)
	{
		if (i != number)
			tmp[t++] = data_p[i];
	}
	length_p--;
	data_p = tmp;
}

void Orchestra::print_percussion() {
	cout << "Ударные" << endl;
	cout << "Колличество ударных в оркестре: " << getLength_p() << endl;
	for (int i = 0; i < getLength_p(); i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}
	cout << endl;
}

void  Orchestra::input_from_file(ifstream& fin) {

	string s;
	getline(fin, s);
	getline(fin, s);
	if (s.find("Название оркестра:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_string_signed) == string::npos)
		{
			setName(s);
			cout << "Найдено название оркестра" << endl;
		}
		else
			cout << "Не верно записано название оркестра" << endl;
	}
	else
		cout << "Не найдено название оркестра" << endl;
	
	fin >> s;
	if (s == "Ударные")
	{
		getline(fin, s);
		getline(fin, s);
		if (s.find("Количество ударных:") != string::npos) {
			s = s.substr(s.find_last_of(":") + 2);
			if (s.find_first_not_of(_int_signed) == string::npos)
			{

				int _length_p = stoi(s);
				cout << "Найдено " << _length_p << " ударных" << endl;
				for (int i = 0; i < _length_p; i++) 
				{
					Percussion Per;
					Per.input_from_file(fin);
					memory_allocation_percussion(Per);
					cout << "Считан" << i + 1 << "ударный инструмент" << endl;
				}
			}
			else
				cout << "Не верно записано количество ударных инструментов" << endl;
			cout << "Считаны ударные инструменты оркестра" << endl;
		}
		else
			cout << "Не найдено количество ударных" << endl;
	}	
}

void Orchestra::coding_to_file(ofstream& fout) {
	fout << encrip("Название оркестра: ") << encrip(name) << endl;
	fout << encrip("Ударные") << endl;
	fout << encrip("Колличество ударных: ") << encrip(to_string(length_p)) << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << encrip("Ударный ") << encrip(to_string(i + 1)) << endl;
		data_p[i].coding_to_file(fout);
	}
	fout << endl;
}