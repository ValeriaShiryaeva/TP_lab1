#include "Êeeper.h"

Orchestra& Êeeper::operator[](int index) {
    if(index >= 0 && index < length);
        return data[index];
}

void Êeeper::creat_container() {
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

void Êeeper::output_container() {
    cout << endl << "Ñîäåğæèìîå êîíòåéíåğà" << endl;
    for (int i = 0; i < getLength(); i++)
        data[i].output_console();
}

//bool srtSigned(const string& s) // ïğîâåğêà íà òîëüêî öèôğû â ñğîêå
//{
//    if (s.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

//bool intSigned(const string& s) // ïğîâåğêà íà òîëüêî öèôğû â ñğîêå
//{
//    if (s.find_first_not_of("0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}

//bool srtSigned(const string&);

//void Êeeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
