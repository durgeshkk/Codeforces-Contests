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

void printDivisors(ll n,vector<ll> &v){
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            // If divisors are equal, print only one
            if (n/i == i){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            } // Otherwise print both
        }
    }
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    printDivisors(n,v);
    // show(v);
    ll a=-1,b=-1;
    for(ll i=0;i<v.size();i++){
        if(v[i] >= 5){
            ll val = (n/v[i]);
            if(val >= 5){
                a = v[i];b = val;
            }
        }
    }
    // cout<<a<<" "<<b<<endl;
    if(a == -1){cout<< -1 <<endl;}
    else{
        if(a > b){swap(a,b);}
        char arr[a][b];
        string s = "aeiou";
        ll k = 0;
        for(ll i = 0;i<a;++i){
            for(ll j = 0;j<b;++j){
                arr[i][j] = s[(k+(j%5))%5];
            }
            --k;
            if(k < 0){k = 4;}
        }

        for(ll i = 0;i<a;++i){
            for(ll j = 0;j<b;++j){
                cout<<arr[i][j];
            }
        }cout<<endl;
    }
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