#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll a,b,c;
    cin>>a>>b>>c;

    if(c>a){
        cout<<1<<" ";
    }
    else{
        cout<<-1<<" ";
    }

    if(b*a >c){
        cout<<b;
    }
    else{
        cout<<-1;
    }
    cout<<endl;
    
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