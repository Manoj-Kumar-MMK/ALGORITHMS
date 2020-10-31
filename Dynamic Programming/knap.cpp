#include<iostream>
using namespace std;

int knap(int wts[],int prices[],int N,int W){
    if(N==0 || W==0){
        return 0;
    }
    int inc=0,exc=0;
    if(wts[N-1]<=W){
        inc=prices[N-1]+knap(wts,prices,N-1,W-wts[N-1]);
    }
    exc=knap(wts,prices,N-1,W);

    return max(inc,exc);
}

int top(int wts[],int prices[],int N,int W,int *dp){
    if(N==0 || W==0){
        dp[N]=0;
    }
    int inc=0,exc=0;
    if(wts[N-1]<=W){
        inc=prices[N-1]+knap(wts,prices,N-1,W-wts[N-1]);
    }
    exc=knap(wts,prices,N-1,W);

    dp[N]=max(inc,exc);
    return dp[N];
}

int bottom(int wts[],int prices[],int N,int W){
    int dp[N+1][W+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wts[i-1]<=j){
                dp[i][j]=max(prices[i-1]+dp[i-1][j-wts[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

int main(){
    int wts[]={2,7,3,4};
    int prices[]={5,20,20,10};
    int N=4;
    int W=11;

    cout<<"RECURSION:"<<knap(wts,prices,N,W)<<endl<<endl;

    cout<<"BOTTOM UP:"<<bottom(wts,prices,N,W)<<endl<<endl;
    
    int dp[100];
    
    cout<<"TOP DOWN:"<<top(wts,prices,N,W,dp)<<endl<<endl;
    return 0;
}