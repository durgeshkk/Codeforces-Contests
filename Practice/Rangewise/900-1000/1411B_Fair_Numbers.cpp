#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{

    ll n;
    cin>>n;

    while(1){
        ll n1 = n;

        while(n1 > 0){
            ll rem = n1%10;

            if(rem != 0 && n%rem != 0){
                break;
            }
            n1 /= 10;
        }

        if(n1 == 0){
            cout<<n<<endl;
            return;
        }
        n++;
    }
    // cout<<s<<endl;
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