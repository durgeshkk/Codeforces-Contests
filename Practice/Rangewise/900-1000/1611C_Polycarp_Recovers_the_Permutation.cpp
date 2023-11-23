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

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        s.push_back(ele);
    }
    sort(s.begin(),s.end());

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    if((v[0] != s[s.size()-1]) && (v[v.size()-1] != s[s.size()-1])){
        // cout<<s[0]<<" "<<s[s.size()-1]<<endl;
        cout<<-1<<endl;
        return;
    }

    ll mx = s[s.size()-1];
/*

    ll l = v[0];
    ll i=1;
    vector<ll> v1;
    v1.push_back(l);
    
    while(v[i] < l){
        v1.push_back(v[i]);
        i++;
    }
    reverse(v1.begin(),v1.end());
    v1.push_back(mx);
    // i++;

    vector<ll> v2;
    while(i != (n-1)){
        v2.push_back(v[i]);
        i++;
    }
    reverse(v2.begin(),v2.end());

    for(ll i=0;i<v2.size();i++){
        v1.push_back(v2[i]);
    }

    for(ll i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;*/

    if(v[v.size()-1] == s[s.size()-1]){
        reverse(v.begin(),v.end());
        v.push_back(mx);
    }
    else{
        v.push_back(mx);
        // cout<<v[0]<<" "<<v[1]<<endl;
        reverse(v.begin(),v.end());

        // cout<<v[0]<<" "<<v[1]<<endl;
    }

    for(ll i=0;i<v.size()-1;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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