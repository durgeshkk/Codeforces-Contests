#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll gcda(ll x,ll y){
    if(x == 0){
        return y;
    }
    ll ans = gcda(x,y%x);
    return ans;
}

void solve()
{
    ll n;
    cin>>n;

    ll e_count=0;

    vector<ll> v;
    vector<ll> odd;
    vector<ll> even;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        if(ele % 2 == 0){
            even.push_back(ele);
        }
        else{
            odd.push_back(ele);
        }
    }
    
// In array 1st have even no & then odd 
// So in v push it accordingly
    for(auto i:even){
        v.push_back(i);
    }
    
    for(auto i:odd){
        v.push_back(i);
    }

    ll gcd_count = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(__gcd(v[i],2*v[j]) > 1){
                gcd_count++;
            }
        }
    }

    cout<<gcd_count<<endl;
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