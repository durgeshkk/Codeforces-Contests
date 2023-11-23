/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
/*
Create Relation between given array{child} and sorted array{par}

Obs :
1. Swapping par & child removes par

Assume making of m cycles : m1,m2,m3....,mm
2. Agar koi bhi 1 cycle mein 2 consecutive elements aa gye then ans is :
--> no. of all ele in cycles - 2
    In case 1,2,4,6 forming cycle, we need to remove 4,6 only as 1,2 will then 
    be each other's par & child !!! So no need for more swaps,
    And more over for 1 inversion we need only 1 cycle consisting of 2 consecutive 
    ele!!

    else : 
    In case 1,3,5,7 and 2,4,6 forming 2 different cycles so 1 more swap to merge 
    this 2 cycles!!
--> no. of all ele in cycles + 1
*/
 
vector<ll> vis;
map<ll,ll> mp;
ll f,cntr;

ll dfs(set<ll> &s,ll par){
    ll len = 0,flag = 0;
    while(1){
        if(vis[par]){break;}
        vis[par] = 1;
        s.insert(par);
        par = mp[par];
        ++len;
    }

    for(auto it:s){
        if(s.find(it+1) != s.end()){
            flag = 1;break;
        }
    }

    if(flag & 1){
        ++cntr;
        if(cntr == 1){
            f = 1;
            return len-2;
        }else{
            return len-1;
        }
    }else{
        return len-1;
    }
}

void solve()
{
    vis.clear();mp.clear();f = 0;cntr = 0;
    ll n;cin>>n;
    
    vector<ll> v(n);enter(v);
    vector<ll> tmp(n);for(ll i=0;i<n;i++){tmp[i] = i+1;}

    // show(v);
    // show(tmp);

    for(ll i=0;i<n;i++){mp[tmp[i]] = v[i];}
    vis.assign(n+1,0);

    ll len = 0;
    for(ll i = 1;i<=n;++i){
        if(mp[i] == i){vis[i] = 1;}

        if(!vis[i]){
            // Call DFS
            set<ll> s;
            len += dfs(s,i);
        }
    }

    ll ans = len;
    // cout<<ans<<endl;

    if(f & 1){
        // ans -= 2;
    }else{
        ans += 1;
    }

    cout<<ans<<endl;
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