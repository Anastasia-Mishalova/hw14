// hw14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

using namespace std;

//Реализуйте шаблонные функции для поиска максимума, минимума, сортировки массива(любым алгоритмом сортировки), 
// двоичного поиска в массиве, замены элемента массива на переданное значение.


template <typename T, size_t n>
T maximum(T(&arr)[n])
{
    T maximum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    return maximum;
}

template <typename T, size_t n>
T minimum(T(&arr)[n])
{
    T minimum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }
    return minimum;
}

template <typename T, size_t n>
void replace_on(T(&arr)[n], T old_value, T new_value)
{
    replace(begin(arr), end(arr), old_value, new_value);
}

template <typename T, size_t n>
void sort(T(&arr)[n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}
template <typename T, size_t n>
void binary_search(T(&arr)[n], int l, int r, int key)
{
    bool flag = false;
    int mid = 0;

    while (flag == false && l <= r)
    {
        mid = (l + r) / 2;

        if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            flag = true;
        }
    }

    cout << endl;

    if (flag == true)
    {
        cout << "Индекс заданного значения - " << mid;
    }
    else
    {
        cout << "Данный элемент не найден";
    }
}


void print(int arr[], int size)
{
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{
    setlocale(LC_ALL, "ru");

    int key;
    int l = 0;
    int r = 7;

    int arr[]{ 5,99,56,314,7,0,13,73 };

    print(arr, 8);

    cout << "\n\nМаксимум массива - " << maximum(arr);
    cout << "\n\nМинимум массива - " << minimum(arr);

    cout << "\n\nЗамена - ";
    replace_on(arr, 314, 413);
    print(arr, 8);

    cout << "\n\nСортировка - ";
    sort(arr);
    print(arr, 8);

    key = 99;
    cout << "\n\nБинарный поиск";
    binary_search(arr, l, r, key);
}