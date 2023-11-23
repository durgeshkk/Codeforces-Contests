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

vector<pair<ll, ll>> ans;
vector<string> h;

void three(ll i, ll j)
{
    for (ll k = i; k < i + 2; k++)
    {
        for (ll l = j; l < j + 2; l++)
        {
            if (h[k][l] == '1')
            {
                ans.push_back({k, l});
                h[k][l] = '0';
            }
        }
    }
}
 
void two(ll i, ll j)
{
    ll c = 0;
    for (ll k = i; k < i + 2; k++)
    {
        for (ll l = j; l < j + 2; l++)
        {
            if (h[k][l] == '1' && c <= 0)
            {
                h[k][l] = '0';
                c++;
                ans.push_back({k, l});
            }
            else if (h[k][l] == '0')
            {
                h[k][l] = '1';
                ans.push_back({k, l});
            }
        }
    }
 
    three(i, j);
}
 
void one(ll i, ll j)
{
    ll c = 0;
    for (ll k = i; k < i + 2; k++)
    {
        for (ll l = j; l < j + 2; l++)
        {
            if (h[k][l] == '1')
            {
                h[k][l] = '0';
                ans.push_back({k, l});
            }
            else if (h[k][l] == '0' && c < 2)
            {
                h[k][l] = '1';
                ans.push_back({k, l});
                c++;
            }
        }
    }
    two(i, j);
}
 
void four(ll i, ll j)
{
    ll c = 0;
    for (ll k = i; k < i + 2; k++)
    {
        for (ll l = j; l < j + 2; l++)
        {
            if (h[k][l] == '1' && c < 3)
            {
                ans.push_back({k, l});
                h[k][l] = '0';
                c++;
            }
        }
    }
 
    one(i, j);
}
 
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    ans.clear();
    vector<string> v;
    for (ll i = 0; i < n; i++)
    {
        string s = "";
        for (ll j = 0; j < m; j++)
        {
            char t;
            cin >> t;
            s += t;
        }
        v.push_back(s);
    }
    h = v;
    ll r = 0;
    for (ll i = 0; i < n; i += 2)
    {
        for (ll j = 0; j < m; j += 2)
        {
 
            if (i + 1 >= n && j + 1 >= m)
            {
                vector<pair<ll, ll>> t;
                for (ll k = i - 1; k < i + 1; k++)
                {
                    for (ll l = j - 1; l < j + 1; l++)
                    {
                        if (h[k][l] == '1')
                        {
                            t.push_back({k, l});
                        }
                    }
                }
 
                if (t.size() == 3)
                {
 
                    three(i - 1, j - 1);
                }
                else if (t.size() == 2)
                {
                    two(i - 1, j - 1);
                }
                else if (t.size() == 1)
                {
                    one(i - 1, j - 1);
                }
                else if (t.size() == 4)
                {
                    four(i - 1, j - 1);
                }
                continue;
            }
            else if (i + 1 >= n)
            {
                vector<pair<ll, ll>> t;
                for (ll k = i - 1; k < i + 1; k++)
                {
                    for (ll l = j; l < j + 2; l++)
                    {
                        if (h[k][l] == '1')
                        {
                            t.push_back({k, l});
                        }
                    }
                }
 
                if (t.size() == 3)
                {
 
                    three(i - 1, j);
                }
                else if (t.size() == 2)
                {
                    two(i - 1, j);
                }
                else if (t.size() == 1)
                {
                    one(i - 1, j);
                }
                else if (t.size() == 4)
                {
                    four(i - 1, j);
                }
                continue;
            }
            else if (j + 1 >= m)
            {
                vector<pair<ll, ll>> t;
                for (ll k = i; k < i + 2; k++)
                {
                    for (ll l = j - 1; l < j + 1; l++)
                    {
                        if (h[k][l] == '1')
                        {
                            t.push_back({k, l});
                        }
                    }
                }
 
                if (t.size() == 3)
                {
 
                    three(i, j - 1);
                }
                else if (t.size() == 2)
                {
                    two(i, j - 1);
                }
                else if (t.size() == 1)
                {
                    one(i, j - 1);
                }
                else if (t.size() == 4)
                {
                    four(i, j - 1);
                }
                continue;
            }
 
            vector<pair<ll, ll>> t;
            for (ll k = i; k < i + 2; k++)
            {
                for (ll l = j; l < j + 2; l++)
                {
                    if (h[k][l] == '1')
                    {
                        t.push_back({k, l});
                    }
                }
            }
 
            if (t.size() == 3)
            {
 
                three(i, j);
            }
            else if (t.size() == 2)
            {
                two(i, j);
            }
            else if (t.size() == 1)
            {
                one(i, j);
            }
            else if (t.size() == 4)
            {
                four(i, j);
            }
        }
    }

    ll c = 0;
    cout << ans.size() / 3 << endl;
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << " ";
        c++;
        if (c == 3)
        {
            cout << endl;
            c = 0;
        }
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
   ll i = 1;
   while (t--)
   {
    //    cout<<"Case #"<<i<<": ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}