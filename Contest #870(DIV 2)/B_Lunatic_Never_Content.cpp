#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;

bool isPalin(vector<ll> &v,ll n){
    ll left = 0,right = n-1,f = 1;
    while(left <= right){
        if(v[left++] != v[right--]){
            return 0;
        }
    }
    return 1;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;++i){cin>>v[i];}

    ll daddy = 0;
    if(isPalin(v,n)){
        cout<<daddy<<endl;
        return;
    }

    daddy = abs(v[0]-v[n-1]);
    for(ll i = 0;i<n;++i){
        daddy = __gcd(abs(v[i]-v[n-i-1]),daddy);
    }
    cout<<daddy<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with daddy now
   // use setprecision before daddy
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