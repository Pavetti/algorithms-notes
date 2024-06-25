#include <iostream>

using namespace std;

int main()
{

    int n = 2;
    int c[n] = {1, 3};

    int k = 4;

    int dp[k + 1] = {0};

    for (int j = 1; j <= k; ++j)
    {
        dp[j] = INT_MAX - 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = c[i - 1]; j <= k; ++j)
        {
            dp[j] = min(dp[j - c[i - 1]] + 1, dp[j]);
        }
    }
    cout << dp[4];
}