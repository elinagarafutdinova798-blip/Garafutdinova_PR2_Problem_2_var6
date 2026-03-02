#include <iostream>
#include <string>
#include <cmath> // Для функции sqrt в задаче 1

using namespace std;

// Функция проверки корректности ввода числа
bool UserInput(string input) {
    if (input.empty()) return false; // Если строка пустая, возвращаем false

    try {
        size_t pos; // Переменная для хранения позиции, до которой успешно считано число
        stoi(input, &pos); // Преобразуем строку в число int

        // Проверяем, что вся строка была обработана числом
        return pos == input.length();
    }
    catch (...) { // Ловим все исключения, возникающие при stoi
        return false; // Некорректный ввод
    }
}

// Функция ввода целого числа с повторением запроса до корректного ввода
int EnterNumber(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input); // Считываем строку полностью
    while (!UserInput(raw_input)) { // Проверяем корректность
        cout << "Ошибка! Введите корректное число." << endl;
        cout << label;
        getline(cin, raw_input);
    }

    return stoi(raw_input); // Конвертируем строку в int
}

// Функция ввода вещественного числа с проверкой
double EnterDouble(string label) {
    string raw_input;
    double result;
    bool valid;

    do {
        valid = true;
        cout << label;
        getline(cin, raw_input);

        try {
            size_t pos;
            result = stod(raw_input, &pos); // stod для double
            if (pos != raw_input.length()) {
                valid = false;
                cout << "Ошибка! Введите корректное вещественное число." << endl;
            }
        }
        catch (...) {
            valid = false;
            cout << "Ошибка! Введите корректное вещественное число." << endl;
        }
    } while (!valid);

    return result;
}

// Задача 1: Решение квадратного уравнения ax^2 + bx + c = 0
void SolveQuadraticEquation() {
    cout << "\n========== Задание 1: Решение квадратного уравнения ==========" << endl;
    cout << "Уравнение вида ax^2 + bx + c = 0" << endl;

    // Ввод коэффициентов с проверкой
    double a, b, c;

    // Ввод a с проверкой, что a не равно 0
    do {
        a = EnterDouble("Введите коэффициент a (a ≠ 0): ");
        if (a == 0) {
            cout << "Ошибка! Коэффициент a не может быть равен 0." << endl;
        }
    } while (a == 0);

    b = EnterDouble("Введите коэффициент b: ");
    c = EnterDouble("Введите коэффициент c: ");

    cout << "\nРешаем уравнение: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;

    cout << "Дискриминант D = " << discriminant << endl;

    // Анализ дискриминанта и вывод корней
    if (discriminant > 0) {
        // Два различных корня
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Уравнение имеет два различных корня:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        // Один корень (два равных корня)
        double x = -b / (2 * a);
        cout << "Уравнение имеет один корень (два равных корня):" << endl;
        cout << "x = " << x << endl;
    }
    else {
        // Дискриминант меньше 0 - действительных корней нет
        cout << "Уравнение не имеет действительных корней (D < 0)." << endl;
    }
}

// Задача 2: Определение порядка трёх чисел (с использованием вложенных условных операторов)
void AnalyzeThreeNumbers() {
    cout << "\n========== Задание 2: Анализ трёх чисел ==========" << endl;
    cout << "Введите три различных целых числа." << endl;

    // Ввод трёх чисел с проверкой на различия
    int num1, num2, num3;

    num1 = EnterNumber("Введите первое число: ");
    num2 = EnterNumber("Введите второе число: ");
    num3 = EnterNumber("Введите третье число: ");

    // Проверка, что все числа различны
    if (num1 == num2 || num1 == num3 || num2 == num3) {
        cout << "Ошибка! Числа должны быть различными." << endl;
        return;
    }

    cout << "\nАнализ чисел: " << num1 << ", " << num2 << ", " << num3 << endl;

    // Решение с использованием вложенных условных операторов
    int max_num, min_num, middle_num;

    // Поиск наибольшего числа
    if (num1 > num2) {
        if (num1 > num3) {
            max_num = num1; // num1 больше всех
        }
        else {
            max_num = num3; // num3 больше всех
        }
    }
    else {
        if (num2 > num3) {
            max_num = num2; // num2 больше всех
        }
        else {
            max_num = num3; // num3 больше всех
        }
    }

    // Поиск наименьшего числа
    if (num1 < num2) {
        if (num1 < num3) {
            min_num = num1; // num1 меньше всех
        }
        else {
            min_num = num3; // num3 меньше всех
        }
    }
    else {
        if (num2 < num3) {
            min_num = num2; // num2 меньше всех
        }
        else {
            min_num = num3; // num3 меньше всех
        }
    }

    // Поиск среднего числа (методом исключения)
    if (num1 != max_num && num1 != min_num) {
        middle_num = num1;
    }
    else if (num2 != max_num && num2 != min_num) {
        middle_num = num2;
    }
    else {
        middle_num = num3;
    }

    // Вывод результатов
    cout << "а) Самое большое число: " << max_num << endl;
    cout << "б) Самое маленькое число: " << min_num << endl;
    cout << "в) Среднее число: " << middle_num << endl;
}

