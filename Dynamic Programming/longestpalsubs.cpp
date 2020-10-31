#include<iostream>
using namespace std;

int lps(string a){
    int n=a.length();
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(i==j)
                dp[i][j]=1;
            else 
                dp[i][j]=0;
        }
    }
        for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(a[i]==a[j])
                dp[i][j]=2+dp[i+1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j];
        cout<<endl;
    }
    return dp[0][n-1];
}

int main(){
    string a="agbdba";
    cout<<lps(a);
    return 0;
}