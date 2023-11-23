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

ll cnt = 0;
ll ans = LLONG_MAX;
ll dfs(ll i,vector<ll> &v, ll sm){

    if(i == 56){
        return 0;
        ans = min(ans,cnt);
    }

    // Pick
    ll a = LLONG_MAX;
    if(sm-v[i] >= 0){
        ++cnt;
        if(sm == v[i]){
            ans = min(ans,cnt);
        }
        a = dfs(i+1,v,sm-v[i]);
        --cnt;
    }

    // Not Pick
    ll b = dfs(i+1,v,sm);
}

void solve(vector<ll> &v){
    cnt = LLONG_MAX;
    ll n;
    cin>>n;

    dfs(0,v,n);
    if(cnt == 56){
        cout<< -1 <<endl;
    }
    else{
        cout<<ans<<endl;   
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
    set<ll> s;
    for(ll i = 1;i<1e13;i*=2){
        s.insert(i);
    }

    vector<ll> fac = {1,2,6,24,120,720,5040,40320,362880,
    39916800,479001600,6227020800,87178291200,130767436800};
    
    for(ll i = 0;i<fac.size();++i){
        s.insert(fac[i]);
    }

    vector<ll> v(s.begin(),s.end());
    cout<<s.size()<<endl;
   while (t--)
   {
       solve(v);
   }
   /*
    for(auto it:s){
        cout<<it<<" ";
    }
    cout<<endl;
*/

   //solve();
   return 0;
}

/*
    ll ans = 0;
    bitset<42> st(n);
    for(ll i=0;i<42;i++){
        if(st[i] == 1){
            ans++;
        }
    }

    if(ans == 1){
        cout<<1<<endl;
        return;
    }
 
    ll ans2 = 0;
    if(n & 1){
        ans2++;
        --n;
    }

    ans = INT16_MAX;
    ll mn = INT16_MAX;
    ll prev = -1;
    while(n > 0){
        ll val = lower_bound(v.begin(),v.end(),n)-v.begin();
        cout<<"val : "<<val<<endl;
        // if(prev  == val){
        //     val--;
        // }

        // prev = val;
        cout<<"prev : "<<prev<<endl;
        ans2++;
        if(v[val] == n && prev != val){
            mn = ans2;
            break;
        }
        else{
            val--;
            n -= v[val];
            cout<<" n : "<<n<<endl;

            bitset<44> st(n);
            cout<<" st : "<<st<<endl;
            ll ak = 0;
            for(ll i = 0;i<44;++i){
                if(st[i] == 1){
                    ++ak;
                }
            }
            mn = min(mn,ans2+ak);
            cout<<"mn "<<mn<<endl;
        }
        prev = val;
        cout<<"----->\n";
    }

    ll dk = min(mn,ans);
    cout<<dk<<endl;
    */
    /*
    4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 130767436800*/
