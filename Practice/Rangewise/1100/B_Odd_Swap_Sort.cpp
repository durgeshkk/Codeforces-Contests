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
    vector<ll> s1;
    vector<ll> s2,odd,even;

    for(ll i=0;i<n;i++){
       cin>>v[i];

       if(v[i]%2){
           odd.push_back(v[i]);
           s1.push_back(v[i]);
       }
       else{
           even.push_back(v[i]);
           s2.push_back(v[i]);
       }
    }

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    if(is_sorted(v.begin(),v.end())){
        // cout<<"HI\n"s;
        cout<<"Yes\n";
        return;
    }

    for(ll i = 0;i<s1.size();i++){
        if(s1[i] != odd[i]){
            cout<<"No\n";
            return;
        }
    }
    
    for(ll i = 0;i<s2.size();i++){
        if(s2[i] != even[i]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
/*
    ll idx = 0;
    for(ll i = 0;i<n;i++){
        if(s[i] != v[i]){
            idx = i;
            break;
        }
    }

    // cout<<idx<<endl;

    ll ele = (v[idx]%2);
    ll odd = 0,even = 0;

    for(ll i = idx+1;i<n;i++){

        if(is_sorted(v.begin()+idx+1,v.end())){
        }
        else{
            cout<<"No\n";
            return;
        }
        if(v[i]%2){
            odd++;
        }
        else{
            even++;
        }
    }

    ll num = n-(idx+1);

    if(ele%2){//ele is odd toh sab even chahiye
        if(even == num){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{//ele is even toh sab odd chahiye
        if(odd == num){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }*/
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