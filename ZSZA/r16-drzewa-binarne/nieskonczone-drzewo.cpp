#include <iostream>

using namespace std;

int main()
{

    int a, b;
    cin >> a >> b;

    int wynik = 0;
    while (a != b)
    {
        if (a > b)
            a /= 2;
        else
            b /= 2;
        wynik++;
    }

    cout << wynik << endl;
    cout << a;
}