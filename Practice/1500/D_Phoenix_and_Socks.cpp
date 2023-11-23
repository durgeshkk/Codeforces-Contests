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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
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
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void solve()
{
 
    ll n;
    cin>>n;

    multiset<ll> ml,mr;
    // map<ll,ll> mpl,mpr;

    ll left,right;
    cin>>left>>right;

    map<ll,multiset<ll>> mp;
    for(ll i = 0;i<left;++i){
        ll x;
        cin>>x;
        ml.insert(x);
        // mp[x].insert(0);
    }
    
    for(ll i = 0;i<right;++i){
        ll x;
        cin>>x;
        if(ml.find(x) != ml.end()){
            ml.erase(ml.find(x));
        }
        else{
            mr.insert(x);
        }
        // cout<<x<<endl;
        // multiset<ll> &ms = mp[x];
        // if(ms.find(0) != ms.end()){
        //     // cout<<x<<" ";
        //     // cout<<"HI\n";
        //     ms.erase(ms.find(0));
        // }
        // else{
        //     mp[x].insert(1);
        // }
        // cout<<"---\n";
    }

    ll ans = 0;
    ll a = ml.size();
    ll b = mr.size();

    ll diff = (a-b);
    // cout<<diff<<endl;
    if(diff > 0){
        diff /= 2;
        map<ll,ll> mp;
        for(auto it:ml){
            mp[it]++;
        }

        ll val = 0;
        for(auto it:mp){
            val += (it.second/2);
        }

        if(val >= diff){
            ans = (b+diff);
            cout<<ans<<endl;
        }
        else{
            ll z = b+2*val;
            ll rem = (a-z);
            ans = (b+val+rem);
            cout<<ans<<endl;
        }
    }
    else if(diff == 0){
        cout<<a<<endl;
    }
    else{
        //  a = ml.size();
        //  b = mr.size();
        diff = (b-a);
        diff /= 2;

        map<ll,ll> mp;
        for(auto it:mr){
            mp[it]++;
        }

        ll val = 0;
        for(auto it:mp){
            val += (it.second/2);
        }

        if(val >= diff){
            ans = (a+diff);
            cout<<ans<<endl;
        }
        else{
            ll z = a+2*val;
            ll rem = (b-z);
            ans = (a+val+rem);
            cout<<ans<<endl;
        }

    }
    
// Sol 1:
/*
    vector<ll> l(left);
    enter(l);
    vector<ll> r(right);
    enter(r);

    // cout<<"hi\n";
    for(ll i=0;i<left;i++){
        // cout<<l[i]<<" ";
        ml.insert(l[i]);
        mpl[l[i]]++;
    }
    // cout<<endl;
    
    // cout<<"hir\n";
    cout<<right<<endl;
    for(ll i=0;i<right;i++){
        // cout<<r[i]<<" ";
        mr.insert(r[i]);
        mpr[r[i]]++;
    }
    // cout<<endl;
    cout<<"HI\n";

    for(auto it:ml){
        // cout<<"HI\n";
        // cout<<it<<" ";

        if(mr.find(it) != mr.end()){
            // cout<<"HI\n";
            ml.erase(it);
            mr.erase(it);
            mpl[it]--;
            mpr[it]--;

            if(mpl[it] == 0){
                mpl.erase(it);
            }
            
            if(mpr[it] == 0){
                mpr.erase(it);
            }
        }
    }
    
    // cout<<"@\n";
    // for(auto it:mpl){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    
    // cout<<"--->\n";

    // for(auto it:mpr){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    // cout<<"--MS->\n";

    // for(auto it:ml){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // for(auto it:mr){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<mr.size()<<" ";
    // cout<<ml.size()<<endl;

    ll sz = 0;
    ll f = 0;
    if(mr.size() > ml.size()){
        sz = (mr.size()-ml.size()); 
        f = 1;
    }
    else{
        sz = (ml.size()-mr.size()); 
        f = 2;
    }

    // cout<<f<<endl;
    // ll sz = (mr.size()-ml.size());
    cout<<sz<<endl;

    if(sz != 0){
        ll ans = 0;
        if(f == 1){
            
            ll req = sz/2;
            ll give = 0;
            ll ans = 0;
            for(auto it:mpr){
                // if(it.second%2){

                // }
                // else{
                    give += (it.second/2);
                // }
            }

            // cout<<"---\n";
            // cout<<req<<" "<<give<<endl;

            if(req <= give){
                // cout<<"HI\n";
                ans = req+ml.size();
                cout<<ans<<endl;
                return;
            }
            else{
                ll val = (2*give);
                ll z = mr.size()-val;
                ll ak = ((z-ml.size())/2);
                ans = give + (2*ak) + ml.size();
                cout<<ans<<endl;
                return;
            }
        }
        else{
            // sz = abs(sz);
            sz = (ml.size()-mr.size()); 
            ll req = sz/2;
            ll give = 0;
            for(auto it:mpl){
                // if(it.second%2){

                // }
                // else{
                    give += (it.second/2);
                // }
            }

            if(req <= give){
                ans = req+mr.size();
                cout<<ans<<endl;
                return;
            }
            else{
                ll val = (2*give);
                ll z = ml.size()-val;
                ll ak = ((z-mr.size())/2);
                ans = give + (2*ak) + mr.size();
                cout<<ans<<endl;
                return;
            }

        }
        // cout<<ans<<endl;
    }
    else{
        ll ans = ml.size();
        cout<<ans<<endl;
        return;
    }
*/

// Sol 2:
/*
    for(auto it:mp){
        cout<<it.first<<" --> ";
        multiset<ll> ms = it.second;
        for(auto dk:ms){
            cout<<dk<<" ";
        }
        cout<<endl;
    }

    ll ans = 0;
    ll ol = 0,ori = 0;
    for(auto it:mp){
        if(it.second.size()%2){
            if(it.second.find(0) != it.second.end()){
                ++ol;
            }
            else{
                ++ori;
            }   
        }
        // else{
            ans += (it.second.size()/2);
        // }
    }

    ans += ((ol+ori)/2);
    ans += (abs(ol-ori)/2);
    cout<<ans<<endl;
*/

    
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
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}


/*
            set<ll> s(ml.begin(),ml.end());

            while(s.size() != ml.size()){
                if(req == 0){
                    break;
                }

                for(auto it:mpr){
                    if(req == 0){
                        break;
                    }

                    if(it.second >= 2 && (it.second%2 == 0)){
                        ll give = (it.second/2);
                        if(req >= give){
                            req -= give;
                            mpr.erase(mpr.find(req));
                            // mr.erase(mr.find(req));
                        }
                        else{
                            mpr[it.first] -= (req*2);
                            req = 0;
                            // mr.erase(mr.find(req));

                        }
                    }
                }
            }

            if(req == 0){

            }*/
        