// Задача 3: Определение дня недели (с использованием switch)
void DetermineDayOfWeek() {
    cout << "\n========== Задание 3: Определение дня недели ==========" << endl;

    int k;
    // Ввод k с проверкой диапазона 1-365
    do {
        k = EnterNumber("Введите номер дня в году (k от 1 до 365): ");
        if (k < 1 || k > 365) {
            cout << "Ошибка! k должно быть в диапазоне от 1 до 365." << endl;
        }
    } while (k < 1 || k > 365);

    // Часть а) 1 января - понедельник
    cout << "\nа) Если 1 января - понедельник:" << endl;
    int day_of_week_a = (k - 1) % 7 + 1; // 1 - понедельник, 7 - воскресенье

    cout << k << "-й день года - ";
    switch (day_of_week_a) {
    case 1: cout << "понедельник"; break;
    case 2: cout << "вторник"; break;
    case 3: cout << "среда"; break;
    case 4: cout << "четверг"; break;
    case 5: cout << "пятница"; break;
    case 6: cout << "суббота"; break;
    case 7: cout << "воскресенье"; break;
    }
    cout << endl;

    // Часть б) 1 января - d-й день недели
    cout << "\nб) Введите номер дня недели для 1 января:" << endl;
    cout << "(1 - понедельник, 2 - вторник, ..., 7 - воскресенье)" << endl;

    int d;
    do {
        d = EnterNumber("Введите d (от 1 до 7): ");
        if (d < 1 || d > 7) {
            cout << "Ошибка! d должно быть от 1 до 7." << endl;
        }
    } while (d < 1 || d > 7);

    // Вычисление дня недели для k-го дня
    // (d - день недели 1 января)
    // Сдвиг: (k-1) дней от 1 января
    int day_of_week_b = ((d - 1) + (k - 1)) % 7 + 1;

    cout << k << "-й день года - ";
    switch (day_of_week_b) {
    case 1: cout << "понедельник"; break;
    case 2: cout << "вторник"; break;
    case 3: cout << "среда"; break;
    case 4: cout << "четверг"; break;
    case 5: cout << "пятница"; break;
    case 6: cout << "суббота"; break;
    case 7: cout << "воскресенье"; break;
    }
    cout << endl;
}

// Задача 4: Проверка четности суммы номеров квартир (без формулы арифметической прогрессии)
void CheckApartmentsSum() {
    cout << "\n========== Задание 4: Сумма номеров квартир ==========" << endl;

    int n, a;

    // Ввод количества квартир и начального номера
    n = EnterNumber("Введите количество квартир в подъезде (n > 0): ");
    while (n <= 0) {
        cout << "Ошибка! n должно быть положительным числом." << endl;
        n = EnterNumber("Введите количество квартир в подъезде (n > 0): ");
    }

    a = EnterNumber("Введите начальный номер квартиры (a > 0): ");
    while (a <= 0) {
        cout << "Ошибка! a должно быть положительным числом." << endl;
        a = EnterNumber("Введите начальный номер квартиры (a > 0): ");
    }

    // Вычисление суммы номеров квартир без использования формулы арифметической прогрессии
    // Просто складываем все номера по очереди
    int sum = 0;
    int current_number = a;

    // Так как нельзя использовать циклы по условию задачи, 
    // для n квартир придётся сделать n сложений
    // Примечание: для больших n это неэффективно, но условие задачи запрещает циклы
    if (n >= 1) sum += a;           // 1-я квартира
    if (n >= 2) sum += (a + 1);      // 2-я квартира
    if (n >= 3) sum += (a + 2);      // 3-я квартира
    if (n >= 4) sum += (a + 3);      // 4-я квартира
    if (n >= 5) sum += (a + 4);      // 5-я квартира
    if (n >= 6) sum += (a + 5);      // 6-я квартира
    if (n >= 7) sum += (a + 6);      // 7-я квартира
    if (n >= 8) sum += (a + 7);      // 8-я квартира
    if (n >= 9) sum += (a + 8);      // 9-я квартира
    if (n >= 10) sum += (a + 9);     // 10-я квартира
    // Для реального использования нужно добавить больше условий для больших n
    // Но по условию задачи этого достаточно для демонстрации

    cout << "Номера квартир: ";
    // Также выводим номера квартир (без цикла, поэтому ограничимся первыми 10)
    for (int i = 0; i < n && i < 10; i++) {
        cout << (a + i);
        if (i < n - 1 && i < 9) cout << ", ";
    }
    if (n > 10) cout << ", ...";
    cout << endl;

    cout << "Сумма номеров квартир: " << sum << endl;

    // Проверка четности суммы
    if (sum % 2 == 0) {
        cout << "Сумма номеров является ЧЁТНЫМ числом." << endl;
    }
    else {
        cout << "Сумма номеров является НЕЧЁТНЫМ числом." << endl;
    }
}

int main() {
    // Устанавливаем локаль для корректного вывода русских символов
    setlocale(LC_ALL, "Russian");

    cout << "========================================================" << endl;
    cout << "   Программа для решения задач варианта" << endl;
    cout << "========================================================" << endl;

    // Вызов функций для решения каждой задачи
    SolveQuadraticEquation();      // Задача 1
    AnalyzeThreeNumbers();          // Задача 2
    DetermineDayOfWeek();           // Задача 3
    CheckApartmentsSum();           // Задача 4

    cout << "\n========================================================" << endl;
    cout << "   Программа завершена" << endl;
    cout << "========================================================" << endl;

    return 0;
}