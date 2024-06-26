#include <iostream>

using namespace std;

int main()
{

    int d;
    cin >> d;
    int zapytania[d][2];
    int k = 0;
    for (int i = 0; i < d; i++)
    {
        cin >> zapytania[i][0] >> zapytania[i][1];
        k = max(zapytania[i][1], k);
    }

    int F[k + 1] = {0};
    for (int i = 2; i * i <= k; i++)
    {
        if (!F[i])
        {
            for (int j = i + i; j <= k; j += i)
            {
                if (!F[j])
                    F[j] = i;
            }
        }
    }
    int pref[k + 1] = {0};
    for (int i = 2; i * i * i <= k; ++i)
    {
        if (F[i] == 0)
        {
            pref[i * i * i] = 1;
        }
    }
    for (int i = 2; i <= k; ++i)
    {
        if (F[i] != 0 && F[i] * F[i] != i && F[i / F[i]] == 0)
        {
            pref[i] = 1;
        }
        pref[i] += pref[i - 1];
    }

    for (int i = 0; i < d; i++)
    {
        int a = zapytania[i][0];
        int b = zapytania[i][1];

        cout << pref[b] - pref[a - 1] << endl;
    }
}