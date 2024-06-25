#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    int dj[n];

    dj[0] = p[0];
    for (int i = 1; i < n; ++i)
    {
        dj[i] = INT_MIN;
        for (int j = 1; j <= 6; ++j)
        {
            if (i - j >= 0)
            {
                dj[i] = max(dj[i], dj[i - j]);
            }
        }
        dj[i] += p[i];
    }
    cout << dj[n - 1];
}