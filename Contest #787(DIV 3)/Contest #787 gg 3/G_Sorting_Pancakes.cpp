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
 
    ll n,m;
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    for(ll i=0;i<n;i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;

    reverse(v.begin(),v.end());
    if(is_sorted(v.begin(),v.end())){
        cout<<0<<endl;
        return;
    }
    else{
        reverse(v.begin(),v.end());

        ll ans = 0;
        ll req = m/n;
        ll extra = (m%n);

        vector<ll> vec(n);
        for(ll i=0;i<extra;i++){
            vec[i] = (req+1);
        }
        
        for(ll i=extra;i<n;i++){
            vec[i] = (req);
        }

        for(ll i=0;i<n;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;

        ll count = 0;
        for(ll i=0;i<n;i++){
            if((vec[i] > v[i]) || (vec[i] < v[i])){
                ans = (ans + abs(vec[i]-v[i]));
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j = i;j<n;j++){
                
            }
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
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}