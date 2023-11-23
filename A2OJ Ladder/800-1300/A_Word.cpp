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

    if(s.length() == 1){
        cout<<s<<endl;
        return;
    }
    
    ll U_case=0,l_case=0;
    for(ll i=0;i<s.length();i++){
        if(s[i] >='a'  && s[i]<= 'z'){
            l_case++;
        }
        else{
            U_case++;
        }
    }

    if(U_case > l_case){
        for(ll i=0;i<s.length();i++){
            if(s[i] >='a'  && s[i]<= 'z'){
                s[i] -= 32;
            }
        }
    }
    else{
        for(ll i=0;i<s.length();i++){
            if(s[i] >='A'  && s[i]<= 'Z'){
                s[i] += 32;
            }
        }
    }

    cout<<s<<endl;
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
//        solve();
//    }
   solve();
   return 0;
}