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

void solve()
{
 
    ll n;
    cin>>n;

    string s;cin>>s;
    map<char,char> mp;
    set<char> st;

    vector<char> v(26,'*');
    vector<ll> kp(26,0);
    string ans(n,'0');

    for(ll i= 0;i<n;++i){

        if(v[s[i]-'a'] != '*'){
            ans[i] = v[s[i]-'a'];
            continue;
        }

        for(ll j=0;j<26;j++){

            if((s[i] == (j+'a'))|| (kp[j])){
                continue;
            }

            ll f = 0;
            v[s[i]-'a'] =(j+'a');
            vector<ll> vis(26,0);
            char ak = s[i];
            // v[ak-'a'] = (i+'a');

            while(1){
                if(ak == '*'){
                    break;
                }
                else if(vis[ak-'a'] == 1){
                    f = 1;
                    break;
                }
                vis[ak-'a'] = 1;
                ak = v[ak-'a'];
            }

            if(f == 0){
                ans[i] = (j+'a');
                v[s[i]-'a'] =(j+'a');
                kp[j] = 1;
                break;
            }
        }
    }
    
    char dk;
    for (ll j = 0;j<26;++j){
        if(kp[j] == 0){
            dk = (j+'a');
            break;
        }
    }
    
    for(auto &it:ans){
        if(it == '0'){
            it = dk;
        }
    }
    cout<<ans<<endl;
    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
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
if(s[0] == 'a'){
        mp[s[0]] = 'b';
        st.erase('b');

        for(ll i = 1;i<n;++i){
            if(mp.find(s[i]) == mp.end()){

            }
        }

    }else{
        vector<char> v;

        for(ll i = 0;i<n;++i){
            if(mp.find(s[i]) == mp.end()){
                char z = *st.begin();
                char child = z;

                if(mp.find(z) != mp.end()){
                    ll f = 0;
                    while(f == 0){
                        char par = mp[child];
                        if(mp.find(par) != mp.end()){
                            child = par;
                            
                        }else{
                            f = 1;
                        }

                        if(child == z){
                            v.push_back(child);
                            st.erase(z);
                        }
                    }
                }else{
                    mp[s[i]] = z;
                }


                if(!vis[z-'a'+1]){
                    vis[z-'a'+1] = 1;
                }else{

                }


            }
        }
    }


*/
/*
    vector<ll> vis(26,0);

    

    for(ll i = 0;i<n;++i){
        ll z = (s[i]-'a'+1);
        if(!vis[z]){
            vis[z] = 1;
            mp[s[i]] = *st.begin();
            st.erase(*st.begin());
        }
    }*/

/*
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
*/
    /*
    string t;
    for(ll i = 0;i<n;++i){
        t += mp[s[i]];
    }
    cout<<t<<endl;*/
    

