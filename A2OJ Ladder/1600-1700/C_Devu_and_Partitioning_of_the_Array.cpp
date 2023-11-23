#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" ";
using namespace std;
ll mod = (ll)(1e9+7);

void yno(ll f){
    if(f & 1) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
  
void solve()
{
 
    ll n,k,p;cin>>n>>k>>p;
    vector<ll> v(n);enter(v);
    ll odd = (k-p);ll even = p;
    multiset<ll> o,e;
    ll odd_cnt = 0,e_cnt= 0;
    for(ll i=0;i<n;i++){
        if(v[i] & 1){
            ++odd_cnt;
        }else{
            ++e_cnt;
        }
    }

    if((odd > odd_cnt) || ((odd_cnt-odd)&1) || (k == 0)){
        yno(0);return;
    }

    ll ex = odd_cnt-odd;
    if(((ex/2)+e_cnt) < even){
        yno(0);return;
    }

    yno(1);
    if(odd == 0){
        for(ll i = 0;i<n;++i){
            if(v[i]%2 == 0){
                if(even > 1){
                    cout<<1<<" "<<v[i]<<endl;
                    --even;
                }else{
                    e.insert(v[i]);
                }
            }else{
                o.insert(v[i]);
            }
        }

        while(even > 1){
            ll f = *o.rbegin();
            o.erase(o.find(f));
            ll s = *o.rbegin();
            o.erase(o.find(s));
            cout<<2<<" "<<f<<" "<<s<<endl;
            --even;
        }
        ll sz = o.size()+e.size();
        cout<<sz<<" ";show(o);show(e);cout<<endl;
        return;
    }

    for(ll i=0;i<n;i++){
        if(v[i] & 1){
            if(odd > 1){
                cout<<1<<" "<<v[i]<<endl;
                --odd;
            }else{
                o.insert(v[i]);
            }
        }else{
            e.insert(v[i]);
        }
    }

    if(even == 0){
        ll sz = o.size()+e.size();
        cout<<sz<<" ";show(o);show(e);cout<<endl;
        return;
    }else{
        // Exhaust the odd
        ll f = *o.rbegin();
        o.erase(o.find(f));
        cout<<1<<" "<<f<<endl;
        e.clear();
    }

    for(ll i = 0;i<n;++i){
        if(v[i]%2 == 0){
            if(even > 1){
                cout<<1<<" "<<v[i]<<endl;
                --even;
            }else{
                e.insert(v[i]);
            }
        }
    }

    if(even <= e_cnt){
        
    }else{
        // No e_cnt left
        // Need to take help from odd;
        while(even > 1){
            ll f = *o.rbegin();
            o.erase(o.find(f));
            ll s = *o.rbegin();
            o.erase(o.find(s));
            cout<<2<<" "<<f<<" "<<s<<endl;
            --even;
        }
    }

    ll sz = o.size()+e.size();
    cout<<sz<<" ";show(o);show(e);cout<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}