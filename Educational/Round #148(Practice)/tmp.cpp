#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}


const ll MAXN = 105;
const ll MAXDIGITSUM = 85;

ll A, B, K, ans = 0;
bool is_prime[MAXDIGITSUM];
vector<ll> primes;
ll digits[MAXN];
ll dp[MAXN][MAXDIGITSUM][2];

ll digit_sum(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < MAXDIGITSUM; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j < MAXDIGITSUM; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll solve(ll idx, ll digit_sum, ll f) {
    if (idx == -1) {
        return is_prime[digit_sum];
    }

    if (dp[idx][digit_sum][f] != -1 && !f) {
        return dp[idx][digit_sum][f];
    }

    ll res = 0;
    ll limit = f ? digits[idx] : 9;
    for (ll i = 0; i <= limit; i++) {
        ll new_digit_sum = digit_sum + i;
        if (is_prime[new_digit_sum]) {
            ll sa = solve(idx - 1, new_digit_sum, f && i == limit);  
            res = mod_add(res,sa,mod);
        }
    }

    if (!f) {
        dp[idx][digit_sum][f] = res;
    }
    return res;
}

ll count_numbers(ll n) {
    ll len = 0;
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return solve(len - 1, 0, true);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> K;
    sieve();

    for (ll i = ((A - 1)/ K + 1) * K; i <= B; i += K) {
        if ((i % K == 0) && (is_prime[digit_sum(i)])){
            ans += count_numbers(i);
        }
    }

    cout << ans << endl;

    return 0;
}
