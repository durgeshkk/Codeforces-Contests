#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    ll pos=0,neg=0;
    // vector<ll> pos,neg;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    ll sum = accumulate(v.begin(),v.end(),0);

    if(sum == 0){
        cout<<"NO\n";
        return;
    }
    else if(v.size() == 1){
        cout<<"YES\n";
        cout<<v[0]<<endl;
        return;
    }
    /*
    else{
        cout<<"YES\n";
        vector<ll> ans;

        sort(pos.begin(),pos.end());
        reverse(pos.begin(),pos.end());
        
        sort(neg.begin(),neg.end());

        if(v[0] == 0){
            reverse(v.begin(),v.end());
        }

        if(abs(v[0]+v[1]) == 0 && v.size()>=3){
            swap(v[0],v[2]);
        }
        for(ll i=0;i<n;i++){
            cout<<v[i]<<" ";
        }   
        cout<<endl;
        ll pos_sum = accumulate(pos.begin(),pos.end(),0);
        for(ll i=0;i<pos.size();i++){
            ans.push_back(pos[i]);
        }

        vector<ll> remain;
        for(ll i=0;i<neg.size();i++){
            if(pos_sum == neg[i]){
                remain.push_back(neg[i]);
            }
            else{
                pos_sum += neg[i];
                ans.push_back(neg[i]);
            }
        }

        if(pos_sum == remain[0]){
            reverse(remain.begin(),remain.end());
            for(ll i=0;i<remain.size();i++){
                ans.push_back(remain[i]);
            }
        }
        else{
            for(ll i=0;i<remain.size();i++){
                ans.push_back(remain[i]);
            }
        }
        for(ll i=0;i<n;i++){
            cout<<ans[i]<<" ";
            cout<<endl;
        }
    }*/

    else{
        cout<<"YES\n";
        if(sum > 0){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
        }
        else{
            sort(v.begin(),v.end());
        }

        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    cout<<endl;

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