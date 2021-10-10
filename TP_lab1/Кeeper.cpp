#include "�eeper.h"

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
        }
    }
    
}


