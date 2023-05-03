#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    // Чтение матрицы
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Поиск одинаковых столбцов
    vector<int> col_idx;
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            bool equal = true;
            for (int i = 0; i < n; i++) {
                if (a[i][j] != a[i][k]) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                col_idx.push_back(j);
                col_idx.push_back(k);
            }
        }
    }

    // Поиск строки, содержащей простое число
    int row_idx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(abs(a[i][j]))) {
                row_idx = i;
                break;
            }
        }
        if (row_idx != -1) {
            break;
        }
    }

    // Если не нашли ни одного простого числа, то завершаем программу
    if (row_idx == -1) {
        return 0;
    }

    // Упорядочивание строк матрицы по неубыванию суммы модулей элементов
    vector<pair<int, int>> row_sum(n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(a[i][j]);
        }
        row_sum[i] = make_pair(sum, i);
    }
    sort(row_sum.begin(), row_sum.end());

    // Создание новой матрицы, упорядоченной по строкам
    vector<vector<int>> new_a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_a[i][j] = a[row_sum[i].second][j];
        }
    }

    // Вывод новой матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << new_a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
