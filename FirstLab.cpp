#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {
public:
    BigInt() {}

    BigInt(const string& s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            data.push_back(s[i] - '0');
        }
        trim();
    }

    BigInt(int x) {
        while (x) {
            data.push_back(x % 10);
            x /= 10;
        }
        trim();
    }

    int size() const {
        return data.size();
    }

    bool operator<(const BigInt& other) const {
        if (size() != other.size()) {
            return size() < other.size();
        }
        for (int i = size() - 1; i >= 0; i--) {
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i];
            }
        }
        return false;
    }

    bool operator==(const BigInt& other) const {
        return data == other.data;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }

    BigInt operator+(const BigInt& other) const {
        BigInt res;
        int carry = 0;
        for (int i = 0; i < max(size(), other.size()) || carry; i++) {
            if (i < size()) {
                carry += data[i];
            }
            if (i < other.size()) {
                carry += other.data[i];
            }
            res.data.push_back(carry % 10);
            carry /= 10;
        }
        res.trim();
        return res;
    }

    BigInt operator*(const BigInt& other) const {
        BigInt res;
        res.data.resize(size() + other.size());
        for (int i = 0; i < size(); i++) {
            int carry = 0;
            for (int j = 0; j < other.size() || carry; j++) {
                long long cur = res.data[i + j] + carry;
                if (j < other.size()) {
                    cur += 1LL * data[i] * other.data[j];
                }
                res.data[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        res.trim();
        return res;
    }

    friend ostream& operator<<(ostream& out, const BigInt& x) {
        for (int i = x.size() - 1; i >= 0; i--) {
            out << x.data[i];
        }
        return out;
    }

private:
    vector<int> data;

    void trim() {
        while (!data.empty() && data.back() == 0) {
            data.pop_back();
        }
        if (data.empty()) {
            data.push_back(0);
        }
    }
};
