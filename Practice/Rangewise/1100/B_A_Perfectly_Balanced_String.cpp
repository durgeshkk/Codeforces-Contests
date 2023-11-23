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
    string s;
    cin>>s;

    ll n;
    n = s.size();
/*
    map<char,ll> mp;
    for(ll i = 0;i<n;i++){
        mp[s[i]]++;
    }

    ll t = mp.size();
    if(mp.size()==n || (mp.size()==1)){
        cout<<"YES\n";
        return;
    }

    cout<<t<<endl;
    
    string st;
    map<char,ll> mt;
    for(ll i = 0;i<t;i++){
        st += s[i];
        mt[st[i]]++;
    }

    cout<<st<<endl;
    
    if((mt.size() != t)){
        // cout<<"HI\n";
        cout<<"NO\n";
        return;
    }

    ll idx = 0;
    string subs;
    for (ll i = t; i <n;)
    {
        if((i+t) >= n){
            break;
        }
        else{
            subs.substr(i,i+t);
        }
        if(subs == st){
        }
        else{
            // cout<<"HI\n";
            cout<<"NO\n";
            return;
        }
        cout<<subs<<endl;
        idx = i;
        if((i+t) >= n){
            break;
        }
        else{
            i += t;
        }
    }

    cout<<idx<<endl;

    if(idx < n){
        ll j=0;
        for(ll i=idx; i<n;i++,j++){
            if(s[i] != st[j]){
                // cout<<"HI\n";
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";*/
    
    set<char> c;

    ll idx = 0;
    for(ll i =0;i<n;i++){
        if(c.find(s[i]) == c.end()){
            c.insert(s[i]);
            idx = i;
        }
        else{
            break;
        }
    }

    idx++;
    // cout<<idx<<endl;
    for(ll i = idx;i<n;i++){
        // cout<<s[i]<<" "<<s[i-idx]<<endl;
        if(s[i] != s[i-idx]){
            cout<<"NO\n";
            return;
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
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}