#include "�eeper.h"

int input_number();
bool intSigned(const string&);

�eeper::�eeper() :length(0), data(nullptr) {
    cout << "The constructor is called Keeper" << endl;
}

�eeper::�eeper(int _length) : length(_length) {
    for (int i = 0; i < length; i++)
        creat();
    cout << "The constructor with parameters is called Keeper" << endl;
}

�eeper::�eeper(const �eeper& keeper) {
    data = new Orchestra[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
    cout << "The copy constructor is called Keeper" << endl;
}

�eeper::~�eeper() {
    delete[] data;
    data = nullptr;
    length = 0;
    cout << "Destructor called Keeper" << endl;
}

Orchestra& �eeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

�eeper& �eeper::operator=(const �eeper& keeper)
{
	if (this == &keeper)
		return *this;
	delete[] data;
    data = new Orchestra[keeper.length];
	length = keeper.length;
	for (int i = 0; i < keeper.length; i++)
		data[i] = keeper.data[i];

	return *this;
}

void �eeper::creat() {
    Orchestra Or;
    Or.creat_orchestra();
    memory_allocation(Or);   
}

void �eeper::memory_allocation( Orchestra& Or) {
    Orchestra* tmp = data;
    length++;
    data = new Orchestra[length];
    for (int i = 0; i < length - 1; i++)
        data[i] = tmp[i];
    data[length - 1] = Or;
}

void �eeper::output_container_console() {
    if (getLength() == 0) {
        cout << "��������� ������" << endl << endl;
    }
    else {
        cout << endl << "���������� ����������" << endl;
        for (int i = 0; i < getLength(); i++)
            data[i].output_console();
    }    
}

void �eeper::output_to_file() {
    string name_file;
    cout << "������� �������� �����: ";
    cin >> name_file;
    ofstream fout(name_file);
    if (!fout)
		cout << "���� " << name_file << " �� ������" << endl; 
    else
    {
        if (getLength() == 0)
            fout << "��������� ������";
        else 
        {
            fout << "���������� ����������" << endl;
            fout << "���������� ���������: " << length << endl;
            for (int i = 0; i < getLength(); i++)
            {
                fout << "������� " << i + 1 << endl;
                data[i].output_to_file(fout);
            }
                
            cout << "���������� ���������� �������� � ����" << endl << endl;
        }
        cout << "������ �������� � ����" << endl;
    }
    fout.close();
}

int �eeper::choosing_orchestra() {
    cout << "�������� ���������" << endl;
    for (int i = 0; i < getLength(); i++)
        cout << i + 1 << ". " << data[i].getName() << endl;
    while (1) {
        int number = input_number();
        if (number <= getLength() && number != 0)
            return number;
        else {
            cout << "�� ����� ������� ��������. ";
        }
    }
}

void �eeper::delite_container() {
    print_menu_delite();
    while (1) {
        int punkt_menu = input_number();
        if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3 || punkt_menu == 4)
        {
            switch (punkt_menu)
            {
            case 1:
                delete[] data;
                data = nullptr;
                length = 0;
                cout << "��������� ������" << endl;
                break;
            case 2:
                delite_one_orchestra(choosing_orchestra() - 1);
                cout << "������� ������" << endl;
                break;
            case 3:
                data[choosing_orchestra() - 1].selecting_delite_instrument();
                break;
            }
            if (punkt_menu == 4)
                break;
        }
        else
            cout << "�� ����� ������ �����. ";
    }
}

void �eeper::print_menu_delite() {
    cout << "��� �� ������ �������?" << endl;
    cout << "1. ������� ���������" << endl;
    cout << "2. ������� �������" << endl;
    cout << "3. ������� ���������� � ��������" << endl;
    cout << "4. ����� � ������� ����" << endl;
}

void �eeper::delite_one_orchestra(int number) {
    Orchestra* tmp = new Orchestra[getLength() - 1];
    int t = 0;
    for (int i = 0; i < getLength(); i++)
    {
        if (i != number)
            tmp[t++] = data[i];
    }
    setLength(getLength() - 1);
    data = tmp;
}

void �eeper::change_container() {
    while (1)
    {
        print_menu_change();
        int punkt_menu = input_number();
        if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
        {
            switch (punkt_menu)
            {
            case 1:
                if (getLength() == 0)
                    cout << "���������� ��������� ����� 0, ������ ������� ������" << endl;
                else
                {
                    data[choosing_orchestra() - 1].inputName();
                    cout << "�������� �������� ��������" << endl;
                }
                break;
            case 2:
                if (getLength() == 0)
                    cout << "���������� ��������� ����� 0, ������ ������� ������" << endl;
                else
                {
                    data[choosing_orchestra() - 1].selecting_change_instrument();
                    break;
                }
            }
            if(punkt_menu == 3)
                break;
        }
        else
            cout << "�� ����� ������ �����. ";
    }
}

void �eeper::print_menu_change() {
    cout << "������� ��, ��� �� ������ ��������."  << endl;
    cout << "1. �������� �������� ��������" << endl;
    cout << "2. �������� ���������� � ��������" << endl;
    cout << "3. ����� � ������� ����" << endl;
}

void �eeper::input_from_file()
{
    string name_file;
    cout << "������� �������� �����: ";
    cin >> name_file;
    ifstream fin(name_file);
    if (!fin)
        cout << "���� Extract_container.txt �� ������" << endl;
    else 
    {
        string s;
        getline(fin, s);
        if (s != "��������� ������" && s == "���������� ����������")
        {
            getline(fin, s);
            if (s.find("���������� ���������:") != string::npos) {
                s = s.substr(s.find_last_of("���������� ���������:") + 1);
                if (s.find_first_not_of("1234567890") == string::npos)
                {
                    int _length = stoi(s);
                    cout << "������� " << _length << " ���������" << endl;
                    for (int i = 0; i < _length; i++)
                    {
                        fin >> s;
                        if (s == "�������")
                        {
                            cout << "������ ������� " << i + 1 << endl;
                            Orchestra Or;
                            Or.input_from_file(fin);
                            memory_allocation(Or);
                            cout << "������ ������� " << i + 1 << endl;
                        }
                        else
                            cout << "�� ������� ����� �� ������ ��������" << endl;
                    }

                }
                else
                    cout << "�������� �� ������ ���������� ��������� � ����������" << endl;
            }
            else
                cout << "�� ������� ���������� ���������" << endl;
            cout << "������ ������� �� �����" << endl;
        }
        else
            cout << "������ �� ������� �������. ��������� ������ � �����" << endl;
    }
    fin.close();
}

void �eeper::coding_to_file() {
    string name_file;
    cout << "������� �������� �����: ";
    cin >> name_file;
    ofstream fout(name_file);
    if (!fout)
        cout << "���� " << name_file << " �� ������" << endl;
    else
    {
        if (length == 0)
            fout << encrip("��������� ������");
        else
        {
            fout << encrip("���������� ����������") << endl;
            fout << encrip("���������� ���������: ") << encrip(to_string(length)) << endl;
            for (int i = 0; i < length; i++)
            {
                fout << encrip("������� ") << encrip(to_string(i + 1)) << endl;
                data[i].coding_to_file(fout);
            }
            cout << "���������� ���������� �������� � ����" << endl << endl;
        }
        cout << "������ �������� � ����" << endl;
    }
    fout.close();
}