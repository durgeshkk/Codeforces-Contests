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
 
    ll a,b;
    cin>>a>>b;
    
    if(b>a){
        cout<<1<<endl;
        return;
    }
    else if(a == b){
        cout<<2<<endl;
    }
    else{
        ll ans = 1e18,count=0;

        for(ll i=0;i*i <= a;i++){

            if(b == 1 and i==0){
                continue;
            }

            count = i;

            ll c = a;

            while(c){
                c /= (b+i);
                count++;
            }
            ans = min(ans,count);
        }
        cout<<ans<<endl;
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