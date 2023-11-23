#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
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
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
vector<ll> adj[100004];

void solverb(){
	ll n;cin>>n;
    vector<ll> v(n);enter(v);
    ll k;cin>>k;
    ll mn = *min_element(v.begin(),v.end());
    ll mx = *max_element(v.begin(),v.end());
    ll ans = ceil(1.0*(mx-mn-k)/(k*2));
    cout<<ans<<endl;
	return;
}

void solvea()
{
 
    ll n;cin>>n;
    string a,b;cin>>a>>b;
    ll cst;cin>>cst;

    vector<ll> pref(n+1,0);
    for(ll i=0;i<n;i++){
        // ll f = mod_sub((a[i]-'a'),(b[i]-'a'),26);
        // ll s = mod_sub((b[i]-'a'),(a[i]-'a'),26);
        ll s = abs((b[i]-'a')-(a[i]-'a'));
        pref[i+1] = min(90*1ll,s);
    }

    for(ll i=1;i<=n;i++){
        pref[i] += pref[i-1];
    }

    ll ans = 0;
    for(ll i=0;i<=n;i++){
        ll x = pref[i]+cst;
        // cout<<x<<" ";
        ll idx = upper_bound(pref.begin(),pref.end(),x)-pref.begin();
        --idx;
        // cout<<idx<<" "<<idx-i<<endl;
        ans = max(ans,idx-i);
    }
    cout<<ans<<endl;
    // show(pref);
    return;
}
 
map<ll,ll> mp;
// C++ code to print all possible
// subsequences for given array using
// recursion
#include <bits/stdc++.h>
using namespace std;



void printSubsequences(vector<ll> arr, ll index,vector<ll> &subarr,ll n,ll p){
	if (index == n){
        ll sm = 0;
		for (auto it:subarr){
            sm *= 10;// 
            sm += it;
		}

        if(mp.find(sm) == mp.end()){mp[sm] = p;}
        else{mp[sm] = min(p,mp[sm]);}
        return;
	}
	else{
		subarr.push_back(arr[index]);
		printSubsequences(arr, index + 1, subarr,n,p);
		subarr.pop_back();
		printSubsequences(arr, index + 1, subarr,n,p);
	}
}

