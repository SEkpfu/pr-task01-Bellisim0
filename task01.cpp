#include <iostream>

using namespace std;

int main() {
    int hours;
    double rate, bonus;
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите ставку почасовой оплаты(руб. в час): ";
    cin >> rate;
    cout << "Введите % премии: ";
    cin >> bonus;
    double total = hours * rate + hours * rate * bonus / 100;
    cout << "Общая заработанная сумма: " << total;

    return 0;
}
