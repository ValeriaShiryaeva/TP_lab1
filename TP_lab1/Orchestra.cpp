#include "Orchestra.h"

void Orchestra::input_keyboard() {

	/*string _name;
	double _cost;
	int _quantity;
	string _name_owner;*/

	cout << "Введите название инструмента" << endl;
	cin >> name;
	cout << "Ведите стоимость инструмента" << endl;
	cin >> cost;
	cout << "Введите возможное количество инструментов" << endl;
	cin >> quantity;
	string s;
	cout << "Введите имя влядельца" << endl;
	getline(cin, s);
	getline(cin, s);
	name_owner = s;
}

void Orchestra::output_console() {

	cout << "Название инструмента: " << name << endl;
	cout << "Стоимость инструмента: " << cost << endl;
	cout << "Возможное количество инструментов: " << quantity << endl;
	cout << "Имя влядельца: " << name_owner << endl;
}

void Orchestra::output_to_file(ofstream& fout){
	if (!fout.is_open())
	{
		cout << "Файл Save_container.txt не открыт" << endl; // сообщение об ошибке открытия файла
	}
	else
	{
		fout << "Название инструмента: " << name << endl;
		fout << "Стоимость инструмента: " << cost << endl;
		fout << "Возможное количество инструментов: " << quantity << endl;
		fout << "Имя влядельца: " << name_owner << endl;
	}
}

void  Orchestra::input_from_file(ifstream& fin) {
	if (!fin)
	{
		cout << "Файл Extract_container.txt не открыт" << endl; // сообщение об ошибке открытия файла
	}
	else
	{
		string _name, _cost, _quantity, _name_owner;
		string s ;

		getline(fin, s);
		if (s.find(' ') != string::npos) {
			int namber = s.find(':');
			_name.append(s, namber+2, s.size() - namber - 1);
			if (_name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM ") == string::npos)
				name = _name;
			else 
				name = "uncounted";
		}
		else
		{
			name = "uncounted";
		}

		getline(fin, s);
		if (s.find(' ') != string::npos) {
			int namber = s.find(':');
			_cost.append(s, namber + 2, s.size() - namber- 1);
			if (_cost.find_first_not_of("0123456789", 0) == string::npos)
			{
				cost = stoi(_cost);
			}
			else
				cost = 0;
		}
		else
		{
			cost = 0;
		}

		getline(fin, s);
		if (s.find(' ') != string::npos) {
			int namber = s.find(':');
			_quantity.append(s, namber + 2, s.size() - namber - 1);
			if (_quantity.find_first_not_of("0123456789", 0) == string::npos)
			{
				quantity = stoi(_quantity);
			}
			else
				quantity = 0;
		}
		else
		{
			quantity = 0;
		}

		getline(fin, s);
		if (s.find(' ') != string::npos) {
			int namber = s.find(':');
			_name_owner.append(s, namber + 2, s.size() - namber - 1);
			if (_name_owner.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM ") == string::npos)
				name_owner = _name_owner;
			else
				name_owner = "uncounted";
		}
		else
		{
			name_owner = "uncounted";
		}
	}

	
}