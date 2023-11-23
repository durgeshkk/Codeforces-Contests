#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

ll helper(vector<ll> v,ll n,ll p){
    if(p & 1){
    }else{
        for(ll i = 0;i<n;++i){
            v[i] += 1;
        }
    }
    
    // show(v);

    ll itr = LLONG_MAX;
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            if(__gcd(v[i],v[j]) != 1){
                itr = min(itr,__gcd(v[i],v[j])*2);
            }
        }
    }

    if(itr == LLONG_MAX){return true;}
    // cout<<itr<<endl;
    for(ll x = 1;x<itr;x++){
        if((v[0]+x) & 1){

        }else{continue;}

        vector<ll> tmp(v);
        for(auto &it:tmp){
            it += x;
        }
        // show(tmp);
        ll f = 1;
        for(ll i = 0;i<tmp.size();++i){
            for(ll j = i+1;j<tmp.size();++j){
                if(__gcd(tmp[i],tmp[j]) != 1){
                    f = 0;
                    // cout<<i<<" "<<j<<" ";
                    // cout<<(x+__gcd(tmp[i],tmp[j])*2)<<"\n";
                    itr = min(itr,x+__gcd(tmp[i],tmp[j])*2);
                }
            }
        }
        // cout<<itr<<endl;
        if(f & 1){
            return true;
        }
    }
    return false;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //1. 2 odd ele + 2 even ele it's nvr pssbl
    //2. Freq of ele mustn't be 2

    map<ll,ll> mp;
    ll odd = 0,even = 0;
    ll f = 1;
    for(ll i=0;i<n;i++){
        if(v[i] & 1){++odd;}
        else{++even;}
        if(v[i] == 1e18){f = 0;break;}
        mp[v[i]]++;
    }

    if(odd >= 2 and even >= 2){
        f = 0;
    }

    for(auto it:mp){
        if(it.second>=2){
            f = 0;break;
        }
    }

    ll p = 0;
    vector<ll> tmp;
    if(odd > even){p = 1;
        for(ll i = 0;i<n;++i){
            if(v[i] & 1){tmp.push_back(v[i]);}
        }
    }else{
        for(ll i = 0;i<n;++i){
            if(v[i]%2 == 0){tmp.push_back(v[i]);}
        }
    }

    sort(tmp.begin(),tmp.end());
    bool help = helper(tmp,tmp.size(),p);
    if(!help){f = 0;}

    yno(f);
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