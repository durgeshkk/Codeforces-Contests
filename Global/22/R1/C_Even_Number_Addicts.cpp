//CELEBRATING SEMIANNIVERSARY OF DADDY_DYNAMO!!
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    ll o = 0,e = 0;
    ll z =0;

    for(ll i=0;i<n;i++){
        ll val;
        cin>>val;
        if(val < 0){
            v[i] = abs(val);
        }else{
            v[i] = val;
        }

        if(v[i] == 0){
            ++z;
            continue;
        }
        if(v[i] & 1){
            ++o;
        }else{
            ++e;
        }
    }

    if((o%4 == 3) || (o%4 == 0)){
        cout<<"Alice\n";
    }else if((o%4 == 2)){
        cout<<"Bob\n";
    }else{
        if(z & 1){
            if(e%4 ==  1 || e%4 == 3){
                cout<<"Bob\n";
            }
            else{
                cout<<"Alice\n";
            }
        }
        else{
            if(e%4 ==  1 || e%4 == 3){
                cout<<"Alice\n";
            }else{
                cout<<"Bob\n";
            }
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}

/*
        else{
            if(o & 1){
                if(e%4 ==  1 || e%4 == 3){
                    cout<<"Bob\n";
                }else{
                    cout<<"Alice\n";
                }
            }else{
                if(e%4 == 1){
                    cout<<"Alice\n";
                }else{
                    cout<<"Bob\n";
                }
            }
        }
        */
