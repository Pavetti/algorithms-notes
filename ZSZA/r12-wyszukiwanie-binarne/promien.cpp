#include <iostream>

using namespace std;

bool sprawdz(int pref[], int w, int r, int t);
int n;
int main()
{
    cin >> n;
    int a[n];
    int w[n];
    int pref[n];
    int wynik[n];

    for (int i = 0; i < n; i++)
        wynik[i] = -1;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    int poc = 0;
    int kon = n - 1;
    int sr;

    for (int i = 0; i < n; i++)
    {
        while (poc <= kon)
        {
            sr = (poc + kon) / 2;

            if (sprawdz(pref, w[i], sr, i))
            {
                kon = sr - 1;
                wynik[i] = sr;
            }
            else
                poc = sr + 1;
        }
        poc = 0;
        kon = n - 1;
    }

    for (int i = 0; i < n; i++)
        cout << wynik[i] << " ";
}

bool sprawdz(int *pref, int w, int r, int t)
{
    int sum;

    const int a = max(0, t - r);
    const int b = min(n - 1, t + r);

    if (a == 0)
        sum = pref[b];
    else
        sum = pref[b] - pref[a - 1];

    return sum >= w;
}