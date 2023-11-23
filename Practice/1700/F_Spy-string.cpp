/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll n,m;
vector<string> v;
void recur(ll idx,map<ll,string> &mp,string tera){
    if(idx == m){
        // all.push_back(tera);
        return;
    }

    string tmp = mp[idx];
    for(ll i = 0;i<mp[idx].size();++i){
        recur(idx+1,mp,tera+tmp[i]);
    }

    return;
}

void smart(){
    for(ll i = 0;i<m;++i){
        for(char ch = 'a';ch<='z';++ch){
            string ans = v[0];
            ans[i] = ch;
            ll flag = 0;
            for(ll k = 0;k<n;++k){
                // Check the diff character between 2 strings : v[k] and ans
                ll cnt = 0;
                for(ll alpha = 0;alpha<m;++alpha){
                    if(v[k][alpha] != ans[alpha]){++cnt;}
                }
                if(cnt <= 1){
                    ++flag;
                }
            }
            if(flag == n){
                cout<<ans<<endl;return;
            }
        }
    }
    cout<<"-1\n";return;
}

void solve()
{
 
    cin>>n>>m;
    v.assign(n,"");enter(v);

    smart();
    return;

    // We need to check over n*m string pssbl ans!!
    // Each s[i][j] 0<=i<n, will result in ans[j]
    // Jo ans[j] honga vo sab s[i][j] 0<=i<n se hi select honga
    // So pssbl combo's are n^m = 10^10 : MLE
    string ans="";
    map<ll,string> col;
    for(ll j = 0;j<m;++j){
        string st;
        set<char> chottu;
        for(ll i = 0;i<n;++i){
            if(chottu.find(v[i][j]) == chottu.end()){
                chottu.insert(v[i][j]);
                st += (v[i][j]);
            }
        }
        col[j] = st;
    }

    set<string> tutu; 
    for(ll i = 0;i<n;++i){
        string st = v[i];
        ll f = 0;
        // Assume if this string is the ans :
        for(ll j = 0;j<n;++j){
            ll cnt = 0,idx2 = -1,idx1 = -1;
            for(ll k = 0;k<m;++k){
                if(st[k] != v[j][k]){
                    ++cnt;
                    if(cnt == 1){idx1 = k;}
                    if(cnt == 2){idx2 = k;}
                }
            }
            if(cnt > 2){
                cout<< -1<<endl;
                return;
            }else{
                if(cnt == 2){
                    string tmpa = v[i];string tmpb = v[j];
                    char a = v[i][idx1];char d = v[j][idx2];
                    tutu.insert(tmpa);tutu.insert(tmpb);
                    tmpa[idx2] = d;tmpb[idx1] = a;
                    tutu.insert(tmpa);tutu.insert(tmpb);
                }else{
                    tutu.insert(v[i]);tutu.insert(v[j]);
                    ++f;
                }   
            }
        }
        if(f == n){
            cout<<v[i]<<endl;return;
        }
    }

    vector<string> all(tutu.begin(),tutu.end());
    for(ll i = 0;i<all.size();++i){
        string st = all[i];
        ll string_diff = 0,f = 0;
        // Iterating over all the strings
        for(ll j = 0;j<n;++j){// Now check if this string is just differing by atmost 1 char
            ll cnt = 0;
            for(ll k = 0;k<m;++k){
                if(st[k] != v[j][k]){
                    ++cnt;
                }
            }

            if(cnt >= 2){// This can't be the ans
                f = 1;break;
            }else{
                ++string_diff;
            }
        }

        if(f & 1){continue;}
        if(string_diff == n){ans = st;}
    }

    if(ans == ""){ans = "-1";}
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}