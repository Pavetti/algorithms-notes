#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    bool sito[n] = {false};

    for (int i = 2; i * i <= n; i++)
    {
        if (!sito[i])
        {
            for (int k = i * i; k <= n; k += i)
                sito[k] = true;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (sito[i])
        {
            cout << i << " -> " << "false" << endl;
        }
        else
        {
            cout << i << " -> " << "true" << endl;
        }
    }
}