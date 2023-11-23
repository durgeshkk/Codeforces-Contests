#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

/*
// Will give Distance
    vector<ll> v;
    
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    // Reversing vector to bring most frequent to be the nearest
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    ll i=0,j=1;
    ll k=1;//for multiplying i.e. distance

    ll ans=0;
    while(i<n && j<n){
        ans = ans + (v[i]+v[j])*k;
        i+=2,j+=2;
        k++;
    }

    if(i<n){
        ans += (v[i]*k);
    }

// ans *2 since jane ka alag aur anne ka alag as given in question
    cout<<2*ans<<endl;
*/
    pair<ll,ll> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i;//let second store the freq
    }

    sort(arr,arr+n);

    ll time=0;
    int ans[n];//to store the new index & return

    int idx = 1;
    // Below loop for travelling idx = 1,2,3..
    for(int i=n-1;i>=0;i-=2){
        ll temp=2*idx;//since dist req is 2*idx
        time = time + (arr[i].first)*temp;//dist = freq*temp
        ans[arr[i].second] = idx;
        idx++;
    }
    
    idx = -1;
    // Below loop for travelling idx = -1,-2,-3..
    for(int i=n-2;i>=0;i-=2){
        ll temp=2*abs(idx);//since dist req is 2*idx
        time = time + (arr[i].first)*temp;//dist = freq*temp
        ans[arr[i].second] = idx;
        idx--;
    }

    cout<<time<<endl;
    cout<<0<<" ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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