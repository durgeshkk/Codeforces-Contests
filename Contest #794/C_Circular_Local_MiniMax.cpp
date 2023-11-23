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
    vector<ll> v(n);

    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }

    if(n%2){
        // for(auto it:mp){
        // if(it.second > ((n+1)/2)){
            cout<<"NO\n";
            return;
        // }
    // }
        cout<<"NO\n";
        return;
    }

    ll mx = *max_element(v.begin(),v.end());
    ll mn = *min_element(v.begin(),v.end());

    ll f = 0,ele = -1;
    for(auto it:mp){
        if(it.second > (n/2)){
            cout<<"NO\n";
            return;
        }

        if(it.second == (n/2)){
            f = 1;
            ele = it.first;
            if(ele != mx && ele != mn){
                cout<<"NO\n";
                return;
            }
        }
    }

    sort(v.begin(),v.end());

    ll l = 0,mid = (n/2);

    vector<ll> ans;

    if(f == 1){

        ll ft = 1;
        for(ll i = 0;i<n;i++){
            if(ft == 1){
                ans.push_back(ele);
                ft = 0;
            }
            if(v[i] == ele){
                continue;
            }
            else {
                ans.push_back(v[i]);
                ft = 1;
            }
        }
    }
    else{
        for(ll i = 0;i<n/2;i++){
            ans.push_back(v[l]);
            ans.push_back(v[mid]);
            mid++,l++;
        }
    }
    cout<<"YES\n";
    for(ll i=0;i<n;i++){
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
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}