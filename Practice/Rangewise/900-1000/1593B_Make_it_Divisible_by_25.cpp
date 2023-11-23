#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    if(n%25 == 0){
        cout<<0<<endl;
        return;
    }

    ll count = 0;
    ll f5=0,f0=0;
    ll prev_rem = 0;

    while(n != 0){
        ll rem = n%10;

        if(rem == 5 && (f5 == 0) && (f0 == 0)){
            f5 = 1;
        }
        else if(rem == 0 && (f0 == 0)){
            f0 = 1;
        }
        else if(f5 == 1 && (rem == 2 || rem == 7)){
            cout<<count+f0<<endl;
            return;
        }
        else if(f0 == 1 && (rem == 0 || rem == 5)){
            cout<<count+f5<<endl;
            return;
        }
        else{
            count++;
        }
        n /= 10;
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