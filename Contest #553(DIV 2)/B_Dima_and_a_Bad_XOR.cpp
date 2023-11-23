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
 
    ll n;
    cin>>n;
    ll m;
    cin>>m;

    ll arr[n][m];
    ll odd = 0;
    ll even = 0;

    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            cin>>arr[i][j];
        }
    }

    vector<vector<ll>> v(n,vector<ll> (12,-1));

    for(ll i=0;i<n;i++){
        map<ll,ll> mp0;
        map<ll,ll> mp1;

        for(ll j = 0;j<m;++j){
            bitset<12> s(arr[i][j]);
            for(ll k = 0;k<12;++k){
                if(s[k] == 0){
                    mp0[k]++;
                }
                else{
                    mp1[k]++;
                }
            }
        }

        for(auto it:mp0){
            v[i][it.first] = 0;
        }
        
        for(auto it:mp1){
            if(v[i][it.first] == (-1)){
                v[i][it.first] = 1;
            }
            else{
                v[i][it.first] = 2;
            }
        }
    }
/*
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<12;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/

    ll f = 0;
    ll ag = -1, dk = -1;
    vector<ll> sad(n);

    for(ll i = 0;i<12;++i){
        ll o = 0,t = 0;
        for(ll j = 0;j<n;++j){
            if(v[j][i] == 1){
                ++o;
            }
            else if(v[j][i] == 2){
                ++t;
                dk = j;
            }
        }

        if(o & 1){
            f = 1;
            ag = i;
            break;
        }
        else{
            if(t >= 1){
                f = 2;
                ag = i;
                break;
            }
        }
    }

/*
    // cout<<ag<<endl;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<12;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */

    for(ll i = 0;i<n;++i){
        sad[i] = v[i][ag];
    }

    // show(sad);
    
    if(f == 0){
        cout<<"NIE\n";
    }
    else{
        cout<<"TAK\n";
        if(f & 1){
            for(ll i = 0;i<n;++i){
                if(sad[i] == 1){
                    for(ll j = 0;j<m;++j){
                        bitset<12> s(arr[i][j]);
                        if(s[ag] == 1){
                            cout<<(j+1)<<" ";
                            break;
                        }
                    }
                }else if(sad[i] == 2){
                    for(ll j = 0;j<m;++j){
                        bitset<12> s(arr[i][j]);
                        if(s[ag] == 0){
                            cout<<(j+1)<<" ";
                            break;
                        }
                    }

                }else{
                    cout<<1<<" ";
                }
            }
            cout<<endl;
        }
        else{
            for(ll i = 0;i<n;++i){
                if(sad[i] == 1){
                    for(ll j = 0;j<m;++j){
                        bitset<12> s(arr[i][j]);
                        if(s[ag] == 1){
                            cout<<(j+1)<<" ";
                            break;
                        }
                    }
                }else if(sad[i] == 2){

                    if(dk == i){
                        for(ll j = 0;j<m;++j){
                            bitset<12> s(arr[i][j]);
                            if(s[ag] == 1){
                                cout<<(j+1)<<" ";
                                break;
                            }
                        }
                    }else{
                        for(ll j = 0;j<m;++j){
                            bitset<12> s(arr[i][j]);
                            if(s[ag] == 0){
                                cout<<(j+1)<<" ";
                                break;
                            }
                        }
                    }
                }else{
                    cout<<1<<" ";
                }
            }
            cout<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
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
    set<ll> o,e;
    for(ll i=0;i<n;i++){
        ll f = 0;
        for(ll j = 0;j<m;++j){
            if(arr[i][j] & 1){
                // ++odd;
                o.insert(i+1);
                f = 1;
                break;
            }
        }
        if(f & 1){

        }
        else{
            e.insert(i+1);
        }
    }    
    
    for(ll i = 1;i<=n;++i){
        if(o.find(i) != o.end()){

        }
    }

    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            if(arr[i][j] & 1){
            }
            else{
                ++even;
                break;
            }
        }
    }    

    if(odd & 1){
        set<ll> ans;
        vector<ll> ag;
        // cout<<"TAK\n";
        for(ll i=0;i<n;i++){
            for(ll j = 0;j<m;++j){
                if(arr[i][j] & 1){
                    ans.insert(j+1);
                    ag.push_back(j+1);
                    odd--;
                    // cout<<(j+1)<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
    else if(odd == 0){

    }
    else{
        // cout<<"TAK\n";
        for(ll i=0;i<n;i++){
            for(ll j = 0;j<m;++j){
                if(arr[i][j] & 1){
                    cout<<(j+1)<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
*/
