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
 
    ll n,k;
    cin>>n>>k;
    
    ll p1 = 1;
    ll count=0;
    while(p1 < k){

        if(n < p1){
            cout<<count<<endl;
            return;
        }
        p1 *= 2;
        count++;
    }

    if(n < p1){
        cout<<count<<endl;
        return;
    }
    else{
        ll rem = n-p1;
        count += ceil(1.0*rem/k);
        cout<<count<<endl;
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