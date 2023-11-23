#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll z;
    cin>>z;

    vector<ll> v;
    set<ll> s;

    for(ll i=0;i<z;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        s.insert(ele);
    }

    if(z == 1){
        cout<<0<<endl;
        return;
    }

    // vector<ll> sort_v;
    set<ll> sort_v;
    for(ll i=0;i<z;i++){
        sort_v.insert(v[i]);
    }

    // sort(sort_v.begin(),sort_v.end());

    ll n = *(sort_v.rbegin());
    ll m = *(++sort_v.rbegin());
    // cout<<"n : "<<n<<" m : "<<m<<endl;

    ll count=0;

    ll i=v.size()-1;
    while(i >= 0){
        
        if((v[i] >= n)){
            cout<<count<<endl;
            return;
        }
        if(v[i] == (m)){
            cout<<count+1<<endl;
            return;
        }

        ll a = v[i];
        v.pop_back();
        while(a >= v[v.size()-1]){
            v.pop_back();
            i--;
        }
        i--;
        count++;
    }
    cout<<count<<endl;
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