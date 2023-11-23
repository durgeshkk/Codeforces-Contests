#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))

vector<ll> sub;
void longestNonDecreasingSubsequence(const vector<ll>& arr) {
    for (ll i = 0; i < arr.size(); ++i) {
        ll x = arr[i];
        if (sub.empty() || sub[sub.size() - 1] <= x) { // Append to LIS if new element is >= last element in LIS
            sub.push_back(x);
        } else {
            ll idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); // Find the index of the smallest number > x
            sub[idx] = x; // Replace that number with x
        }
    }
    return;
}

ll n,m;
vector<ll> v;

bool check(ll x){
    ll lst_ele = 0,cntr = 0;
    vector<ll> z(v);
    for(ll i = 0;i<n;++i){
        if(lst_ele > z[i]){
            cntr = (lst_ele-z[i]);
            if(cntr > x){return 0;}
        }else if(lst_ele < z[i]){
            cntr = (m-z[i]+lst_ele);
            // Agar chal rha toh chalne do
            // Agar Op's zyada aa rhe toh replace last ele by the curr & check if 
            // this case is pssbl or not 
            if(cntr > x){
                lst_ele = z[i];
            }
        }
    }
    return 1;
}

void solve()
{
    cin>>n>>m;
    v.assign(n,0);enter(v);
    ll ans = 0;
    ll l = 0,h = 1e9;
    while(l <= h){
        ll mid = (l+h)/2;
        if(check(mid)){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    /*
    longestNonDecreasingSubsequence(v);
    ll j = 0,ans = 0;
    for(ll i = 0;i<n;++i){
        if(j < sub.size()){
            if(v[i] == sub[j]){++j;}
            else{
                if(j > 0 and j<(sub.size()-1)){
                    ans = max(ans,min())
                }else if(j == 0){
                    ans = max(ans,(m-v[i]+sub[j]));
                }else{
                    ans = max(ans,(m-v[i]+sub[j-1]));
                }
            }
        }else{
            ans = max(ans,(sub[j-1]-v[i]));
        }
        cout<<ans<<endl;
    }
    show(sub);*/
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}