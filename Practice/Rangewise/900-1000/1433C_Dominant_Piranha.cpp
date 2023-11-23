#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    ll max=0;
    ll max_ind=-1;

    map<ll,ll> mp;
    vector <ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);

       if(ele > max){
           max = ele;
           max_ind = i;
       }
       mp[ele]++;
    }

    if(mp[max] == n){
        cout<<-1<<endl;
        return;
    }

    if(mp[max] == 1){
        cout<<max_ind+1<<endl;
        return;
    }

    ll i=0;
    if(v[i] == max){
        while(v[i] == max && v[i+1] == max){
            i++;
        }
        cout<<i+1<<endl;
    }
    else{
        while(v[i] != max){
            i++;
        }
        cout<<i+1<<endl;
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