#include "Êeeper.h"

Êeeper::Êeeper() :length(0), data(nullptr) {}

Êeeper::Êeeper(int _length) :length(_length) {
    for (int i = 0; i < length; i++)
        creat();
}

Êeeper::Êeeper(const Êeeper& keeper) {
    data = new Orchestra[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
}

Êeeper::~Êeeper() {
    delete[] data;
    data = nullptr;
    length = 0;
}

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
    Orchestra* tmp = data;
    length++;
    data = new Orchestra[length];
    for (int i = 0; i < length - 1; i++)
    {
        data[i] = tmp[i];
    }
    data[length - 1] = Or;
}

void Êeeper::output_container_console() {
    if (getLength() == 0) {
        cout << "Êîíòåéíåð ïóñòîé" << endl << endl;
    }
    else {
        cout << endl << "Ñîäåðæèìîå êîíòåéíåðà" << endl;
        for (int i = 0; i < getLength(); i++)
            data[i].output_console();
    }    
}

void Êeeper::output_to_file(ofstream& fout) {
    if (!fout.is_open())
		cout << "Ôàéë Save_container.txt íå îòêðûò" << endl; 
    else
    {
        if (getLength() == 0)
            fout << "Êîíòåéíåð ïóñòîé";
        else 
        {
            fout << "Ñîäåðæèìîå êîíòåéíåðà" << endl;
            for (int i = 0; i < getLength(); i++)
                data[i].output_to_file(fout);
        }
    }
    
}


