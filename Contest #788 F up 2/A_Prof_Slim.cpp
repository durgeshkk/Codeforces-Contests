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
    vector<ll> v(n);

    ll min = INT16_MAX;
    
    ll neg = 0,pos=0;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       if(v[i] > 0){
           pos++;
       }
       else if(v[i] < 0){
           neg++;
       }

       if(v[i] < min){
           min = v[i];
       }
    }

    
    if(is_sorted(v.begin(),v.end())){
        cout<<"YES\n";
        return;
    }

    // if(n%2){
    //     cout<<"NO\n";
    //     return;
    // }

    vector<ll> vneg,vpos;
    for(ll i=0;i<neg;i++){
        vneg.push_back(abs(v[i]));
    }
    
    for(ll i=neg;i<n;i++){
        vpos.push_back(abs(v[i]));
    }

    

    reverse(vneg.begin(),vneg.end());

    if(is_sorted(vneg.begin(),vneg.end())){
        if(is_sorted(vpos.begin(),vpos.end())){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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