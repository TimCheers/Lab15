#include <iostream>
#include <string>
#include <stack>
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
void Huarsort(STR*arr,int left,int right)
{
    int i, j, support;
    STR tmp;
    stack<int>st;
    st.push(left);
    st.push(right);
    do
    {
        right = st.top();
        st.pop();
        left = st.top();
        st.pop();
        i = left;
        j = right;
        support = arr[(right + left) / 2].quantity;
        do
        {
            while (arr[i].quantity < support)
            {
                i++;
            }
            while (support < arr[j].quantity)
            {
                j--;
            }
            if (i <= j)
            {
                tmp.quantity = arr[i].quantity;
                arr[i].quantity = arr[j].quantity;
                arr[j].quantity = tmp.quantity;
                tmp.specialty = arr[i].specialty;
                arr[i].specialty = arr[j].specialty;
                arr[j].specialty = tmp.specialty;
                i++;
                j--;
            }
        } while (i <= j);
        if (left < j) {
            st.push(left);
            st.push(j);
        }
        if (i < right) {
            st.push(i);
            st.push(right);
        }
    } while (!st.empty());
}
int main()
{
    system("chcp 1251>nul");
    int size = -1, menu = -1;
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
    while (menu != 4)
    {
        cout << "\nКоманды:\n1.Вывод\n2.Сортировка Хуара\n3.Сортировка Шелла\n4.стоп" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            out(N, size);
            break;
        }
        case 2:
        {
            Huarsort(N, 0, size - 1);
            menu = 4;
            out(N, size);
            break;
        }
        case 3:
        {
            shellSort(N, size);
            menu = 4;
            out(N, size);
            break;
        }
        case 4:
        {
            cout << "\nПрограмма остановлена." << endl;
            break;
        }
        default:
            cout << "\nНеизвестная команда!" << endl;
            break;
        }
    }
    return 0;
}