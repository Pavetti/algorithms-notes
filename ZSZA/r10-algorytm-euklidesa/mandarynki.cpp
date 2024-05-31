#include <iostream>

using namespace std;

int nwd(int a, int b);

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << n * 2;
    }
    else
    {
        cout << n * (n - 1) + 1;
    }
}

int nwd(int a, int b)
{
    if (a % b == 0)
        return b;
    return nwd(b, a % b);
}