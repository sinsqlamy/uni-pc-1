#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

struct Row {
    int index;
    int sum;
};

bool compare_rows(const Row& r1, const Row& r2) {
    return r1.sum < r2.sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int col1 = -1, col2 = -1;
    for (int j1 = 0; j1 < n - 1; j1++) {
        for (int j2 = j1 + 1; j2 < n; j2++) {
            bool found_prime = false;
            for (int i = 0; i < n; i++) {
                if (abs(matrix[i][j1]) == abs(matrix[i][j2]) && is_prime(abs(matrix[i][j1]))) {
                    found_prime = true;
                    break;
                }
            }
            if (found_prime) {
                col1 = j1;
                col2 = j2;
                break;
            }
        }
        if (col1 != -1) {
            break;
        }

    }
}