#include <iostream>

using namespace std;
int kop(int suma, int w[], int poziom, int index);
int k;
int n;
int pakk = 1;
int main()
{
    cin >> k;
    int n = 2;
    for (int i = 1; i < k; ++i)
    {
        n *= 2;
    }
    int w[n];
    int index = 1;
    int poziom = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int i = 0; i < poziom; ++i)
        {
            cin >> w[index];
            index++;
        }
        poziom *= 2;
    }
    // metoda moja
    int chuj = kop(w[1], w, 1, 1);
    cout << chuj;
    cout << endl;

    // O(nlogn)
    int wynik = INT_MAX;
    int p;
    int suma = 0;
    for (int i = n / 2; i < n; ++i)
    {
        p = i;
        suma = 0;
        while (p >= 1)
        {
            suma += w[p];
            p /= 2;
        }
        wynik = min(suma, wynik);
    }
    cout << wynik;
    cout << endl;

    // O(n)
    n = n - 1; // n = ilosc wierzcholkow
    int sciezka[n + 1];
    for (int i = n / 2 + 1; i <= n; ++i)
    {
        sciezka[i] = w[i];
    }
    for (int i = n / 2; i >= 1; --i)
    {
        sciezka[i] = w[i] + min(sciezka[i * 2], sciezka[i * 2 + 1]);
    }
    wynik = sciezka[1];
    cout << wynik;
}

int kop(int suma, int w[], int poziom, int index)
{
    if (poziom >= k)
    {
        return suma;
    }
    pakk += 2;
    return min(kop(suma + w[index * 2], w, poziom + 1, index * 2), kop(suma + w[index * 2 + 1], w, poziom + 1, index * 2 + 1));
}

// 4
// 3
// 8 4
// 6 3 0 12
// 11 6 4 10 12 7 11 10
