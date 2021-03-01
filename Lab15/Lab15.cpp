#include <iostream>
#include <string>
using namespace std;
struct STR
{
    string specialty;;
    int quantity;
};
void out(STR* N, int size)
{
    cout << endl << "---------------------------------------------------------------------";
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        cout << i + 1 << ")\t" << N[i].specialty << "\n\t" << N[i].quantity << endl;
        cout << endl;
    }
    cout << endl << "---------------------------------------------------------------------";
}
void shellSort(STR* arr, int size)
{
    int j;
    STR tmp;
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            tmp.quantity = arr[i].quantity;
            tmp.specialty = arr[i].specialty;
            for (j = i; j >= step; j -= step)
            {
                if (tmp.quantity < arr[j - step].quantity)
                {
                    arr[j].specialty = arr[j - step].specialty;
                    arr[j].quantity = arr[j - step].quantity;
                }
                else
                {
                    break;
                    j = -2;
                }
            }
            arr[j].specialty = tmp.specialty;
            arr[j].quantity = tmp.quantity;
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int size = -1;
    cout << "Введите количество элементов" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    STR* N = new STR[size];
    for (int i = 0; i < size; i++)
    {
        cin.ignore();
        cout << endl;
        cout << i+1 << ")\tНазвание специальности: ";
        getline(cin, N[i].specialty);
        cout << "\tКоличество студентов: ";
        cin >> N[i].quantity;
        cout << endl;
    }
    out(N, size);
    shellSort(N, size);
    out(N, size);
    return 0;
}

