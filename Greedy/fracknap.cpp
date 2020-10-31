#include<iostream>
#include<algorithm>
using namespace std;

typedef struct item{
    int profit;
    int weight;
}item;

bool comp(item a,item b){
    return (double)a.profit/a.weight > (double)b.profit/b.weight;
}

double fracknap(int W,item a[],int n){
    sort(a,a+n,comp);
    double w,p;
    w=p=0;
    for(int i=0;i<n;i++){
        if(w+a[i].weight<W){
            w+=a[i].weight;
            p+=a[i].profit;
        }
        else
        {
            p+=(a[i].profit/a[i].weight)*(W-w);
            break;
        }
    }
    return p;
}

int main(){
    int W=50;
    item a[]={{60,10},{100,20},{120,30}};

    cout<<fracknap(W,a,3);
    return 0;
}