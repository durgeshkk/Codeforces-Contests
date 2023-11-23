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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> printDivisors(ll j)
{
    // Note that this loop runs till square root
    // for(ll j = 1;j<=26;++j){
        vector<ll> tmp;
        ll ak = min((ll)sqrt(j),26*1ll);
        for (ll i=1; i<=ak; i++){
            if (j%i == 0)
            {
                // If divisors are equal, print only one
                if (j/i == i)
                    tmp.push_back(i);
    
                else // Otherwise print both
                    tmp.push_back(i);
                    tmp.push_back(j/i);
            }
        }
        return tmp;
    //     factor[j] = tmp;
    // }
}
 
void solve()
{
 
    ll n;cin>>n;
    string s;cin>>s;
    map<char,ll> mp;
    map<char,set<ll>> idx;
    set<char> accha;

    for(ll j = 0;j<26;++j){
        char ch = 'a'+j;
        accha.insert(ch);

        set<ll> tmp;
        for(ll i=0;i<s.size();i++){
            if(s[i] == ch){
                tmp.insert(i);
            }
        }
        idx[j] = tmp;
    }

    for(ll i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    multiset<pair<ll,char>> ms;
    for(auto it:mp){
        accha.erase(accha.find(it.first));
        ms.insert({it.second,it.first});
    }

    vector<ll> fac = printDivisors(n);
    sort(fac.begin(),fac.end());


    // show(fac);
    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }


    ll min_op = LLONG_MAX,mera = 0;
    for(auto it:fac){
        // Check if we can get min_val using it 
        ll op = 0;
        if(it == 1 || it == n){
            continue;
        }else{
            for(auto x:mp){
                op += abs((x.second-it));
            }
        }

        // cout<<op<<endl;
        
        if(min_op > op){
            min_op = op;
            mera = it;
        }
    }

    // Handle 1 and n differently!!
    ll ans = (min_op/2);
    // cout<<min_op<<endl;
    if(ans > mp.size()-1){
        ans = (mp.size()-1);
        mera = n;
    }

    ll op = 0;
    for(auto x:mp){
        op += abs((x.second-1));
    }

    if(ans > op and mp.size()+op < 27){
        ans = (op);
        mera = 1;

        

    }

    // cout<<endl;
    // cout<<endl;
    // for(auto it:ms){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    // Now check for mera!!Mera will result in min_op!!
    map<ll,char> replac;
    while(ms.size() > 1){
        auto f = *ms.begin();
        ms.erase(ms.find(f));

        if(f.first == mera){break;}

        auto r = *ms.begin();
        ms.erase(ms.find(r));

        (f.first)--;
        (r.first)++;
        
        // now just check the idx of replaced char and update it
        ll ch = (f.second- ('a'));
        set<ll> &st = idx[ch];
        ll fck = *st.begin();
        st.erase(st.find(fck));
        replac[fck] = r.second;


        if(f.first > 0){
            ms.insert(f);
        }
        if(r.first < mera){
            ms.insert(r);
        }
    }

    for(auto it:replac){
        s[it.first] = it.second;
    }
    cout<<ans<<endl;
    cout<<s<<endl;
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