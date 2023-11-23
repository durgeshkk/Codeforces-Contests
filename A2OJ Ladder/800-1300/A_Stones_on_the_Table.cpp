#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll count=0;

    for(ll i=0;i<n-1;i++){
        if((s[i]=='R' && s[i+1] == 'R') || 
        (s[i]=='B' && s[i+1] == 'B')
        || (s[i]=='G' && s[i+1] == 'G')){
            count++;
        }
    }
    cout<<count<<endl;
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