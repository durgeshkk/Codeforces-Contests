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
        cout<<0<<endl;
        return;
    }

    ll i = 0,j = n-1;
    ll wi = v[0],wj = v[n-1];
    ll ans = 0;

    if(wi == wj){
        ans = 2;
        wi += v[i+1];
        wj += v[j-1];
        i++,j--;
    }
    // else if(wi < wj){
    //     wi += v[i+1];
    //     i++;
    // }
    // else if(wj < wi){
    //     wj += v[j-1];
    //     j--;
    // }

    while(i<j){
        if(wi < wj){
            wi += v[i+1];
            i++;
        }
        else if(wj < wi){
            wj += v[j-1];
            j--;
        }
        else{//wi == wj
            // cout<<wi<<" "<<wj<<endl;
            ans = (i+1);
            ans += ((n)-j);
            wi += v[i+1];
            wj += v[j-1];
            i++,j--;
        }
    }
    cout<<ans<<endl;

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