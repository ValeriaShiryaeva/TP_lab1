#include "Кeeper.h"

int input_number();

Кeeper::Кeeper() :length(0), data(nullptr) {}

Кeeper::Кeeper(int _length) :length(_length) {
    for (int i = 0; i < length; i++)
        creat();
}

Кeeper::Кeeper(const Кeeper& keeper) {
    data = new Orchestra[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
}

Кeeper::~Кeeper() {
    delete[] data;
    data = nullptr;
    length = 0;
}

Orchestra& Кeeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

Кeeper& Кeeper::operator=(const Кeeper& keeper)
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

void Кeeper::creat() {
    Orchestra Or;
    Or.creat_orchestra();
    memory_allocation(Or);   
}

void Кeeper::memory_allocation( Orchestra& Or) {
    Orchestra* tmp = data;
    length++;
    data = new Orchestra[length];
    for (int i = 0; i < length - 1; i++)
    {
        data[i] = tmp[i];
    }
    data[length - 1] = Or;
}

void Кeeper::output_container_console() {
    if (getLength() == 0) {
        cout << "Контейнер пустой" << endl << endl;
    }
    else {
        cout << endl << "Содержимое контейнера" << endl;
        for (int i = 0; i < getLength(); i++)
            data[i].output_console();
    }    
}

void Кeeper::output_to_file(ofstream& fout) {
    if (!fout.is_open())
		cout << "Файл Save_container.txt не открыт" << endl; 
    else
    {
        if (getLength() == 0)
            fout << "Контейнер пустой";
        else 
        {
            fout << "Содержимое контейнера" << endl;
            for (int i = 0; i < getLength(); i++)
                data[i].output_to_file(fout);
            cout << "Содержимое контейнера выведено в файл" << endl << endl;
        }
    }
    
}

int Кeeper::choosing_orchestra() {
    if (getLength() == 0)
        cout << "Вы не можете изменить инструмент, сначала создайте оркестр" << endl;
    else {
        cout << "Названия оркестров" << endl;
        for (int i = 0; i < getLength(); i++)
            cout << i + 1 << ". " << data[i].getName() << endl;
        while (1) {
            int number = input_number();
            if (number <= getLength() && number != 0)
                return number;
            else {
                cout << "Не верно введено значение. ";
            }
        }
    }
}

void Кeeper::delite_container() {
    if (getLength() == 0) {
        cout << "Вы не можете удалить контейнет и его содержимое. Контейнер пустой" << endl << endl;
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
                    cout << "Контейнер удален" << endl;
                    break;
                case 2:
                    delite_one_orchestra(choosing_orchestra());
                    cout << "Оркестр удален" << endl;
                    break;
                case 3:
                    data[choosing_orchestra() - 1].selecting_delite_instrument();
                    cout << "Инструмент оркеста удален" << endl;
                    break;
                }
                if (punkt_menu == 4)
                    break;
            }
            else
                cout << "Не верно введен номер. ";
        }
    }
}
void Кeeper::print_menu_delite() {
    cout << "Что вы хотите удалить?" << endl;
    cout << "1. Удалить контейнер" << endl;
    cout << "2. Удалить оркестр" << endl;
    cout << "3. Удалить инструмент в оркестре" << endl;
    cout << "4. Выход в главное меню" << endl;
}

void Кeeper::delite_one_orchestra(int number) {
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

void Кeeper::change_container() {
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
                cout << "Название оркестра изменено" << endl;
                break;
            case 2:
                data[choosing_orchestra() - 1].selecting_change_instrument();
                break;
            }
            if(punkt_menu == 3)
                break;
        }
        else
            cout << "Не верно введен номер. ";
    }
}

void Кeeper::print_menu_change() {
    cout << "Введите то, что вы хотите изменить."  << endl;
    cout << "1. Изменить название оркестра" << endl;
    cout << "2. Изменить инструмент в оркестре" << endl;
    cout << "3. Выход в главное меню" << endl;
}

