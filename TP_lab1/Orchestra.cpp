#include "Orchestra.h"

void Orchestra::input_keyboard() {

	/*string _name;
	double _cost;
	int _quantity;
	string _name_owner;*/

	cout << "������� �������� �����������" << endl;
	cin >> name;
	cout << "������ ��������� �����������" << endl;
	cin >> cost;
	cout << "������� ��������� ���������� ������������" << endl;
	cin >> quantity;
	string s;
	cout << "������� ��� ���������" << endl;
	getline(cin, s);
	getline(cin, s);
	name_owner = s;
}

void Orchestra::output_console() {

	cout << "�������� �����������: " << name << endl;
	cout << "��������� �����������: " << cost << endl;
	cout << "��������� ���������� ������������: " << quantity << endl;
	cout << "��� ���������: " << name_owner << endl;
}

void Orchestra::output_to_file(ofstream& fout){
	if (!fout.is_open())
	{
		cout << "���� Save_container.txt �� ������" << endl; // ��������� �� ������ �������� �����
	}
	else
	{
		fout << "�������� �����������: " << name << endl;
		fout << "��������� �����������: " << cost << endl;
		fout << "��������� ���������� ������������: " << quantity << endl;
		fout << "��� ���������: " << name_owner << endl;
	}
}

void  Orchestra::input_from_file(ifstream& fin) {
	if (!fin)
	{
		cout << "���� Extract_container.txt �� ������" << endl; // ��������� �� ������ �������� �����
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