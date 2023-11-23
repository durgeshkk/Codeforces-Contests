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
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    ll c=0;
    for(ll i=1;i<n;i++){
        if(v[i-1] == v[i]){
            c++;
        }
    }

    if(c<2){
        cout<<"0\n";
        return;
    }

    ll l=-1,r=-1;

    for(ll i=1;i<n;i++){
        if(v[i-1] == v[i]){
            if(l == -1){
                l = i-1;
                r=i;
            }
            r=i;
        }
    }

    ll d = r-l+1;
    if(d == 3){
        cout<<"1\n";
    }
    else{
        cout<<d-3<<endl;
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