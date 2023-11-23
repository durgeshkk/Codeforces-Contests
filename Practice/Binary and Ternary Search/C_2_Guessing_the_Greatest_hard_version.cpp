#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
bool check(ll mid){

}

void solve()
{
 
    ll n;cin>>n;
    cout<<"? "<<1<<" "<<n<<endl;fflush(stdout);ll pos;cin>>pos;

    ll a = 0,b = 0;
    if(pos != 1){
        cout<<"? "<<1<<" "<<pos<<endl;fflush(stdout);cin>>a;
    }
    if(pos != n){
        cout<<"? "<<pos<<" "<<n<<endl;fflush(stdout);cin>>b;
    }

    ll ans = 0;
    if(a == pos){// a & pos in same
        ll l = 1,r = pos-1;
        ans = pos-1;
        if(l == r){
        }else{
            while(l <= r){
                ll mid = (l+r)/2;
                cout<<"? "<<mid<<" "<<pos<<endl;fflush(stdout);cin>>b;
                if(b == pos){
                    ans = mid;
                    l = mid+1;
                }else{
                    r = mid-1; 
                }
            }
        }
        cout<<"! "<<ans<<endl;
        fflush(stdout);
    }else{
        // b & pos in same
        ll l = pos+1,r = n;
        ans = pos+1;
        if(l == r){
        }else{
            while(l <= r){
                ll mid = (l+r)/2;
                
                cout<<"? "<<pos<<" "<<mid<<endl;fflush(stdout);cin>>b;
                if(b == pos){
                    ans = mid;
                    r = mid-1; 
                }else{
                    l = mid+1;
                }
            }
        }
        cout<<"! "<<ans<<endl;
        fflush(stdout);
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}