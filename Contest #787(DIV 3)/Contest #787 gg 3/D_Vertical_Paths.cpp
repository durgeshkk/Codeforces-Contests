#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
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

vector<vector<ll>> ans;
vector<vector<ll>> adj;
vector<ll> vec;

void dfs(ll curr_node){
    bool done = false;

    for(auto x:adj[curr_node]){
        if(!done){
            vec.push_back(x);
            dfs(x);
            done = true;
        }
        else{
            vec = {x};
            dfs(x);
        }

        // For Leaf Nodes 
        if(sizeof(adj[curr_node])==0){
            ans.push_back(vec);
        }
    }
}

void solve()
{
    ll temp=0,sum=0;

    ll n;
    cin>>n;
    
    ll root = -1;
    adj.assign(n+1,{});
    ans.clear();
    vec.clear();

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x == i){
            root = i;
        }
        else{
            adj[x].push_back(i);
        }
    }

    vec = {root};
    dfs(root);
    cout<<sizeof(ans)<<endl;

    for(auto x:ans){
        cout<<sizeof(x)<<endl;

        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}