#include<iostream>
using namespace std;

bool subset(int set[],int n,int sum,bool dpt[]){
    if(sum==0)
        return dpt[n]=true;
    if(n==0)
        return dpt[n]=false;

    if(set[n-1]>sum){
        return dpt[n]=subset(set,n-1,sum,dpt);   //exc
    }
    return dpt[n]=subset(set,n-1,sum,dpt) || subset(set,n-1,sum-set[n-1],dpt);
}

bool bottom(int set[],int n,int sum){
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0)
                dp[i][j]=true;
            else if(i==0 && j!=0)
                dp[i][j]=false;
            else if(set[i-1]>sum)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-set[i-1]];            
        }
    }
    return dp[n][sum];
}
int main(){
    int set[] = {3, 34, 4, 12, 5, 2};
    bool dpt[100];
for(int i=0;i<100;i++)dpt[i]=false;
    if(subset(set,6,9,dpt)){
        cout<<"Possible"<<endl;
    }
    if(bottom(set,6,9)){
        cout<<"Possible";
    }
    return 0;
}