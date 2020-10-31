#include<iostream>
#include<vector>
using namespace std;

int ways(int n,vector<int>& a){
    if(n<0)
        return 0;
    if(n==0)
    {
        a[n]=1;
        return a[n];
    }
    if(a[n]!=-1){
        return a[n];
    }
    else
    {
        a[n]=ways(n-1,a)+ways(n-2,a)+ways(n-3,a);
        return a[n];
    }
}

int bottom(int n,vector<int>& a){
    a[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=0;
        for(int j=1;j<=3;j++){
            if(i-j>=0)
            a[i]+=a[i-j];
        }
    }
    return a[n];
}

int main(){  // max 3 steps
    int n;
    cin>>n;
    vector<int> a(n+1,-1);
    cout<<"TOP DOWN:"<<ways(n,a)<<endl;
    cout<<"BOTTOM UP:"<<bottom(n,a);
    return 0;
}