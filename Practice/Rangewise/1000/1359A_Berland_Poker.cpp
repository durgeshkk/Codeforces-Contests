#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m,k;
    cin>>n>>m>>k;

    if(m == 0){
        cout<<0<<endl;
        return;
    }

    ll card_per_player = n/k;

    if(card_per_player >= m){
        cout<<m<<endl;
    }
    else{
        ll give_1_max = card_per_player;
        ll remain_joker = m-card_per_player;

        ll min_deno = ceil(1.0*remain_joker/(k-1));
        cout<<give_1_max-min_deno<<endl;
        /*
        if((2*card_per_player) < m){
            cout<<0<<endl;
        }
        else{
            ll give_1_max = card_per_player;

            if(give_1_max == 1){
                cout<<0<<endl;
                return;
            }
            if(n-1 > remain_joker){
                cout<<give_1_max<<endl;
            }
            else if(n-1 == remain_joker){
                cout<<give_1_max-1<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }*/
    }
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
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
   return 0;
}