#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll x,y,k;
    cin>>x>>y>>k;
    
    ll stick_for_coal = k*y;
    stick_for_coal += k;
    stick_for_coal--;//since ek stick pehle se h toh better remove 1 from overall like 1->42 but from next 1 will give 41 effective

    ll total = stick_for_coal/(x-1);
    ll other = stick_for_coal%(x-1);

    if(other){
        total++;
    }
    
    cout<<total+k<<endl;
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