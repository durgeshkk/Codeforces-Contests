#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
    ll a,b,c;cin>>a>>b>>c;
    if(a > b){swap(a,b);}

    ll x = a,y = b;
    if(x == c || y == c){cout<<"YES\n";return;}
    while(a != c && b != c && a != b && max(a, b) >= c && a != 0 && b != 0){
        if(a > b){swap(a,b);}
        ll allowedK = (b / a) + 1;//check if ans is in between while trnasforming 
        // from state of (a,b) to (a-xb,b).
        // cout<<allowedK<<endl;
		if(((b - c) % a == 0) && ((b - c) / a < allowedK)){
            cout<<"YES\n";return;
			break;
		}
        b = b%a;
    }

    cout<<"NO\n";
    return;

/* Second Approach : Some error
    ll val = __gcd(a,b);
    if(c > b){cout<<"NO\n";return;}
    if(c == a || c == b){cout<<"YES\n";return;}
    if(c%val){cout<<"NO\n";}
    else{cout<<"YES\n";}
    return;
*/
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