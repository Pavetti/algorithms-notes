// rozwiązanie O(n*k)
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ilos = 2;
    for (int i = 1; i < k; ++i)
    {
        ilos *= 2;
    }
    bool w[ilos];

    for (int i = 2; i < ilos; ++i)
    {
        if (i % 2 == 0)
            w[i] = true;
        else
            w[i] = false;
    }
    int wynik;
    int j = 1;
    int poziom = 1;
    for (int i = 0; i < n; ++i)
    {

        while (poziom < k)
        {
            w[j * 2] = !w[j * 2];
            w[(j * 2) + 1] = !w[(j * 2) + 1];
            if (w[j * 2])
            {
                wynik = j * 2 + 1;
                j = j * 2 + 1;
            }
            else
            {
                wynik = (j * 2);
                j = j * 2;
            }
            poziom++;
        }
        poziom = 1;
        j = 1;
    }
    wynik = wynik - ilos / 2;
    cout << wynik;
}
