#include"CoderDecoder.h"

string alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ :.1234567890!";

std::string encrip(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 1) % 131];

                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

std::string decrip(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
               // cout << i << ' ' << j << endl;
                word[i] = alphabet[(j - 1) % 131];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}