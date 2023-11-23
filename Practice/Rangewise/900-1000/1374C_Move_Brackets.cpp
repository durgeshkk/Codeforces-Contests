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

    ll count=0,ans=0;
    for(ll i=0;i<s.length();i++){
        if(s[i] == '('){
            count++;
        }
        else if(s[i] == ')' && count<=0){
            ans++;
            // count--;
        }
        else{
            count--;
        }
    }
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
//    solve();
   return 0;
}