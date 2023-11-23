#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);

    multiset<ll> l,r;
    ll mn1 = v[0];
    ll mn2 = v[1];
    ll c1 = v[0], c2 = v[1];
    ll a=1,b=1;

    ll mn = (v[0]+v[1])*n;
/*
    for(ll i=0;i<n;i++){

        if(i & 1){
            if(r.size() <= 1){
                r.insert(v[i]);
            }
            else{
                ll val = *r.begin();
                if(val <= v[i]){
                    ll z = *r.rbegin();
                    r.erase(*r.rbegin());
                    z += v[i];
                    r.insert(z);
                }
                else{
                    ll z = *r.rbegin();
                    r.erase(*r.rbegin());
                    z += val;
                    r.insert(z);
                    r.insert(v[i]);
                }
            }
        }
        else{

            if(l.size() <= 1){
                l.insert(v[i]);
            }
            else{
                ll val = *l.begin();
                if(val <= v[i]){
                    ll z = *l.rbegin();
                    l.erase(*l.rbegin());
                    z += v[i];
                    l.insert(z);
                }
                else{
                    ll z = *l.rbegin();
                    l.erase(*l.rbegin());
                    z += val;
                    l.insert(z);
                    l.insert(v[i]);
                }
            }
        }

        if(l.size() == 1 && r.size() == 0){
            continue;
        }

        if(l.size() == 1 && r.size() == 1){
            continue;
        }

        ll ans1 = 0;
        ll idx = i/2;
        idx = (n-idx);
        ll val1 = (*l.begin());
        ll val2 = (*l.rbegin());
        ans1 = val2 + (val1*idx);

        ll ans2 = 0;
        ll idx2 = (i-1)/2;
        idx2 = (n-idx2);
        ll val3 = (*r.begin());
        ll val4 = (*r.rbegin());
        ans2 = val4*(n-idx2) + (val3*idx2);

        if(r.size() == 1){
            ans2 = (val3*n);
        }

        ll mx = (ans1+ans2);
        if(mx < mn){
            mn = mx;
        }
    }*/
    
    for (ll i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            mn1 = min(mn1, v[i]);
            c1 += v[i];
            a++;
        }
        else
        {
            mn2 = min(mn2, v[i]);
            c2 += v[i];
            b++;
        }
        mn = min(mn, mn1 * (n - a + 1) + (c1 - mn1) + mn2 * (n - b + 1) + (c2 - mn2));
    }

    cout<<mn<<endl;
 
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
   ll i = 1;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}