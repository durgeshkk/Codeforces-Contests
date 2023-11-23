/*
      Author : ME
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n,0);
    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){
        cin>>v[i];
        mp[v[i]]++;
    }

    ll mx = 0;
    vector<ll> tmp(v);
    sort(tmp.begin(),tmp.end());
    for(ll i = 0;i<n;++i){
        if(tmp[i] == mx){++mx;}
    }

    if(mx == n){
        cout<<"NO\n";
        return;
    }

    if(mx == 0 || mp[mx+1] == 1  || mp[mx+1] == 0){
        cout<<"YES\n";
        return;
    }

    if(mp.find(mx+1) == mp.end()){
        ll flag = 0;
        for(auto it:mp){
            if(it.second >= 2 || it.first > mx){flag = 1;}
        }

        if(!flag){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    else{
        ll first = -1,second = -1;
        for(ll i = 0;i<n;++i){
            if(v[i] == (mx+1)){
                if(first == -1){
                    first = i;
                }
                else{
                }
                if(second == -1){
                    second = i;
                }
                else{
                    second = i;
                }
            }
        }

        for(ll i = first;i<=second;++i){
            v[i] = mx;
        }

        sort(v.begin(),v.end());
        ll dk = 0;
        for(ll i = 0;i<n;i++){
            if(v[i] == dk){
                dk++;
            }
        }

        if(dk != (mx+1)){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}