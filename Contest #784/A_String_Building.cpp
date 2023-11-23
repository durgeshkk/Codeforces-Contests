#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
 /*
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
    string s;
    cin>>s;

    ll count_a = 0,count_b=0;

    for(ll i=0;i<s.length();i++){
        if(s[i] == 'a'){
            count_a++;
        }
        else{
            count_b++;
        }
    }

    if(count_a == 1 || count_b == 1){
        cout<<"NO\n";
        return;
    }

    if((s[0] == 'a' && s[1] == 'b') || (s[0] == 'b' && s[1] == 'a')){
        cout<<"NO\n";
        return;
    }

    if((s[s.size()-1] == 'a' && s[s.size()-2] == 'b') || (s[s.size()-1] == 'b' && s[s.size()-2] == 'a')){
        cout<<"NO\n";
        return;
    }

    for(ll i=0;i<s.size()-2;i++){
        if((s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a') || (s[i] == 'b' && s[i+1] == 'a' && s[i+2] == 'b')){
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
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}