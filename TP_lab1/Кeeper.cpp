#include "Кeeper.h"

Кeeper keeper;

bool srtSigned(const string&);

void Кeeper:: erase() { 
    delete[] data;
    length = 0;
    data = nullptr;
}

Orchestra& Кeeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

Orchestra& Кeeper::operator>> (Orchestra& Or1) {
    Or1.input_keyboard();
    return Or1;
}

Orchestra& Кeeper::operator<< (Orchestra& Or1) {
    Or1.output_console();
    return Or1;
}

void Кeeper::creat_container() {
    
    keeper[length-1] = allocation_of_memory();
    keeper[length - 1].input_keyboard();
}

void Кeeper::output_container() {
    cout << "Содержимое контейнера" << endl;
    for (int i = 0; i < keeper.getLength(); i++)
        keeper[i].output_console();
}

Orchestra& Кeeper::allocation_of_memory() { // выделение памяти под новые элементы
    cout << "Создание оркестра" << endl;
    keeper.length += 1;
    Orchestra Or;
    data = new Orchestra[1];
    return Or;
}

//bool srtSigned(const string& s) // проверка на только цифры в сроке
//{
//    if (s.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

bool intSigned(const string& s) // проверка на только цифры в сроке
{
    if (s.find_first_not_of("0123456789", 0) == string::npos)
        return true;
    else
        return false;
}


int main()
{
    setlocale(LC_ALL, "rus"); // вывод русского языка в консоли
    keeper.creat_container();
    keeper.output_container();
}