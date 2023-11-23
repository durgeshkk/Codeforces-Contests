#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    
    cout<<2<<endl;

    if(n == 2){
        cout<<1<<" "<<2<<endl;
    }
    else{
        cout<<n-2<<" "<<n<<endl;
        cout<<n-1<<" "<<n-1<<endl;

        ll t=n-3,m = n-1;
        while(t>0){
            cout<<m<<" "<<t<<endl;
            t--,m--;
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
   //solve();
   return 0;
}