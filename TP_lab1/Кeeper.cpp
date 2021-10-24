#include "Кeeper.h"

int input_number();
bool intSigned(const string&);
string int_signed = "123456789";

Кeeper::Кeeper() :length(0), data(nullptr) {
    cout << "The constructor is called Keeper" << endl;
}

Кeeper::Кeeper(int _length) : length(_length) {
    for (int i = 0; i < length; i++)
        creat();
    cout << "The constructor with parameters is called Keeper" << endl;
}

Кeeper::Кeeper(const Кeeper& keeper) {
    data = new Orchestra[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
    cout << "The copy constructor is called Keeper" << endl;
}

Кeeper::~Кeeper() {
    delete[] data;
    data = nullptr;
    length = 0;
    cout << "Destructor called Keeper" << endl;
}

Orchestra& Кeeper::operator[](int index) {
    if(index >= 0 && index < length)
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
        data[i] = tmp[i];
    data[length - 1] = Or;
}

void Кeeper::input_from_file()
{
    string name_file;
    cout << "Введите название файла, из которого считать информацию: ";
    getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ifstream fin(name_file);
        if (!fin)
            cout << "Файл " << name_file << " не открыт" << endl;
        else
        {
            string s;
            getline(fin, s);
            if (s != "Контейнер пустой" && s == "Содержимое контейнера")
            {
                getline(fin, s);
                if (s.find("Количество оркестров:") != string::npos) {
                    s = s.substr(s.find_last_of(":") + 2);
                    if (s.find_first_not_of(int_signed) == string::npos)
                    {
                        int _length = stoi(s);
                        cout << "Найдено " << _length << " оркестров" << endl;
                        fin >> s;
                        for (int i = 0; i < _length; i++)
                        {
                            if (s == "Оркестр" )
                            {
                                cout << "Найден оркестр " << i + 1 << endl;
                                Orchestra Or;
                                Or.input_from_file(fin);
                                memory_allocation(Or);
                                cout << "Считан оркестр " << i + 1 << endl;
                            }
                            else
                                cout << "Не удалось найти ни одного оркестра" << endl;
                        }
                    }
                    else
                        cout << "Записано не верное количество оркестров в контейнере" << endl;
                }
                else
                    cout << "Не найдено количество оркестров" << endl;
                cout << "Данные считаны из файла" << endl;
            }
            else
                cout << "Ничего не удалось считать, измените данные в файле" << endl;
        }
        fin.close();
    }
    else
        cout << "Не верное имя файла или расширение." << endl;
    
}

void Кeeper::output_to_console() {
    if (length == 0) {
        cout << "Контейнер пустой" << endl << endl;
    }
    else {
        cout << endl << "Содержимое контейнера" << endl;
        for (int i = 0; i < length; i++)
            data[i].output_console();
    }    
}

void Кeeper::output_to_file() {
    string name_file;
    cout << "Введите название файла: ";
    getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ofstream fout;
        fout.open(name_file);
        if (!fout)
            cout << "Файл " << name_file << " не открыт" << endl;
        else
        {
            if (length == 0)
                fout << "Контейнер пустой";
            else
            {
                fout << "Содержимое контейнера" << endl;
                fout << "Количество оркестров: " << length << endl;
                for (int i = 0; i < length; i++)
                {
                    fout << "Оркестр " << i + 1 << endl;
                    data[i].output_to_file(fout);
                }
            }
            cout << "Данные выведены в файл" << endl;
        }
        fout.close();
    }
    else
        cout << "Не верное имя файла или расширение." << endl;
}

void Кeeper::coding_to_file() {
    string name_file;
    cout << "Введите название файла, куда вывести зашифрованную информацию: ";
    getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ofstream fout;
        fout.open(name_file);
        if (!fout)
            cout << "Файл " << name_file << " не открыт" << endl;
        else
        {
            if (length == 0)
                fout << encrip("Контейнер пустой");
            else
            {
                fout << encrip("Содержимое контейнера") << endl;
                fout << encrip("Количество оркестров: ") << encrip(to_string(length)) << endl;
                for (int i = 0; i < length; i++)
                {
                    fout << encrip("Оркестр ") << encrip(to_string(i + 1)) << endl;
                    data[i].coding_to_file(fout);
                }
            }
            cout << "Данные выведены в файл" << endl;
        }
        fout.close();
    }
    else
        cout << "Не верное имя файла или расширение." << endl;    
}

