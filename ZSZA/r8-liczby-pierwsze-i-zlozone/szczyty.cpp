#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int road[n];
    for (int i = 0; i < n; i++)
    {
        cin >> road[i];
    }
    int wynik = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            int a = i;
            int b = n / i;
            int szczyty_count = 0;
            int pomocnik;

            for (int s = 1; s < n - 1; s++)
            {
                if (road[s] > road[s - 1] && road[s] > road[s + 1])
                {
                    szczyty_count++;
                    pomocnik = (s + 1) % a;
                    s += a - pomocnik;
                }
            }
            if (szczyty_count == b)
            {
                wynik = max(wynik, b);
            }
            szczyty_count = 0;
            for (int s = 1; s < n - 1; s++)
            {
                if (road[s] > road[s - 1] && road[s] > road[s + 1])
                {
                    szczyty_count++;
                    pomocnik = (s + 1) % b;
                    s += b - pomocnik;
                }
            }
            if (szczyty_count == a)
            {
                wynik = max(wynik, a);
            }
        }
    }
    cout << wynik;
}