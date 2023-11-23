#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long size;
    cin>>size;

    long long k;
    cin>>k;

    vector<long long>a;//all max ele
    vector<long long>b;//all max ele
    vector<pair<long long,long long>>v;//all max ele

    for(long long i=0;i<size;i++){
        long long ele;
        cin>>ele;
        a.push_back(ele);
    }

    for(long long i=0;i<size;i++){
        long long ele;
        cin>>ele;
        b.push_back(ele);
    }

    for(long long i=0;i<size;i++){
        long long l1 = a[i] ;
        long long l2 = b[i] ;
        v.push_back(make_pair(l1,l2));
    }

    sort(v.begin(),v.end());

    for(long long i=0;i<size;i++){
        if(v[i].first > k){
            cout<<k<<endl;
            return;
        }
        else{
            k += v[i].second;
        }
    }
    cout<<k<<endl;

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