void Кeeper::decoding_to_file() {
    string name_file_coding, name_file_decoding;
    while (1) {
        cout << "Введите название файла с зашифрованной информацией: ";
        getline(cin, name_file_coding);
        getline(cin, name_file_coding);
        cout << "Введите название файла для расшифрованной информации: ";
        getline(cin, name_file_decoding);
        if (checkingFileName(name_file_coding) == true && checkingFileName(name_file_decoding) == true)
        {
            ifstream fin(name_file_coding);
            ofstream fout;
            fout.open(name_file_decoding);
            if (!fin)
                cout << "Файл " << name_file_coding << " не открыт" << endl;
            else
            {
                if (!fout)
                    cout << "Файл " << name_file_decoding << " не открыт" << endl;
                else
                {
                    string s;
                    while (getline(fin, s))
                        fout << decrip(s) << endl;
                    cout << "Данные выведены в файл" << endl;
                }
                fin.close();
                fout.close();
                break;
            }
        }
        else 
            cout << "Не верное имя файла или расширение." << endl;
    }
}

int Кeeper::choosing_orchestra() {
    cout << "Названия оркестров:" << endl;
    for (int i = 0; i < length; i++)
        cout << i + 1 << ". " << data[i].getName() << endl;
    while (1) {
        int number = input_number();
        if (number <= length && number != 0)
            return number;
        else
            cout << "Не верно введено значение. ";
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
                if (length == 0)
                    cout << "Количество оркестров равно 0, ничего нельзя изменть" << endl;
                else
                {
                    data[choosing_orchestra() - 1].inputName();
                    cout << "Название оркестра изменено" << endl;
                }
                break;
            case 2:
                if (length == 0)
                    cout << "Количество оркестров равно 0, ничего изменть нельзя" << endl;
                else
                {
                    data[choosing_orchestra() - 1].selecting_change_instrument();
                    break;
                }
            }
            if (punkt_menu == 3)
                break;
        }
        else
            cout << "Не верно введен пункт. ";
    }
}

void Кeeper::print_menu_change() {
    cout << "Введите то, что вы хотите изменить." << endl;
    cout << "1. Изменить название оркестра" << endl;
    cout << "2. Изменить инструмент в оркестре" << endl;
    cout << "3. Выход в главное меню" << endl;
}

void Кeeper::delite_container() {
    while (1) {
        print_menu_delite();
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
                delite_one_orchestra(choosing_orchestra() - 1);
                cout << "Оркестр удален" << endl;
                break;
            case 3:
                data[choosing_orchestra() - 1].selecting_delite_instrument();
                break;
            }
            if (punkt_menu == 4)
                break;
        }
        else
            cout << "Не верно введен номер. ";
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
    Orchestra* tmp = new Orchestra[length - 1];
    int t = 0;
    for (int i = 0; i < length; i++)
    {
        if (i != number)
            tmp[t++] = data[i];
    }
    length--;
    data = tmp;
}

bool Кeeper::checkingFileName(string name_file) {
    if (name_file.size() < 4 ) {
        cout << "Имя файла короткое." << endl;
        return false;
    }
    name_file = name_file.substr(name_file.find_last_of(".") + 1);
    if (name_file == "txt" || name_file == "doc")
        return true;
    else
    {      
        cout << "Файл должен иметь формат .txt или .doc" << endl;;
        return false;
    }
}

void Кeeper::menu_sorting() {
    while (1) {
        print_menu_sorting();
        int punkt_menu = input_number();
        if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
        {
            switch (punkt_menu)
            {
            case 1:
                sorting_orchestra();
                cout << "Оркестры отсортированы по названию" << endl;
                break;
            case 2:
                data[choosing_orchestra() - 1].selecting_sorting_instrument();
                break;
            }
            if (punkt_menu == 3)
                break;
        }
        else
            cout << "Не верно введен номер. ";
    }
}

void Кeeper::print_menu_sorting() {
    cout << "Что Вы хотите отсортировать по алфавиту?" << endl;
    cout << "1. Сортировать оркестры по названию" << endl;
    cout << "2. Сортировать инструменты в оркестре по названию" << endl;
    cout << "3. Выход в главное меню" << endl;
}

void Кeeper::sorting_orchestra() {
    Orchestra or1;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (data[i].getName() > data[j].getName()) {
                or1 = data[i];
                data[i] = data[j];
                data[j] = or1;
            }
        }
    }
}
