#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll findlcm(vector<ll> arr, ll n){
    // Initialize result
    ll ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (__gcd(arr[i], ans)));
 
    return ans;
}
void solve()
{
 
    ll n;cin>>n;ll x;cin>>x;
    vector<ll> v(n);
    enter(v);
    
    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){if(v[i] >= x){continue;}mp[v[i]]++;}

    ll dk = 0;
    for(auto &it:mp){
        ll f = it.first;
        ll val = it.second;
        ll cnt = (val)/(f+1);
        ll ak = (val%(f+1));
        if((cnt >= 1) and (ak == 0)){mp[f+1] += cnt;}
        else{dk = 1;break;}
    }

    if(mp.size() == 0){cout<<"Yes\n";return;}

    if(mp.find(x) == mp.end()){cout<<"No\n";}
    else{cout<<"Yes\n";}
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
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}
/*
    for(ll i=0;i<n;i++){mp[v[i]]++;}
    set<ll> s(v.begin(),v.end());
    vector<ll> ms(s.begin(),s.end());
    vector<ll> l,num;
    for(ll i = 0;i<ms.size();++i){
        ll nm = 1,dn = 1;
        if(x > ms[i]){
            for(ll j = x;j>ms[i];--j){dn*=j;}
            nm *= mp[ms[i]];
            ll val = __gcd(nm,dn);
            nm /= val;
            dn /= val;
        }else{
            // nm *= mp[ms[i]];
            // for(ll j = ms[i];j>x;--j){nm*=j;}
        }
        num.push_back(nm);
        l.push_back(dn);
    }
    ll lcm = findlcm(l,l.size());
    for(ll i = 0;i<num.size();++i){
        ll val = lcm/l[i];
        val *= num[i];
        num[i] = val;
    }

    ll ans = 0;
    for(ll i = 0;i<num.size();++i){
        ans += num[i];
    }

    if(ans%lcm){cout<<"No\n";}else{cout<<"Yes\n";}*/
    