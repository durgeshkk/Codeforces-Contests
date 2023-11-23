#include<bits/stdc++.h>
#include<iomanip>
#include <bitset>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<pair<ll,ll>> a(n+1),b(n+1);
    vector<ll> a_org(n+1);
    vector<ll> b_org(n+1);

    for(ll i = 1;i<=n;++i){
        cin>>a[i].first;
        a[i].second = (i);
        a_org[i] = a[i].first;
    }
    
    for(ll i = 1;i<=n;++i){
        cin>>b[i].first;
        b[i].second = (i);
        b_org[i] = b[i].first;
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<bool> ans(n+1,0);
    ans[a[n].second]=true;
    ans[b[n].second]=true;
    ll i = n-1,j = n-1;
    ll mna = a_org[b[n].second];
    ll mnb = b_org[a[n].second];

    while (i > 0 and j > 0){
        
		while (i > 0 and ans[a[i].second]){
			i--;
		}
		if (i == 0 or j == 0)break;
		ll cnt = 0;
		if (a[i].first > mna){
			cnt++;
			mnb = min(mnb, b_org[a[i].second]);
			ans[a[i].second] = true;
			i--;
		}

		while (j > 0 and ans[b[j].second]){
			j--;
		}
		if (i == 0 or j == 0)break;
		if (b[j].first > mnb){
			cnt++;
			mna = min(mna, a_org[b[j].second]);
			ans[b[j].second] = true;
			j--;
		}

        // No more winner pssbl
		if (cnt == 0)break;
	}

    for(ll i= 1;i<=n;++i){
        cout<<ans[i];
    }cout<<endl;
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

/*
// TLE Solution on TC 4: 
vector<ll> adj[100004];
vector<ll> adj2[100004];
vector<ll> vis;
vector<ll> ans; 

void dfs(ll i,queue<ll> &q){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){   
            q.push(it);
            dfs(it,q);
        }
    }
    return;
}

void dfs2(ll i,queue<ll> &q){
    vis[i] = 1;
    for(auto it:adj2[i]){
        if(!vis[it]){   
            q.push(it);
            dfs2(it,q);
        }
    }
    return;
}

void bfs(ll n,ll f,ll ele){

    queue<ll> q;
    q.push(ele);

    while(!q.empty()){
        ll tmp = q.front();
        ans[tmp] = 1;
        q.pop();

        if(f == 0){
            // Yane ele 1st map se ayya h
            // toh DFS in adj2
            // Call dfs
            dfs2(tmp,q);
        }else{
            // Yane ele 2nd map se ayya h
            // toh DFS in adj
            // Call dfs
            dfs(tmp,q);
        }
        f ^= 1;
    }
}

void solve()
{
 
    ll n;cin>>n;
    for(ll i = 1;i<=n;++i){
        adj[i].clear();
        adj2[i].clear();
    }

    vis.assign(n+1,0);
    ans.assign(n+1,0);

    vector<pair<ll,ll>> a(n),b(n);
    
    for(ll i = 0;i<n;++i){
        cin>>a[i].first;
        a[i].second = (i+1);
    }
    
    for(ll i = 0;i<n;++i){
        cin>>b[i].first;
        b[i].second = (i+1);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // for(auto it:b){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }cout<<endl;
    // reverse(a.begin(),a.end());
    // reverse(b.begin(),b.end());

    for(ll i = 0;i<n-1;++i){
        adj[a[i].second].push_back(a[i+1].second);
    }
    
    for(ll i = 0;i<n-1;++i){
        adj2[b[i].second].push_back(b[i+1].second);
    }

    ll ele = a[n-1].second; 
    bfs(n,0,a[n-1].second);

    vis.assign(n+1,0);
    bfs(n,1,b[n-1].second);

    vis.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        if(ans[i] == 1){
            bfs(n,0,i);
            bfs(n,1,i);
            vis.assign(n+1,0);
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<ans[i];
    }cout<<endl;
 
    return;
}
*/