#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

ll printDivisors(ll n,ll a)
{
    ll i;
    for (i = 2; i * i < n; i++) {
        if (n % i == 0){
            ll val = (n/i);
            if((val%a) != 0){
                return val;
            }
        }
            // cout<<i<<" ";
    }
    return 0;
/*
    if (i - (n / i) == 1) {
        i--;
    }
    
    for (; i >= 1; i--) {
        if (n % i == 0)
            v.push_back(n/i);
            // cout<<n / i<<" ";
    }
    */
}

vector<ll> primeFactors(ll n)
{
    // Print the number of 2s that divide n
    vector<ll> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n / 2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans.push_back(i);
            n = n / i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans.push_back(n);
 
    return ans;
}

void seive(vector<ll> &v,ll n){
    v.push_back(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) {
            v.push_back(i);
            if(i!=n/i){
                v.push_back(n/i);
            }
        }
    }
} 
 

void solve()
{
 
    ll p,q;
    cin>>p>>q;

    ll z = __gcd(p,q);
    if(z != q){
        cout<<p<<endl;
        return;
    }

    vector<ll>v;
    seive(v,q);
    ll ans=1;
    for(auto i:v){
        ll tt=p;
        while(tt%i==0){
            tt=tt/i;
            if(tt%q!=0){
                ans=max(ans,tt);
                break;
            }
        }
    }
    cout<<ans<<endl;
/*
    for(ll i=0;i<v.size();i++){
        ll val = (v[i]%q);
        if(val == 0){
            continue;
        }
        else{
            cout<<v[i]<<endl;
            return;
        }
    }
 */
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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
    //    cout<<"Case #"<<i<<": ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}