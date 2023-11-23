#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
bool helper(ll mid,ll n){
    ll a = mid/3;
    ll b = mid/3;
    ll c = mid/3;
    if(mid%3){
        ++a;
    }   
    if(mid%3 == 2){
        ++b;
    }   

    ll tri_pssbl = 2*(a*b+b*c+c*a);
    return tri_pssbl >= n;
}

ll binarys(ll n){
    // We have 3 direxn l,r, and s & to maximise the ans we need to make them
    // all Equal!!
    // So, (l & r),(s & r),(l & s) will result in 2 equli T & 
    // all of l,r,s will result in 6
    // Thus, ans = 2*(lr + rs + ls)
    // Given, l+r+s = n(n is given) & also x must be approx = y = z
    ll ans = 0;
    ll l = 1,r = 1e6;//max no. of lines we can draw
    while(l <= r){
        ll mid = (l+r)/2;
        if(helper(mid,n)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}


vector<ll> v;
void precompute(){
    ll l = 0,r = 0,s = 0,flag = 0;
    ll ans = 0,f = 0;
    // Wrong thinking:
    // /*
    while(ans <= 1e9){
        flag %= 3;
        if(flag == 0){
            ++l;
            ans += ((r+s)*2);
        }else if(flag == 1){
            ++r;
            ans += ((l+s)*2);
        }else{
            ++s;
            ans += ((l+r-2)*2+6);
        }
        ++flag;
        v.push_back(ans);
    }
    // */
} 

void solve()
{
 
    ll n;cin>>n;
    ll ans=  binarys(n);
    cout<<ans<<endl;
    // ll ans = lower_bound(v.begin(),v.end(),n)-v.begin();
    // cout<<ans+1<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    precompute();
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}