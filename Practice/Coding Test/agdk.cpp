#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll ans = 0;
    ordered_set os;  
    for(int i = 0;i<n;++i){
        os.insert(v[i]);
    }
    
    ll ag = 0;
    for(ll i=0;i<n-3;i++){
        os.find(os.erase(v[i]));
        
        for(ll j=i+1;j<n-1;++j){
            os.find(os.erase(v[j]));
            if(v[i] > v[j] || ((j-i) == 1)){
                continue;
            }
            
            for(ll k = i+1;k<j;++k){
                os.insert(v[k]);
                ag += (os.order_of_key(v[k]));
                os.erase(os.find(v[k]));
            }
        }
        
        os.clear();
        for(ll j = i+1;j<n;++j){
            os.insert(v[j]);
        }
    }
    // cout<<"HI\n";
    cout<<ag<<endl;
    // cout<<"HI\n";
    return;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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
/*
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll ans = 0;
    ordered_set os;  
    for(int i = 0;i<n;++i){
        os.insert(v[i]);
    }
    
    ll ag = 0;
    for(ll i=0;i<n-3;i++){
        os.find(os.erase(v[i]));
        
        for(ll j=i+1;j<n-1;++j){
            os.find(os.erase(v[j]));
            if(v[i] > v[j] || ((j-i) == 1)){
                continue;
            }
            
            for(ll k = i+1;k<j;++k){
                os.insert(v[k]);
                ag += (os.order_of_key(v[k]));
                os.erase(os.find(v[k]));
            }
            // os.insert(v[j]);
        }
        
        os.clear();
        for(ll j = i+1;j<n;++j){
            os.insert(v[j]);
        }
    }
    // cout<<"HI\n";
    cout<<ag<<endl;
    // cout<<"HI\n";
    return;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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

*/