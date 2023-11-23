#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    string s;
    cin>>s;

    string fi;
    cin>>fi;

    if(s == fi){
        cout<<"YES\n";
        return;
    }

    reverse(fi.begin(),fi.end());
    for(auto i:fi){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<pair<char,ll>> v(s.length());
    for (ll i = 0; i <s.length(); i++)
    {
        v[i].first = s[i];
        v[i].second = i;
    }

    reverse(v.begin(),v.end());


    for(auto i:v){
        cout<<i.first<<" ";
        // cout<<i.first<<" "<<i.second<<" ";
    }
    cout<<endl;

    vector<ll> ind(fi.size());

    ll j=0;
    for (ll i = 0; i <s.length(); i++){
        if(fi[j] == v[i].first){
            ind[j] = (v[i].second);
            v[i].first = 'a';
            // v[i].second = 0;
            i=0;
            j++;
        }
    }


    for(auto i:v){
        cout<<i.first<<" "<<i.second<<" ";
    }
    cout<<endl;


    if(j < fi.size()){
        cout<<"NO\n";
        return;
    }

    for(auto i:ind){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<ll> sorted(fi.size());
    for(ll i=0;i<ind.size();i++){
        sorted[i] = ind[i];
    }

    sort(sorted.begin(),sorted.end());
    reverse(sorted.begin(),sorted.end());

    for(ll i=0;i<ind.size();i++){
        if(sorted[i] != ind[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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