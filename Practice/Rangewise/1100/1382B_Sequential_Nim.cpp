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

    if(n == 1){
        cout<<"First\n";
        return;
    }

    ll ind = 0,count1 = 0;
    for(ll i = 0;i<n;i++){
        if(v[i] == 1){
            count1++;
        }
        else{
            ind = i;
            break;
        }
    }

    if(count1 == n && n%2 == 0){
        cout<<"Second\n";
        return;
    }
    else if(count1 == n){
        cout<<"First\n";
        return;
    }

    if(ind%2 == 0){
        cout<<"First\n";
    }
    else{
        cout<<"Second\n";
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