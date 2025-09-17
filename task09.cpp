#include <iostream>

using namespace std;

//функция, считающая общую зп, налог и зп на руки
void All(int hours, double hourly_rate, double &total_salary, double &income_tax, double &net_salary) {
    total_salary = hours * hourly_rate;
    income_tax = total_salary * 0.13;
    net_salary = total_salary - income_tax;
}

//функция по нахождению номера минимального элемента
int MinInd(double array[], int size) {
    int min_index = 0;
    for (int i = 1; i < size; i++ ){
        if (array[i] < array[min_index]) min_index = i + 1;
    }
    return min_index;
}

//функция поиска максимального элемента и его номера
void MaxEl(double array[], int size, double &max_el, int &max_index){
    max_el = array[0];
    max_index = 0;
    for (int i = 1; i < size; i++ ){
        if (array[i] > array[max_index]) {
            max_el = array[i];
            max_index = i + 1;
        }
    }
}

//функция считающая кол-во элементов больше заданного числа
int MoreNumb(double array[], int size, double numb) {
    int count = 0;
    for (int i = 0;i < size; i++) {
        if (array[i] > numb) count++;
    }
    return count;
}

//функция возвращающая сумму элементов
double Sum(double array[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum;
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

    cout << "Работник с номером " << MinInd(net_sals, n) << " получил меньше всех\n";

    double max_salary;
    int max_index;
    MaxEl(net_sals, n, max_salary, max_index);
    cout << "Максимальную зп в размере " << max_salary << " получил работник номер " << max_index << endl;

    int numb = 50000;
    cout << "Количество работников с зп выше 50000 рублей: " << MoreNumb(net_sals, n, numb) << endl;

    cout << "Общая сумма налогов: " << Sum(taxes, n);
    
    return 0;
}