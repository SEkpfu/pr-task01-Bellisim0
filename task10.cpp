#include <iostream>
#include <iomanip>

using namespace std;

//функция, считающая общую зп, налог и зп на руки
void All(int hours, double hourly_rate, double &total_salary, double &income_tax, double &net_salary) {
    total_salary = hours * hourly_rate;
    income_tax = total_salary * 0.13;
    net_salary = total_salary - income_tax;
}

int main(){
    int count_work = 4;
    int monthes = 3;
    
    //массив с почасовыми ставками
    double rates[count_work];

    //массив с отработанными часами
    double hours[count_work][monthes];

    //трехмерный массив со всеми результатами[работник][месяц][0 - общ зп, 1 - налог, 2 - зп на руки]
    double res[count_work][monthes][3];

    cout << "Введите данные для " << count_work << " работников за " << monthes << " месяца\n";
    for (int i = 0; i < count_work; i++) {
        cout << "Работник номер " << 1 + i << endl;
        cout << "Введите почасовую ставку: ";
        cin >> rates[i];

        for (int j = 0; j < monthes; j++ ) {
            cout << "Месяц номер " << j + 1 << endl;
            cout << "Введите количество часов: ";
            cin >> hours[i][j];
            All(hours[i][j], rates[i], res[i][j][0], res[i][j][1], res[i][j][2]);
        }
    }
    cout << "Сумма полученная первым работником на руки во втором месяце: " << fixed << setprecision(2) << res[0][1][2] << endl;
    
    double sum1 = 0;
    for (int j = 0; j < monthes; j++) {
        sum1 += res[2][j][1];
    }
    cout << "Сумма налога удержанная с третьего работника за год: " << fixed << setprecision(2) << sum1 << endl;

    double max_salary = res[0][2][2];
    int max_ind = 0;
    for (int i = 1; i < count_work; i++){
        if (res[i][2][2] > max_salary) {
            max_salary = res[i][2][2];
            max_ind = i ;
        }
    }
    cout << "Номер работника, заработавшего больше всех в третьем месяце: " << fixed  << setprecision(2) <<  max_ind + 1<< endl;

    double sum2 = 0;
    for (int i = 0; i < count_work; i++) {
        for (int j = 0; j < monthes; j++){
            sum2 += res[i][j][0];
        }
    }
    cout << "Общая сумма, заработанную всей бригадой за год: " << fixed << setprecision(2) <<  sum2;

    return 0;
}