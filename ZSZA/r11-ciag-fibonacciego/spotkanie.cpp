#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    n %= 60;
    if (n == 0)
    {
        n = 60;
    }

    int fib[61];
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 2; i <= 60; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }

    int wynik = (2 * fib[n - 2] + fib[n - 1]) % 10;
    cout << wynik;
}