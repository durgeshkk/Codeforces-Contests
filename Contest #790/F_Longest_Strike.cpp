#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    map<ll,ll> mp;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }

    ll st = 0,ed=0;
    ll f=0;

    vector<pair<ll,ll>> ans;

    for(ll i = 0;i<n;i++){
        if(mp[v[i]] >= k && f==0){
            st = v[i];
            ed = v[i];
            f = 1;
        }
        else if(mp[v[i]] >= k && f==1){
            ed = v[i];
        }
        else{
            ans.push_back(make_pair(st,ed));
            f = 0;
        }
    }

    ll mx = 0,mn=0;
    for(ll i = 0;i<ans.size();i++){
        ll t = abs(ans[i].first - ans[i].second);
        if(mx < t){
            mn = ans[i].first;
            mx = ans[i].second;
        }
    }

    if(mn == 0 && mx == 0){
        cout<<-1<<endl;
        return;
    }
    cout<<mn<<" "<<mx<<endl;
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