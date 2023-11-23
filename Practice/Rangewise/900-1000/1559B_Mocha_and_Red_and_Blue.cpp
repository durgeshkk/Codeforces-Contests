#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;

    vector<pair<char,ll>> v;

    if(n == 1){
        if(s == "?"){
            cout<<'B'<<endl;
        }
        else{
            cout<<s<<endl;
        }
        return;
    }

    
/* A bit error for test case 1:
    for(ll i=0;i<n;i++){
        if(s[i] == 'R'){
            v.push_back(make_pair('R',i));
        }
        else if(s[i] == 'B'){
            v.push_back(make_pair('B',i));
        }
    }

    if(v.size() == 1){
        for(ll i=0;i<n;i++){
            if(s[i] == '?'){
                ll diff = abs(v[0].second - i);
                if(diff%2 == 0){
                    s[i] = v[0].first;
                }
                else{
                    if(v[0].first == 'R'){
                        s[i] = 'B';
                    }
                    else{
                        s[i] = 'R';
                    }
                }
            }
        }
    }
    else{

        ll j=0;//to traverse vector
        for(ll i=0;i<n;i++){
            if(s[i] == '?'){
                ll diff = v[j].second - i;
                if(diff%2 == 0){
                    s[i] = v[j].first;
                }
                else{
                    if(v[j].first == 'R'){
                        s[i] = 'B';
                    }
                    else{
                        s[i] = 'R';
                    }
                }
                j++;
            }
        }
    }
    cout<<s<<endl;*/

    map<char,char> converse;
    converse['B'] = 'R';
    converse['R'] = 'B';

    string ans = "";
    char first = 'z';
    for(int i=0;i<n;i++){
        while(i<n && s[i] == '?'){
            i++;
        }

        if(i==n){
            break;
        }

        if((i-ans.size())%2){
            char cons = s[i];

            for(int j=ans.size();j<=i;j++){
                ans += converse[cons];
                cons = converse[cons];
            }
        }
        else{
            char cons = converse[s[i]];

            for(int j=ans.size();j<=i;j++){
                ans += converse[cons];
                cons = converse[cons];
            }
        }
    }

    if(ans.size() ==0){//for all ?
        char m='B';
        for(int i=0;i<n;i++){
            ans+=m;
            m = converse[m];
        }
    }

    while(ans.size() < n){
        int last = ans.size();
        ans += converse[ans[last-1]];
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}