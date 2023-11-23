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

    ll count1=0,count0 = 0;

    for(ll i=0;i<s.length();i++){
        /*
        if(s[i]=='0' && s[i+1] == '1'){
            count01;
            i++;
        }
        else if(s[i]=='1' && s[i+1] == '0'){
            i++;
            count10++;
        }*/
        if(s[i] == '1'){
            count1++;
        }
        else{
            count0++;
        }
    }

    ll ans = min(count0,count1);
    if(ans%2==0){
        cout<<"NET\n";
    }
    else{
        cout<<"DA\n";
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
   return 0;
}