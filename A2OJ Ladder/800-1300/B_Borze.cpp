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

    ll i=0;
    for(i;i<s.length()-1;i++){
        if(s[i] == '.'){
            cout<<0;
        }
        else if(s[i] == '-' && s[i+1] == '.'){
            cout<<1;
            i++;
        }
        else if(s[i] == '-' && s[i+1] == '-'){
            cout<<2;
            i++;
        }
    }
    if(s[s.size()-1] == '.' && i<s.size()){
        cout<<0;
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
       solve();
//    }
   return 0;
}