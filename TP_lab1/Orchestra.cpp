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
	for (int i = 0; i < length_s; i++)
		creat_stringed();

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

//Percussion& Orchestra::operator[](int index) {
//	if (index >= 0 && index < length_p);
//	return data_p[index];
//}

//Stringed& Orchestra::operator[](int index) {
//	if (index >= 0 && index < length_s);
//	return data_s[index];
//}

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

void  Orchestra::input_from_file(ifstream& fin) {

	string s;
	getline(fin, s);
	inputFaleName(fin);
	fin >> s;
	if (s == "Ударные")
	{
		int _length_p = inputFaleLenght_p(fin);
		if(_length_p != 0)
		{
			for (int i = 0; i < _length_p; i++)
			{
				cout << "Найдено " << _length_p << " ударных" << endl;
				Percussion Per;
				Per.input_from_file(fin);
				memory_allocation_percussion(Per);
				cout << "Считан " << i + 1 << " ударный инструмент" << endl;
			}
			cout << "Считаны ударные инструменты оркестра" << endl;
		} 
		else
			cout << "Не найдено количество ударных инструментов" << endl;
	}
	else
		cout << "Не найдено ударных инструментов" << endl;
	fin >> s;
	if (s == "Струнные")
	{
		int _length_s = inputFaleLenght_s(fin);
		if (_length_s != 0)
		{
			for (int i = 0; i < _length_s; i++)
			{
				cout << "Найдено " << _length_s << " струнных" << endl;
				Stringed Str;
				Str.input_from_file(fin);
				memory_allocation_stringed(Str);
				cout << "Считан " << i + 1 << " струнный инструмент" << endl;
			}
			cout << "Считаны струнные инструменты оркестра" << endl;
		}		
		else
			cout << "Не найдено количество струнных инструментов" << endl;
	}
	else
		cout << "Не найдено струнных инструментов" << endl;
}

void Orchestra::inputFaleName(ifstream& fin) {
	string s;
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
}

int Orchestra::inputFaleLenght_p(ifstream& fin) {
	string s;
	getline(fin, s);
	getline(fin, s);
	if (s.find("Количество ударных:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_int_signed) == string::npos)
		{
			int _length_p = stoi(s);
			return _length_p;
		}
		else
		{
			cout << "Не верно записано количество ударных инструментов" << endl;
			return 0;
		}
	}
	else
		return 0;	
}

int Orchestra::inputFaleLenght_s(ifstream& fin) {
	string s;
	getline(fin, s);
	getline(fin, s);
	if (s.find("Количество струнных:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_int_signed) == string::npos)
		{
			int _length_s = stoi(s);
			return _length_s;
		}
		else
		{
			cout << "Не верно записано количество струнных инструментов" << endl;
			return 0;
		}
	}
	else
		return 0;
}

void Orchestra::output_console() {
	cout << "Инструменты оркестра " << name << endl;
	cout << "Ударные" << endl;
	cout << "Количество ударных в оркестре: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}

	cout << "Струнные" << endl;
	cout << "Количество струнных в оркестре: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		cout << i + 1 << '.' << endl;
		data_s[i].output_console();
	}
	cout << endl;
}

void Orchestra::output_to_file(ofstream& fout) {
	fout << "Название оркестра: " << name << endl;

	fout << "Ударные" << endl;
	fout << "Количество ударных: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << "Ударный " << i + 1 << endl;
		data_p[i].output_to_file(fout);
	}

	fout << "Струнные" << endl;
	fout << "Количество струнных: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		fout << "Струнный " << i + 1 << endl;
		data_s[i].output_to_file(fout);
	}
}

