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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void alice_bob(ll f){
   if(f & 1) cout<<"Alice\n";
   else cout<<"Bob\n";
   return;
}
  
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> v1 = sieve(1e5);
ll printDivisors(ll n)
{
    ll em = LLONG_MAX,om = LLONG_MAX;
    ll eM =LLONG_MIN,oM =LLONG_MIN;
    for(auto i:v1){
        if (n%i == 0){
            if ((n/i) == i){
                if(i & 1){
                    if(om == LLONG_MAX){om = i;}
                    oM=max(oM,i);
                }else{
                    if(em == LLONG_MAX){em = i;}
                    eM=max(i,eM);
                }
            }else {
                if(i & 1){
                    if(om == LLONG_MAX){om = i;}
                    oM=max(oM,i);
                }else{
                    if(em == LLONG_MAX){em = i;}
                    eM=max(i,eM);
                }

                if((n/i) & 1){
                    if(om == LLONG_MAX){om = n/i;}
                    oM=max(n/i,eM);
                }else{
                    if(em == LLONG_MAX){em = n/i;}
                    eM=max(n/i,eM);
                }
            }
        }
    }

    if(n & 1){
        if(eM == LLONG_MIN){
            return om;
        }
        return eM;
    }else{
        if(oM == LLONG_MIN){
            return em;
        }
        return oM;
    }
}

void solve()
{
 
    ll n;cin>>n;
    // Obs : 
    // At all odd no. 'B' wins
    // At all even no., if any odd divisor exists then 'A' wins else 'B' wins!! 
    if(n & 1){alice_bob(0);return;}
    ll f = 1;
    ll a = 1,cnt = 0;
    while(a < n){
        a *= 2;
        cnt ^= 1;
    }    
    if(a == n){
        if(cnt & 1){
            f = 0;
        }
    }
    alice_bob(f);
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