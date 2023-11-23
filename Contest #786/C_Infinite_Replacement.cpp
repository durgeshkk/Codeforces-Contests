#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    string s,t;
    cin>>s>>t;

    if(t.length() == 1){
        if(t[0] == 'a'){
            cout<<1<<endl;
        }
        else{
            ll ans = pow(2,s.length());
            cout<<ans<<endl;
        }
        return;
    }

    for(ll i=0;i<t.length();i++){
        if(t[i] == 'a'){
            cout<<-1<<endl;
            return;
        }
    }

    ll ans = pow(2,s.length()); 
    cout<<ans<<endl;

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