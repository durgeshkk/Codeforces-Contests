#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll r,g,b,w;
    cin>>r>>g>>b>>w;

    ll num_odds = 0;
    ll mn = min(r,min(g,b));

    if(r%2){
        num_odds++;
    }
    if(g%2){
        num_odds++;
    }
    if(b%2){
        num_odds++;
    }
    if(w%2){
        num_odds++;
    }

    if(num_odds <= 1){
        cout<<"Yes\n";
    }
    else if(mn != 0){
        r--,g--,b--;
        w--; //has same effect as w+=3;
        num_odds=0;
        if(r%2){
            num_odds++;
        }
        if(g%2){
            num_odds++;
        }
        if(b%2){
            num_odds++;
        }
        if(w%2){
            num_odds++;
        }
        if(num_odds <= 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{
        cout<<"No\n";
    }
        /*

    while(mn>0){
        num_odds = 0;
        mn = min(r,min(g,b));
        if(r%2){
            num_odds++;
        }
        if(g%2){
            num_odds++;
        }
        if(b%2){
            num_odds++;
        }
        if(w%2){
            num_odds++;
        }

        if(num_odds <= 1){
            cout<<"Yes\n";
            return;
        }

        r--;
        b--;
        g--;
        w += 3;
    }

    if(r%2 == 0 && )
    cout<<"No\n";
    return;*/

 
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