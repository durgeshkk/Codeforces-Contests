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
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    string s,t;
    cin>>s>>t;

    map<ll,ll> mp,ak;
    for(ll i=0;i<n;i++){
        mp[s[i] - 'a']++;
        ak[t[i] - 'a']++;
    }

    for(ll i = 0;i<26;++i){

        if(mp[i]<ak[i] || ((mp[i] -ak[i])%k)){
            cout<<"No\n";
            return;
        }

        if(mp[i] > ak[i]){
            ll diff = mp[i]-ak[i];
            mp[i+1] += diff;
        }
    }
    
/*
    

    // for(auto it:mp){
    //     cout<<it.first<<" --> "<<it.second<<endl;
    // }

    // for(auto it:mp){
    //     if(it.second == 0){
    //         mp.erase(it.first);
    //     }
    // }

    if(mp.find('z') != mp.end()){
        cout<<"No\n";
        return;
    }

    for(auto it:mp){
        if(it.second%k){
            cout<<"No\n";
            return;
        }
    }

    for(auto it:ak){
        if(it.second%k){
            cout<<"No\n";
            return;
        }
    }

    vector<pair<ll,char>> dk,st;
    for(auto it:mp){
        st.push_back({it.second,it.first});
    }

    for(auto it:ak){
        dk.push_back({it.second,it.first});
    }

    ll i = 0,j = 0;
    while(i < dk.size() && j<st.size()){
        pair<char,ll> p1 = dk[i],p2 = st[j];

        if(p1.first > p2.first){
            if(p2.second <= p1.second){
                p1.first -= p2.first;
                ++j;
            }
            else{
                cout<<"No\n";
                return;
            }
        }
        else if(p1.first == p2.first){
            if(p2.second <= p1.second){
                p1.first -= p2.first;
                ++j,++i;
            }
            else{
                cout<<"No\n";
                return;
            }
        }
        else{
            if(p2.second <= p1.second){
                p2.first -= p1.first;
                ++i;
            }
            else{
                cout<<"No\n";
                return;
            }

        }
    }
*/
    cout<<"Yes\n";
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