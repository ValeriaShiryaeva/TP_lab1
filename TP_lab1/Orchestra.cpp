#include "Orchestra.h"

Percussion& Orchestra::operator[](int index) {
	if (index >= 0 && index < length_p);
	return data_p[index];
}

Orchestra& Orchestra::operator=(const Orchestra& Or)
{
	if (this == &Or)
		return *this;
	name = Or.name;
	delete[] data_p;
	data_p = new Percussion[Or.length_p];
	length_p = Or.length_p;
	for (int i = 0; i < Or.length_p; i++)
		data_p[i] = Or.data_p[i];

	delete[] data_s;
	data_s = new Stringed[Or.length_s];
	length_s = Or.length_s;
	for (int i = 0; i < Or.length_s; i++)
		data_s[i] = Or.data_s[i];

	delete[] data_w;
	data_w = new Wind[Or.length_w];
	length_w = Or.length_w;
	for (int i = 0; i < Or.length_w; i++)
		data_w[i] = Or.data_w[i];

	return *this;
}

void Orchestra::creat_orchestra() {

	string _name;
	cout << "Введите название оркестра" << endl;
	getline(cin, _name);
	getline(cin, _name);
	if (_name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890") == string::npos)
		name = _name;
	else
		name = "uncounted";
	//cout << name;
	selecting_type_instrument();
}

void Orchestra::output_console() {
	cout << "Инструменты оркестра " << name << endl;
	cout << "Ударные" << endl;
	for (int i = 0; i < length_p; i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}
	cout << endl;
}

void Orchestra::selecting_type_instrument() {
	menu_selecting_type_instrument();
	int punkt_menu;
	cin >> punkt_menu;
	switch (punkt_menu) // оператор switch 
	{
	case 1:
		creat_percussion();
		break;
	}
}

void Orchestra::creat_percussion() {

	Percussion Per;
	Per.input_keyboard();
	memory_allocation_percussion(Per);
}

void Orchestra::memory_allocation_percussion(Percussion& Per) {

	Percussion* tmp = data_p;
	//length++;
	length_p++;
	data_p = new Percussion[length_p];
	for (int i = 0; i < length_p - 1; i++)
	{
		data_p[i] = tmp[i];
	}
	data_p[length_p - 1] = Per;
}

void Orchestra::menu_selecting_type_instrument() {
	cout << "Выберите какой инструмент создать:" << endl;
	cout << "1. Ударный" << endl;
	cout << "2. Струнный" << endl;
	cout << "3. Духовой" << endl;
}



//void Orchestra::output_to_file(ofstream& fout){
//	if (!fout.is_open())
//	{
//		cout << "Файл Save_container.txt не открыт" << endl; // сообщение об ошибке открытия файла
//	}
//	else
//	{
//		fout << "Название инструмента: " << name << endl;
//	}
//}

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