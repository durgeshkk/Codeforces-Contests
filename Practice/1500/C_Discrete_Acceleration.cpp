#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
    ll f, r;
    cin >> f >> r;
 
    vector<ll> v(f);
    enter(v);

    double l = 0, d2 = r;
    ll i = 0;
    ll j = f - 1;
    ll s1 = 1, s2 = 1;
    double ans = 0;
    while (i <= j && i < f && j >= 0)
    {
        double a = (v[i] - l) / double(s1);
        double b = (d2 - v[j]) / double(s2);

        if (a < b){
            l = v[i];
            ans += a;
            s1++;
            d2 -= s2 * a;
            i++;
        }
        else if (a > b){
            d2 = v[j];
            ans += b;
            s2++;
            l += s1 * b;
            j--;
        }
        else
        {
            l = v[i];
            d2 = v[j];
            i++;
            j--;
            s1++;
            s2++;
            ans += a;
        }
    }
    double t = max(0.0, d2 - l);
    ans += (t / double(s2 + s1));
 
    cout << fixed << setprecision(20) << ans << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   setprecision(20);// also use precision with ans now
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
void solve()
{
 
    ll n;
    cin>>n;

    ll dist;
    cin>>dist;

    vector<ll> v(n);
    enter(v);
 
    set<ll> s(v.begin(),v.end());

    double l = 0,r = dist;
    double vf = 1, vb = 1;
    double tym = 0;
    double mn = 1e9;
    // cout<<mn<<endl;

    while(!s.empty()){
        ll f = *s.begin();
        ll b = *s.rbegin();
        
        if(s.size() == 1){
            ll df = (f-l);
            ll db = (r-b);

            double a = (1.0*db/vb);
            double ag = (1.0*df/vf);

            if(a > ag){
                tym += ag;
                double da = (b*vf);
                l += da;
                r -= (da);
                ++vf;
                // s.insert(db);
            }
            else if(a == ag){
                tym += ag;
                double da = (ag*vf);
                l += da;
                r -= (da);
                ++vb;++vf;
            }
            else{
                tym += a;
                double da = (a*vb);
                l += da;
                r -= (da);
                ++vb;
                // s.insert(df);
            }

            double remdist = (r-l);
            double rels = (vf+vb);
            double reqt = (remdist/rels); 
            mn = min(mn,tym+reqt);
            break;
        }

        s.erase(*s.begin());
        s.erase(*s.rbegin());
        
        ll df = (f-l);
        ll db = (r-b);

        double a = (1.0*db/vb);
        double ag = (1.0*df/vf);
        cout<<ag<<" "<<a<<" ";

        if(a > ag){
            tym += ag;
            double da = (b*vf);
            double dz = (b*vb);
            l += da;
            r -= (da);
            ++vf;
            s.insert(db);
        }
        else if(a == ag){
            tym += ag;
            double da = (ag*vf);
            double dz = (ag*vb);
            l += da;
            r -= (dz);
            ++vb;++vf;
        }
        else{
            tym += a;
            double da = (a*vb);
            l += da;
            r -= (da);
            ++vb;
            s.insert(df);
        }
        
        double remdist = (r-l);
        double rels = (vf+vb);
        double reqt = (remdist/rels); 
        mn = min(mn,tym+reqt);

        cout<<mn<<" "<<df<<" "<<db<<" "<<vf<<" "<<vb<<endl;
        if(r <= l){
            break;
        }
    }

    cout<<setprecision(20)<<mn<<endl;
    return;
}
 */
/*
void solve()
{
 
    ll n;
    cin>>n;

    ll f;
    cin>>f;

    vector<ll> v(n);
    enter(v);
 
    set<ll> s(v.begin(),v.end());
    double l = 0;
    double r = f;
    double tym = 0;
    double mn = 1e14;
    double vf = 1,vb = 1;

    while(!s.empty()){
        ll f = *s.begin();
        ll b = *s.rbegin();
        ll df = (f-l);
        ll db = (r-b);
        double tf = (1.0*df/vf);
        double tb = (1.0*db/vb);

        if(s.size() == 1){
            s.erase(*s.begin());
            if(tf > tb){
                // vb reaches first
                double z = (tb*vf);
                l -= z;
                r = b;
                tym += tb;
                ++vb;
            }
            else if(tf == tb){
                l = f;
                r = b;
                tym += tf;
                ++vf;++vb;
                // mn = min(mn,tym);
                // break;
            }
            else{//tb > tf
                // vf reaches first
                l = f;
                double z = (tf*vb);
                r -= z;
                tym += tf;
                ++vf;
            }

            double rels = (vf+vb);
            double reldist = (r-l);
            double t = (reldist/rels);

            double ans = (t+tym);
            mn = min(mn,ans);
            break;
        }


        // cout<<l<<" "<<r<<" "<<vf<<" "<<vb<<" "<<tym<<" "<<tf<<" "<<tb<<" "<<" --> ";
        if(tf > tb){
            // vb reaches first
            s.erase(*s.rbegin());
            double z = (tb*vf);
            l -= z;
            r = b;
            tym += tb;
            ++vb;
        }
        else if(tf == tb){
            s.erase(*s.begin());
            s.erase(*s.rbegin());
            l = f;
            r = b;
            tym += tf;
            ++vf;++vb;
        }
        else{//tb > tf
            // vf reaches first
            s.erase(*s.begin());
            l = f;
            double z = (tf*vb);
            r -= z;
            tym += tf;
            ++vf;
        }

        if(s.empty()){
            double rels = (vf+vb);
            double reldist = (r-l);
            double t = reldist/rels;
            double ans = (t+tym);
            mn = min(mn,ans);
            break;
        }
        // cout<<l<<" "<<r<<" "<<vf<<" "<<vb<<" "<<tym<<" "<<t<<" "<<tf<<" "<<tb<<endl;
    }
    cout<<setprecision(20)<<mn<<endl;
    return;
}
*/