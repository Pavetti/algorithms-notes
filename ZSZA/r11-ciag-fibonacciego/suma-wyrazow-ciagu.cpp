#include <iostream>

using namespace std;

int main()
{

    int x;
    const int n = 31;
    cin >> x;
    int m = 1000000;
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    bool wyniki[m + 1] = {false};
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (fib[i] + fib[j] <= m)
            {
                wyniki[fib[i] + fib[j]] = true;
            }
        }
    }
    cout << wyniki[x];
}