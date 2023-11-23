#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

// Sohan :
/*
void solve()
{
 
    ll n;ll k;
    cin>>n;cin>>k;
    
    if(n & 1){
        cout<<1<<" ";
        n--;--k;
    }

    if(k == 3){
        if(n & 1){
            cout<<1<<" "<<n/2<<" "<<n/2<<endl;
        }else{
            if(n%4 == 0){
                cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
                return;
            }
            n -= 2;
            cout<<2<<" "<<n/2<<" "<<n/2<<endl;
        }
        return;
    }


    ll f= 0; 
    if((k) & 1){
        n -= 2;
        cout<<2<<" ";
        --k;

        ll val = (n-k+2)/2;
        if(val&1){
            cout<<val-1<<" "<<val-1<<" ";
            cout<<2<<" "<<2<<" ";
            n -= 4;
            n -= (2*val-2);
            k-=4;
        }else{
            cout<<val<<" "<<val<<" ";
            n -= (2*val);
            k -= 2;
        }

        for(ll i = 0;i<k;++i){
            cout<<1<<" ";
        }
        cout<<endl;
    }else{
        for(ll i = 0;i<k-2;++i){
            cout<<1<<" ";
        }
        n -= (k-2);
        cout<<n/2<<" "<<n/2<<endl;
    }

    return;
}
 */

// ME :
void solve()
{
 
    ll n;cin>>n;ll k;cin>>k;

    if(n & 1){
        cout<<1<<" ";
        --n,--k;
    }
    
    if(k == 3){
        if(n & 1){
            cout<<1<<" "<<n/2<<" "<<n/2<<endl;
        }else{
            if(n%4 == 0){
                cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;
            }else{
                cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
            }
        }
        return;
    }

    if(k&1){
        cout<<2<<" ";
        n -= 2;--k;

        ll val = (n-k+2)/2;
        if(val & 1){
            cout<<(val-1)<<" "<<(val-1)<<" ";
            cout<<2<<" ";
            cout<<2<<" ";
            k -= 4;
        }else{
            cout<<(val)<<" "<<(val)<<" ";
            cout<<1<<" "<<1<<" ";
            k -= 4;
        }

        for(ll i = 0;i<k;++i){
            cout<<1<<" ";
        }cout<<endl;
    }else{
        for(ll i = 0;i<k-2;++i){
            cout<<1<<" ";
        }
        ll val = (n-k+2);
        cout<<val/2<<" "<<val/2;
        cout<<endl;
    }
    return;
}
 

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
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