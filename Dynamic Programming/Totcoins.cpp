#include<iostream>
#include<climits>
using namespace std;
int dp[10];
 
int coinsnum(int coins[],int n,int amount){
    if(amount==0)
        return dp[amount]=0;
    for(int i=0;i<n && coins[i]<=amount;i++)
        dp[amount]+=1+coinsnum(coins,n-i,amount-coins[i]);
    return dp[amount];    
}

int totcoins(int coins[],int n,int amount){
    int dp[n+1][amount+1];
    for(int j=0;j<=amount;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(j==0)
                dp[i][j]=1;
            else if(j<coins[i-1])  
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
        }
    }
    return dp[n][amount];
}

int main(){
    int coins[]={1,2,3};
    int amount=5;
    for(int i=0;i<=9;i++)dp[i]=INT_MAX;
    cout<<coinsnum(coins,3,amount)<<endl; 
    cout<<totcoins(coins,3,amount);
    return 0;
}