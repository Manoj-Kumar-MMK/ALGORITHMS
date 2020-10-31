#include<iostream>
#include<climits>
using namespace std;

int minjumps(int arr[],int n,int c,int dp[]){
    if(c==n-1)
        return dp[c]=0;
    for(int i=1;i<=arr[c];i++){
        if(c+i<n)
        dp[c]=min(dp[c],i+dp[c+i]);
        else
            break;
    }
    return dp[c];
}


int main(){
    int arr[]={2,3,1,1,2,4,2,0,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=INT_MAX;
    cout<<minjumps(arr,n,0,dp);
    return 0;
}