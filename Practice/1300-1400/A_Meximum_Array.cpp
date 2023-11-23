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

    map<ll,ll> mp;
    vector<ll> v(n);
    set<ll> s;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       s.insert(v[i]);
       mp[v[i]]++;
    }

    ll mx = -1;
    ll mn = 0;
   /* 
    ll f = 0;
    for(auto it:mp){
        if(it.second == 0){
            mx = it.first;
            f = 1;
            break;
        }
    }

    if(f == 0){
        // cout<<"HI\n";
        mx = mp.size();
    }

    if(mp.find(mn) == mp.end()){
        mx = mn;
    }
*/
    for(ll i =0;i<=n;++i){
        if(mp[i] == 0){
            mx = i;
            break;
        }
    }

    // cout<<"mx : "<<mx<<endl;

    ll tt = mx;
    set<ll> s1;
    vector<ll> ans;

    for(ll i=0;i<n;i++){
        
        if(mx > v[i]){
            s1.insert(v[i]);
        }

        mp[v[i]]--;

        if(mp[v[i]] == 0){
            tt = min(tt,v[i]);
        }

        if(mx == s1.size()){
            ans.push_back(s1.size());
            // cout<<s1.size()<<" ";
            mx = tt;
            s1.erase(s1.begin(),s1.end());
        }
    }

    cout<<ans.size()<<endl;
    for(ll i = 0;i<ans.size();++i){
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