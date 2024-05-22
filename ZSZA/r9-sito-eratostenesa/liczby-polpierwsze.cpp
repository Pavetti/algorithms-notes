#include <iostream>

using namespace std;

int n;
int z;

void wypiszTablice(int tablica[], int rozmiar);

int main()
{
    cin >> n >> z;
    int req[z][2];
    for (int i = 0; i < z; i++)
    {
        cin >> req[i][0] >> req[i][1];
    }

    int F[n] = {0};
    for (int i = 2; i * i <= n; i++)
    {
        if (!F[i])
        {
            for (int k = i * i; k < n; k += i)
                if (!F[k])
                    F[k] = i;
        }
    }

    int pref[n] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (F[i] != 0 && F[i / F[i]] == 0)
            pref[i] = 1;
        pref[i] += pref[i - 1];
    }
    int a;
    int b;
    int wynik;
    for (int i = 0; i < z; i++)
    {
        a = req[i][0];
        b = req[i][1];
        wynik = pref[b] - pref[a];
        cout << wynik << endl;
    }
    cout << endl;
}
