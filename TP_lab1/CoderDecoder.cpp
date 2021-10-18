#include"CoderDecoder.h"

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�����Ũ���������������������������������������������������������� :.1234567890";

string encrip(std::string input) {
    vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 3) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}


string decrip(std::string input) {
    vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 3) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}