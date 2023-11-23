#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

// Gym prblm Basic :
void solve()
{
 
    ll l = 1,h = (ll)1e6;
    while(l < h){
        ll mid = (l+h+1)/2;
        cout<<mid<<endl;
        fflush(stdout);

        string x;cin>>x;

        if(x == ">="){
            l = mid;
        }else{
            h = mid-1;
        }
    }
    cout<<"! "<<l<<endl;
    fflush(stdout);
    return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
   return 0;
}