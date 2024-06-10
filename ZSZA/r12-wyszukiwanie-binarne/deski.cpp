#include <iostream>

using namespace std;
int d, n, m;
bool sprawdz(int deski[][2], int gwozdzie[], int x);
int main()
{
    d = 0;
    cin >> n >> m;
    int deski[n][2], gwozdzie[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> deski[i][0] >> deski[i][1];
        d = max(d, deski[i][1]);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> gwozdzie[i];
    }

    int poc, kon, sr, wynik, das;
    das = 0;
    poc = 0;
    kon = m - 1;

    while (poc <= kon)
    {
        sr = (poc + kon) / 2;
        if (sprawdz(deski, gwozdzie, sr))
        {
            kon = sr - 1;
            wynik = sr;
        }
        else
        {
            poc = sr + 1;
        }
        das++;
    }
}

bool sprawdz(int deski[][2], int gwozdzie[], int x)
{
    int pref[d + 1] = {0};
    int a, b, count;
    for (int i = 0; i < x; ++i)
    {
        pref[gwozdzie[i]]++;
    }
    for (int i = 1; i <= d; ++i)
    {
        pref[i] += pref[i - 1];
    }
    count = 0;
    for (int i = 0; i < n; ++i)
    {
        a = deski[i][0];
        b = deski[i][1];
        if (pref[b] - pref[a - 1] > 0)
            count++;
    }
    return count == n;
}