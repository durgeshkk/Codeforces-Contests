#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
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
 
// Recursion :
int rcr(int idx,vector<int> v,int n,int prev_idx){
    if(idx == n){
        return 0;
    }

    // Don't Take :
    int len1 = rcr(idx+1,v,n,prev_idx);

    // Take :
    int len2 = INT_FAST16_MIN;
    if(prev_idx == -1 || v[idx] > v[prev_idx]){
        len2 = 1+rcr(idx+1,v,n,idx);
    }

    return max(len1,len2);
}

// Memoization :
/*
We are using idx & prev_idx & there will be a lot of overlapping subprblms there
in between so we can use an array of size(idx : 0 --> (n-1)) 'n' to store the values
But with prev_idx :(-1 --> (n-1)) & 2d attay can't have idx as -1..
So we can do coordinate change:
-1 0 1 2 ......(n-1)
0  1 2 3 ...... (n)
So ,we do dp[idx][prev_idx+1] = len;
Thus, TC goes as : O(N*N)   SC = O(N*N)(array) + O(N)(rcr)
*/

// Tabulation/IDP :
int memoopt(vector<int> v,int n){
    // for 10^5 array can't be allocated so just use spcae optimization by
    // next(idx+1 is replaced) & curr(idx is replaced) vector
    // vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        vector<int> next(n+1,0);
        vector<int> cur(n+1,0);
        for(int idx = n-1;idx >= 0;--idx)    {
            for(int prev_idx = idx-1;prev_idx >= -1;prev_idx--){
                int len1 = next[1+prev_idx];

                // Take :
                if(prev_idx == -1 || v[idx] > v[prev_idx]){
                    len1 = max(len1,(1+next[1+idx]));
                }

                // int len = max(len1,len2);
                cur[prev_idx+1] = len1;
            }
            next = cur;
        }
    
//         int ans = recur(v,n);
        // return next[-1+1];// will be saem as below..
        return cur[-1+1];
}



int rcr(int idx,vector<int> v,int n,int prev_idx,vector<vector<int>> &dp){
    if(idx == n){
        return 0;
    }

    if(dp[idx][prev_idx+1] != -1){
        return dp[idx][prev_idx+1];
    }

    // Don't Take :
    int len1 = rcr(idx+1,v,n,prev_idx,dp);

    // Take :
    int len2 = INT_FAST16_MIN;
    if(prev_idx == -1 || v[idx] > v[prev_idx]){
        len2 = 1+rcr(idx+1,v,n,idx,dp);
    }

    int len = max(len1,len2);
    dp[idx][prev_idx+1] = len;
    return len;
}


int recur(vector<int> v,int n){
    
    // Memoization :
    int maxi = 1;
    vector<int> hash(n);//printing the LIS
    // Fetching the values idx wise
    int lst_idx = 0;
    vector<int> ak(n,1);

        for(int i = 0;i<n;++i){
            hash[i] = i;
            for(int j = i-1;j>=0;--j){
                // if(v[i] > v[j]){
                //     int dk = 1+ak[j];
                //     ak[i] = max(ak[i],dk);
                // }
                if((v[i] > v[j])  && (1+ak[j] > ak[i])){
                    ak[i] = 1+ak[j];
                    hash[i] = j;
                }
            }

            // maxi = max(maxi,ak[i]);
            if(ak[i] > maxi){
                lst_idx = i;
                maxi = ak[i];
            }
        }

        vector<int> temp;
        temp.push_back(v[lst_idx]);
        while(hash[lst_idx] != lst_idx){
            lst_idx = hash[lst_idx];
            temp.push_back(v[lst_idx]);
        }

        reverse(temp.begin(),temp.end());
        show(temp);
        
    // int ans = *max_element(ak.begin(),ak.end());
    return maxi;
}

void solve()
{
 
    int n;
    cin>>n;

    vector<int> v(n);
    enter(v);

    int ans = recur(v,n);
    cout<<ans<<endl;

    vector<vector<int>> dp(n,vector<int> (n+1,-1));

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