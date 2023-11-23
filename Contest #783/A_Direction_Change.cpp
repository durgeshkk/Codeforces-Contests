#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    if(n==1 && m==1){
        cout<<0<<endl;
        return;
    }
    else if((n==1 && m==2) || (m==1 && n==2)){
        cout<<1<<endl;
        return;
    }

    if(n==1 || m==1){
        cout<<-1<<endl;
        return;
    }

    if(m > n){
        /*
        ll hori = m-1;
        ll diff = m-n;
        // ll verti = min(abs(n-1),abs(m-1));
        ll verti = n-1+diff;*/
        // cout<<hori+verti<<endl;
        ll mn = n;
        ll p1 = 2*(mn-1);
        ll diff = (m-n);
        if(diff%2 == 0){
            diff = diff*2;
        }
        else{
            diff = (diff*2)-1;
        }
        cout<<p1+diff<<endl;
    }
    else{
        ll mn = m;
        ll p1 = 2*(mn-1);
        ll diff = (n-m);
        if(diff%2 == 0){
            diff = diff*2;
        }
        else{
            diff = (diff*2)-1;
        }
        cout<<p1+diff<<endl;
        // ll verti = m-1;
        // ll diff = n-m;
        // ll hori = n-1+diff;
        // cout<<hori+verti<<endl;
    }
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
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