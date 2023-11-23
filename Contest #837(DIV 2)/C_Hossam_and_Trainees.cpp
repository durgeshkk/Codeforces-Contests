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
 
multiset<ll> s;
bool flag = 0; 
void primeFactors(ll n) 
{ 
    // Print the number of 2s that divide n 
    ll f = 0;
    while(n%2 == 0){
        f = 1;
        n = n/2; 
    } 

    if(f & 1){
        if(s.find(2) != s.end()){
            flag = 1;
        }
        s.insert(2); 
    }
     
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (ll i = 3; i*i <= (n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        ll ak = 0;
        while (n%i == 0) { 
            ak = 1;
            n = n/i; 
        } 

        if(ak & 1){
            if(s.find(i) != s.end()){
                flag = 1;
            }
            s.insert(i); 
        }
    } 
     
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) {
        if(s.find(n) != s.end()){
            flag = 1;
        }
        s.insert(n);
        // printf ("%d ", n); 
    }
} 

#define MAXN (int)100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i){
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<ll,ll> mp;
void getFactorization(ll x)
{
    set<ll> ret;
    while (x != 1){
        ret.insert(spf[x]);
        // ret.push_back(spf[x]);
        x = x / spf[x];
    }

    for(auto it:ret){
        cout<<it<<" ";
        mp[it]++;
    }
}
 

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
    

    s.clear();
    mp.clear();
    flag = 0;
    for(ll i=0;i<n;i++){
        getFactorization(v[i]);
    }
 
    for(auto it:mp){
        if(it.second >= 2){flag = 1;}
    }

    if(flag & 1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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
   sieve();
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