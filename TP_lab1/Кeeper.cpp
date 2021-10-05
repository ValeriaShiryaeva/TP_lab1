#include "Êeeper.h"

Orchestra& Êeeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

Êeeper& Êeeper::operator=(const Êeeper& keeper)
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

void Êeeper::creat() {
    Orchestra Or;
    Or.creat_orchestra();
    memory_allocation(Or);   
}

void Êeeper::memory_allocation( Orchestra& Or) {
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

void Êeeper::output_container() {
    cout << endl << "Ñîäåğæèìîå êîíòåéíåğà" << endl;
    for (int i = 0; i < getLength(); i++)
        data[i].output_console();
}

//void Êeeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
