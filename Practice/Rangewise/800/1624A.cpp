#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long size;
    cin>>size;

    vector<long long>v1;//all max ele

    for(long long i=0;i<size;i++){
        long long ele;
        cin>>ele;
        v1.push_back(ele);
    }

    sort(v1.begin(),v1.end());
    cout<<(v1[v1.size()-1] - v1[0])<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;

    while(t != 0){
        solve();
        t--;
    }

    return 0;
}