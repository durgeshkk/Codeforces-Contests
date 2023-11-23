#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    if(n == m){
        cout<<0<<endl;
        return;
    }
    else if((n == 1 && m%2 != 0) || (m == 1 && n%2 != 0)){
        cout<<-1<<endl;
        return;
    }

    ll a = min(n,m);
    ll b = max(n,m);

    // cout<<a<<" "<<b<<endl;
    if(b%a == 0){
        /*TLE
        ll count2=0;

        while(1){
            if(a == b){
                break;
            }
            a = a*2;
            count2++;
        }

        ll num_8 = count2/3;
        ll remain_2 = count2%3;

        ll num_4 = remain_2/2;
        remain_2 = remain_2%2;

        ll num_2 = remain_2;*/

        ll ans = b/a;

        ll total = 0;

        while(ans%8 == 0){
            total++;
            ans /= 8;
        }  
        
        while(ans%4 == 0){
            total++;
            ans /= 4;
        }  

        while(ans%2 == 0){
            total++;
            ans /= 2;
        }  

        if(ans != 1){
            cout<<-1<<endl;
            return;
        }
        cout<<total<<endl;
    }
    else{
        cout<<-1<<endl;
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
//    solve();
   return 0;
}