// O(n)
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int poc = 0;
    int kon = pow(2, k - 1) - 1;
    int sr;
    n--;
    for (int i = 0; i < k - 1; ++i)
    {
        sr = (poc + kon) / 2;
        if (n % 2 == 0)
            kon = sr;
        else
            poc = sr + 1;
        n /= 2;
    }
    cout << poc;
}
