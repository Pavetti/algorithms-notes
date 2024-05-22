#include <iostream>

using namespace std;

int main()
{
    int n = 100;
    int x = 16;
    int F[n] = {0};
    int czynniki[x] = {0};
    for (int i = 2; i * i <= n; i++)
    {
        if (!F[i])
        {
            for (int k = i * i; k <= n; k += i)
                if (!F[k])
                    F[k] = i;
        }
    }
    int k = 0;
    int helper = x;
    while (F[x] > 0)
    {
        czynniki[k] = F[x];
        k++;
        x /= F[x];
    }
    czynniki[k] = x;
    k++;

    for (int i = 0; i < helper; i++)
    {
        if (czynniki[i] != 0)
        {
            cout << czynniki[i] << endl;
        }
    }
}