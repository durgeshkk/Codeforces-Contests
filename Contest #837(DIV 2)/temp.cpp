#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> v[100001];
void createsieve(){
    int sieve[100001];

    int ntlen = 100000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
        if(sieve[i] == 1){
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
                 v[j].push_back(i);
            }
        }
    }

    return;
}
 
void solve()
{

    ll n;
    cin>>n;

    for(ll i= 0;i<=n;++i){
        v[i].clear();
    }    

    vector<ll> tmp(n);
    enter(tmp);

    set<ll> st;    
    for(ll i = 0;i<n;++i){
        for(auto it:v[tmp[i]]){
            if(st.find(it) != st.end()){
                cout<<"YES\n";return;
            }
            st.insert(it);
        }
    }
    cout<<"NO"<<endl;
    // cout<<s.size()<<endl;
    // for(auto it:s){
    //     cout<<it<<" ";
    // }cout<<endl;
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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
   createsieve();
    // SieveOfEratosthenes(100000);
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   
   solve();
   return 0;
}