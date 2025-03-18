#include <iostream>   // Введення та виведення
#include <fstream>    // Робота з файлами
#include <vector>     // Вектор
#include <algorithm>  // Алгоритми (reverse, sort)
#include <set>        // Множини
#include <limits>     // Обробка помилок вводу

using namespace std;

// ========================== Завдання 1: Обробка масиву ==========================
void executeTask1() {
    int n;
    cout << "Завдання 1: Перестановка частини масиву.\n";
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    vector<float> mas(n);
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    int K, L;
    cout << "Введіть K та L для перестановки (1 ≤ K < L ≤ " << n << "): ";
    cin >> K >> L;
    reverse(mas.begin() + K - 1, mas.begin() + L); // Переставляємо 2-4 елементи в зворотному порядку

    // Запис результату в файл
    ofstream outputFile("array_out_n.txt");
    for (float value : mas) outputFile << value << " ";
    outputFile << endl;
    outputFile.close();
    cout << "Завдання 1 виконано! Результат записано в файл array_out_n.txt.\n";
}

// ========================== Завдання 2: Аналіз матриці ==========================
void executeTask2() {
    int M, N;
    cout << "Завдання 2: Пошук схожих стовпців у матриці.\n";
    cout << "Введіть кількість рядків та стовпців матриці: ";
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    for (int j = 0; j < N - 1; j++) {
        for (int k = j + 1; k < N; k++) {
            multiset<int> set1, set2;
            for (int i = 0; i < M; i++) {
                set1.insert(matrix[i][j]);
                set2.insert(matrix[i][k]);
            }
            if (set1 == set2) count++;
        }
    }

    // Запис результату в файл
    ofstream outputFile("matr_out_n.txt");
    outputFile << "Кількість схожих стовпців: " << count << endl;
    outputFile.close();
    cout << "Завдання 2 виконано! Результат записано в файл matr_out_n.txt.\n";
}

// ========================== Завдання 3: Сортування символів ==========================
void executeTask3() {
    int n;
    cout << "Завдання 3: Сортування символів.\n";
    cout << "Введіть кількість символів для сортування: ";
    cin >> n;

    vector<char> charArray(n);
    cout << "Введіть символи для сортування: ";
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }

    sort(charArray.begin(), charArray.end());

    // Запис результату в файл
    ofstream outputFile("char_out_n.txt");
    for (char ch : charArray) outputFile << ch << " ";
    outputFile << endl;
    outputFile.close();
    cout << "Завдання 3 виконано! Результат записано в файл char_out_n.txt.\n";
}

// ========================== Завдання 4: Обернення тексту ==========================
void executeTask4() {
    cin.ignore();  // Очистка буфера після попереднього вводу
    string text;
    cout << "Завдання 4: Обернення тексту.\n";
    cout << "Введіть текст для обертання: ";
    getline(cin, text);  // Отримуємо весь текст

    reverse(text.begin(), text.end());

    // Запис результату в файл
    ofstream outputFile("text_out_n.txt");
    outputFile << text << endl;
    outputFile.close();
    cout << "Завдання 4 виконано! Результат записано в файл text_out_n.txt.\n";
}

// ========================== Головне меню програми ==========================
void showMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Завдання 1: Перестановка частини масиву\n";
    cout << "2. Завдання 2: Пошук схожих стовпців у матриці\n";
    cout << "3. Завдання 3: Сортування символів\n";
    cout << "4. Завдання 4: Обернення тексту\n";
    cout << "5. Вихід\n";
    cout << "Оберіть завдання (1-5): ";
}

int main() {
    int choice;
    while (true) {
        showMenu(); // Виводимо меню
        cin >> choice;

        // Перевірка на некоректний ввід (наприклад, якщо ввели букву)
        if (cin.fail()) {
            cin.clear();  // Очищення помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Видаляємо зайві символи
            cout << "Помилка! Введіть число від 1 до 5.\n";
            continue;
        }

        // Виконання вибраного завдання
        switch (choice) {
            case 1:
                executeTask1();
                break;
            case 2:
                executeTask2();
                break;
            case 3:
                executeTask3();
                break;
            case 4:
                executeTask4();
                break;
            case 5:
                cout << "Вихід з програми...\n";
                return 0;
            default:
                cout << "Невірний вибір! Введіть число від 1 до 5.\n";
                break;
        }

        // Очищення залишкових символів після вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
