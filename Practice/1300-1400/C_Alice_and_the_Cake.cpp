#include<bits/stdc++.h>
#include<iomanip>
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
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sm = 0;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       sm += v[i];
    }

    multiset<ll> ms;
    multiset<ll> ms2;

    for(auto it:v){
        ms2.insert(it);
    }

    ms.insert(sm);

    while(!ms.empty()){
        ll mx = *(ms.rbegin());
        ll mxq = *(ms2.rbegin());

        if(mx < mxq){
            cout<<"NO\n";
            return;
        }

        ms.erase(ms.find(mx));

        if(ms2.find(mx) != ms2.end()){
            ms2.erase(ms2.find(mx));
            // ms2.erase((mx));//DANGER will delete all occurences
        }
        else{
            ms.insert(mx/2);
            ms.insert(ceil(1.0*mx/2));
        }
    }
    cout<<"YES\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}