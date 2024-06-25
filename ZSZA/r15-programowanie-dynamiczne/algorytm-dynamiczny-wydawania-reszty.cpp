#include <iostream>

using namespace std;

int main()
{

    int n = 2;
    int c[n] = {1, 3};

    int k = 4;

    int dp[n + 1][k + 1] = {0};

    for (int j = 1; j <= k; j++)
        dp[0][j] = INT_MAX - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < c[i - 1]; j++)
            dp[i][j] = dp[i - 1][j];

        for (int j = c[i - 1]; j <= k; j++)
            dp[i][j] = min(
                dp[i][j - c[i - 1]] + 1,
                dp[i - 1][j]);
    }
}