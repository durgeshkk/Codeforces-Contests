#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Q1
void solve1(){
    ll n;cin>>n;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){
        cin>>v[i];
        mp[v[i]] = i;
    }

    vector<ll> tmp(v);
    sort(tmp.begin(),tmp.end());
    ll ans = 0;
    for(ll i = 0;i<n;++i){
        if(tmp[i] == v[i]){
            continue;
        }else{
            ll idx = mp[tmp[i]];
            mp[v[i]] = idx;
            ++ans;
            swap(v[i],v[idx]);
        }
    }
    cout<<ans<<endl;
    return;
}

// Q2 : 
void solve2()
{
 
    ll n;
    cin>>n;
 
    vector<string> v;
    for(ll i=0;i<n;i++){
        string a,b;cin>>a>>b;
        if(a == "add"){
            v.push_back(b);
        }else{
            ll cnt = 0;
            for(ll j = 0;j<v.size();++j){
                string st = v[j];
                string s = st.substr(0,b.size());
                if(s == b){
                    ++cnt;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return;
}


int main()
{
   solve2();
//    solve1();
   return 0;
}

