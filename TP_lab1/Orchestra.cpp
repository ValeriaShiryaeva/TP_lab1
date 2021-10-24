#include "Orchestra.h"

int input_number();

string _string_signed = "qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM 1234567890";
string _int_signed = "123456789";

Orchestra::Orchestra() : name("no"), length_p(0), length_s(0), length_w(0), data_p(nullptr), data_s(nullptr), data_w(nullptr) {
	cout << "The constructor is called Orchestra" << endl;
}

Orchestra::Orchestra(string _name, int _length_p, int _length_s, int _length_w) : 
	name(_name), length_p(_length_p), length_s(_length_s), length_w(_length_w) {
	for (int i = 0; i < length_p; i++)
		creat_percussion();
	for (int i = 0; i < length_s; i++)
		creat_stringed();
	for (int i = 0; i < length_w; i++)
		creat_wind();

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
	cout << "������� �������� ��������" << endl;
	getline(cin, _name);
	while (1) {
		getline(cin, _name);
		if (_name.find_first_not_of(_string_signed) == string::npos)
		{
			setName(_name);
			break;
		}
		else
			cout << "�� ������ �������� ��������, ��������� ����" << endl;
	}
}

void  Orchestra::input_from_file(ifstream& fin) {

	string s;
	getline(fin, s);
	inputFaleName(fin);
	while (!fin.eof())
	{
		fin >> s;
		if (s == "�������")
		{
			int _length_p = inputFaleLenght_p(fin);
			if (_length_p != 0)
			{
				for (int i = 0; i < _length_p; i++)
				{
					cout << "������� " << _length_p << " �������" << endl;
					Percussion Per;
					Per.input_from_file(fin);
					memory_allocation_percussion(Per);
					cout << "������ " << i + 1 << " ������� ����������" << endl;
				}
				cout << "������� ������� ����������� ��������" << endl;
			}
			else
				cout << "�� ������� ���������� ������� ������������" << endl;
		}
		else
			cout << "�� ������� ������� ������������" << endl;

		if (s == "��������")
		{
			int _length_s = inputFaleLenght_s(fin);
			if (_length_s != 0)
			{
				for (int i = 0; i < _length_s; i++)
				{
					cout << "������� " << _length_s << " ��������" << endl;
					Stringed Str;
					Str.input_from_file(fin);
					memory_allocation_stringed(Str);
					cout << "������ " << i + 1 << " �������� ����������" << endl;
				}
				cout << "������� �������� ����������� ��������" << endl;
			}
			else
				cout << "�� ������� ���������� �������� ������������" << endl;
		}
		else
			cout << "�� ������� �������� ������������" << endl;

		if (s == "�������")
		{
			int _length_w = inputFaleLenght_w(fin);
			if (_length_w != 0)
			{
				for (int i = 0; i < _length_w; i++)
				{
					cout << "������� " << _length_w << " �������" << endl;
					Wind Win;
					Win.input_from_file(fin);
					memory_allocation_wind(Win);
					cout << "������ " << i + 1 << " ������� ����������" << endl;
				}
				cout << "������� ������� ����������� ��������" << endl;
			}
			else
				cout << "�� ������� ���������� ������� ������������" << endl;
		}
		else
			cout << "�� ������� ������� ������������" << endl;

		if (s == "�������")
			break;
	}
	
}

void Orchestra::inputFaleName(ifstream& fin) {
	string s;
	getline(fin, s);
	if (s.find("�������� ��������:") != string::npos)
	{
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_string_signed) == string::npos)
		{
			setName(s);
			cout << "������� �������� ��������" << endl;
		}
		else
			cout << "�� ����� �������� �������� ��������" << endl;
	}
	else
		cout << "�� ������� �������� ��������" << endl;
}

