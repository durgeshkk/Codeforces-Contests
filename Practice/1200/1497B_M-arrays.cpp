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

    ll k;
    cin>>k;

    map<ll,ll> mp;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
       v[i] = (v[i]%k);
        mp[v[i]]++;
    }

    sort(v.begin(),v.end());

    ll ans=0;
    for(auto it:mp){
        if(it.first == 0){
            ans++;
        }
        else if(it.first*2 == k){
            ans++;
        }
        else if(2*it.first < k || (mp.find(k-it.first) == mp.end())){
            ll x = it.second;
            ll y = mp[k-it.first];
            ans = ans + max(abs(x-y)-1,0LL)+1;
        }
    }

/*
    ll f = 0,ans=0,flag = 0;
    for(ll i=0;i<n;i++){
        ll req = k-v[i];
        if(v[i] == 0){
            f = 1;
            continue;
        }
        if(v[i] == (k/2) && (k%2==0)){
            flag++;
            continue;
        }
        if(mp.find(req) != mp.end() && (mp[req] > 0)){
            mp[req]--;
            mp[v[i]]--;
        }
        else{
            ans++;
        }
    }

    if(f == 1){
        ans++;
    }
    if(flag>=2){
        ans++;
    }

    for(auto it:mp){
        if(it.second == 1){
            ans++;
        }
    }*/
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}