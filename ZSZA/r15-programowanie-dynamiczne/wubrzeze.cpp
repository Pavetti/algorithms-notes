#include <iostream>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    int m[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }
    int dp[k + 1][n];
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j < n; ++j)
        {
            if (m[j] >= 0)
            {
                dp[i][m[j]] = min(dp[i][m[j]], dp[i - 1][j] + 1);
            }
        }
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    cout << dp[k][n - 1];
}