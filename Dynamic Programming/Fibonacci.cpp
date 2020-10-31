#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>& a){
    if(n==0 || n==1){
        a[n]=n;
        return a[n];
    }

    if(a[n]!=-1){
        return a[n];
    }
    else
    {
        a[n]=fib(n-1,a)+fib(n-2,a);
        return a[n];
    }    
}

int bottom(int n,vector<int>& a){
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1,-1);
    cout<<"TOP DOWN:"<<fib(n,a)<<endl;
    cout<<"BOTTUM UP:"<<bottom(n,a)<<endl;
    return 0;
}