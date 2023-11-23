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

    vector<ll> v;
    // vector<ll> v(n);
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        // cin>>v[i];
        v.push_back(ele);
    }
    cout<<"HI\n";

    for(ll i=0;i<n;i++){
       cout<<v[i]<<" ";
    }

    vector<ll> v2(m);
    for(ll i=0;i<m;i++){
       cin>>v2[i];
    }

    for(ll i=0;i<m;i++){
       cout<<v2[i]<<" ";
    }

    ll j=0;
    // ll ind = -1;

    reverse(v.begin(),v.end());
    vector<ll> ans;
    cout<<"HI\n";
    for(ll i=(n-1);i>=0;i--){
        if(m==j){
            break;
        }
        if(v[i] == v2[j]){
            ans.push_back(v.size()-i);
            ll val = v[i];
            v.erase(v.begin(),v.begin()+i);
            v.push_back(val);
            j++;
            i=n-1;
        }
    }

    for(ll i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t=1;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}