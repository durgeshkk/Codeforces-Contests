#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
void solve()
{
 
    ll n;
    cin>>n;

    ll k;
    cin>>k;
    vector<ll> v(n);
    ll arr[101] = {0};
    ll max=INT16_MIN;

    for(ll i=0;i<n;i++){   
       cin>>v[i];
       arr[v[i]]++;
    }
    /* fails test case 4 :
    // cout<<max_ele<<" "<<max_freq<<endl;

    if(mp.size() == n && k==1){
        cout<<n-1<<endl;
        return;
    }

    if((mp.size() == 2) && (max_freq==k)){
        ll a = (last_ind-max_freq);
        for(ll i = a;i<last_ind;i++){
            if(v[i] != max_ele){
                break;
            }
        }
        cout<<1<<endl;
        return;
    }

    ll ans = 0;  
    for(ll i = 0;i<v.size();){
        if(v[i] == max_ele){
            i++;
        }
        else{
            ans++;
            i+=(k);
        }
    }
    cout<<ans<<endl;*/

    ll days = INT_MAX;
    for (int i = 0; i <= 100; i++)
    {
        if(arr[i])
        {
            ll c = i;
            ll t = k;
            ll d = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[j] == c && t == k)
                {
                    continue;
                }
                else
                {
                    while (t--)
                    {
                        j++;
                    }
                    j--;
                    d++;
                    t = k;
                }
            }
            days = min(d, days);
        }
    }
    cout << days << endl;
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
   //solve();
   return 0;
}