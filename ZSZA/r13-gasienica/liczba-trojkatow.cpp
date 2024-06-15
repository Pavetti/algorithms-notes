#include <iostream>

using namespace std;

int main()
{

    int n = 12;
    int a[n] = {2, 4, 5, 7, 12, 15, 15, 29, 74, 146, 268, 532};

    int z, y, wynik;
    for (int x = 0; x < n; x++)
    {
        z = x + 2;
        for (int y = x + 1; y < n; y++)
        {
            while (z < n && (a[x] + a[y]) > a[z])
                z++;
            wynik += z - y - 1;
        }
    }
}