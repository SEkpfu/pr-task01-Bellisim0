#include <iostream>
#include <string>
using namespace std;

//функция, считающая общую зп, налог и зп на руки
void All(int hours, double hourly_rate, double &total_salary, double &income_tax, double &net_salary) {
    total_salary = hours * hourly_rate;
    income_tax = total_salary * 0.13;
    net_salary = total_salary - income_tax;
}

int main() {
    string surname1, surname2;
    int hours1, hours2;
    double rate1, rate2, total1, total2, tax1, tax2, net_sal1, net_sal2;
    
    cout << "Введите данные первого работника " << endl;
    cout << "Фамилия (до 20 символов): ";
    cin >> surname1;
    cout << "Количество часов: ";
    cin >> hours1;
    cout << "Ставка оплаты: ";
    cin >> rate1;
    
    cout << "Введите данные второго работника  " << endl;
    cout << "Фамилия (до 20 символов): ";
    cin >> surname2;
    cout << "Количество часов: ";
    cin >> hours2;
    cout << "Ставка оплаты: ";
    cin >> rate2;

    All(hours1, rate1, total1, tax1, net_sal1);
    All(hours2, rate2, total2, tax2, net_sal2);
    
    if (net_sal1 < 1000) cout << "Меньше 1000 руб. получил: " << surname1 << endl;
    if (net_sal2< 1000) cout << "Меньше 1000 руб. получил: " << surname2 << endl;
    
    
    if (tax1 > 50) {
        size_t len = surname1.size();
        cout << surname1 << ": " << surname1[0] << "-" << surname1[len-1] << endl;
    }
    if (tax2 > 50) {
        size_t len = surname2.size();
        cout << surname2 << ": " << surname2[0] << "-" << surname2[len-1] << endl;
    }
    
    return 0;
}