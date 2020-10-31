#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minc(int coins[], int n, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        dp[amount] = 0;
        return dp[amount];
    }

    for (int i = 0; i < n; i++)
    {
        if (amount - coins[i] >= 0)
        {
            dp[amount] = min(minc(coins, n, amount - coins[i], dp)+1, dp[amount]);
        }
    }
    return dp[amount];
}

int bottom(int coins[],int n,int amount,vector<int> & dp){
    dp[0]=0;
    int tr;
    for(int a=1;a<=amount;a++){

        for(int i=0;i<n;i++){
            if(coins[i]<=a)
                dp[a]=min(dp[a],dp[a-coins[i]]+1);
        }
    
    }

    return dp[amount];
}

int table(int coins[],int n,int amount){
    int dp[50][50];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if( i==0 && j==0)
                dp[i][j]=INT_MAX;
            if(i==0 && j>0)
                dp[i][j]=0;
            else if(j>coins[i-1])
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            else
                dp[i][j]=dp[i-1][j];            
        }
    }
    return dp[n][amount];
}

int main()
{
    int coins[] = {1, 7, 10};
    int n = 3;
    int amount;
    cin >> amount;
    vector<int> dp(amount + 1, INT_MAX);
    for(int i=0;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    cout << "TOP DOWN:"<<minc(coins, n, amount, dp)<<endl;
    for(int i=0;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    cout<<"BOTTOM UP:"<<bottom(coins,n,amount,dp)<<endl;

    cout<<"TABLE:"<<table(coins,n,amount);

    return 0;
}