#include "�eeper.h"

Orchestra& �eeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

void �eeper::creat_container() {
    Orchestra* tmp = data;
    length ++;
    Orchestra Or;
    data = new Orchestra[length];
    for (int i = 0; i < length - 1; i++)
    {
        data[i] = tmp[i];
    }
    data[length - 1] = Or;
    data[length - 1].input_keyboard();
}

void �eeper::output_container() {
    cout << endl << "���������� ����������" << endl;
    for (int i = 0; i < getLength(); i++)
        data[i].output_console();
}

//bool srtSigned(const string& s) // �������� �� ������ ����� � �����
//{
//    if (s.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

//bool intSigned(const string& s) // �������� �� ������ ����� � �����
//{
//    if (s.find_first_not_of("0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

//bool srtSigned(const string&);

//void �eeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
