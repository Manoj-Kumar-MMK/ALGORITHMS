#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

bool comp(pair<string,pair<int,int> > a,pair<string,pair<int,int> > b){
    return a.second.second>b.second.second;
}

int maxdead(vector<pair<string, pair<int, int> > > a){
    int max=INT_MIN;
    for(auto it=a.begin();it!=a.end();it++){
        if(it->second.first>max)
            max=it->second.first;
    }
    return max;
}

void seq(vector<pair<string, pair<int, int> > > a){
    sort(a.begin(),a.end(),comp);
    int n=maxdead(a);
    vector<bool> period(n,false);
    vector<pair<string,pair<int, int> > > b;
    for(auto it=a.begin();it!=a.end();it++){  // peroid(n) denotes n to n-1 
        int j=min(n,it->second.first)-1;
        for(;j>=0;j--){
            if(!period[j]){
                period[j]=true;
                b.push_back(*it);
                break;
            }
        }
    }
    int profit=0;
    for(auto it=b.begin();it!=b.end();it++){
        cout<<it->first<<"\t"<<it->second.first<<"\t"<<it->second.second<<endl;
        profit+=it->second.second;
    }
    cout<<"PROFIT:"<<profit;
}

int main()
{
    vector<pair<string, pair<int, int> > > a = {  {"a",{2, 100} } , {"b",{1, 19} }, {"c",{2, 27} }, {"d",{1, 25} }, {"e",{3, 15} } };
    int n=sizeof(a)/sizeof(a[0]);
    seq(a);
    return 0;
}