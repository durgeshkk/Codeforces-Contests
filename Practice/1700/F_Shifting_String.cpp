/*
      Author : ME
*/
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

ll gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

vector<ll> v,vis;
string s;
map<char,ll> mp;
string tmp;
ll cycle(ll i){
    mp[s[i-1]]++;
    tmp += s[i-1];
    vis[i] = 1;

    if(!vis[v[i]]){
        return 1+cycle(v[i]);
    }else{
        return 1;
    }
}

vector<ll> factors(int n)
{
    vector<ll> t;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i){
                t.push_back(i);
            }else{
                t.push_back(i);
                t.push_back(n/i);
            } // Otherwise print both
        }
    }
    return t;
}

void solve()
{
 
    ll n;cin>>n;
    cin>>s;
    v.assign(n+1,0);vis.assign(n+1,0);
    for(ll i = 1;i<=n;++i){
        cin>>v[i];
    }
 
    // Mostly in this type of Q's we need to think
    // abt dfs cycle returning max. cycle len!!

    // But here there are many cycles pssbl so we need to take LCM of all cycles len,
    // as after this particular LCM all will return the initial string!!
    ll ans = 1;
    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            mp.clear();tmp.clear();
            ll len = cycle(i);
            // Check if char are repeating themselves after sometime,like ababab,etc.
            // Check if after a particular factors of len it returns the same..
            // e.g. 6(abcabc) repeats after len 3!!
            // Find factors of 6
            auto t = factors(len);
            sort(t.begin(),t.end());

            for(auto it:t){
                ll flag = 1;
                if(it == len){continue;}
                for(ll j = 0;j<it;++j){
                    char ch = tmp[j];
                    for(ll k = j;k<tmp.size();k += it){
                        if(ch != tmp[k]){flag = 0;break;}
                    }
                }
                if(flag & 1){
                    len = it;break;
                }
            }
            ans = lcm(ans,len);
        }
    }
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
   //precomputefact();
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