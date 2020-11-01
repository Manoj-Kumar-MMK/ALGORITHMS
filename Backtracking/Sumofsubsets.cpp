#include<iostream>
using namespace std;

void print(int sub[],int n){
    for (int i = 0; i < n;i++)
        cout << sub[i] << " ";
    cout << "\n";
}

void subset(int a[],int sub[],int n,int sn,int sum,int x,int t){
    if(sum==t){
        print(sub, sn);
        subset(a, sub, n, sn -1,sum-a[x], x + 1, t);
    }
    else{
    for (int i = x; i < n;i++){
            sub[sn] = a[i];
            subset(a, sub, n, sn + 1,sum+a[i], i + 1, t);
    }
    }
}


int main(){
    int n,t;
    cout << "Enter the number of elements:";
    cin >> n;
    int a[n],sub[n];
    cout << "Enter the elements";
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    cout << "enter the targert value:";
    cin >> t;
    subset(a, sub, n, 0, 0, 0, t);
    return 0;
}