//#include "�eeper.h"
//
//�eeper keeper;
//
//bool intSigned(const string&);
//
//void �eeper:: erase() { 
//    delete[] data;
//    length = 0;
//    data = nullptr;
//}
//
//int& �eeper::operator[](int index) { 
//    assert(index >= 0 && index < length);
//    return data[index];
//}
//
//void �eeper::creat_container() { 
//    
//    int quantity_elements = allocation_of_memory();
//    int temp;
//    cout << "������ " << quantity_elements << " ���������" << endl;
//    for (int i = 0; i < quantity_elements; i++)
//    {
//        cin >> temp;
//        keeper[i] = temp;
//    }
//        
//}
//
//void �eeper::output_container() {
//    cout << "���������� ����������" << endl;
//    for (int j = 0; j < keeper.getLength(); j++)
//        std::cout << keeper[j] << " ";
//
//}
//
//int �eeper::allocation_of_memory() { // ��������� ������ ��� ����� ��������
//    string s_quantity_elements;
//    cout << "������ ����������� ��������, ������� �� ������ �������" << endl;
//    cin >> s_quantity_elements;
//    while (1) {
//        if (intSigned(s_quantity_elements) == true)
//        {
//            int quantity_elements = stoi(s_quantity_elements); // ������� �� ���� string � ��� int 
//            if (quantity_elements != 0)
//            {
//                keeper.length += quantity_elements;
//                data = new int[quantity_elements];
//                return quantity_elements;
//            }
//        }
//        else
//        {
//            cout << "�� ������ ����� ����������" << endl;
//            cout << "������ ����������� ��������, ������� �� ������ �������" << endl;
//            cin >> s_quantity_elements;
//        }
//    }
//}
//
//bool intSigned(const string& s) // �������� �� ������ ����� � �����
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
//    setlocale(LC_ALL, "rus"); // ����� �������� ����� � �������
//    keeper.creat_container();
//    keeper.output_container();
//
//}