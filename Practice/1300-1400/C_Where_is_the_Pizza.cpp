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
 
    ll mod = 1e9+7;
    ll n;
    cin>>n;

    map<ll,ll> mp1;

    vector<ll> a(n),b(n),c(n);
    set<ll> s;

    for(ll i=0;i<n;i++){
       cin>>a[i];
    }

    for(ll i=0;i<n;i++){
       cin>>b[i];
    }
    
    for(ll i=0;i<n;i++){
        if(a[i] == b[i]){
            s.insert(a[i]);
        }
        mp1[a[i]] = b[i];
    }

    // for(auto it:mp1){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    for(ll i=0;i<n;i++){
       cin>>c[i];
       s.insert(c[i]);
    }

    // for(auto it:s){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    ll cnt = 1;
    for(auto it:mp1){
        ll flg = 0;
        ll f = it.first;
        ll sc = it.second;
        // s.insert(sc);

        // if(s.find(sc) != s.end()){
        //     flg = 1;
        // }

        if(s.find(f) != s.end()){
            continue;
        }

        while(sc != f){

            if(s.find(sc) != s.end() && (flg == 0)){
                flg = 1;
            }

            s.insert(sc);
            sc = mp1[sc];
        }

        s.insert(f);
        if(flg == 0){
            cnt %= mod;
            cnt = ((cnt*2)%mod);
        }
        // cout<<"Count  : "<<cnt<<endl;
    }

    cout<<cnt<<endl;
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