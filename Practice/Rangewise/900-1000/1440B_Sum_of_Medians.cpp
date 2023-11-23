#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,k;
    cin>>n>>k;
    
    ll len = n*k;
    vector<ll> v;

    for(ll i=0;i<len;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    if(k == 1){
        ll start=ceil(1.0*n/2)-1;
        cout<<v[start]<<endl;
        return;
    }
    else if(k == 2){
        ll sum = 0;
        for(ll i=0;i<len;i++){
            if(i%2 == 0){
                sum += v[i];
            }
        }
        cout<<sum<<endl;
        return;
    }

    sort(v.begin(),v.end());

    ll sum = 0,count=0;
    ll start=ceil(1.0*n/2)-1;
    for(ll i=start;i<len;i= (i+ (n-2)+1)){
        if(count >= k){
            break;
        }
        cout<<v[i]<<" ";
        sum += v[i];
        count++;
    }
    cout<<endl;

    cout<<sum<<endl;
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