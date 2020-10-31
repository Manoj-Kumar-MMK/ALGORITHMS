#include <iostream>
#include <string.h>
using namespace std;

int LCS(char a[], char b[], int m, int n, int dp[])
{
    if (n == 0 || m == 0)
        return dp[0] = 0;
    if (a[m - 1] == b[n - 1])
        return dp[n] = 1 + LCS(a, b, m - 1, n - 1, dp);
    else
        return dp[n] = max(LCS(a, b, m - 1, n, dp), LCS(a, b, m, n - 1, dp));
}

int bottom(char a[], char b[], int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
    char arr1[] = "AGGTAB";
    char arr2[] = "GXTXAYB";
    int dp[20];
    for (int i = 0; i < 20; i++)
        dp[i] = 0;
    cout << LCS(arr1, arr2, strlen(arr1), strlen(arr2), dp) << endl;
    cout<<bottom(arr1,arr2,strlen(arr1),strlen(arr2));
    return 0;
}