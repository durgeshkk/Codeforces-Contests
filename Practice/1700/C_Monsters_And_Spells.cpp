#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> k(n);enter(k);
    vector<ll> h(n);enter(h);

    ll mx = h[n-1];
    vector<ll> v;
    ll prev = 0,prev_idx = k[n-1];
    
    for(ll i=n-2;i>=0;--i){

        // prev = h[i+1]-(k[i+1]-k[i]);
        prev = mx-(k[i+1]-k[i]);
        ll req = h[i];

        if(prev <= 0){
            // cout<<i<<" ";
            // cout<<mx<<" "<<prev_idx<<" "<<k[i+1]<<endl;
            v.push_back(mx+(prev_idx-k[i+1]));
            prev_idx = k[i];
        }
        mx = max(req,prev);

        // cout<<prev<<" "<<mx<<" "<<i<<endl;
    }
    // cout<<endl;

    // Check for 0th idx still pending
    v.push_back(mx+(prev_idx-k[0]));
    // show(v);

    ll dynamo = 0;
    for(auto it:v){
        ll val = it;
        dynamo += ((val*(val+1))/2);
    }
    cout<<dynamo<<endl;
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