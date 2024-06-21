#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int sum[n];

    cin >> x;
    sum[0] = x;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    int s = sum[n - 1] / n;

    int wynik = 0;
    for (int i = 0; i < n; ++i)
    {
        if (sum[i - 1] < (i)*s)
            wynik++;
        if (sum[n - 1] - sum[i] < (n - 1 - i) * s)
            wynik++;
    }

    cout << wynik;
}