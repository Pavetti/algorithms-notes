#include <iostream>
#include <algorithm>

using namespace std;

// 6 7 2 3 1 3 1 5

long long nieMniejsze(long long s, int szer[], int dlug[]);
int a, b, n, k;
int main()
{

    cin >> a >> b >> n >> k;
    int x[n], y[n];
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    int szer[n + 1];
    int dlug[n + 1];

    szer[0] = x[0];
    dlug[0] = y[0];
    for (int i = 1; i < n; ++i)
    {
        szer[i] = x[i] - x[i - 1];
        dlug[i] = y[i] - y[i - 1];
    }
    szer[n] = a - x[n - 1];
    dlug[n] = b - y[n - 1];

    sort(szer, szer + (n + 1));
    sort(dlug, dlug + (n + 1));

    long long poc, kon, s, wynik;

    poc = 1;
    kon = a * b;

    while (poc <= kon)
    {

        s = (poc + kon) / 2;
        if (nieMniejsze(s, szer, dlug) >= k)
        {
            poc = s + 1;
            wynik = s;
        }
        else
            kon = s - 1;
    }
    cout << wynik;
}

long long nieMniejsze(long long s, int szer[], int dlug[])
{
    long long wynik = 0;
    int j = n;
    for (int i = 0; i <= n; ++i)
    {
        while (j >= 0 && (long long)szer[i] * dlug[j] >= s)
            j--;
        wynik += (n - j);
    }
    return wynik;
}