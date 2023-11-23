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

bool checkCycle(int src, vector<bool> &vis, vector<bool> &memo, vector<int> adj[]) {
    memo[src] = true;
    vis[src] = true;

    for (int i : adj[src]) {
        if (memo[i] != true) {
        }else{
            return 1;
        }

        if (!vis[i]) {
            if (checkCycle(i, vis, memo, adj)) {
                return true;
            }
        }
    }

    memo[src] = false;
    return false;
}

int dfs(int src, vector<int> &freq, string &s, vector<int> adj[]) {
    freq[s[src - 1] - 'a']++;
    int maxValue = freq[s[src - 1] - 'a'];

    for (int i : adj[src]) {
        maxValue = max(maxValue, dfs(i, freq, s, adj));
    }

    freq[s[src - 1]-'a']--;
    return maxValue;
}
 
int beauty(int n,int m,string s,int x[],int y[]) {
    int ans = 0;
    vector<int> adj[n + 1];
    for(ll i = 0;i<m;++i){
        adj[x[i]].push_back(y[i]);
    }
    
    // Takes log(n) use array takes O(1)
    map<int,int> mp;
    for(int i = 0;i<n;++i){
        mp[s[i]-'0']++;
    }

    vector<bool> vis(n + 1, 0), memo(n + 1, 0);
    vector<int> freq(26, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i] and checkCycle(i, vis, memo, adj)) {
            return -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(freq.begin(), freq.end(), 0);
        ans = max(ans, dfs(i, freq, s, adj));
    }
    return ans;
}

void solve()
{
 
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int x[m];
    int y[m];
    for(int i = 0;i<m;++i){
        cin>>x[i];
    }
    for(int i = 0;i<m;++i){
        cin>>y[i];
    }
    
    int ans = beauty(n,m,s,x,y);
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}