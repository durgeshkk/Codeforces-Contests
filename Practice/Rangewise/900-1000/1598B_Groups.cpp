#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;
    /*
    ll a = 1;
    map <ll,ll> mp;

    while(a <= n){

        for (int i = 1; i <= 5; i++)
        {
            ll ele;
            cin>>ele;
            if(ele == 1){
                mp[i]++;
            }
        }
        a++;
    }
    
    ll count = 0;
    for(ll i=1;i<=5;i++){
        if(mp[i] >= (n/2)){
            count++;
        }
    }

    if(count >= 2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }*/
    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}