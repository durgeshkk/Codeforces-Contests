#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    string s;
    cin>>s;

    if(s[0] == ')' || ((s.length()%2)!= 0) || (s[s.size()-1] == '(')){
        cout<<"NO\n";
        return;
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
   //solve();
   return 0;
}