#include<iostream>
#include<algorithm>
using namespace std;

int mincoins(int coins[],int n,int amount){
    sort(coins,coins+n,greater<int>());

    int ct=0;

    for(int i=0;i<n;i++){
        while(amount-coins[i]>=0){
            amount-=coins[i];
            ct++;
        }
    }
    return ct;
}

int main(){
    int coins[]={ 1, 2, 5, 10, 20,50,100, 500, 1000 };
    int n=sizeof(coins)/sizeof(coins[0]);
    int amount;
    cin>>amount;

    cout<<mincoins(coins,n,amount);

    return 0;
}