//CELEBRATING SEMIANNIVERSARY OF DADDY_DYNAMO!!
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
 
    ll n;cin>>n;ll k;cin>>k;

    vector<ll> v(k);
    enter(v);

    if(n == 1 || k == 1){
        cout<<"Yes\n";
        return;
    }

    vector<ll> ap;
    for(ll i=1;i<k;i++){
        ap.push_back(v[i]-v[i-1]);
    }

    ll f = 0;
    if(is_sorted(ap.begin(),ap.end())){
        ll val = (n-k+1);
        ll req = (val*ap[0]);

        if(ap[0] < 0){
            if(req >= v[0]){
                f = 1;
            }
        }else if(ap[0] == 0){
            if(v[0] <= 0){
                f = 1;
            }
        }else{
            if(v[0] <= req){
                f = 1;
            }
        }

        if(f & 1){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else{
        cout<<"No\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}