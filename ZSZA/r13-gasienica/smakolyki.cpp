#include <iostream>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    bool smakolyki[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        smakolyki[i] = false;
    }

    int wynik = 0;
    int poc = 0;
    for (int kon = 0; kon < n; kon++)
    {
        while (poc < n && !smakolyki[a[poc]])
        {
            smakolyki[a[poc]] = true;
            poc++;
        }
        smakolyki[a[kon]] = false;
        wynik += (poc - kon);
    }
    cout << wynik;
}