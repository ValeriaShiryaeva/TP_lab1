#include "�eeper.h"

int input_number();

�eeper::�eeper() :length(0), data(nullptr) {}

�eeper::�eeper(int _length) :length(_length) {
    for (int i = 0; i < length; i++)
        creat();
}

�eeper::�eeper(const �eeper& keeper) {
    data = new Orchestra[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
}

�eeper::~�eeper() {
    delete[] data;
    data = nullptr;
    length = 0;
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
    {
        data[i] = tmp[i];
    }
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

void �eeper::output_to_file(ofstream& fout) {
    if (!fout.is_open())
		cout << "���� Save_container.txt �� ������" << endl; 
    else
    {
        if (getLength() == 0)
            fout << "��������� ������";
        else 
        {
            fout << "���������� ����������" << endl;
            for (int i = 0; i < getLength(); i++)
                data[i].output_to_file(fout);
            cout << "���������� ���������� �������� � ����" << endl << endl;
        }
    }
    
}

int �eeper::choosing_orchestra() {
    if (getLength() == 0)
        cout << "�� �� ������ �������� ����������, ������� �������� �������" << endl;
    else {
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
}

void �eeper::delite_container() {
    if (getLength() == 0) {
        cout << "�� �� ������ ������� ��������� � ��� ����������. ��������� ������" << endl << endl;
    }
    else {
        print_menu_delite();
        while (1){
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
                    delite_one_orchestra(choosing_orchestra());
                    cout << "������� ������" << endl;
                    break;
                case 3:
                    data[choosing_orchestra() - 1].selecting_delite_instrument();
                    cout << "���������� ������� ������" << endl;
                    break;
                }
                if (punkt_menu == 4)
                    break;
            }
            else
                cout << "�� ����� ������ �����. ";
        }
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
    if (getLength() > 1) {
        Orchestra* tmp = new Orchestra[getLength() - 1];
        bool flag = 0;
        for (int i = 0; i < getLength() - 1; i++)
        {
            if (i != number && flag == 0)
                tmp[i] = data[i];
            else {
                tmp[i] = data[i++];
                flag = 1;
            }
        }
        setLength(getLength() - 1);
        data = tmp;
    }
    else {
        setLength(getLength() - 1);
        data = new Orchestra[0];
    }
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
                data[choosing_orchestra() - 1].inputName();
                cout << "�������� �������� ��������" << endl;
                break;
            case 2:
                data[choosing_orchestra() - 1].selecting_change_instrument();
                break;
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

