#include <iostream>

using namespace std;

//функция, считающая общую зп, налог и зп на руки
void All(int hours, double hourly_rate, double &total_salary, double &income_tax, double &net_salary) {
    total_salary = hours * hourly_rate;
    income_tax = total_salary * 0.13;
    net_salary = total_salary - income_tax;
}

int main() {
    int n;
    cout << "Введите количество работников: ";
    cin >> n;
    
    //создание массивов
    int hours[n];
    double rate[n];
    double totals[n];
    double taxes[n];
    double net_sals[n];

    //введение данных о работниках 
    for (int i = 0; i < n; i++){
        cout << "Работник номер " << i+1 << endl;
        cout << "Количество часов: ";
        cin >> hours[i];
        cout << "Ставка оплаты: ";
        cin >> rate[i];

        All(hours[i], rate[i], totals[i], taxes[i], net_sals[i]);
    }
    
    //нахождение работника с минимальной зп
    double min_salary = net_sals[0];
    int min_index = 1;
    for (int i = 1; i < n; i ++){
        if (net_sals[i] < min_salary){
            min_salary = net_sals[i];
            min_index = i + 1;
        }
    }
    cout << "Работник с номером " << min_index << " получил меньше всех\n";

    //нахождение максимальной зп
    double max_salary = net_sals[0];
    int max_index = 1;
    for (int i = 1; i < n; i++){
        if (net_sals[i] > max_salary){
            max_salary = net_sals[i];
            max_index = i + 1;
        }
    }
    cout << "Максимальную зп в размере " << max_salary << " получил работник номер " << max_index << endl;

    //вывод количества и номеров работников с зп > 50000 руб.
    int count = 0;
    for (int i = 0; i < n; i++){
        if (net_sals[i] > 50000){
            cout << "Работник номер " << i + 1<< " получил зп выше 50000 руб.\n";
            count++;
        }
    }
    cout << "Количество работников с зп выше 50000 рублей: " << count << endl;

    //нахождение общей суммы налога
    double tax_sum = 0;
    for (int i = 0;i < n; i++){
        tax_sum += taxes[i];
    }
    cout << "Общая сумма налогов: " << tax_sum;

    return 0;
}