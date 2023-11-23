#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void solve()
{
 
    ll n;
    cin>>n;

    ll k;
    cin>>k;
    ll sm = (n-1);

    if(k == sm){
        if(k == 3)
            cout<< -1 <<endl;
        else{
            ll z = (sm/2)+1;
            cout<<z<<" "<<sm<<endl;
            cout<<0<<" "<<(z-1)<<endl;

            ll a = 1, b = (sm-a);  
            ll c = (k/2-1), d = (sm-c);
            if(a > d){
                swap(a,d);
            }

            if(b > c){
                swap(b,c);
            }
            cout<<a<<" "<<d<<endl;
            cout<<b<<" "<<c<<endl;

            // if(a == 2 || b == 2){
            //     return;
            // }
            for(ll i = 2;i<n/2-2;++i){
                if(i == a || i == b){
                    continue;
                }
                cout<<i<<" "<<sm-i<<endl;
            }
        }
        return;
    }

    ll ag = (sm-k);

    cout<<0<<" "<<ag<<endl;
    if(k != 0){
        cout<<k<<" "<<sm<<endl;
    }

    map<ll,ll> mp;
    for(ll i=1;i<n/2;i++){
        if(i == ag || i == k){

        }
        else{
            cout<<i<<" "<<sm-i<<endl;
        }
    }
 /*
    if(k >= n/2){
        k = (sm-k);
    }

    mp[k] = 0;
*/
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}