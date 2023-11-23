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
 
    ll l,r,u,d;
    cin>>l>>r>>d>>u;

    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;

    int f=1;
    if(((r-l) > (x2-x)) || ((l-r) > (x-x1))){
        f=0;
    }
    
    if(((u-d) > (y2-y)) || ((d-u) > (y-y1))){
        f=0;
    }
    
    if((x1==x2) && ((l+r) > 0)){
        f=0;
    }
    
    if((y1==y2) && ((d+u) > 0)){
        f=0;
    }

    if(f == 1){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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