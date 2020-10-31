#include<iostream>
using namespace std;

int bottom(int coins[],int n,int amount){
    int dp[100][100];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(j==0 || i==0){
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j];  // exclude
                if(coins[i]<=amount){
                    dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        }
    }
    return dp[n+1][amount+1];
}
int main(){
    int n=4;
    int coins[]={1,5,10,20};
    int amount;
    cin>>amount;
    cout<<bottom(coins,n,amount)<<endl;
    return 0;
}