void solve(){
    ll q;cin>>q;
    map<char,ll> ch;
    ch['#'] = 1;ch['@'] = 2;ch['&'] = 3;ch['%'] = 4;ch['$'] = 5;
    
    vector<ll> tmp = {1,2,3,4,5};
    vector<ll> z;
    printSubsequences(tmp, 0, z,5,LLONG_MAX);

    for(ll i = 0;i<q;++i){
        string s;cin>>s;ll p;cin>>p;
        sort(s.begin(),s.end());
        
        vector<ll> arr;
        for(ll j = 0;j<s.size();++j){
            arr.push_back(ch[s[j]]);
        }

        sort(arr.begin(),arr.end());
        vector<ll> subarr;
        printSubsequences(arr, 0, subarr,s.size(),p);
    }



    ll ans = LLONG_MAX;
    // string ak = "12345";
    // res = partition(ak);

    // for(auto it:res){
    //     auto ag = it;
    //     ll sm = 0;
    //     for(auto x:ag){
    //         ll t = stoll(x);
    //         sm += mp[t];
    //     }
    //     ans = min(ans,sm);
    // }
    // if(ans == LLONG_MAX){ans = -1;}
    // cout<<ans<<endl;
    // return;

    for(auto it:mp){
        if(it.second == LLONG_MAX){
            cout<<"-1\n";return;
        }
    }

    // 1
    ans = min(ans,mp[1]+mp[2]+mp[3]+mp[4]+mp[5]);

    // 2
    ans = min(ans,mp[12]+mp[3]+mp[4]+mp[5]);
    ans = min(ans,mp[13]+mp[2]+mp[4]+mp[5]);
    ans = min(ans,mp[14]+mp[2]+mp[3]+mp[5]);
    ans = min(ans,mp[15]+mp[2]+mp[3]+mp[4]);
    ans = min(ans,mp[23]+mp[1]+mp[4]+mp[5]);
    ans = min(ans,mp[24]+mp[1]+mp[3]+mp[5]);
    ans = min(ans,mp[25]+mp[1]+mp[3]+mp[4]);
    ans = min(ans,mp[34]+mp[1]+mp[2]+mp[5]);
    ans = min(ans,mp[35]+mp[1]+mp[2]+mp[4]);
    ans = min(ans,mp[45]+mp[1]+mp[2]+mp[3]);

    ans = min(ans,mp[12]+mp[34]+mp[5]);
    ans = min(ans,mp[12]+mp[35]+mp[4]);
    ans = min(ans,mp[12]+mp[45]+mp[3]);
    ans = min(ans,mp[13]+mp[24]+mp[5]);
    ans = min(ans,mp[13]+mp[25]+mp[4]);
    ans = min(ans,mp[13]+mp[45]+mp[2]);
    ans = min(ans,mp[14]+mp[23]+mp[5]);
    ans = min(ans,mp[14]+mp[35]+mp[2]);
    ans = min(ans,mp[14]+mp[25]+mp[3]);
    ans = min(ans,mp[15]+mp[23]+mp[4]);
    ans = min(ans,mp[15]+mp[24]+mp[3]);
    ans = min(ans,mp[15]+mp[34]+mp[2]);
    ans = min(ans,mp[23]+mp[14]+mp[5]);
    ans = min(ans,mp[23]+mp[15]+mp[4]);
    ans = min(ans,mp[23]+mp[45]+mp[1]);
    ans = min(ans,mp[24]+mp[13]+mp[5]);
    ans = min(ans,mp[24]+mp[15]+mp[3]);
    ans = min(ans,mp[24]+mp[35]+mp[1]);
    ans = min(ans,mp[25]+mp[13]+mp[4]);
    ans = min(ans,mp[25]+mp[14]+mp[3]);
    ans = min(ans,mp[25]+mp[34]+mp[1]);
    ans = min(ans,mp[34]+mp[12]+mp[5]);
    ans = min(ans,mp[34]+mp[15]+mp[2]);
    ans = min(ans,mp[34]+mp[25]+mp[1]);
    ans = min(ans,mp[35]+mp[12]+mp[4]);
    ans = min(ans,mp[35]+mp[14]+mp[2]);
    ans = min(ans,mp[35]+mp[24]+mp[1]);
    ans = min(ans,mp[45]+mp[12]+mp[3]);
    ans = min(ans,mp[45]+mp[13]+mp[2]);
    ans = min(ans,mp[45]+mp[23]+mp[1]);

    // 3
    ans = min(ans,mp[123]+mp[4]+mp[5]);
    ans = min(ans,mp[124]+mp[3]+mp[5]);
    ans = min(ans,mp[125]+mp[3]+mp[4]);
    ans = min(ans,mp[134]+mp[2]+mp[5]);
    ans = min(ans,mp[135]+mp[2]+mp[4]);
    ans = min(ans,mp[145]+mp[2]+mp[3]);
    ans = min(ans,mp[123]+mp[45]);
    ans = min(ans,mp[124]+mp[35]);
    ans = min(ans,mp[125]+mp[34]);
    ans = min(ans,mp[134]+mp[25]);
    ans = min(ans,mp[135]+mp[24]);
    ans = min(ans,mp[145]+mp[23]);

    ans = min(ans,mp[234]+mp[1]+mp[5]);
    ans = min(ans,mp[235]+mp[1]+mp[4]);
    ans = min(ans,mp[245]+mp[1]+mp[3]);
    ans = min(ans,mp[234]+mp[15]);
    ans = min(ans,mp[235]+mp[14]);
    ans = min(ans,mp[245]+mp[13]);

    ans = min(ans,mp[345]+mp[1]+mp[2]);
    ans = min(ans,mp[345]+mp[12]);

    //  4
    ans = min(ans,mp[1234]+mp[5]);
    ans = min(ans,mp[1235]+mp[4]);
    ans = min(ans,mp[1245]+mp[3]);
    ans = min(ans,mp[1345]+mp[2]);
    ans = min(ans,mp[2345]+mp[1]);

    // 5
    ans = min(ans,mp[12345]);

    if(ans == LLONG_MAX){ans = -1;}


    cout<<ans<<endl;return;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precochutefact();
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