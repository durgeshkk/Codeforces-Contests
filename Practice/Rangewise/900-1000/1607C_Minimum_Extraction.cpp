#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;
    // https://www.youtube.com/watch?v=e5MOA1Wocyg
/* wrog question interpretation
    vector<ll> v;
    set<ll> s;

    for(int i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        s.insert(ele);
    }

    sort(v.begin(),v.end());

    ll sum = accumulate(v.begin(),v.end(),0);

    while(s.size() > 1){
        ll a = *(s.begin());
        sum -= (a*s.size());
        s.erase(a);
    }

    cout<<sum<<endl;*/
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    ll res=a[0],sum=0;

    for(ll i=0;i<n;i++){
        a[i] -= sum;
        sum += a[i];
    }

    for(ll i=0;i<n;i++){
        res = max(res,a[i]);
    }
    cout<<res<<endl;
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