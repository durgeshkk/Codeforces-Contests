#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
// BFS :
const int n = 200010;
// vector<int> adj[n];
// vector<bool> vis(n);


bool bfs(vector<int> adj[], ll node){

    int colorArr[n + 1];
    for (int i = 0; i <= n; ++i)
        colorArr[i] = -1;
 
    colorArr[node] = 1;
 
    queue<int> q;
    q.push(node);
 
    while (!q.empty()){
 
        int u = q.front();
        vis[u] = true;
        q.pop();
 
        for (auto it : adj[u]){
            if (colorArr[it] == -1){
                colorArr[it] = (1 - colorArr[u]);
                q.push(it);
            }
            else if (colorArr[it] == colorArr[u]){
                return true;
            }
        }
    }
    return false;
}
*/
// DFS :
vector<int> adj[200005];
int vis[200005];

void dfs(int &x, int &d){
    vis[x] = 1;
    ++d;

    for(auto it:adj[x]){
        if(!vis[it]){
            dfs(it,d);
        }
    }
}

void tree(ll u,ll v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> mp(n+1,0);
    ll flag = 0;

    for(ll i=1;i<=n;i++){
        vis[i] = 0;
        adj[i].clear();
        // vis[i] = false;

        ll u,v;
        cin>>u>>v;
        mp[u]++;
        mp[v]++;
        if(u == v || mp[u]>2 || mp[v]>2){
            flag = 1;
        }
        tree(u,v);
    }

    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            int c = 0;
            dfs(i,c);

            if(c%2 != 0){
                flag = 1;
                break;
            }
        }
    }
    
    if(flag == 1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}

/*
        ll a,b;
        cin>>a>>b;

        if(a > b){
            swap(a,b);
        }

        if(a == b){
            z = 1;
        }

        ms.insert({a,b});
        mp[a]++;
        mp[b]++;
    }

    for(auto it:mp){
        if(it.second >= 3){
            z = 1;
            break;
        }
    }
 
    if(z & 1){
        cout<<"NO\n";
        return;
    }

    
    set<ll> f,l;
    for(auto it:ms){
        ll flag = 0;
        pair<ll,ll> p = it;
        ll ag = p.first;
        ll dk = p.second;
        ll ak = 0;

        if((f.find(ag) == f.end()) && (f.find(dk) == f.end())){
            f.insert(ag);
            f.insert(dk);
            ak = 1;
        }

        if((l.find(ag) == l.end()) && (l.find(dk) == l.end()) && (ak == 0)){
            l.insert(ag);
            l.insert(dk);
            ak = 1;
        }

        // else {
        //     flag = 1;
        // }
        
        if((f.find(ag) == f.end())){
            f.insert(ag);
            if((f.find(dk) == f.end())){
                f.insert(dk);
                ak = 1;
            }
            else{
                f.erase(f.find(ag));
                flag = 1;
            }
        }

        if((l.find(ag) == l.end()) && (ak == 0)){
            l.insert(ag);
            if((l.find(dk) == l.end())){
                l.insert(dk);
            }
            else{
                flag = 1;
            }
        }
        else{
            flag = 1;
        }

        if(ak == 0){
            cout<<"NO\n";
            return;
        }
    }
    */
/*
    for(ll i=1;i<=n;++i){
        if(f.find(i) == f.end()){
            z = 1;
            break;
        }
    }

    for(ll i=1;i<=n;++i){
        if(l.find(i) == l.end()){
            z = 1;
            break;
        }
    }

    if(z & 1){
        cout<<"NO\n";
        return;
    }
*/
/*
    for(auto it:adj){
        // cout<<adj[it]<<" --> ";
        for(auto z:it){
            cout<<z<<" ";
        }
        cout<<endl;
    }
*/
