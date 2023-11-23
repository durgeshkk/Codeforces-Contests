#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    ll count0 = 0;
    ll count1 = 0;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        if(ele == 0){
            count0++;
        }
        else if(ele == 1){
            count1++;
        }
    }

    ll sum = accumulate(v.begin(),v.end(),0);
    if(sum == 0){
        cout<<0<<endl;
        return;
    }
    if(n == 2 && count0 == 1 && count1 == 1){
        cout<<2<<endl;
        return;
    }

    ll b = pow(2,count0);
    ll ans =  count1;
    // if(count0 == 1){
    //     cout<<ans*2<<endl;
    //     return;
    // }
    ans = ans*b;
    cout<<ans<<endl;
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