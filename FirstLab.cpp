#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Открытие файла с текстом
    ifstream file("text.txt");
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 0;
    }

    // Чтение текста из файла
    string text;
    getline(file, text, '\0');
    file.close();

    // Запрос буквы
    char letter;
    cout << "Введите букву: ";
    cin >> letter;

    // Запрос количества слов
    int n;
    cout << "Введите количество слов: ";
    cin >> n;

    // Разбиение текста на слова
    vector<string> words;
    string word = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            word += tolower(text[i]);
        }
        else if (word.length() > 0 && word[word.length() - 1] == letter)
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word = "";
        }
    }
    if (word.length() > 0 && word[word.length() - 1] == letter)
    {
        words.push_back(word);
    }

    // Сортировка слов по длине в порядке не возрастания
    sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() > b.length(); });

    // Вывод N самых длинных слов
    ofstream output("output.txt");
    if (!output.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 0;
    }
    output << "Список " << n << " самых длинных слов, оканчивающихся на букву " << letter << ":" << endl;
    int count = 0;
    for (string word : words)
    {
        if (word[word.length() - 1] == letter)
        {
            output << word << endl;
            count++;
        }
        if (count == n)
        {
            break;
        }
    }
    output.close();

    cout << "Готово!" << endl;

    return 0;
}