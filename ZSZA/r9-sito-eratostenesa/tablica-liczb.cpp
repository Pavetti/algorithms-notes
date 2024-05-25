#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > k)
            k = a[i];
    }

    int ile[k + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        ile[a[i]]++;
    }

    int dzielniki[k + 1] = {0};
    int wynik[n];

    for (int i = 1; i <= k; i++)
    {
        if (ile[i])
        {
            for (int j = i; j <= k; j += i)
            {
                dzielniki[j] += ile[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        wynik[i] = n - dzielniki[a[i]];
        cout << wynik[i] << " ";
    }
}

//  for(int i = 0; i < n ; i++)