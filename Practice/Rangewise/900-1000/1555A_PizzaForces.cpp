#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;
/*
    if(n%6 == 0){
        cout<<(n/6)*15<<endl;
    }
    else if(n%8 == 0){
        cout<<(n/8)*20<<endl;
    }
    else if(n%10 == 0){
        cout<<(n/10)*25<<endl;
    }
    else{
        
        // ll pack_6 = ceil(1.0*n/6);
        // ll pack_8 = ceil(1.0*n/8);
        // ll pack_10 = ceil(1.0*n/10);

        // ll ans_6 = pack_6*15;
        // ll ans_8 = pack_8*20;
        // ll ans_10 = pack_10*25;

        // ll ans = min(ans_10,min(ans_6,ans_8));
        // cout<<ans<<endl;

        ll pack_6 = 0;

        while(n >= 0)
        {
            ll ans = (pack_6*15);
            if(n%6 == 0){
                cout<<((n/6)*15)+ans<<endl;
                return;
            }
            else if(n%8 == 0){
                cout<<((n/8)*20)+ans<<endl;
                return;
            }
            else if(n%10 == 0){
                cout<<((n/10)*25)+ans<<endl;
                return;
            }
            else{
                // if(n > 10){
                //     n -= 10;
                //     pack_10++;
                // }
                // else if(n > 8){
                //     n -= 8;
                //     pack_8++;
                // }
                // else{
                    pack_6 += ceil(1.0*n/6);
                    n = (n%6);
                    // pack_6++;
                // }
            }
        }
        ll ans = (pack_6*15);
        cout<<ans<<endl;
    }*/

    if(n <= 6){
        cout<<15<<endl;
        return;
    }
    if(n%2 == 0){
        ll ans = (n/2)*5;
        cout<<ans<<endl;
    }
    else{
        ll ans = ((n+1)/2)*5;
        cout<<ans<<endl;
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