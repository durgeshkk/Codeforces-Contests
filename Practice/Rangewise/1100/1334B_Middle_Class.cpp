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

    ll x;cin>>x;
/* TEST CASE 103 cmng wrong
    ll bade=0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
       if(v[i]>=x){
           bade++;
       }
    }

    if(bade == 0){
        cout<<0<<endl;
        return;
    }

    if(bade == n){
        cout<<n<<endl;
        return;
    }

    ll sm = accumulate(v.begin(),v.end(),0);
    sm = (sm-n);
    ll ppl = (sm/(x-1));

    if(ppl >= n){
        cout<<n<<endl;
    }
    else{
        cout<<ppl<<endl;
    }*/
    
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll cnt = 0;
    sort(a,a+n);

    ll no=1;
    ll sum = 0;

    for(ll i=n-1;i>=0;i--){
        sum += a[i];

        if((sum/(no*1.0)) >= x){
            cnt++;
            no++;
        }
        else{
            break;
        }
    }
    cout<<cnt<<endl;
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