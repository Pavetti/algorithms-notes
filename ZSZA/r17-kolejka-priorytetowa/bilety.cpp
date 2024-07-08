#include <iostream>
#include <vector>

using namespace std;

void wstaw(int e, int t[]);
int usun(int w[]);
void przywroc(int i, int t[]);
int m = 0;
int main()
{
    int b[1000];

    int n;
    cin >> n;
    int c, x;

    int bilety = 0;
    int cena = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> c >> x;
        for (int j = 0; j < x; ++j)
        {
            wstaw(-c, b);
        }
        cena += usun(b);
        bilety++;
    }
    cout << -cena;
}

void wstaw(int e, int t[])
{
    m++;
    t[m] = e;
    int w = m;
    while (w > 1 && t[w] >= t[w / 2])
    {
        swap(t[w], t[w / 2]);
        w /= 2;
    }
}

void przywroc(int i, int t[])
{
    int lewy = 2 * i;
    int prawy = 2 * i + 1;
    int maks = i;

    if (lewy <= m && t[lewy] >= t[maks])
        maks = lewy;
    if (prawy <= m && t[prawy] >= t[maks])
        maks = prawy;
    if (maks > i)
    {
        swap(t[i], t[maks]);
        przywroc(maks, t);
    }
}

int usun(int w[])
{
    int x = w[1];
    w[1] = w[m];
    m--;
    przywroc(1, w);
    return x;
}