int Orchestra::inputFaleLenght_p(ifstream& fin) {
	string s;
	getline(fin, s);
	getline(fin, s);
	if (s.find("���������� �������:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_int_signed) == string::npos)
		{
			int _length_p = stoi(s);
			return _length_p;
		}
		else
		{
			cout << "�� ����� �������� ���������� ������� ������������" << endl;
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
	if (s.find("���������� ��������:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_int_signed) == string::npos)
		{
			int _length_s = stoi(s);
			return _length_s;
		}
		else
		{
			cout << "�� ����� �������� ���������� �������� ������������" << endl;
			return 0;
		}
	}
	else
		return 0;
}

int Orchestra::inputFaleLenght_w(ifstream& fin) {
	string s;
	getline(fin, s);
	getline(fin, s);
	if (s.find("���������� �������:") != string::npos) {
		s = s.substr(s.find_last_of(":") + 2);
		if (s.find_first_not_of(_int_signed) == string::npos)
		{
			int _length_w = stoi(s);
			return _length_w;
		}
		else
		{
			cout << "�� ����� �������� ���������� ������� ������������" << endl;
			return 0;
		}
	}
	else
		return 0;
}

void Orchestra::output_console() {
	cout << "����������� �������� " << name << endl;
	cout << "�������" << endl;
	cout << "���������� ������� � ��������: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}

	cout << "��������" << endl;
	cout << "���������� �������� � ��������: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		cout << i + 1 << '.' << endl;
		data_s[i].output_console();
	}
	
	cout << "�������" << endl;
	cout << "���������� ������� � ��������: " << length_w << endl;
	for (int i = 0; i < length_w; i++)
	{
		cout << i + 1 << '.' << endl;
		data_w[i].output_console();
	}
	cout << endl;
}

void Orchestra::output_to_file(ofstream& fout) {
	fout << "�������� ��������: " << name << endl;

	fout << "�������" << endl;
	fout << "���������� �������: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << "������� " << i + 1 << endl;
		data_p[i].output_to_file(fout);
	}

	fout << "��������" << endl;
	fout << "���������� ��������: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		fout << "�������� " << i + 1 << endl;
		data_s[i].output_to_file(fout);
	}

	fout << "�������" << endl;
	fout << "���������� �������: " << length_w << endl;
	for (int i = 0; i < length_w; i++)
	{
		fout << "������� " << i + 1 << endl;
		data_w[i].output_to_file(fout);
	}
}

void Orchestra::coding_to_file(ofstream& fout) {
	fout << encrip("�������� ��������: ") << encrip(name) << endl;

	fout << encrip("�������") << endl;
	fout << encrip("���������� �������: ") << encrip(to_string(length_p)) << endl;
	for (int i = 0; i < length_p; i++)
	{
		fout << encrip("������� ") << encrip(to_string(i + 1)) << endl;
		data_p[i].coding_to_file(fout);
	}

	fout << encrip("��������") << endl;
	fout << encrip("���������� ��������: ") << encrip(to_string(length_s)) << endl;
	for (int i = 0; i < length_s; i++)
	{
		fout << encrip("�������� ") << encrip(to_string(i + 1)) << endl;
		data_s[i].coding_to_file(fout);
	}

	fout << encrip("�������") << endl;
	fout << encrip("���������� �������: ") << encrip(to_string(length_w)) << endl;
	for (int i = 0; i < length_w; i++)
	{
		fout << encrip("������� ") << encrip(to_string(i + 1)) << endl;
		data_w[i].coding_to_file(fout);
	}	
}

void Orchestra::selecting_type_instrument() {
	while (1) {
		menu_selecting_type_instrument();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4)
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
				creat_wind();
				break;
			}
			if (punkt_menu == 4)
				break;
		}
		else
			cout << "�� ����� ������ ����� ���� �����������" << endl;
	}
}

