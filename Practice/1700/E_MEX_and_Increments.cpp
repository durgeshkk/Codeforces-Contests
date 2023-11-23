#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<(e)<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    sort(v.begin(),v.end());

    ll val = -1; 
    vector<ll> ans(n+1,0);
    vector<ll> freq(n+1,0);
    map<ll,ll> mp;

    set<ll> s(v.begin(),v.end());

    for(ll i=0;i<n;i++){
        freq[v[i]]++;
    }

    if(s.find(0) == s.end()){
        vector<ll> z(n+1,-1);
        z[0] = 0;
        show(z);return;
    }

    ll excess = 0,flag = 0,prev = 0;
    multiset<ll> ms;
    ans[0] = freq[0];
    if(freq[0] > 0){
        excess += (freq[0]-1);
        for(ll j = 1;j<freq[0];++j){
            ms.insert(0);
        }
    }
    // show(freq);

    for(ll i=1;i<=n;i++){
        if(flag&1){ans[i]=(-1);continue;}

        if(s.find(i-1) != s.end()){
            // Work is done
            ans[i] = (prev+freq[i]);
        }else{
            // Pehle (i-1) leke aao fir baat kro
            if(excess > 0){
                ll val = *ms.rbegin();
                ms.erase(ms.find(val));
                // Bring (i-1) to the route
                ans[i] = ((i-1-val)+prev+freq[i]);
                prev += (i-1-val);
                --excess;
            }else{
                ans[i] = -1;
                flag = 1;
            }
        }

        if(freq[i] > 0){
            excess += (freq[i]-1);
            for(ll j = 1;j<freq[i];++j){
                ms.insert(i);
            }
        }

        /*
        if((freq[i] == 0) and (excess != 0)){
            if(freq[i-1] != 0){
                ans[i] = prev;
                continue;
            }
        }

        if(freq[i] != 0){
            ans[i] = (freq[i]+prev);
        }
        
        if(freq[i] > 1){
            excess += (freq[i]-1);
            for(ll j = 1;j<freq[i];++j){
                ms.insert(i);
            }
        }

        if(freq[i] == 0){
            ll val = *ms.rbegin();
            ms.erase(ms.find(val));
            // Getting MEX = 2 means 2 is absent in the array but we need 2 for MEX = 3
            ans[i] = ((i-1-val)+prev);
            prev += ans[i];
            --excess;
            // Adding 2 in array :
            if(ms.size() == 0){
                flag = 1;
            }else{
                val = *ms.rbegin();
                ms.erase(ms.find(val));
                --excess;
                prev += (i-val);
            }
        }*/
    }
    // cout<<endl;
    show(ans);
    return;













/*
    ll mx = 0;
    for(ll i=0;i<n;i++){
        mx = max(mx,v[i]);
    }

    // show(v);
    ll prev = 0,f = 0;
    ll j = 0;//Iterate over vector
    for(ll i = 0;i<=n;++i){//Iterate over ans

        while(v[j] <= i and j < n){
            mp[v[j]]++;
            if(mp[v[j]] >= 2){
                ms.insert(v[j]);
            }
            ++j;
        }

        if(vis[i] == 0){
            // Newly Operations req will be sum of last one + curr
            f = 1;
        }

        // For i requirement is (i-1)
        if(mp.find(i) != mp.end()){
            ans[i] = mp[i];
        }else if(mp.find(i-1) != mp.end()){
            ans[i] = 0;
        }
        else{
            // if((ans[i-1] != 0) and (ms.size() == 0)){
            //     ans[i] = 0;
            // }else{
                // cout<<ms.size()<<endl;
                if(ms.size() == 0 and ans[i-1] != 0){
                    ans[i] = 0;
                }else{
                    ll val = *ms.rbegin();
                    ms.erase(ms.find(val));
                    ans[i] = (i-1-val)+(prev);
                    prev = ans[i];
                }
            // }
        }

        if(j == n){

        }
    }

    // for(auto it:mp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }
    show(ans);
    return;*/
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