#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b)
{
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}


void solve()
{
    ll d;
    cin>>d;

    ll p1 = 0,p2=0;

// Storing 1st prime no.
    ll i=1+d;
    while(1){
        if(isPrime(i) && (i-1 >= d)){
            p1 = i;
            break;
        }
        i++;
    }
    
// Storing 2nd prime no.
    i = p1+d;
    while(1){
        if(isPrime(i) && (i-p1 >= d)){
            p2 = i;
            break;
        }
        i++;
    }

    // for(ll i=0;i<v.size();i++){
    //     if((v[i]-1 )>= d){
    //         ans *= v[i];
    //         j = v[i];
    //         break;
    //     }
    // }
    // for(ll i=0;i<v.size();i++)
    // {
    //     if(v[i]-j >= d)
    //     {
    //         ans *= v[i];
    //         j = v[i];
    //         break;
    //     }
    // }
    ll ans = p1*p2;
    cout<<ans<<endl;
    return;
}
 
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    prime();
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}