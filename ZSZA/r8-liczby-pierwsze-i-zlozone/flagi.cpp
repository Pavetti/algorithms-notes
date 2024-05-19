#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int road[n];
    for (int i = 0; i < n; i++)
    {
        cin >> road[i];
    }

    int count = 0;
    int wynik = 0;

    for (int k = 1; (k - 1) * (k - 1) + k < n; k++)
    {
        for (int i = 1; i < n - 1; i++)
        {
            if (road[i] > road[i - 1] && road[i] > road[i + 1])
            {
                count++;
                if (k == 1)
                    i += n;
                i += k - 1;
                if (count == k)
                    break;
            }
        }
        if (k == count)
            wynik = max(wynik, count);
        count = 0;
    }
    cout << wynik;
}