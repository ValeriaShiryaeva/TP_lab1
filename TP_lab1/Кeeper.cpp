//#include "Кeeper.h"
//
//Кeeper keeper;
//
//bool intSigned(const string&);
//
//void Кeeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
//
//int& Кeeper::operator[](int index) { 
//    assert(index >= 0 && index < length);
//    return data[index];
//}
//
//void Кeeper::creat_container() { 
//    
//    int quantity_elements = allocation_of_memory();
//    int temp;
//    cout << "Ведете " << quantity_elements << " элементов" << endl;
//    for (int i = 0; i < quantity_elements; i++)
//    {
//        cin >> temp;
//        keeper[i] = temp;
//    }
//        
//}
//
//void Кeeper::output_container() {
//    cout << "Содержимое контейнера" << endl;
//    for (int j = 0; j < keeper.getLength(); j++)
//        std::cout << keeper[j] << " ";
//
//}
//
//int Кeeper::allocation_of_memory() { // выделение памяти под новые элементы
//    string s_quantity_elements;
//    cout << "Ведите колличество элментов, которое вы хотите создать" << endl;
//    cin >> s_quantity_elements;
//    while (1) {
//        if (intSigned(s_quantity_elements) == true)
//        {
//            int quantity_elements = stoi(s_quantity_elements); // перевод из типа string в тип int 
//            if (quantity_elements != 0)
//            {
//                keeper.length += quantity_elements;
//                data = new int[quantity_elements];
//                return quantity_elements;
//            }
//        }
//        else
//        {
//            cout << "Не верная длина контейнера" << endl;
//            cout << "Ведите колличество элментов, которое вы хотите создать" << endl;
//            cin >> s_quantity_elements;
//        }
//    }
//}
//
//bool intSigned(const string& s) // проверка на только цифры в сроке
//{
//    if (s.find_first_not_of("0123456789", 0) == string::npos)
//        return true;
//    else
//        return false;
//}
//
//
//int main()
//{
//    setlocale(LC_ALL, "rus"); // вывод русского языка в консоли
//    keeper.creat_container();
//    keeper.output_container();
//
//}