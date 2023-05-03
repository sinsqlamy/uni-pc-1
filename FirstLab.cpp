#include <iostream>

class SmartArray {
private:
    int* arr; // указатель на массив
    int size; // текущий размер массива
    int capacity; // максимальная емкость массива

public:
    // конструкторы
    SmartArray() {
        size = 0;
        capacity = 4; // начальная емкость массива
        arr = new int[capacity];
    }

    SmartArray(int initial_capacity) {
        size = 0;
        capacity = initial_capacity;
        arr = new int[capacity];
    }

    // деструктор
    ~SmartArray() {
        delete[] arr;
    }

    // добавление элемента в конец массива
    void append(int element) {
        // проверка, достигнут ли максимальный размер массива
        if (size == capacity) {
            // увеличение емкости массива вдвое
            int* new_arr = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity *= 2;
        }
        arr[size] = element;
        size++;
    }

    // получение текущего количества элементов
    int get_size() {
        return size;
    }

    // получение элемента по индексу
    int get_element(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return -1; // возврат ошибки
        }
        return arr[index];
    }

    // изменение элемента по индексу
    void set_element(int index, int element) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return;
        }
        arr[index] = element;
    }

    // удаление элемента по индексу
    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error: index out of range" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // вставка элемента по индексу
    void insert(int index, int element) {
        if (index < 0 || index > size) {
            std::cout << "Error: index out of range" << std::endl;
            return;
        }
        // проверка, достигнут ли максимальный размер массива
        if (size == capacity) {
            // увеличение емкости массива вдвое
            int* new_arr = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity *= 2;
        }
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        size++;
    }
};