#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void solve()
{
 
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> v(n,vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    for(ll ak = 0;ak<k;++ak) {
        ll z;
        cin>>z;
        --z;

        ll j = z;
        for(ll i = 0;i<n;){
            if(v[i][j] == 1){
                v[i][j] = 2;
                ++j;
            }
            else if(v[i][j] == 3){
                v[i][j] = 2;
                --j;
            }
            else{
                ++i;
            }
        }
        cout<<j+1<<" ";
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   solve();
   return 0;
}