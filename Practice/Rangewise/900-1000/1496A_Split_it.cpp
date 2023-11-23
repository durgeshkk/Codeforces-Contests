#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    if(k == 0){
        cout<<"YES\n";
        return;
    }

    ll count = 0;
    for(int i=0;i<s.length()/2;i++){
        if(s[i] == s[n-1-i]){
            count++;
        }
        else{
            break;
        }
    }

    // Now check for len even or odd :
    if(n%2 == 0){
        // Also check k<n/2 for odd since if n=6 k=3 & s=aaaaaa, then string becomes :
        // Left Str :  a a a & middle str remains empty & according to Q it shouldn't!!
        // Right Str : a a a 
        if(k<=count && (k<(n/2))){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        if(k<=count){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
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