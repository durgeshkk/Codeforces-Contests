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
 

void solve()
{
 
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll val = (a*b);
    map<ll,ll> mp1,mp2;
    set<ll> v1,v2;

    for(ll i = a+1;i<=c;++i){
        ll x = __gcd((i),(val));
        v1.insert(x);
        mp1[x] = i;
    }

    for(ll j = b+1;j<=d;++j){
        ll x = __gcd((j),(val));
        v2.insert(x);
        mp2[x] = j;
    }

    vector<ll> ag(v1.begin(),v1.end());
    vector<ll> ak(v2.begin(),v2.end());

    for(ll i = 0;i<ag.size();++i){
        for(ll j = 0;j<ak.size();++j){
            ll dk = ak[j]*ag[i];
            if((dk%val) == 0){
                ll x = mp1[ag[i]];
                ll y = mp2[ak[j]];
                cout<<x<<" "<<y<<endl;
                return;
            }
        }   
    }
    cout<< -1 <<" "<< -1 <<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
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