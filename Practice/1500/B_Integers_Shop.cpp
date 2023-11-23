#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;
    cin>>n;

    ll ans = 0;
    ll f = 0;
    ll mn = LLONG_MAX,mx = LLONG_MIN;
    map<ll,ll> mp;
    map<ll,ll> mnmp;

    while(n--){
        ll a,b;
        cin>>a>>b;
        ll c;
        cin>>c;

        if(mnmp.find(a) != mnmp.end()){
            ll ag = mnmp[a];
            mnmp[a] = min(c,ag);
        }
        else{
            mnmp[a] = c;
        }
        
        if(mnmp.find(b) != mnmp.end()){
            ll ag = mnmp[b];
            mnmp[b] = min(c,ag);
        }
        else{
            mnmp[b] = c;
        }

        if(a < mn && b > mx){
            f = 1;
            mn = a,mx = b;
            mp[mn] = c;
            mp[mx] = c;
        }

        else if(a == mn && b == mx){
            ll z;
            z = mp[mn];
            if(f & 1){
            }
            else{
                z += mp[mx];
            }

            if(z >= c){
                f = 1;
                mp[mn] = c;
                mp[mx] = c;
            }
        }
        else if(a < mn){
            mn = a;
            if(b == mx){
                f = 1;
                mp[mx] = c;
            }
            else{
                f = 0;
            }
            mp[a] = c;
        }
        else if(b > mx){
            mx = b;
            if(a == mn){
                f = 1;
                mp[mn] = c;
            }
            else{
                f = 0;
            }
            mp[b] = c;
        }

        if(f == 0){
            if(a == mn){
                ll z = mp[a];
                if(z >= c){
                    mp[mn] = c;
                }
            }

            if(b == mx){
                ll z = mp[b];
                if(z >= c){
                    mp[mx] = c;
                }
            }
        }

        if(f & 1){
            ll val = mnmp[mn] + mnmp[mx];
            ans = min(mp[mn],val);
        }
        else{
            ans = mnmp[mn]+mnmp[mx];
            // ans = mp[mn]+mp[mx];
        }
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
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}

/*
ll n;
    cin>>n;

    // n--;
    ll mn = LLONG_MAX;
    ll mx = LLONG_MIN;
    ll cmin = 0,cmax = 0;
    ll ans = 0;
    while(n--){
        ll a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b<<endl;

        ll cst;
        cin>>cst;
        // cout<<cst<<endl;

        if(mx < b){
            // cout<<"HI\n";

            // Update & include in set
            mx = b;
            cmax = cst;

            if(a < mn){
                // cout<<"a\n";
                mn = a;
                cmin = cst;
                ans = cst;
            }
            else if(a == mn){
                cmin = a;
                ans = cst;
            }
            else{ //a>mn
                ans = cmax+cmin;
            }
            
        }

        else if(mx == b){
            // Keep cheap
            if(a < mn){
                mn = a;
                cmin = cst;
                cmax = cst;
                ans = cst;
            }
            else if(a == mn){
                cmin = min(cmin,cst);
                cmax = min(cmax,cst);
                ans = min(cmin,cmax);
            }
            else{ //a>mn
                ans = min(ans,cst+cmin);
            }
        }
        else{
            // Don't do anything
            if(a < mn){
                cmin = cst;
                ans = cmin+cmax;
                mn = a;
            }
            else if(a == mn){

            }
            else{ //a>mn

            }
        }
        cout<<ans<<endl;
            continue;
        }
        else if(a > mn && b>mx){

        }
        else if(a < mn && b > mx){
            mn = a,mx = b;
            ans = cst;
        }
        else if(a < mn && b < mx){

        }
        else{ // a == mn && b == mx

        }


        if(mn > a){
            // Update
            mn = a;
            if(b == mx){
                cout<<cmin<<endl;
                continue;
            }
            cmin = cst;
        }
        else if(mn == a){
            // Keep cheap
            cmin = min(cmin,b);
        }
        else{
            // Don't do anything
        }


        if(mx < b){
            // Update & include in set
            mx = b;
            if(a == mn){
                cout<<cmax<<endl;
                continue;
            }
            cmax = cst;
        }
        else if(mx == b){
            // Keep cheap
            cmax = min(cmax,b);
        }
        else{
            // Don't do anything

        }

        ll ans = cmin+cmax;
    }
 */
/*
cout<<s.size()<<" ";
        if(s.size() == 0){
            s.insert({a,b});
            mp[{a,b}] = c;
            ans = c;
        }
        else if(s.size() == 1){
            pair<ll,ll> p1 = *s.begin();
            if(a == p1.first && b == p1.second){
                ll cst1 = mp[p1];

                if(cst1 <= c){

                }
                else{
                    s.clear();
                    mp.clear();
                    s.insert({a,b});
                    mp[p1] = c;
                }
            }
            else if(a <= p1.first && b >= p1.second){
                s.clear();  
                mp.clear();
                s.insert({a,b});
                mp[{a,b}] = c;
            }
            else if(a < p1.first){
                s.insert({a,b});
                mp[{a,b}] = c;
            }
            else if(b > p1.second){
                s.insert({a,b});
                mp[{a,b}] = c;
            }

            pair<ll,ll> p = *s.begin();
            ans = mp[p];
            if(s.size() == 2){
                p = *s.rbegin();
                ans += mp[p];
            }
        }
        else{
            pair<ll,ll> f = *s.begin();
            pair<ll,ll> r = *s.rbegin();
            ll cst = mp[f]+mp[r];


            if(b == r.second && a == f.first){
                if(cst >= c){
                    s.clear();
                    s.insert({a,b});
                    mp[{a,b}] = c;
                }
                else{

                }
            }
            else if(b > r.second){
                s.erase(*s.rbegin());
                s.insert({a,b});
                mp[{a,b}] = c;
            }
            
            else if(a < f.first){
                s.erase(*s.begin());
                s.insert({a,b});
                mp[{a,b}] = c;
            }

            else if(b == r.second){
                ll z = mp[*s.rbegin()];

                if(z <= c){

                }
                else{
                    s.erase(*s.rbegin());
                    s.insert({a,b});
                    mp[{a,b}] = c;
                }
            }
            else if(a == f.first){
                ll z = mp[*s.begin()];

                if(z <= c){

                }
                else{
                    s.erase(*s.begin());
                    s.insert({a,b});
                    mp[{a,b}] = c;
                }

            }
            else if(b > r.second && a < f.first){
                s.clear();
                s.insert({a,b});
                mp[{a,b}] = c;
            }
            

            pair<ll,ll> p = *s.begin();
            ans = mp[p];
            if(s.size() == 2){
                p = *s.rbegin();
                ans += mp[p];
            }
        }
        
*/