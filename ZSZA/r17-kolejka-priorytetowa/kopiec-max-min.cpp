#include <cmath>
#include <iostream>

using namespace std;
int n = 8;
int nMax = 0;
int nMin = 0;
int a[8] = {2, 3, 4, 0, 3, 2, 8, 0};
int kMax[9] = {0};
int kMin[9] = {0};
int usunienty[1000000] = {0};
int wyniki[8] = {0};

void wstawMax(int e);
void wstawMin(int e);
void usunMax();
void usunMin();
void przywrocMax(int i);
void przywrocMin(int i);

int main()
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 0)
        {
            wstawMax(a[i]);
            wstawMin(-a[i]);
        }
        else
        {
            wyniki[i] = kMax[1] + kMin[1];
            usunienty[kMax[1]] = 1;
            usunienty[-kMin[1]] = 1;
            while (nMax > 0 && usunienty[kMax[1]] == 1)
                usunMax();
            while (nMin > 0 && usunienty[-kMin[1]] == 1)
                usunMin();
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << wyniki[i] << endl;
    }
}

void wstawMax(int e)
{
    nMax++;
    kMax[nMax] = e;
    int w = nMax;
    while (w > 1 && kMax[w] > kMax[w / 2])
    {
        swap(kMax[w], kMax[w / 2]);
        w /= 2;
    }
}

void wstawMin(int e)
{
    nMin++;
    kMin[nMin] = e;
    int w = nMin;
    while (w > 1 && kMin[w] > kMin[w / 2])
    {
        swap(kMin[w], kMin[w / 2]);
        w /= 2;
    }
}

void przywrocMax(int i)
{
    int lewy = 2 * i;
    int prawy = 2 * i + 1;
    int maks = i;

    if (lewy <= nMax && kMax[lewy] > kMax[maks])
        maks = lewy;
    if (prawy <= nMax && kMax[prawy] > kMax[maks])
        maks = prawy;
    if (maks > i)
    {
        swap(kMax[i], kMax[maks]);
        przywrocMax(maks);
    }
}

void przywrocMin(int i)
{
    int lewy = 2 * i;
    int prawy = 2 * i + 1;
    int maks = i;

    if (lewy <= nMin && kMin[lewy] > kMin[maks])
        maks = lewy;
    if (prawy <= nMin && kMin[prawy] > kMin[maks])
        maks = prawy;
    if (maks > i)
    {
        swap(kMin[i], kMin[maks]);
        przywrocMax(maks);
    }
}

void usunMax()
{
    kMax[1] = kMax[nMax];
    nMax--;
    przywrocMax(1);
}

void usunMin()
{
    kMin[1] = kMin[nMin];
    nMin--;
    przywrocMin(1);
}
