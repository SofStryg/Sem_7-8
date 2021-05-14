#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(0, "");

    //Рандомизируем значения для каждого запуска
    srand(time(0));
    //Можно сгенерировать другое количество неповторяющихся чисел, но в пределах RAND_MAX
    int N = 10000;

    //Генерируем случайные числа
    set <int> unique_values;
    while (unique_values.size() < N) {
        unique_values.insert(rand());
    }
    set <int> unique_values2 = unique_values;
    //Запускаем секундомер
    long start_time = clock();

    //Начинаем код
    set <int> test_values;
    test_values.merge(unique_values);

    long end_time = clock();

    cout << "Общее время работы (мс) set: " << end_time - start_time << endl;


    //Теперь вектор
    start_time = clock();

    vector <int> test_vector;
    test_vector.insert(test_vector.end(), unique_values2.begin(), unique_values2.end());
    sort(test_vector.begin(), test_vector.end());

    end_time = clock();

    cout << "Общее время работы (мс) vector: " << end_time - start_time << endl;
}