void Orchestra::coding_to_file(ofstream& fout) {
	fout << encrip("Название оркестра: ") << encrip(name) << endl;

	fout << encrip("Ударные") << endl;
	fout << encrip("Количество ударных: ") << encrip(to_string(length_p)) << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << encrip("Ударный ") << encrip(to_string(i + 1)) << endl;
		data_p[i].coding_to_file(fout);
	}

	fout << encrip("Струнные") << endl;
	fout << encrip("Количество струнных: ") << encrip(to_string(length_s)) << endl;
	for (int i = 0; i < length_s; i++)
	{
		fout << encrip("Струнный ") << encrip(to_string(i + 1)) << endl;
		data_s[i].coding_to_file(fout);
	}
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
				creat_stringed();
				break;
			case 3:
				break;
			}
			break;
		}
		cout << "Не верно введен номер типа инструмента" << endl;
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

void Orchestra::creat_stringed() {
	Stringed Str;
	Str.input_keyboard();
	memory_allocation_stringed(Str);
}

void Orchestra::memory_allocation_percussion(Percussion& Per) {
	Percussion* tmp = data_p;
	length_p++;
	data_p = new Percussion[length_p];
	for (int i = 0; i < length_p - 1; i++)
		data_p[i] = tmp[i];
	data_p[length_p - 1] = Per;
}

void Orchestra::memory_allocation_stringed(Stringed& Str) {
	Stringed* tmp = data_s;
	length_s++;
	data_s = new Stringed[length_s];
	for (int i = 0; i < length_s - 1; i++)
		data_s[i] = tmp[i];
	data_s[length_s - 1] = Str;
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
				if (length_p == 0)
					cout << "В этом оркестре нет ударных инструментов" << endl;
				else
				{
					data_p[choosing_percussion() - 1].change();
					cout << "Ударный инструмент оркеста изменен" << endl;
				}
				break;
			case 2:
				if (length_s == 0)
					cout << "В этом оркестре нет струнных инструментов" << endl;
				else
				{
					data_s[choosing_stringed() - 1].change();
					cout << "Струнный инструмент оркеста изменен" << endl;
				}
				break;
			case 3:
				break;
			}
			break;
		}
		cout << "Не верно введен номер типа инструмента" << endl;
	}
}

int Orchestra::choosing_percussion() {
	print_percussion();
	cout << "Выбор ударного инструмента. ";
	int number_percussion = input_number();
	while (1) {
		if (number_percussion <= length_p && number_percussion != 0)
			return number_percussion;
		else {
			cout << "Введен неверный номер ударного инструмента. Повторите ввод" << endl;
			number_percussion = input_number();
		}
	}
}

int Orchestra::choosing_stringed() {
	print_stringed();
	cout << "Выбор струнного инструмента. ";
	int number_percussion = input_number();
	while (1) {
		if (number_percussion <= length_s && number_percussion != 0)
			return number_percussion;
		else {
			cout << "Введен неверный номер струнного инструмента. Повторите ввод" << endl;
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
			switch (punkt_menu)
			{
			case 1:
				if (length_p == 0)
					cout << "В этом оркестре нет ударных инструментов" << endl;
				else
				{
					delite_one_percussion(choosing_percussion() - 1);
					cout << "Ударный инструмент оркеста удален" << endl;
				}
				break;
			case 2:
				if (length_s == 0)
					cout << "В этом оркестре нет струнных инструментов" << endl;
				else
				{
					delite_one_stringed(choosing_stringed() - 1);
					cout << "Струнный инструмент оркеста удален" << endl;
				}
				break;
			case 3:
				break;
			}
			break;
		}
		cout << "Не верно введен номер типа инструмента" << endl;
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

void Orchestra::delite_one_stringed(int number) {
	Stringed* tmp = new Stringed[length_s - 1];
	int t = 0;
	for (int i = 0; i < length_s; i++)
	{
		if (i != number)
			tmp[t++] = data_s[i];
	}
	length_s--;
	data_s = tmp;
}

void Orchestra::print_percussion() {
	cout << "Ударные" << endl;
	cout << "Колличество ударных в оркестре: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}
	cout << endl;
}

void Orchestra::print_stringed() {
	cout << "Струнные" << endl;
	cout << "Колличество струнных в оркестре: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		cout << i + 1 << '.' << endl;
		data_s[i].output_console();
	}
	cout << endl;
}
