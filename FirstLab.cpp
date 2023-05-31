Денис ..., [31.05.2023 10:10]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {
public:
    // Конструктор по умолчанию
    BigInt() {}

    // Конструктор, принимающий строку в качестве аргумента
    BigInt(const string& s) {
        // Проходим по строке в обратном порядке
        for (int i = s.size() - 1; i >= 0; i--) {
            // Преобразуем каждую цифру в числовое значение и добавляем в вектор
            data.push_back(s[i] - '0');
        }
        // Удаляем ведущие нули
        trim();
    }

    // Конструктор, принимающий целое число в качестве аргумента
    BigInt(int x) {
        // Пока число не равно нулю
        while (x) {
            // Получаем остаток от деления на 10 (получаем последнюю цифру числа) и добавляем в вектор
            data.push_back(x % 10);
            // Делим число на 10 (удаляем последнюю цифру)
            x /= 10;
        }
        // Удаляем ведущие нули
        trim();
    }

    // Возвращает количество цифр в числе
    int size() const {
        return data.size();
    }

    // Перегруженный оператор "<" для сравнения двух объектов BigInt
    bool operator<(const BigInt& other) const {
        // Сравниваем размеры чисел
        if (size() != other.size()) {
            return size() < other.size();
        }
        // Проходим по цифрам чисел, начиная с наиболее значимой
        for (int i = size() - 1; i >= 0; i--) {
            // Если находим различие в цифрах, возвращаем результат сравнения
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i];
            }
        }
        // Если все цифры равны, числа считаются равными, возвращаем false
        return false;
    }

    // Перегруженный оператор "==" для сравнения двух объектов BigInt
    // Возвращает true, если векторы data обоих объектов равны
    bool operator==(const BigInt& other) const {
        return data == other.data;
    }

    // Перегруженный оператор "!=" для сравнения двух объектов BigInt
    // Возвращает true, если векторы data обоих объектов не равны
    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }

    // Перегруженный оператор "+" для сложения двух объектов BigInt
    // Создает новый объект BigInt, в котором цифры складываются покомпонентно с учетом переноса
    BigInt operator+(const BigInt& other) const {
        BigInt res;
        int carry = 0;
        // Проходим по цифрам обоих чисел, складываем их и добавляем в результирующий объект
        for (int i = 0; i < max(size(), other.size()) carry; i++) {
            if (i < size()) {
                carry += data[i];
            }
            if (i < other.size()) {
                carry += other.data[i];
            }
            res.data.push_back(carry % 10);
            carry /= 10;
        }
        // Удаляем ведущие нули
        res.trim();
        return res;
    }

    // Перегруженный оператор "*" для умножения двух объектов BigInt
    // Создает новый объект BigInt, в котором производится умножение цифр с учетом переноса
    BigInt operator*(const BigInt& other) const {
        BigInt res;
        // Выделяем достаточное количество места в векторе для результата
        res.data.resize(size() + other.size());
        // Проходим по цифрам обоих чисел и выполняем умножение
        for (int i = 0; i < size(); i++) {
            int carry = 0;
            for (int j = 0; j < other.size() carry; j++) {
                long long cur = res.data[i + j] + carry;
                if (j < other.size()) {
                    cur += 1LL * data[i] * other.data[j];
                }
                res.data[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        // Удаляем ведущие нули
        res.trim();
        return res;
    }

    Денис ..., [31.05.2023 10:10]
        // Перегруженный оператор "<<" для вывода объекта BigInt в поток ostream
            // Выводит цифры числа в обратном порядке
        friend ostream& operator<<(ostream& out, const BigInt& x) {
        for (int i = x.size() - 1; i >= 0; i--) {
            out << x.data[i];
        }
        return out;
    }

private:
    // Вектор для хранения цифр числа
    vector<int> data;

    // Функция для удаления ведущих нулей из числа
    void trim() {
        // Пока вектор не пуст и последний элемент равен нулю, удаляем последний элемент
        while (!data.empty() && data.back() == 0) {
            data.pop_back();
        }
        // Если вектор оказался пустым после удаления нулей, добавляем один элемент со значением нуля
        if (data.empty()) {
            data.push_back(0);
        }
    }
};