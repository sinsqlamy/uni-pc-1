#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main()
std::ifstream input_file("input.txt");
std::string text;
std::getline(input_file, text);

// словарь (ассоциативный массив) 
std::unordered_map<char, int> letter_counts;

for (char c : text) {
    if (std::isalpha(c)) {
        letter_counts[std::toupper(c)]++;
    }
}

// сортировка и поиск 5 наиболее часто встречающихся букв
std::vector<std::pair<char, int>> sorted_letter_counts(letter_counts.begin(), letter_counts.end());
std::sort(sorted_letter_counts.begin(), sorted_letter_counts.end(),
    [](const auto& a, const auto& b) { return a.second > b.second; });
std::string top_five_letters;
for (int i = 0; i < std::min(static_cast<int>(sorted_letter_counts.size()), 5); i++) {
    top_five_letters += sorted_letter_counts[i].first;
}

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
            // проверка, содержит ли слово не менее четырех из пяти наиболее часто встречающихся букв
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
            in_word = false;
        }
        output_text += c;
    }
    if (in_word) {
        // last word in text
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
// Запись результатa в выходной файл.
std::ofstream output_file("output.txt");
output_file << output_text;

return 0;
}