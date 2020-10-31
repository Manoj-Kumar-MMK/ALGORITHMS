#include <iostream>
#include <climits>
using namespace std;
int dpt[50];

int rodcut(int price[], int n)
{
    if (n <= 0)
        return dpt[0] = 0;
    for (int i = 0; i < n; i++)
        dpt[n] = max(dpt[n], price[i] + rodcut(price, n - i - 1));
    return dpt[n];
}

int bottom(int price[], int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0;j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (i > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(price[i - 1] + dp[i - 1][j - i], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    for (int i = 0; i <= 9; i++)
        dpt[i] = INT_MIN;
    cout << rodcut(price, 8) << endl;
    cout << bottom(price, 8);
    return 0;
}