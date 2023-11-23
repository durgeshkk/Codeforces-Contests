#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void subsequence(string s,ll l,ll r){
    string sub = s.substr(l-1,r-l+1);
    // cout<<sub<<endl;

    for(int i=0;i<(l-1);i++){
        if(sub[0] == s[i]){
            cout<<"YES\n";
            return;
        }
    }
    
    for(int i=r;i<s.length();i++){
        if(sub[sub.size()-1] == s[i]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}

void solve()
{
    ll n,x;
    cin>>n>>x;

    string s;
    cin>>s;

    ll i=1;
    while(i <= x){
        ll l;
        ll r;
        cin>>l>>r;
        subsequence(s,l,r);
        i++;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}