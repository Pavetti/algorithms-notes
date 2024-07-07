#include <cmath>
#include <iostream>

using namespace std;
void wstaw(int e, int kopiec[]);
void usun(int kopiec[]);
void przywroc(int i, int kopiec[]);
int n = 0;
int k = 0;
int nK = 0;
int main()
{
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int wynik = 0;
    int kopiec[n + 1] = {0};
    for (int i = 1; i < k + 2; ++i)
    {
        wstaw(a[i], kopiec);
    }
    wynik = max(wynik, kopiec[1] + kopiec[2]);
    wynik = max(wynik, kopiec[1] + kopiec[3]);

    bool usuniety[1000009];
    for (int i = 0; i < 1000009; ++i)
    {
        usuniety[i] = false;
    }

    int konic = 1;
    for (int i = nK + 1; i < n; ++i)
    {
        usuniety[kopiec[konic]] = true;
        konic++;
        wstaw(a[i], kopiec);
        while (nK > 0 && usuniety[kopiec[1]])
        {
            usun(kopiec);
        }
        int a = kopiec[1];
        usun(kopiec);
        while (nK > 0 && usuniety[kopiec[1]])
        {
            usun(kopiec);
        }
        int b = kopiec[1];
        wstaw(a, kopiec);
        wynik = max(wynik, a + b);
    }
    cout << wynik;
}
void wstaw(int e, int kopiec[])
{
    nK++;
    kopiec[nK] = e;
    int w = nK;
    while (w > 1 && kopiec[w] > kopiec[w / 2])
    {
        swap(kopiec[w], kopiec[w / 2]);
        w /= 2;
    }
}
void przywroc(int i, int kopiec[])
{
    const int lewy = 2 * i;
    const int prawy = 2 * i + 1;
    int maks = i;

    if (lewy <= nK && kopiec[lewy] > kopiec[maks])
        maks = lewy;
    if (prawy <= nK && kopiec[prawy] > kopiec[maks])
        maks = prawy;
    if (maks > i)
    {
        swap(kopiec[i], kopiec[maks]);
        przywroc(maks, kopiec);
    }
}

void usun(int kopiec[])
{
    kopiec[1] = kopiec[nK];
    nK--;
    przywroc(1, kopiec);
}
