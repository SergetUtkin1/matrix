#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int m, n, k, r;
    cout << "Введите целые числа m - кол-во строк, n - столбцов, k - № столбца:" << "\n";
    cin >> m >> n >> k;

    int ** a = new int*[m];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Элемент " << i << "й строки " << j << "го столбца: \n";
            cin >> a[i][j];
        }
    }

    cout << "Исходная матрица: \n";
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << "\n";
    
    cout << "Номер k: " << k << "\n";

    for (int j = 0; j < n; j++)
    {
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            if (a[i][j] < 0)
            {
                flag = false;
            }
        }
        if (flag)
        {
            r = j;
        }
    }

    cout << "Номер найденного столбца: " << r+1 << "\n";

    for (int i = 0; i < m; i++)
    {
        int temp = a[i][k - 1];
        a[i][k - 1] = a[i][r];
        a[i][r] = temp;
    }

    cout << "Матрица после преобразования: \n";
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
    }
}

//Ввести с клавиатуры m и n, матрицу mxn и целое число k. Поменять местами
//столбец  с  номером  k и  последний  из  столбцов,
//  содержащих  только  положительные  элементы.
// Вывести  исходную  матрицу, номер  k, номер  найденного
//столбца, матрицу после преобразования.