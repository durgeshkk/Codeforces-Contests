#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    
    vector<ll> v;
    set<ll> s;
    // for(ll i=1;(i*i)<=n;i++){
    //     v.push_back(i*i);
    // }

    if(n%2 == 0){
        /*
        for(ll i=1;(i*i)<=n;i++){
        // for(ll i=0;i<v.size();i++){
            s.insert(i*i*2);
            s.insert(i*i*4);
            // s.insert(v[i]*4);
        }

        if(s.find(n) == s.end()){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }*/

        ll x = sqrt(n);
        ll xx = sqrt(n/2);

        if((n%2 == 0 && x*x==n) || (2*xx*xx == n)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }


    }
    else{
        cout<<"NO\n";
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
//    solve();
   return 0;
}