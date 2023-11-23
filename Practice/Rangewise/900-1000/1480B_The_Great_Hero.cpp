#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll a,b,n;
    cin>>a>>b>>n;

    vector<pair<ll,ll>> v(n);

    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }

    sort(v.begin(),v.end());
    
    for(ll i=0;i<n;i++){
        if(b <= 0){
            cout<<"NO\n";
            return;
        }
        // k1 = monster can get to 0 in how many matches
        ll k1 = (v[i].second/a);
        ll k2 = (v[i].second%a);

        // k3 = I can get to 0 in how many matches
        ll k3 = (b/v[i].first);
        ll k4 = (b%v[i].first);
        if(k4){
            k3++;
        }
            
        if(k2){
            k1++;
        }

        // now update k1 with min. no. of matches in which who can die
        k1 = min(k1,k3);
        // reduce hero health
        b = b - (k1*v[i].first);
        v[i].second = v[i].second - (k1*a);
    }

    if(v[n-1].second>0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}