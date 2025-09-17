#include <iostream>

using namespace std;

// функция ввода даных
void InputData(int &hours, double &hourly_rate, double &bonus_percent) {
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите ставку почасовой оплаты(руб. в час): ";
    cin >> hourly_rate;
    cout << "Введите % премии: ";
    cin >> bonus_percent;
}

//функция, считающая общую зп, налог и зп на руки
void All(int hours, double hourly_rate, double bonus_percent, double &total_salary,
double &income_tax, double &net_salary) {
    total_salary = hours * hourly_rate + hours * hourly_rate * bonus_percent / 100;
    income_tax = total_salary * 0.13;
    net_salary = total_salary - income_tax;
}

int main() {
    int hours;
    double rate, bonus, total, tax, net_sal;
    InputData(hours, rate, bonus);
    All(hours, rate, bonus, total, tax, net_sal);
    cout << "Общая зп: " << total << endl;
    cout << "Сумма подоходного налога: " << tax << endl;
    cout << "Зп на руки: " << net_sal;

    return 0;
}