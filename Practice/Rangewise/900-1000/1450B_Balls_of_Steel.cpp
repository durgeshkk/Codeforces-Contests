#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;
    
    vector<pair<ll,ll>> v;
    for (int i = 0; i < n; i++)
    {   
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    for (int i = 0; i < n; i++)
    {   
        ll num = 0;
        for(ll j=0;j<n;j++){
            ll dist1 = abs(v[j].first - v[i].first);
            ll dist2 = abs(v[j].second - v[i].second);
            if(dist1+dist2 > k){
                // cout<<dist1<<" "<<dist2<<endl;
                break;
            }
            else{
                num++;
            }
        }
        if(num == n){
            cout<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
   //solve();
   return 0;
}