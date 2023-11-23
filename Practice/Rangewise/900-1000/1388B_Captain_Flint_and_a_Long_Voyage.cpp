#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    
    ll num_zeroes = (n+3)/4;
    string s = "";
        for(int i=0;i<n-num_zeroes;i++){
            s += "9";
        }
        
        for(int i=0;i<num_zeroes;i++){
            s += "8";
        }
    cout<<s<<endl;
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