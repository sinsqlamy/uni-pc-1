#include <iostream>
using namespace std;

int main() {
    int x = 123456789; // исходное число
    char* p = reinterpret_cast<char*>(&x); // приводим указатель на int к указателю на char
    for (int i = 0; i < sizeof(int); i++) {
        cout << static_cast<int>(*p) << " "; // выводим значение текущего байта
        p++; // переходим к следующему байту
    }
    return 0;
}