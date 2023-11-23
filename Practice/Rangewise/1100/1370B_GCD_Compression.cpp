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
    // cout<<endl;
    ll n;
    cin>>n;

    vector<ll> v(2*n);
    vector<pair<ll,ll>> odd,even;

    for(ll i=0;i<2*n;i++){
       cin>>v[i];

       if(v[i]%2){
           odd.push_back(make_pair(v[i],i+1));
       }
       else{
           even.push_back(make_pair(v[i],i+1));
       }
    }

    vector<ll> ans;
    ll k = 0;

    if(odd.size()%2){
        for(ll i = 0;i<odd.size()-1;i+=2){
            cout<<odd[i].second<<" "<<odd[i+1].second<<endl;
            k++;
            if(k == (n-1)){
                return;
            }
        }
    }
    else{
        if(k == (n-1)){
                return;
            }
        for(ll i = 0;i<odd.size();i+=2){
            cout<<odd[i].second<<" "<<odd[i+1].second<<endl;
            k++;
            if(k == (n-1)){
                return;
            }
        }
    }

    if(k == (n-1)){
                return;
            }

    if(even.size()%2 != 0){
        for(ll i = 0;i<even.size()-1;i+=2){
            cout<<even[i].second<<" "<<even[i+1].second<<endl;
            k++;
            if(k == (n-1)){
                return;
            }
        }
    }
    else{
        if(k == (n-1)){
                return;
            }
        for(ll i = 0;i<even.size();i+=2){
            if(k == (n-1)){
                return;
            }
            cout<<even[i].second<<" "<<even[i+1].second<<endl;
            k++;
            
        }
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