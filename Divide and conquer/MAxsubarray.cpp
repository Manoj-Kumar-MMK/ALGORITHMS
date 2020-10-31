#include<iostream>
#include<climits>
using namespace std;

int max(int a,int b,int c){return max(max(a,b),c);}

int maxoverlap(int a[],int p,int mid,int q){
    int s=0,l=INT_MIN,r=INT_MIN;
    for(int i=mid;i>=p;i--){
        s+=a[i];
        if(s>l)
            l=s;
    }
    s=0;
    for(int i=mid+1;i<=q;i++){
        s+=a[i];
        if(s>r)
            r=s;
    }
    return max(l,r,l+r);
}

int maxsub(int a[],int p,int q){
    if(p==q)
        return a[p];
    
    int mid=(p+q)/2;
    maxsub(a,p,mid);
    maxsub(a,mid+1,q);
    return maxoverlap(a,p,mid,q);
}

int main(){
    int a[]={2,3,4,5,7};
    int n=5;
    cout<<maxsub(a,0,n-1);
    return 0;
}