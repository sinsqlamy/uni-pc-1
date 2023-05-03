#include <iostream>
#include <string>
#include <cctype> // для функции isvowel и toupper

using namespace std;

bool isvowel(char c) { // функция проверки, является ли символ гласной буквой
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    string s;
    getline(cin, s); // считываем строку с пробелами

    for (int i = 0; i < s.length(); i++) {
        if (isvowel(s[i])) { // если символ является гласной буквой
            s[i] = toupper(s[i]); // делаем его заглавным
        }
    }

    cout << s << endl; // выводим измененную строку

    return 0;
}

