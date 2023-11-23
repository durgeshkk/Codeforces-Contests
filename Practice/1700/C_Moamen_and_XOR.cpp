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

/*
===> Case 1:
AND = 0 ==> XOR = 0; when all bits count are even in the array

===> Case 2:
AND = k ==> XOR <= k; 
--> Subcase 1;XOR < k 
        ==> toh k se chotte xor's ka cnt kuch bhi chalenga whether odd or even 
        doesn't matter but k se badhe ke liye we need there bits cnt as even only...

--> Subcase 2;XOR = k 
        ==> get all bits cnt as even, except at the place of k get them as odd 

k is [0,2e5] and a[i] = [0,2^k] = [0,2^(2e5)]        
    Which means we need an array of 2e5 representing the bits

[0,3] all bits set cnt are even & adding [4,7] to it willalso make all bits
cnt as even.


Correct Thinking :
&       ^       result
0 0     0 0     & = ^ = 0
0 1     0 1
1 0     1 0
1 1     1 1     & = 1 and ^ = 0

AND > XOR
Maintain an array of k
arr1 : 1 0 0 0 0 ....
arr2 : 0 0 0 0 0 ....
abb aage koi bhi num's daalo np.
arr1 > arr2 at 1st position & we need rest all bits same, i.e. pssbility = (2^n)^(k-1)

AND = XOR
Agar equal h then everything depends on n:
If n is even then we can put same bits & can get and = xor,i.e. adding pairs of 
1,1 or adding complete 1's
In case of adding complete 1's we will reach the same case of 2^n since, we have
and = 1 & xor = 0
but if n is odd then we need :and > xor at any pt, so if n is odd we can't add the 
pssbl ans to ans instead we need topass it on to next value as we are not confirm 
yet..
*/

ll power(ll base,ll n,ll mod){
    ll ans = 1;
    while( n!= 0){
    if(n%2){
        n-=1;
        ans = (ans*base)%mod;
    }
    else{
        n /= 2;
        base = (base*base)%mod;
    }
    }
    return ans;
}

ll fact[1000005];
ll powfact[1000005];
void precomputefact(){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=1000005;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

/*
Refer Tutorials for clear explaination
*/
ll even,pwr;
vector<vector<ll>> dp;
ll recur(ll bit,ll f,ll n){
    if(bit < 0){return 1;}
    ll &ans = dp[bit][f];
    if(ans != -1){return ans;}

    if(f & 1){
        // Our job is done, so aage ke koi bhi combo chalenge
        ans = pwr;
        ans = mod_mul(ans,recur(bit-1,1,n),mod);
    }else{
        // Abb tak equal h bc
        if(n & 1){
            // +1 for 2nd case when all of nextbits are 1
            // even denotes no. of indices to make 1 nxt
            ans = mod_mul(recur(bit-1,f,n),mod_add(even,1,mod),mod);
        }else{
            // Make this bit 1 in all idx's
            ll sa = recur(bit-1,1,n);
            // Make all other even bits in pair as 1 
            ans = mod_add(sa,mod_mul(recur(bit-1,f,n),even,mod),mod);
        }
    }
    return ans;
}

void solve()
{
 
    ll n;cin>>n;
    ll k;cin>>k;
    dp.assign(k+5,vector<ll> (2,-1));
    even = 0;
    if(k == 0){cout<<1<<endl;return;}

    // Calculate pssbility of even no.'s
    for(ll i = 0;i<n;i+=2){
        even = mod_add(even,nCr(n,i),mod);
    }

    pwr = power(2,n,mod);
    ll ans = recur(k-1,0,n);
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
   precomputefact();
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