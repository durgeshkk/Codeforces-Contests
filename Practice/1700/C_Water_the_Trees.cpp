/*
    Author: ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll helper(ll n,vector<ll> &v,ll mx){
    ll l = 0,h = 1e18;
    ll ans;
    while(l <= h){
        ll mid = (l+h)/2;

        // Check if on mid no. of days I can make all the trees of equal height
        ll f = 1;// I can water
        ll even_days = mid/2;
        ll odd_days = mid-even_days;

        for(ll i = 0;i<n;++i){
            ll req_hght = (mx-v[i]);
            ll need_edays = req_hght/2;
            
            if(even_days >= need_edays){
                even_days -= need_edays;
                ll need_odd = req_hght - 2*need_edays;
                if(need_odd > odd_days){f = 0;break;}
                odd_days -= need_odd;
            }else{
                // jitne even days chahiye utne nhi h bt ha if odd days h toh 
                // use them
                ll need_odd = req_hght - 2*even_days;
                even_days = 0;

                // Only for odd days pending
                if(need_odd > odd_days){f = 0;break;}
                odd_days -= need_odd;
            }
        }

        if(f & 1){
            ans = mid;h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
    sort(v.begin(),v.end());
    ll mx = v[v.size()-1];
    ll ans = helper(n,v,mx);
    ll ans2 = helper(n,v,mx+1);
    ans = min(ans,ans2);
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