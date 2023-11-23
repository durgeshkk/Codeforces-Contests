/*
    ***Author : daddy_dynamo
*/
#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve(){
    ll n;cin>>n;
    vector<string> v;
    multiset<string> suff,pref;
    for(ll i = 0;i<n;++i){
        string st;cin>>st;
        v.push_back(st);
        suff.insert(st);
    }

    ll f = 0;
    map<char,vector<string>> start,end;

    for(ll i = 0;i<n;++i){
        suff.erase(suff.find(v[i]));
        string s = v[i];
        
        // Size = 1(This are palindrome sizes)
        if(s.size() == 1){f = 1;}

        // Size = 2
        if(s.size() == 2){
            if(s[0] == s[1]){f = 1;}
        }

        // Size = 3
        if(s.size() == 3){
            start[s[0]].push_back(s);
            end[s[2]].push_back(s);
            if(s[0] == s[1] and s[1] == s[2]){f = 1;}
            else if(s[0] == s[2]){f = 1;}
        }

        // Size = 4
        if(s.size() == 2){
            // ab + ba
            string tmp = s;
            reverse(tmp.begin(),tmp.end());
            if(suff.find(tmp) != suff.end()){
                f = 1;
            }

            if(pref.find(tmp) != pref.end()){
                f = 1;
            }
        }

        // Size = 5
        if(s.size() == 3){
            // Standing on abc & need to find ba in suff
            string tmp;//ba
            tmp += s[1];
            tmp += s[0];
            if(suff.find(tmp) != suff.end()){f=1;}

            tmp.clear();
            // Standing on cba & need to find ab in pref
            tmp += s[2];//ab from cba
            tmp += s[1];
            if(pref.find(tmp) != pref.end()){f=1;}
        }

        // Size = 6
        if(s.size() == 3){
            string tmp = s;
            reverse(tmp.begin(),tmp.end());

            if(pref.find(tmp) != pref.end()){f = 1;}
            if(suff.find(tmp) != suff.end()){f = 1;}
        }

        // Size = 7 and + sab uppar hamesha cover ho jayengen will always form Palindromes!!
        pref.insert(v[i]);
    }

    if(f & 1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return;
}

// A bit wrong!!
/* 
void solve()
{
 
    ll n;cin>>n;
    multiset<string> s;
    vector<string> v(n);
    map<string,ll> mst;
    ll f = 0;
    for(ll i=0;i<n;i++){
        string st;cin>>st;
        s.insert(st);
        v[i] = st;
        mst[v[i]]++;
    }

    for(ll i=0;i<n;i++){
        string t = v[i];
        reverse(t.begin(),t.end());
        if(t.size() == 1){f = 1;}

        if(s.find(t) != s.end()){
            f = 1;
        }

        reverse(t.begin(),t.end());
        if(t.size() == 2){
            string tmp1,tmp2;
            tmp1 += t[0];
            tmp2 += t[1];
            if(s.find(tmp1) != s.end()){
                if(s.find(tmp2) != s.end()){
                    f = 1;
                }
            }
        }else{
            // Check size = 5
            // Check size = 6
            // Handle the case : aab 
            string tmp1;
            map<char,ll> mp;
            mp[t[0]]++;
            mp[t[1]]++;
            mp[t[2]]++;

            if(mp.size() == 1){
                f = 1;
            }else if(mp.size() == 2){
                if(t[0] == t[2]){f = 1;}//palindrome
                // Check aab,baa,aabaa
                else if(t[1] == t[2]){
                    tmp1 += t[1];
                    //aab a a check :
                    if(s.find(tmp1) != s.end()){
                        ll freq = mst[tmp1];
                        if(freq >= 2){f = 1;}
                    }
                    //aab aa check :
                    tmp1 += t[1];
                    if(s.find(tmp1) != s.end()){f = 1;}
                }else{
                    // Check for baa:
                    tmp1 += t[1];
                    //a a baa check :
                    if(s.find(tmp1) != s.end()){
                        ll freq = mst[tmp1];
                        if(freq >= 2){f = 1;}
                    }

                    //aa baa check :
                    tmp1 += t[1];
                    if(s.find(tmp1) != s.end()){f = 1;}
                }
            }else{
                // Size 3 : check for only size = 5 palindrome as 6 is checked in reverse part
                // Check : abc b a
                tmp1 += t[1];
                string tmp2; tmp2 += t[0];

                if(s.find(tmp1) != s.end()){
                    if(s.find(tmp2) != s.end()){
                        f = 1;
                    }
                }

                // Check : abc ba
                tmp1 += t[0];
                if(s.find(tmp1) != s.end()){
                    f = 1;
                }
            }
        }
    }

    if(f & 1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return;
}
 */


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