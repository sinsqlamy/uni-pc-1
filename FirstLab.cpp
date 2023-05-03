#include <iostream>

// Упаковка двух чисел в 1 байт
unsigned char pack_numbers(unsigned int num1, unsigned int num2) {
    unsigned char packed = (num1 & 0x0F) | ((num2 & 0x0F) << 4);
    return packed;
}

// Извлечение двух чисел из 1 байта
void unpack_numbers(unsigned char packed, unsigned int& num1, unsigned int& num2) {
    num1 = packed & 0x0F;
    num2 = (packed >> 4) & 0x0F;
}

int main() {
    unsigned int num1 = 3;
    unsigned int num2 = 7;

    std::cout << "Original numbers: " << num1 << ", " << num2 << std::endl;

    // Упаковываем числа
    unsigned char packed = pack_numbers(num1, num2);
    std::cout << "Packed number: " << (int)packed << std::endl;

    // Извлекаем числа из упакованного значения
    unsigned int unpacked_num1, unpacked_num2;
    unpack_numbers(packed, unpacked_num1, unpacked_num2);
    std::cout << "Unpacked numbers: " << unpacked_num1 << ", " << unpacked_num2 << std::endl;

    return 0;
}