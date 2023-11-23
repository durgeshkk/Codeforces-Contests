#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll x0,n;
    cin>>x0>>n;

    if(n == 0){
        cout<<x0<<endl;
        return;
    }

    ll f_pos;

    if(n%4 == 0){
        f_pos = 0;
    }
    else if(n%4 == 1){
        f_pos = -n;
    }
    else if(n%4 == 2){
        f_pos = 1;
    }
    else{
        f_pos = (n+1);
    }

    if(x0&1){//initial position is odd move left
        cout<<-f_pos+x0<<endl;
    }
    else{//initial position is even move right
        cout<<f_pos+x0<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}