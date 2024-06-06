#include <iostream>

using namespace std;

int main()
{

    int x = 5;
    int n = 11;
    int a[n] = {1, 2, 4, 5, 6, 7, 11, 23, 24, 28, 34};

    // poczatek
    int poc = 0;
    // koniec
    int kon = n - 1;
    int wynik = -1;
    int sr;

    while (poc <= kon)
    {
        sr = (poc + kon) / 2;
        if (a[sr] <= x)
        {
            poc = sr + 1;
            wynik = sr;
        }
        else
        {
            kon = sr - 1;
        }
    }
    cout << a[wynik];
}