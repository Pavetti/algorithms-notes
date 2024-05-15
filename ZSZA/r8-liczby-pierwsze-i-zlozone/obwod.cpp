#include <iostream>

using namespace std;

int main()
{
    int p;
    cin >> p;

    int wynik = 2 * (p + 1);
    for (int i = 2; i * i < p; i++)
    {

        if (p % i == 0)
        {
            wynik = min(wynik, i * 2 + p / i * 2);
        }
    }
    cout << wynik;
}