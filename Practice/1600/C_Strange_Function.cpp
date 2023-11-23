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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

void solve()
{
 
    ll n;cin>>n;
    ll even = n/2, odd = n-even;

    // For odd num's :
    ll sm = mod_mul(odd,2,mod);
    
    // For Even num's :
    ll cnt_5 = n/12;
    ll cnt_4 = ((n/6)-cnt_5);
    ll cnt_3 = even-cnt_4-cnt_5;
    
    ll a = mod_mul(cnt_3,3,mod);
    ll b = mod_mul(cnt_4,4,mod);
    ll c = mod_mul(cnt_5,5,mod);

    ll val = mod_add(a,b,mod);
    val = mod_add(val,c,mod);
    sm = mod_add(sm,val,mod);

    ll z = 60;
    ll i = 5;
    while(z <= n){
        // z *= i;
        ll cnt = n/z;
        if(cnt == 0){//cout<<z<<" "<<i<<"\n";
        break;}

        ll j = i+1;
        while(z%j == 0){
            ++j;
        }
        if(z <= j){//cout<<"HI\n";
        break;}

        ll dff = (j-i);
        val = mod_mul(cnt,dff,mod);
        sm = mod_add(sm,val,mod);
        i = j;
        ll g = __gcd(i,z);
        if(g == 1){z *= i;}
        else{ll val = i/g;z*=val;}
    }
    cout<<sm<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}