#include <iostream>

using namespace std;

int main()
{

    int z, s, p;
    cin >> z;
    int wynik[z];
    int zapytania[z][2];
    int k = 0;
    int m;
    for (int i = 0; i < z; i++)
    {
        cin >> zapytania[i][0] >> zapytania[i][1];
        k = max(k, zapytania[i][0]);
    }

    int potega[30];
    potega[0] = 1;
    for (int i = 1; i < k; i++)
    {
        potega[i] = 2 * potega[i - 1];
    }

    int fib[k];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < k; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % potega[30];
    }

    for (int i = 0; i < z; i++)
    {
        s = zapytania[i][0];
        p = zapytania[i][1];
        wynik[i] = fib[s] % potega[p];
    }

    for (int i = 0; i < z; i++)
    {
        cout << wynik[i];
    }
}