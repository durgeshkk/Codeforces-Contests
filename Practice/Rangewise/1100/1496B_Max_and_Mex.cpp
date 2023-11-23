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
 
    ll n;
    cin>>n;

    ll k;
    cin>>k;

    ll mx = INT16_MIN;
    ll mn = INT16_MAX;
    
    vector<ll> v(n);
    set<ll> s;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       s.insert(v[i]);
       if(mx < v[i]){
           mx = v[i];
       }
       if(mn > v[i]){
           mn = v[i];
       }
    }

    if(k == 0){
        cout<<s.size()<<endl;
        return;
    }

    ll mex = 0;
    ll f = 0;
    for(ll i = 0;i<s.size();i++){
        if(s.find(i) == s.end()){
            mex = i;
            f = 1;
            break;
        }
    }
    if(f == 0){
        mex = s.size();
    }

    if(s.size() == (mx+1)){
        ll ans = s.size()+k;
        cout<<ans<<endl;
        return;
    }

    ll ans = ceil(1.0*(mex+mx)/2);
    if(s.find(ans) == s.end()){
        cout<<s.size()+1<<endl;
    }
    else{
        cout<<s.size()<<endl;
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
   //solve();
   return 0;
}