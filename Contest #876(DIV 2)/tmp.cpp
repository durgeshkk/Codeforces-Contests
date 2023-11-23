#include<bits/stdc++.h>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        ll f = 0;
        ll cntr = 0,ok = 0;
        while(i<n){
            if(!v[i]){
                f = 1;
                ans.push_back(cntr);
                // v.erase(v.begin()+j);
                // --i;
                break;
            }else{
                // v[i] = 0;
            }
            ++cntr,++i;
            ok++;
        }
        if(ok){
            --i;
        }
        if(!f){
            yno(0);return;
        }
    }
    yno(1);
    if(ans.size() < n){
        ans.push_back(0);
    }
    reverse(all(ans));
    show(ans);
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