void Orchestra::menu_selecting_type_instrument() {
	cout << "�������� ����������:" << endl;
	cout << "1. �������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. �������" << endl;
	cout << "4. ����� � ������� ����" << endl;
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

void Orchestra::creat_wind() {
	Wind Win;
	Win.input_keyboard();
	memory_allocation_wind(Win);
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

void Orchestra::memory_allocation_wind(Wind& Win) {
	Wind* tmp = data_w;
	length_w++;
	data_w = new Wind[length_w];
	for (int i = 0; i < length_w - 1; i++)
		data_w[i] = tmp[i];
	data_w[length_w - 1] = Win;
}

void Orchestra::selecting_change_instrument() {
	while (1) {
		menu_selecting_type_instrument();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4)
		{
			switch (punkt_menu) // �������� switch 
			{
			case 1:
				if (length_p == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					data_p[choosing_percussion() - 1].change();
					cout << "������� ���������� ������� �������" << endl;
				}
				break;
			case 2:
				if (length_s == 0)
					cout << "� ���� �������� ��� �������� ������������" << endl;
				else
				{
					data_s[choosing_stringed() - 1].change();
					cout << "�������� ���������� ������� �������" << endl;
				}
				break;
			case 3:
				if (length_w == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					data_s[choosing_wind() - 1].change();
					cout << "������� ���������� ������� �������" << endl;
				}
				break;
			}
			if (punkt_menu == 4)
				break;
		}
		else
			cout << "�� ����� ������ ����� ���� �����������" << endl;
	}
}

int Orchestra::choosing_percussion() {
	print_percussion();
	cout << "����� �������� �����������. ";
	int number_percussion = input_number();
	while (1) {
		if (number_percussion <= length_p && number_percussion != 0)
			return number_percussion;
		else {
			cout << "������ �������� ����� �������� �����������. ��������� ����" << endl;
			number_percussion = input_number();
		}
	}
}

int Orchestra::choosing_stringed() {
	print_stringed();
	cout << "����� ��������� �����������. ";
	int number_stringed = input_number();
	while (1) {
		if (number_stringed <= length_s && number_stringed != 0)
			return number_stringed;
		else {
			cout << "������ �������� ����� ��������� �����������. ��������� ����" << endl;
			number_stringed = input_number();
		}
	}
}

int Orchestra::choosing_wind() {
	print_wind();
	cout << "����� �������� �����������. ";
	int number_wind = input_number();
	while (1) {
		if (number_wind <= length_s && number_wind != 0)
			return number_wind;
		else {
			cout << "������ �������� ����� �������� �����������. ��������� ����" << endl;
			number_wind = input_number();
		}
	}
}

void Orchestra::selecting_delite_instrument() {
	while (1) {
		menu_selecting_type_instrument();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4)
		{
			switch (punkt_menu)
			{
			case 1:
				if (length_p == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					delite_one_percussion(choosing_percussion() - 1);
					cout << "������� ���������� ������� ������" << endl;
				}
				break;
			case 2:
				if (length_s == 0)
					cout << "� ���� �������� ��� �������� ������������" << endl;
				else
				{
					delite_one_stringed(choosing_stringed() - 1);
					cout << "�������� ���������� ������� ������" << endl;
				}
				break;
			case 3:
				if (length_w == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					delite_one_wind(choosing_wind() - 1);
					cout << "������� ���������� ������� ������" << endl;
				}
				break;
			}
			if(punkt_menu == 4)
				break;
		}
		else
			cout << "�� ����� ������ ����� ���� �����������" << endl;
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

void Orchestra::delite_one_wind(int number) {
	Wind* tmp = new Wind[length_w - 1];
	int t = 0;
	for (int i = 0; i < length_w; i++)
	{
		if (i != number)
			tmp[t++] = data_w[i];
	}
	length_w--;
	data_w= tmp;
}

void Orchestra::print_percussion() {
	cout << "�������" << endl;
	cout << "����������� ������� � ��������: " << length_p << endl;
	for (int i = 0; i < length_p; i++)
	{
		cout << i + 1 << '.' << endl;
		data_p[i].output_console();
	}
	cout << endl;
}

void Orchestra::print_stringed() {
	cout << "��������" << endl;
	cout << "����������� �������� � ��������: " << length_s << endl;
	for (int i = 0; i < length_s; i++)
	{
		cout << i + 1 << '.' << endl;
		data_s[i].output_console();
	}
	cout << endl;
}

void Orchestra::print_wind() {
	cout << "�������" << endl;
	cout << "����������� ������� � ��������: " << length_w << endl;
	for (int i = 0; i < length_w; i++)
	{
		cout << i + 1 << '.' << endl;
		data_w[i].output_console();
	}
	cout << endl;
}

void Orchestra::selecting_sorting_instrument() {
	while (1) {
		menu_selecting_type_instrument();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4)
		{
			switch (punkt_menu)
			{
			case 1:
				if (length_p == 1)
					cout << "� ���� �������� ���� ������� ����������, ���������� �� ��������." << endl;
				if (length_p == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					sorting_percussion();
					cout << "������� ����������� ������������� �� ��������" << endl;
				}
				break;
			case 2:
				if (length_s == 1)
					cout << "� ���� �������� ���� �������� ����������, ���������� �� ��������." << endl;
				if (length_s == 0)
					cout << "� ���� �������� ��� �������� ������������" << endl;
				else
				{
					sorting_stringed();
					cout << "�������� ����������� ������������� �� ��������" << endl;
				}
				break;
			case 3:
				if (length_w == 1)
					cout << "� ���� �������� ���� ������� ����������, ���������� �� ��������." << endl;
				if (length_w == 0)
					cout << "� ���� �������� ��� ������� ������������" << endl;
				else
				{
					sorting_wind();
					cout << "������� ����������� ������������� �� ��������" << endl;
				}
				break;
			}
			if(punkt_menu == 4)
				break;
		}
		else
			cout << "�� ����� ������ ����� ���� �����������" << endl;
	}
}

void Orchestra::sorting_percussion() {
	Percussion Per;
	for (int i = 0; i < length_p; i++) {
		for (int j = i + 1; j < length_p; j++) {
			if (data_p[i].getName() > data_p[j].getName()) {
				Per = data_p[i];
				data_p[i] = data_p[j];
				data_p[j] = Per;
			}
		}
	}
}

void Orchestra::sorting_stringed() {
	Stringed Str;
	for (int i = 0; i < length_s; i++) {
		for (int j = i + 1; j < length_s; j++) {
			if (data_s[i].getName() > data_s[j].getName()) {
				Str = data_s[i];
				data_s[i] = data_s[j];
				data_s[j] = Str;
			}
		}
	}
}

void Orchestra::sorting_wind() {
	Wind Win;
	for (int i = 0; i < length_w; i++) {
		for (int j = i + 1; j < length_w; j++) {
			if (data_w[i].getName() > data_w[j].getName()) {
				Win = data_w[i];
				data_w[i] = data_w[j];
				data_w[j] = Win;
			}
		}
	}
}