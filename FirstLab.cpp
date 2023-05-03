#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main() {
    // 1. Прочитать входной файл и сохранить его содержимое в строку.
    std::ifstream input_file("input.txt");
    std::string text;
    std::getline(input_file, text);

    // 2. Создать словарь (ассоциативный массив) для хранения количества встречающихся букв в тексте.
    std::unordered_map<char, int> letter_counts;

    // 3. Пройтись по каждой букве текста и увеличивать соответствующее значение в словаре.
    for (char c : text) {
        if (std::isalpha(c)) {
            letter_counts[std::toupper(c)]++;
        }
    }

    // 4. Отсортировать словарь по убыванию значения и выбрать 5 наиболее часто встречающихся букв.
    std::vector<std::pair<char, int>> sorted_letter_counts(letter_counts.begin(), letter_counts.end());
    std::sort(sorted_letter_counts.begin(), sorted_letter_counts.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });
    std::string top_five_letters;
    for (int i = 0; i < std::min(static_cast<int>(sorted_letter_counts.size()), 5); i++) {
        top_five_letters += sorted_letter_counts[i].first;
    }

    // 5. Разбить текст на слова, используя пробельные символы в качестве разделителя.
    std::string word;
    std::string output_text;
    bool in_word = false;
    for (char c : text) {
        if (std::isalpha(c)) {
            if (!in_word) {
                word = "";
                in_word = true;
            }
            word += c;
        }
        else {
            if (in_word) {
                // 6.Для каждого слова проверить, содержит ли оно не менее четырех из пяти наиболее часто встречающихся букв.
                int count = 0;
                std::string word_uppercase;
                for (char letter : word) {
                    char uppercase_letter = std::toupper(letter);
                    if (top_five_letters.find(uppercase_letter) != std::string::npos) {
                        count++;
                    }
                    word_uppercase += uppercase_letter;
                }
                if (count >= 4) {
                    // Если слово содержит не менее четырех из пяти наиболее часто встречающихся букв, то
                    // записать его в верхнем регистре и в скобках указать найденные буквы.
                    output_text += "(" + top_five_letters + ")";
                    for (char letter : word_uppercase) {
                        output_text += std::toupper(letter);
                    }
                }
                else {
                    // Иначе записать слово без изменений.
                    output_text += word;
                }
                in_word = false;
            }
            output_text += c;
        }
        if (in_word) {
            // 6. (Продолжение) Для последнего слова в тексте.
            int count = 0;
            std::string word_uppercase;
            for (char letter : word) {
                char uppercase_letter = std::toupper(letter);
                if (top_five_letters.find(uppercase_letter) != std::string::npos) {
                    count++;
                }
                word_uppercase += uppercase_letter;
            }
            if (count >= 4) {
                output_text += "(" + top_five_letters + ")";
                for (char letter : word_uppercase) {
                    output_text += std::toupper(letter);
                }
            }
            else {
                output_text += word;
            }
        }
    }
    // 7. Записать результат в выходной файл.
    std::ofstream output_file("output.txt");
    output_file << output_text;

    return 0;
}