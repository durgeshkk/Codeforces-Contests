#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    string s;
    cin>>s;

    map<char,ll> mp;
    for(ll i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    ll mn = INT16_MAX,mx=INT16_MIN;
    for(ll i=0;i<s.size();i++){
        if(mp[s[i]] < mn){
            mn = mp[s[i]];
        }
        
        if(mp[s[i]] > mx){
            mx = mp[s[i]];
        }
    }

    if(mx-mn >= 2){
        cout<<"NO\n";
        return;
    }
    else if(mx-mn == 1){
        ll f=0;
        ll count = 0;
        map <char,ll> mpi;

        for(ll i=0;i<s.size();i++){
            if(mp[s[i]] == mx && f==0){
                f = 1;
            }
            else if(mp[s[i]] == mx && f == 1){
                if(mpi.size() == mp.size()-1){
                    cout<<"YES\n";
                    return;
                }
            }
            else if(f == 1){
                mpi[s[i]]++;
            }
        }
        cout<<"NO\n";
    }
    else{//mx == mn
        ll f = 0;
        for(ll i=0;i<mp.size();i++){
            if(mp[s[i]] != 1){
                f = 1;
            }
        }
        if(f == 0){
            cout<<"YES\n";
            return;
        }

        ll j = s.size()/2;
        for(ll i=0;i<s.size()/2;i++,j++){
            if(s[i] != s[j]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}