#include <iostream>

using namespace std;

int main()
{

    int z;
    cin >> z;
    int zapytania[z][2];
    int k = 0;
    for (int i = 0; i < z; i++)
    {
        cin >> zapytania[i][0] >> zapytania[i][1];
        k = max(zapytania[i][1], k);
    }

    int F[k + 1] = {0};
    for (int i = 2; i * i <= k; i++)
    {
        if (!F[i])
        {
            for (int j = i * i; j <= k; j += i)
            {
                if (!F[j])
                    F[j] = i;
            }
        }
    }

    int pref_1[k] = {0};
    int pref_2[k] = {0};
    int pref_3[k] = {0};
    int licznik_2 = 0;
    int licznik_3 = 0;
    for (int i = 2; i <= k; i++)
    {
        if (F[i] != 0 && F[i / F[i]] == 0)
        {
            pref_1[i] = 1;
            licznik_2++;
            licznik_3++;
        }
        else
        {
            licznik_2 = 0;
            licznik_3 = 0;
        }
        if (licznik_2 == 2)
        {
            pref_2[i] = 1;
            licznik_2 = 0;
        }
        if (licznik_3 == 3)
        {
            pref_3[i] = 1;
            licznik_3 = 0;
        }

        pref_1[i] += pref_1[i - 1];
        pref_2[i] += pref_2[i - 1];
        pref_3[i] += pref_3[i - 1];
    }

    for (int i = 0; i < z; i++)
    {
        int a = zapytania[i][0];
        int b = zapytania[i][1];
        if (pref_3[b] - pref_3[a - 1] > 0)
        {
            cout << 3 << endl;
        }
        else if (pref_2[b] - pref_2[a - 1] > 0)
        {
            cout << 2 << endl;
        }
        else if (pref_1[b] - pref_1[a - 1] > 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}