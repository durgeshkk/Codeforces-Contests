#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    vector<ll> s;
    for(int i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        s.push_back(ele);
    }

    sort(s.begin(),s.end());

    ll f=0;
    for(int i=1;i<n;i++){
        if((v[i] != s[i]) && ((v[0]==1) || (v[v.size()-1] == n))){
            cout<<1<<endl;
            return;
        }
        else if((v[i] != s[i]) && ((v[0]==n) && (v[v.size()-1] == 1))){
            cout<<3<<endl;
            return;
        }
        else if((v[i] != s[i])){
            cout<<2<<endl;
            return;
        }
    }
    cout<<0<<endl;
    /*
    ll f=0;
    for(int i=0;i<n;i++){
        if(v[i] != s[i]){
            cout<<2<<endl;
            f=1;
            return;
        }
        else if(v[0] == 1){
            cout<<1<<endl;
            return;
        }
        
    }

    if(v[0] == 1){
        cout<<1<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(v[i] != s[i]){
            cout<<2<<endl;
            return;
        }
    }*/
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