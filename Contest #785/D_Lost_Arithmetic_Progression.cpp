#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{

    ll a,d,n;
    cin>>a>>d>>n;

    vector<ll> B;
    multiset<ll> setb;
    for(ll i=0;i<n;i++){
       B.push_back(a+(i)*d);
        setb.insert(a+(i)*d);
    }

    ll a2,d2,n2;
    cin>>a2>>d2>>n2;

    vector<ll> C;
    for(ll i=0;i<n2;i++){
        ll ele = a2+(i)*d2;
        C.push_back(ele);
    }
    
    for(ll i=0;i<n2;i++){
       if(setb.find(C[i]) == setb.end()){
           cout<<0<<endl;
           return;
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