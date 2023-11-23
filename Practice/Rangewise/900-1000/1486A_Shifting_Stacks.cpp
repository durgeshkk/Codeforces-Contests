#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    for(int i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    if(n == 1){
        cout<<"YES\n";
        return;
    }
// /*
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        // sum = sum%10000;
    }
// */
        /*
       ll mx = v[0]-0;
       for(int i=0;i<n;i++){
           ll t = v[i]-i;
           if(t > mx){
               mx = t;
           }
           if(mx < 0){
               cout<<"NO\n";
               return;
           }
           mx--;
       }

*/
        ll k=v[0];
    for(ll i=0;i<n-1;i++){
           if(v[i] > i){
               k = v[i]-i;
               v[i+1] += k;
               v[i] -= k;
           }
    }
    
    ll f=0;
    for(ll i=1;i<n;i++){

           if(v[i] <=  v[i-1]){
               f = 33;
           }
    }


    if(f == 33){
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