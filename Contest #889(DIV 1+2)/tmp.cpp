#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vll vector<long long int>
#define pll pair<long long int, long long int>
#define vvl vector<vll>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define nl "\n"
const ll mod = 1e9 + 7,inf = 1e18;//998244353
ll expo(ll x, ll y){ll res=1;x%=mod;while(y){if(y%2)res=(res*x%mod)%mod;x=(x*x)%mod;y/=2;}return res;}
ll inv(ll x) {return expo(x,mod-2);}
ll madd(ll a, ll b){a=a%mod;b=b%mod;return(((a + b) % mod)+mod)%mod;}
ll mmul(ll a, ll b){a=a%mod;b=b%mod;return(((a * b) % mod)+mod)%mod;}
ll msub(ll a, ll b){a=a%mod;b=b%mod;return(((a - b) % mod)+mod)%mod;}
ll mdiv(ll a, ll b){a=a%mod;b=b%mod;return(mmul(a, inv(b))+mod)%mod;}
ll gcd(ll a, ll b){if(b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return a/gcd(a,b) * b;}

void PerformOp(){

    ll n;cin >> n;

    vll v(n);
    for(auto &i : v)
        cin >> i;

    const ll N = 30;
    bitset<N> dp;
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        dp |= (dp >> i) << (i + v[i]);
        cout << dp << nl;
    }

    ll res = 0, sum = 0;
    for(ll i = 0; i < N; i++){
        if(i < n){
            sum += v[i];
        }
        if(dp[i]){
            res = max(res, sum - i);
        }
    }
    cout << res;
    
}

signed main(){
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        PerformOp();
        cout << nl;
    }
    return 0;
}