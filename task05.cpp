#include <iostream>

using namespace std;

//функция расчета общей зп
double TotalSalary(int hours, double hourly_rate) {
    double total_salary = hours * hourly_rate;
    
    return total_salary;
}

int main() {
    int hours1, hours2;
    double rate1, rate2;
    cout << "Введите количество часов первого работника: ";
    cin >> hours1;
    cout << "Введите ставку оплаты первого работника: ";
    cin >> rate1;
    cout << "Введите количество часов второго работника: ";
    cin >> hours2;
    cout << "Введите ставку оплаты второго работника: ";
    cin >> rate2;
    double total1 = TotalSalary(hours1, rate1);
    double total2 = TotalSalary(hours2, rate2);

    if (total1 > total2) cout << "Первый работник заработал больше\n";
    else cout << "Второй работник заработал больше\n";
    double summ = total1 + total2;
    cout << "Сумма заработанная вместе: " << summ;

    return 0;
}
