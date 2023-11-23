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
    
    ll c1=0,c2=0,c3=0;
    
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       if(ele%3 == 0) c1++;
       if(ele%3 == 1) c2++;
       if(ele%3 == 2) c3++;
    }

    if((c1 == c2) && (c2 == c3)){
        cout<<0<<endl;
        return;
    }

    // cout<<c1<<" "<<c2<<" "<<c3<<endl;

    ll count = 0;
    while(1){
        if((c1 == c2) && (c2 == c3)){
            break;
        }
        if(c1>c2){
            c1--;
            c2++;
        }
        else if(c2>c3){
            c2--;
            c3++;
        }
        else if(c3>c1){//c3>c1
            c3--;
            c1++;
        }
        count++;
    }
    cout<<count<<endl;
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