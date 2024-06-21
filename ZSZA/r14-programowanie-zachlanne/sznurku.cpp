#include <iostream>

using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    int a;
    int suma = 0;
    int wynik = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (suma + a >= w)
        {
            wynik++;
            suma = 0;
        }
        else
            suma += a;
    }

    cout << wynik;
}