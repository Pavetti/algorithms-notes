#include <iostream>

using namespace std;
int nwd(int a, int b);

int main()
{

    int z, n, d;
    cin >> z;
    int results[z];
    for (int i = 0; i < z; i++)
    {
        cin >> n >> d;

        if (n % d == 0)
            results[i] = n / d;
        else
            results[i] = n / nwd(n, d);
    }
    for (int i = 0; i < z; i++)
    {
        cout << results[i] << " ";
    }
}

int nwd(int a, int b)
{
    if (a % b == 0)
        return b;
    return nwd(b, a % b);
}