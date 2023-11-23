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
    map<ll,ll> mp;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }

    for(auto it:mp){
        if(it.second < 2){
            cout<< -1<<endl;
            return;
        }
    }

    // ll prev = mp[v[0]];
    vector<ll> freq;
    set<ll> s;
    for(auto it:mp){
        freq.push_back(it.second);
        s.insert(it.second);
    }
    
/*
    for(ll i = 1;i<freq.size();i++){
        freq[i] = (freq[i]+freq[i-1]);
    }

    for(ll i=0;i<freq.size();++i){
        s.insert(freq[i]);
    }
*/
    vector<ll> ans(n);
    ans[0] = freq[0];

    ll j = 0;
    ll prev = freq[j]-1;
    ll f = freq[0];
    for(ll i=1;i<n;i++){

        if(prev > 0){
            prev--;
            continue;
        }
        else{
            j++;
            prev = freq[j]-1;
            ans[i] = f+freq[j];
            f = ans[i];
        }

    }

    set<ll> st;
    for(ll i =0 ;i<n;++i){
        if(ans[i] != 0){
            st.insert(ans[i]);
        }
    }

    j = 1;
    for(ll i = 0;i<n;++i){
        if(ans[i] == 0){
            if(st.find(j) != st.end()){
                j++;
                // continue;
            }
            ans[i] = j;
            j++;
        }
    }
/*
        if(i == prev){
            continue;
        }
        else if(i>prev){
            j++;
            prev = freq[j];
            ans[i-1] = prev;
            i++;
        }

        ans[i-1] = i;
        // ll t = mp[v[i]];
        // ans[i] = mp[v[i]];
    }*/

    for(ll i= 0;i<n;i++){
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