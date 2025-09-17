#include <iostream>

using namespace std;

//функция вычисления общей зп
double TotalSalary(int hours, double hourly_rate) {
    double total_salary = hours * hourly_rate;

    return total_salary;
}

int main() {
    int workers = 5;
    double all_salary = 0;
    cout << "Введите данные для бригады из 5 работников\n";

    for (int i = 0; i < 5; i++) {
        int hours;
        double rate;

        cout << "Данные работника номер " << i + 1 << endl;
        cout << "Количество часов: ";
        cin >> hours;
        cout << "Введите ставку оплаты: ";
        cin >> rate;

        double total = TotalSalary(hours, rate);
        all_salary += total;

        cout << "Общий заработок: " << total << endl;
    }
    cout << "Средняя заработная плата в бригаде: " << all_salary / workers;
    return 0;
}