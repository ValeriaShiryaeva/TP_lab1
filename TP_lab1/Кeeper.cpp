#include "�eeper.h"

�eeper keeper;

bool srtSigned(const string&);

void �eeper:: erase() { 
    delete[] data;
    length = 0;
    data = nullptr;
}

Orchestra& �eeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

Orchestra& �eeper::operator>> (Orchestra& Or1) {
    Or1.input_keyboard();
    return Or1;
}

Orchestra& �eeper::operator<< (Orchestra& Or1) {
    Or1.output_console();
    return Or1;
}

void �eeper::creat_container() {
    
    keeper[length-1] = allocation_of_memory();
    keeper[length - 1].input_keyboard();
}

void �eeper::output_container() {
    cout << "���������� ����������" << endl;
    for (int i = 0; i < keeper.getLength(); i++)
        keeper[i].output_console();
}

Orchestra& �eeper::allocation_of_memory() { // ��������� ������ ��� ����� ��������
    cout << "�������� ��������" << endl;
    keeper.length += 1;
    Orchestra Or;
    data = new Orchestra[1];
    return Or;
}

//bool srtSigned(const string& s) // �������� �� ������ ����� � �����
//{
//    if (s.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

bool intSigned(const string& s) // �������� �� ������ ����� � �����
{
    if (s.find_first_not_of("0123456789", 0) == string::npos)
        return true;
    else
        return false;
}


int main()
{
    setlocale(LC_ALL, "rus"); // ����� �������� ����� � �������
    keeper.creat_container();
    keeper.output_container();
}