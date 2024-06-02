#include <iostream>

using namespace std;

int main()
{

    // 0 - można iść
    // 1 kamień

    int n;
    cin >> n;
    int m[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        cin >> m[i];
    }

    int ile = 1;
    int fib[n];
    int skoki[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    int s;
    while (fib[ile] < n)
    {
        ile++;
        fib[ile] = fib[ile - 1] + fib[ile - 2];
    }

    for (int k = 0; k <= n; ++k)
    {
        skoki[k] = n + 1;
    }
    if (m[0] == 0)
    {
        skoki[0] = 0;
    }
    for (int k = 1; k <= n; ++k)
    {
        if (m[k] == 0)
        {
            for (int i = 1; i <= ile; ++i)
            {
                s = k - fib[i];
                if (s >= 0)
                {
                    skoki[k] = min(skoki[k], skoki[s] + 1);
                }
            }
        }
    }
    int wynik = -1;
    if (skoki[n] <= n)
    {
        wynik = skoki[n];
    }
    cout << wynik;
}