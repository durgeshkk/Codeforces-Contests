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
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    ll n;
    cin>>n;
 
    set<ll> s;
    vector<pair<ll,pair<ll,pair<ll,ll>>>> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i].second.second.first;
       cin>>v[i].second.second.second;

        v[i].second.first = i;
       ll diff = abs(v[i].second.second.first-v[i].second.second.second);
        v[i].first = diff;
    }

    sort(v.begin(),v.end());

    if(n == 1){
        cout<<v[0].second.second.first<<" "<<v[0].second.second.second<<" "<<1<<endl;
        cout<<endl;
        return;
    }

    vector<ll> ans(n);

    ll i = 0;
    ll cnt = 0;
    while(i < n){
        if(cnt == n){
            break;
        }

        if(ans[v[i].second.first] == 0){
            if(v[i].second.second.first == v[i].second.second.second){
                ans[v[i].second.first] = v[i].second.second.first;
                s.insert(v[i].second.second.first);
                cnt++;
            }
            else{
                ll ele = 0;
                ll t = 0;
                
                for(ll j = v[i].second.second.first;j<=v[i].second.second.second;j++){
                    if(s.find(j) != s.end()){

                    }
                    else{
                        t++;
                        ele = j;
                    }
                }

                if(t == 1){
                    ans[v[i].second.first] = ele;
                    s.insert(ele);
                    cnt++;
                }
            }
        }

        i++;
        // i = (i%n);
    }

    for(ll i=0;i<n;i++){
        cout<<v[i].second.second.first<<" "<<v[i].second.second.second<<" "<<ans[v[i].second.first]<<endl;
    }
    cout<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}