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
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}
 
/*
Obs :
1. If even & odd both >= 2 nt pssbl, since if x is odd/even GCD will always be 2
1.1 Also if no. r same then ans = NO, since gcd(v[i]+x,v[i]+x) = v[i]+x;

// 2 & 3 x is always pssbl!!
2. If all even : x can only be odd
3. If all Odd : x can only be even

// Main prblm is here!!
4. (n-1)even + 1 odd;
5. (n-1)odd + 1 even;

2,4,8,9,12
__gcd() != 1
(2,4) = 2k      (2,8) = 2k and (1+6k)    (2,9) = 5+7k       (2,12) = 3+10k and 2k
(4,8) = 2k      (4,9) = 1+5k       (4,12) = 2k 
(8,9) = -       (8,12) = 2k 
(9,12) = 3k 

v[i]' = k1*p    v[j]' != k2*p
If v[i]' is multiple of p then v[j]' can't be multiple of p
So for any prime p, it should have only 1 multiple
Atmost one idx i,s.t. v[i]' % p = 0

Fail :  Generate freq table for every prime p
Find some k s.t. , 0<= k<= (p-1)
freq[k-1] <= 1
& if it's nt pssbl to generate 
*/

bool prime[1000001];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (ll p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            for (ll i = p*p; i <= 1e6; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    ll odd = 0,even = 0;
    for(ll i=0;i<n;i++){
        if(v[i] & 1){++odd;}
        else{++even;}
    }
 
    ll f = 1;
    if(odd >= 2 and even >= 2){
        yno(0);return;
    }else{
        for(ll i = 0;i<n;++i){
            for(ll j = i+1;j<n;++j){
                if(v[i] == v[j]){yno(0);return;}
            }
        }

        for(ll i = 2;i<=n;++i){
            map<ll,ll> freq;
            if(prime[i]){
                for(ll j:v){
                    freq[j%i]++;
                }

                // Chinese Remainder Theorem
                ll mn = LLONG_MAX;
                for(auto it:freq){
                    mn = min(mn,it.second);
                    // if(it.second >= 2){++mn;}
                }
                if(mn >= 2){
                    yno(0);return;
                }
            }
        }
        yno(1);
        // Will result in TLE if ele >= 1e9;
        /*
        // for(ll x = 1;x<100;x++){
        //     // if((__gcd(8+x,12+x) != 1) and x&1){
        //     if((__gcd(8+x,12+x) != 1)){
        //         cout<<x<<endl;
        //     }
        // }

        ll ele = 0;
        for(ll i = 0;i<n;++i){
            for(ll j = i+1;j<n;++j){
                ll x;
                for(x = 0;x<v[i]*v[j];++x){
                    if(__gcd(v[i]+x,v[j]+x) != 1){break;}
                }
                ele = max(ele,x+abs(v[j]-v[i]));
                cout<<v[i]<<" "<<v[j]<<" "<<x+abs(v[j]-v[i])<<endl;
            }
        }
        cout<<ele<<endl;
        // Run x till mx
        set<ll> s;for(ll i = 1;i<=ele;++i){s.insert(i);}

        for(ll i = 0;i<n;++i){
            for(ll j = i+1;j<n;++j){
                ll x;
                for(x = 0;x<v[i]*v[j];++x){
                    if(__gcd(v[i]+x,v[j]+x) != 1){break;}
                }

                while(x <= ele){
                    if(s.find(x) != s.end()){s.erase(s.find(x));}
                    x += abs(v[j]-v[i]);
                }
            }
        }

        if(s.size()){yno(1);}
        else{yno(0);}*/
        
    }

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
    SieveOfEratosthenes();
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