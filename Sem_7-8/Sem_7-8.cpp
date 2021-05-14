#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(0, "");

    //������������� �������� ��� ������� �������
    srand(time(0));
    //����� ������������� ������ ���������� ��������������� �����, �� � �������� RAND_MAX
    int N = 10000;

    //���������� ��������� �����
    set <int> unique_values;
    while (unique_values.size() < N) {
        unique_values.insert(rand());
    }
    set <int> unique_values2 = unique_values;
    //��������� ����������
    long start_time = clock();

    //�������� ���
    set <int> test_values;
    test_values.merge(unique_values);

    long end_time = clock();

    cout << "����� ����� ������ (��) set: " << end_time - start_time << endl;


    //������ ������
    start_time = clock();

    vector <int> test_vector;
    test_vector.insert(test_vector.end(), unique_values2.begin(), unique_values2.end());
    sort(test_vector.begin(), test_vector.end());

    end_time = clock();

    cout << "����� ����� ������ (��) vector: " << end_time - start_time << endl;
}