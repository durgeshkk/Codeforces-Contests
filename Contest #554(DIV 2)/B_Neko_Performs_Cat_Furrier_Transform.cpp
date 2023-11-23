#include<bits/stdc++.h>
#include<iomanip>
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

    bitset<32> s(n);
    ll idx = 0;
    for(ll i=0;i<32;i++){
        if(s[i] == 1){
            idx = i;
        }
    }
    
    ll ans = 0;
    vector<ll> ag;
    ll f = 0;
    ll z = n;

    while(idx >= 0){
        bitset<32> ak(z);
        if(ak[idx] == 1){
            ll aka = (1<<idx);
            z -= aka;
            --idx;
            continue;
        }

        // cout<<"---\n";
        
        ll val = 1<<(idx+1);
        --val;
        // cout<<z<<" "<<val<<" ";
        z = (z^val);
        // cout<<z<<" "<<val<<" ";
        
        
        ag.push_back(idx+1);
        ++ans;
        // bitset<32> b(z);
        // bitset<32> c(val);
        // cout<<z<<" "<<val<<endl;
        // cout<<b<<" "<<c<<endl;
        
        ll a = (val ^ z);
        if(a == 0){
            break;
        }
        // cout<<"--\n";
        // cout<<((1<<(idx)))<<endl;
        // z -= (1<<(idx));
        // cout<<"--\n";
        
        ++z;
        ++ans;
        // --idx;
    }

    cout<<ans<<endl;
    show(ag);
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   solve();
   return 0;
}
/*
            for(ll j = idx;j>=0;--j){
                if(ak[j] == 1){
                    --idx;
                }
                else{
                    break;
                }
            }

            string st;
            for(ll j = idx;j>=0;--j){
                if(ak[j] == 0){
                    st += '0';
                }
                else{
                    st += '1';
                }
            }
            z = stoi(st);
            */
            
            // cout<<ak<<endl;
        // cout<<idx<<" ";
        // cout<<z<<endl;
        // cout<<z<<" "<<val<<" ";
        // cout<<z<<endl;
        // cout<<dk<<endl;
        