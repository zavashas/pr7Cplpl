#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

typedef bool (*ContainsAllCharsFunc)(const char*, const char*);

int main() {
    setlocale(0, "");
    string inputStr;
    string inputChars;

    HINSTANCE hLib = LoadLibrary(L"DynamicLib.dll");
    if (hLib == NULL) {
        cerr << "Не удалось загрузить библиотеку!" << endl;
        return 1;
    }

    ContainsAllCharsFunc contains_all_chars = (ContainsAllCharsFunc)GetProcAddress(hLib, "contains_all_chars");
    if (contains_all_chars == NULL) {
        cerr << "Не удалось получить адрес функции!" << endl;
        FreeLibrary(hLib);
        return 1;
    }

    while (true) {
        cout << "Введите строку (или введите '0' для завершения): ";
        getline(cin, inputStr);

        if (inputStr == "0") {
            break;
        }

        cout << "Введите символы для поиска: ";
        getline(cin, inputChars);

        bool result = contains_all_chars(inputStr.c_str(), inputChars.c_str());

        if (result) {
            cout << "Все символы найдены в строке." << endl;
        }
        else {
            cout << "Не все символы найдены в строке." << endl;
        }
    }

    FreeLibrary(hLib);

    return 0;
}
