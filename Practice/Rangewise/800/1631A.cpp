#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long size;
    cin>>size;

    vector<long long>v1;//all max ele
    vector<long long>v2;//all min ele

    for(long long i=0;i<size;i++){
        long long ele;
        cin>>ele;
        v1.push_back(ele);
    }

    for(long long i=0;i<size;i++){
        long long ele;
        cin>>ele;
        v2.push_back(ele);
    }

    long long i=0;
    while(i<size){
        if(v1[i] >= v2[i]){

        }
        else{
            swap(v1[i],v2[i]);
        }
        i++;
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    long long ans = (v1[v1.size()-1]) * (v2[v2.size()-1]);
    cout<<ans<<endl;
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