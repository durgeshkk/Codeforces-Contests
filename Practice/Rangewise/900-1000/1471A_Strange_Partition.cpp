#include<bits/stdc++.h>
#include <deque>
#define ll long long int
#define m 1000000007
using namespace std;
 
void solve()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> v;
    ll mx = 0;
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;

        v.push_back(ele);
        
        mx = mx + ceil(1.0*ele/x);
    }

    ll sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + (v[i]%1000000007);
        sum = sum%1000000007;
    }

    ll mini = accumulate(v.begin(),v.end(),0);


    ll min_ans = ceil(sum*1.0/x);
    cout<<min_ans<<" "<<mx<<endl;
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