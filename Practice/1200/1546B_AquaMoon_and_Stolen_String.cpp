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
 
    ll n,m;
    cin>>n>>m;

    vector<string> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll tt = (n-1);
    vector<string> check(tt);
    for(ll i = 0;i<tt;i++){
        cin>>check[i];
    }

/*
    char ans;
    string op;
    map<char,ll> mp;
    for(ll j = 0;j<m;j++){
        ll f = 0;
        for(ll i = 0;i<n;i++){
            mp[v[i][j]]++;
        }

        for(ll i = 0;i<tt;i++){
            mp[check[i][j]]++;
        }

        for(auto it:mp){
            if(it.second == 1){
                ans = it.first;
                op += (it.first);
                // f = 1;
                // break;
            }
        }
        mp.erase(mp.begin(),mp.end());
        // if(f == 1){
        //     break;
        // }
    }

    cout<<op<<endl;
    // for(ll i =0;i<n;i++){
    //     if(v[i][0] == ans){
    //         cout<<v[i]<<endl;
    //         return;
    //     }
    // }*/
    ll cnt[m] = {0};
    for(ll i = 0;i<n;i++){
        for(ll j =0;j<m;j++){
            cnt[j] += v[i][j];//storing ascii value
        }
    }
    
    for(ll i = 0;i<n-1;i++){
        for(ll j =0;j<m;j++){
            cnt[j] -= check[i][j];
        }
    }

    for(ll i : cnt){
        // cout<<i<<" ";
        cout<<char(i);//convert to char directly from ASCII value
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