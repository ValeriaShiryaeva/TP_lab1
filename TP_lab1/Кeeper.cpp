#include "�eeper.h"

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
    cout << Or.getName();
    Orchestra* tmp = data;
    length++;
    data = new Orchestra[length];
    for (int i = 0; i < length - 1; i++)
    {
        data[i] = tmp[i];
    }
    data[length - 1] = Or;
    cout << data[length - 1].getName();
}

void �eeper::output_container() {
    cout << endl << "���������� ����������" << endl;
    for (int i = 0; i < getLength(); i++)
        data[i].output_console();
}

//void �eeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
