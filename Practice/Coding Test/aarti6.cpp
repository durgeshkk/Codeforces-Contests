#include<bits/stdc++.h>
#define ll long long int
using namespace std; 
void solve()
{
 
    vector<ll> v;
    while(1){
        ll z;
        cin>>z;

        if(z < 0){
            break;
        }
        v.push_back(z);
    }
 
    vector<vector<ll>> ans;
    vector<ll> dk;
    ll i = 0;
    vector<ll> ag;
    while(i<v.size()){
        
        if(v[i]&1){
            ans.push_back(ag);
            ll sm = accumulate(ag.begin(),ag.end(),0);
            ll avg = sm/ag.size();
            dk.push_back(avg);
            ag.clear();
        }
        else{
            ag.push_back(v[i]);
        }
        ++i;
    }

    ans.push_back(ag);
    ll sm = accumulate(ag.begin(),ag.end(),0);
    ll avg = sm/ag.size();
    dk.push_back(avg);
    ll mx = *max_element(dk.begin(),dk.end());
    cout<<mx<<endl;

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