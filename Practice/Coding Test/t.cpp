#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> a(n);
    enter(a);
 
    vector<ll> b(n);
    enter(b);

    ll pos = 0,neg = 0;
    for(ll i=0;i<n;i++){
        if(a[i] > b[i]){
            pos += (a[i]-b[i]);
        }
        else{
            neg += (b[i]-a[i]);
        }
    }

    if(neg == pos){
        cout<<pos<<endl;
    }
    else{
        cout<< -1 << endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}