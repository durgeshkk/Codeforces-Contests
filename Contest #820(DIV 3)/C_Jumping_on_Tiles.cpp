#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void solve()
{
 
    string s;
    cin>>s;

    map<ll,char> mp;
    for(ll i = 0;i<26;++i){
        mp[i+'a'] = (1+i);
    }

    ll n = s.size();

    map<char,set<ll>> ms;
    for(ll i = 1;i<n-1;++i){
        ms[s[i]].insert(i+1);
    }

    ll ans = 0;
    string ag = s.substr(1,n-2);
    sort(ag.begin(),ag.end());
    vector<ll> dk;
    dk.push_back(1);
    ll ak = 0;
    char prev = s[0];

    if(s[0] > s[n-1]){
        reverse(ag.begin(),ag.end());
        for(ll j = 0;j<ag.size();++j){
            if((ag[j] >= s[n-1]) and (ag[j] <= s[0])){
                char c = ag[j];
                set<ll> &st = ms[c];
                ll val = *st.begin();
                st.erase(st.find(val));
                ms[c] = st;
                dk.push_back(val);
                ++ans;
            }
        }
    }
    else{
        for(ll j = 0;j<ag.size();++j){
            if((ag[j] >= s[0]) and (ag[j] <= s[n-1])){
                char c = ag[j];
                set<ll> &st = ms[c];
                ll val = *st.begin();
                st.erase(st.find(val));
                ms[c] = st;
                dk.push_back(val);
                ++ans;
                // cout<<ag[j]<<" ";
            }
        }
    }
    dk.push_back(n);

    ak = 0;
    for(ll i = 1;i<dk.size();++i){
        ll a = dk[i]-1;
        ll b = dk[i-1]-1;
        char c = s[a];
        char d = s[b];
        // cout<<a<<" "<<b<<" ";
        // cout<<c<<" "<<d<<" ";
        ll xy = mp[c];
        ll xyz = mp[d];
        // cout<<xy<<" "<<xyz<<" ";
        // cout<<ak<<" ";
        ak += abs(xy-xyz);
        // cout<<ak<<endl;
        // ak += abs(mp[s[dk[i]-1]]-mp[s[dk[i-1]-1]]);
    }

    cout<<ak<<" ";
    cout<<(ans+2)<<endl;
    show(dk);
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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
       ++i;
   }
   //solve();
   return 0;
}