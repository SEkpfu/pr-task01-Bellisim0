#include <iostream>

using namespace std;

//функция расчета общей зп
double TotalSalary(int hours, double hourly_rate, double bonus_percent) {
    double total = hours * hourly_rate + hours * hourly_rate * bonus_percent / 100;
    
    return total;
}

//функция расчета подоходного налога
double IncomeTax(double total_salary) {
    double income_tax = total_salary * 0.13;

    return income_tax;
}

//функция расчета зп на руки
double NetSalary(double total_salary, double income_tax){
    double net_salary = total_salary - income_tax;

    return net_salary;
}

int main() {
    int hours;
    double rate, bonus;
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите ставку почасовой оплаты(руб. в час): ";
    cin >> rate;
    cout << "Введите % премии: ";
    cin >> bonus;
    double total = TotalSalary(hours, rate, bonus);
    double tax = IncomeTax(total);
    double net_sal = NetSalary(total, tax);
    cout << "Общая зп: " << total << endl;
    cout << "Сумма подоходного налога: " << tax << endl;
    cout << "Зп на руки: " << net_sal;

    return 0;
}
