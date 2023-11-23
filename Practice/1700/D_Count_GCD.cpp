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
 
vector<ll> printDivisors(ll n)
{
    vector<ll> v;

    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                v.push_back(i);
                // cout <<" "<< i;
  
            else // Otherwise print both
                v.push_back(i);
                v.push_back(n/i);
                // cout << " "<< i << " " << n/i;
        }
    }
    return v;
}

void solve()
{
 
    ll n,m;cin>>n>>m;
    vector<ll> v(n);enter(v);
    
    ll f = 1,gcd = v[0];
    ll lst = 1,idx = -1;
    set<ll> s(v.begin(),v.end());
    for(ll i=1;i<n;i++){
        if(v[i]%v[i-1]){
            f = 0;
        }
    }
    
    if(f == 0){cout<<0<<endl;return;}
    /*
        To get the ans we need,
        a[i] must be multiple of a[i-1] and also
        smaller..

        So, gcd(a[i-1],x) = a[i]
        Thus, a[i-1] = g*a[i]
        And, x = f*a[i]
        ==> gcd(g,f) = 1 !!!
    */



    // Find multiples of v[0]..
    vector<ll> tmp = printDivisors(v[0]);
    sort(tmp.begin(),tmp.end());

    // Remove the largest multiple at the last!!


    // Then select (m-k)Ck
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
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