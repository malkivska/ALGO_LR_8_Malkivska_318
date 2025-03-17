#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

// Завдання 1: Зчитування масиву з файлу і перестановка частини масиву в зворотному порядку
// Функція для зчитування масиву з файлу
void get_mas(const string &filename, vector<float> &mas) {
    ifstream inputFile(filename);  // Відкриваємо файл для читання
    int n;
    inputFile >> n;  // Зчитуємо розмір масиву
    mas.resize(n);  // Задаємо розмір масиву
    for (int i = 0; i < n; i++) {
        inputFile >> mas[i];  // Зчитуємо елементи масиву з файлу
    }
    inputFile.close();  // Закриваємо файл після зчитування
}

// Функція для виведення масиву в файл
void show_mas(const string &filename, const vector<float> &mas) {
    ofstream outputFile(filename);  // Відкриваємо файл для запису
    for (float value : mas) {
        outputFile << value << " ";  // Записуємо кожен елемент масиву в файл
    }
    outputFile << endl;  // Перехід на новий рядок
    outputFile.close();  // Закриваємо файл після запису
}

// Функція для перестановки частини масиву в зворотному порядку
void reverseArraySection(vector<float> &mas, int K, int L) {
    // Використовуємо стандартну функцію reverse для перестановки частини масиву
    reverse(mas.begin() + K - 1, mas.begin() + L);  // K і L зменшені на 1 через 0-індексацію
}

// Завдання 2: Пошук схожих стовпців у матриці
// Функція для зчитування матриці з файлу
void get_matrix(const string &filename, vector<vector<int>> &matrix, int &M, int &N) {
    ifstream inputFile(filename);  // Відкриваємо файл для читання
    inputFile >> M >> N;  // Зчитуємо кількість рядків і стовпців
    matrix.resize(M, vector<int>(N));  // Створюємо матрицю потрібного розміру
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> matrix[i][j];  // Зчитуємо елементи матриці з файлу
        }
    }
    inputFile.close();  // Закриваємо файл після зчитування
}

// Функція для перевірки схожості двох стовпців
bool areColumnsSimilar(const vector<vector<int>> &matrix, int col1, int col2, int M) {
    set<int> set1, set2;  // Використовуємо множини для зберігання унікальних значень стовпців
    for (int i = 0; i < M; i++) {
        set1.insert(matrix[i][col1]);  // Додаємо значення з першого стовпця в множину
        set2.insert(matrix[i][col2]);  // Додаємо значення з другого стовпця в множину
    }
    return set1 == set2;  // Порівнюємо множини для визначення схожості
}

// Функція для підрахунку схожих стовпців
int countSimilarColumns(const vector<vector<int>> &matrix, int M, int N) {
    int similarCount = 0;  // Лічильник схожих стовпців
    for (int j = 0; j < N - 1; j++) {
        if (areColumnsSimilar(matrix, j, N - 1, M)) {  // Перевіряємо кожен стовпець на схожість з останнім
            similarCount++;  // Якщо схожі, збільшуємо лічильник
        }
    }
    return similarCount;  // Повертаємо кількість схожих стовпців
}

// Завдання 3: Шейкерне сортування для масиву символів
// Функція для виконання шейкерного сортування (з двох напрямків)
void CocktailShakerSort(vector<char> &arr) {
    int n = arr.size();
    for (int p = 1; p <= n / 2; p++) {  // Проходимо по масиву з двох напрямків
        for (int i = p - 1; i < n - p; i++) {  // Прохід зліва направо (бульбашковий)
            if (arr[i] < arr[i + 1]) {  // Якщо елемент менший за наступний
                swap(arr[i], arr[i + 1]);  // Міняємо їх місцями
            }
        }
        for (int i = n - p - 1; i >= p; i--) {  // Прохід справа наліво (зворотний)
            if (arr[i] < arr[i - 1]) {  // Якщо елемент менший за попередній
                swap(arr[i], arr[i - 1]);  // Міняємо їх місцями
            }
        }
    }
}

// Функція для виведення відсортованого масиву символів
void show_array(const vector<char> &arr) {
    for (char ch : arr) {
        cout << ch << " ";  // Виводимо кожен елемент масиву
    }
    cout << endl;  // Перехід на новий рядок
}

// Завдання 4: Створення меню для вибору завдання
// Функція для виведення меню
void showMenu() {
    cout << "Меню:" << endl;
    cout << "1. Завдання 1: Перестановка частини масиву" << endl;
    cout << "2. Завдання 2: Пошук схожих стовпців" << endl;
    cout << "3. Завдання 3: Шейкерне сортування символів" << endl;
    cout << "4. Вихід" << endl;
    cout << "Оберіть завдання (1-4): ";
}

// Головна функція для виконання програми
int main() {
    int choice;
    bool exit = false;  // Флаг для виходу з програми

    while (!exit) {
        showMenu();  // Виводимо меню
        cin >> choice;  // Вводимо вибір користувача

        switch (choice) {
            case 1: {
                // Завдання 1: Перестановка частини масиву
                cout << "Введіть ім'я файлу для масиву: ";
                string filename;
                cin >> filename;
                vector<float> mas;
                get_mas(filename, mas);  // Зчитуємо масив з файлу

                int K, L;
                cout << "Введіть K та L для перестановки (1 ≤ K < L ≤ N): ";
                cin >> K >> L;
                reverseArraySection(mas, K, L);  // Перестановка частини масиву в зворотному порядку

                show_mas("array_out_n.txt", mas);  // Записуємо результат в файл
                break;
            }
            case 2: {
                // Завдання 2: Пошук схожих стовпців у матриці
                cout << "Введіть ім'я файлу для матриці: ";
                string filename;
                cin >> filename;
                vector<vector<int>> matrix;
                int M, N;
                get_matrix(filename, matrix, M, N);  // Зчитуємо матрицю з файлу

                int similarCount = countSimilarColumns(matrix, M, N);  // Підраховуємо схожі стовпці
                ofstream outputFile("matr_out_n.txt");
                outputFile << "Кількість схожих стовпців: " << similarCount << endl;  // Записуємо результат
                break;
            }
            case 3: {
                // Завдання 3: Шейкерне сортування
                cout << "Введіть масив символів для сортування (7 елементів): ";
                vector<char> charArray(7);
                for (int i = 0; i < 7; i++) {
                    cin >> charArray[i];  // Вводимо масив символів для сортування
                }
                CocktailShakerSort(charArray);  // Виконуємо шейкерне сортування

                cout << "Відсортований масив: ";
                show_array(charArray);  // Виводимо відсортований масив символів
                break;
            }
            case 4: {
                // Вихід з програми
                cout << "Вихід з програми..." << endl;
                exit = true;  // Змінюємо флаг, щоб вийти з циклу
                break;
            }
            default:
                cout << "Невірний вибір! Спробуйте ще раз." << endl;
                break;
        }
    }

    return 0;  // Завершення програми
}
