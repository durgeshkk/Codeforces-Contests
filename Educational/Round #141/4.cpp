#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
map<pair<ll,ll>,ll> mp;
ll recur(string &s,ll idx,ll n,char prev){
    if(idx >= n){
        return 0;
    }

    if(mp.find({idx,prev-'0'}) != mp.end()){
        return mp[{idx,prev-'0'}];
    }

    ll a = LLONG_MAX,b = LLONG_MAX;
    if(prev == '0'){
        if(s[idx] =='0'){
            // Flip
            a = 1+recur(s,idx+1,n,'1');
            // Not Flip 
            b = recur(s,idx+1,n,'0');
        }else{
            // Flip
            a = 1+recur(s,idx+1,n,'0');
            // Not Flip 
            b = recur(s,idx+1,n,'1');
        }
    }else{
        // prev = 1
        if(s[idx] =='0'){
            // Flip
            a = 1+recur(s,idx+1,n,'1');
        }else{
            a = recur(s,idx+1,n,'1');
        }
    }
    return mp[{idx,prev-'0'}] = min(a,b);
}

void solve()
{
    mp.clear();
    ll n;cin>>n;
    string s;cin>>s;
    ll ans = recur(s,0,n,'0');
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
   return 0;
}