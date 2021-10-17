#include "Orchestra.h"

int input_number();

Orchestra::Orchestra() : name("no"), length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {
	cout << "The constructor is called Orchestra" << endl;
}
 // доделать
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
		if (_name.find_first_not_of(letters_symbols) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "Не верное название оркестра, повторите ввод:";
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
	fout << "Инструменты оркестра " << getName() << endl;
	fout << "Ударные" << endl;
	fout << "Колличество ударных в оркестре: " << getLength_p() << endl;
	for (int i = 0; i < getLength_p(); i++)
	{
		fout << i + 1 << '.' << endl;
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
			switch (punkt_menu) // оператор switch 
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
	setLength_p(getLength_p() + 1);
	data_p = new Percussion[getLength_p()];
	for (int i = 0; i < getLength_p() - 1; i++)
		data_p[i] = tmp[i];
	data_p[getLength_p() - 1] = Per;
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
					delite_one_percussion(choosing_percussion());
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
	if (getLength_p() > 1) {
		Percussion* tmp = new Percussion[getLength_p() - 1];
		int t = 0;
		for (int i = 0; i < getLength_p()-1; i++)
		{
			if (i != number)
				tmp[t++] = data_p[i];
		}
		setLength_p(getLength_p() - 1);
		data_p = tmp;
	}
	else {
		setLength_p(getLength_p() - 1);
		data_p = new Percussion[0];
	}
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

//void  Orchestra::input_from_file(ifstream& fin) {
//	if (!fin)
//	{
//		cout << "Файл Extract_container.txt не открыт" << endl; // сообщение об ошибке открытия файла
//	}
//	else
//	{
//		string _name, _cost, _quantity, _name_owner;
//		string s ;
//
//		getline(fin, s);
//		if (s.find(' ') != string::npos) {
//			int namber = s.find(':');
//			_name.append(s, namber+2, s.size() - namber - 1);
//			if (_name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM ") == string::npos)
//				name = _name;
//			else 
//				name = "uncounted";
//		}
//		else
//		{
//			name = "uncounted";
//		}
//
//		getline(fin, s);
//		if (s.find(' ') != string::npos) {
//			int namber = s.find(':');
//			_cost.append(s, namber + 2, s.size() - namber- 1);
//			if (_cost.find_first_not_of("0123456789", 0) == string::npos)
//			{
//				cost = stoi(_cost);
//			}
//			else
//				cost = 0;
//		}
//		else
//		{
//			cost = 0;
//		}
//
//		getline(fin, s);
//		if (s.find(' ') != string::npos) {
//			int namber = s.find(':');
//			_quantity.append(s, namber + 2, s.size() - namber - 1);
//			if (_quantity.find_first_not_of("0123456789", 0) == string::npos)
//			{
//				quantity = stoi(_quantity);
//			}
//			else
//				quantity = 0;
//		}
//		else
//		{
//			quantity = 0;
//		}
//
//		getline(fin, s);
//		if (s.find(' ') != string::npos) {
//			int namber = s.find(':');
//			_name_owner.append(s, namber + 2, s.size() - namber - 1);
//			if (_name_owner.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM ") == string::npos)
//				name_owner = _name_owner;
//			else
//				name_owner = "uncounted";
//		}
//		else
//		{
//			name_owner = "uncounted";
//		}
//	}
//
//	
//}