#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;


    vector<ll> v;
    
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }


    if(n==1){
        cout<<v[0]<<endl;
        return;
    }

    ll x=0,mx=0,sum=0;
    for(ll i=0;i<n;i++){
        while(v[i]%2 == 0){
            x++;
            v[i] /= 2;
        }
        mx = max(mx,v[i]);
        sum += v[i];
    }
    sum-=mx;
    cout<<sum+mx*(ll)pow(2,x)<<endl;
/*
    sort(v.begin(),v.end());
    map <ll,ll> mp;
    mp[2] = 1;
    mp[4] = 2;
    mp[6] = 1;
    mp[8] = 3;
    mp[10] = 1;
    mp[12] = 2;
    mp[14] = 1;

    ll max_2_give = 0;

    for(ll i=0;i<v.size();i++){

        if((v[i]%2 == 0) && (mp.find(v[i]) != mp.end())){
            max_2_give += mp[v[i]];
        }
    }


    ll max = 0;
    for(ll i=0;i<v.size();i++){
        if((v[i] > max) && (v[i]%2 != 0) && v[i] != 1){
            max = v[i];
        }
    }

    if(max == 0){//no odd no. in array
        max = v[v.size()-1];
        max_2_give = max_2_give - (mp[v[v.size()-1]]);
    }

    // Calculate odd no's in vector
    ll odd_sum = 0,odd_count = 0;
    for(ll i=0;i<v.size();i++){
        if((v[i]>1) && (v[i] != max) && v[i]%2 != 0){
            odd_sum += v[i];
            odd_count++;
        }
    }

    ll sum = accumulate(v.begin(),v.end(),0);
    ll ans = max * pow(2,max_2_give);
    ll new_sum = ans+(n-1)+odd_sum-odd_count;

    if(sum>new_sum){
        cout<<sum<<endl;
    }
    else{
        cout<<new_sum<<endl;
    }*/
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