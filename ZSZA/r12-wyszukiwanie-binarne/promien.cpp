#include <iostream>

using namespace std;

// bool sprawdz(int pref[], int w, int r, int t);
int main()
{
    int n;
    cin >> n;
    int a[n];
    int w[n];
    int pref[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    int poc = 0;
    int kon = n - 1;
    int sr, p, q, h;
    int wynik[n];
    for (int i = 0; i < n; i++)
    {
        wynik[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        while (poc <= kon)
        {
            sr = (poc + kon) / 2;
            p = max(0, i - sr);
            q = min(n - 1, i + sr);
            if (p == 0)
                h = pref[q];
            else
                h = pref[q] - pref[p - 1];
            if (h >= w[i])
            {
                kon = sr - 1;
                wynik[i] = sr;
            }
            else
            {
                poc = sr + 1;
            }
        }
        poc = 0;
        kon = n - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << wynik[i] << " ";
    }
}
//
// bool sprawdz(int pref[], int w, int r, int t)
// {
//     int a = max(0, t - r);
//     int b = min(n, t + r);
//     return (pref[b] - pref[a - 1]) >= w;
// }