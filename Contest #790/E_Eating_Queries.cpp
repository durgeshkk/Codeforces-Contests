#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
void solve()
{
 
    ll n,q;
    cin>>n>>q;

    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    ll sum = 0;
    vector<ll> sumget;
    for(ll i = 0;i<v.size();i++){
        sum += v[i];
        sumget.push_back(sum);
    }

    for(ll i=0;i<q;i++){
        ll ele;
        cin>>ele;
        ll val = lower_bound(sumget.begin(),sumget.end(),ele) - sumget.begin();
        if(val == n){
            cout<<-1<<endl;
        }
        else{
            cout<<val+1<<endl;
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