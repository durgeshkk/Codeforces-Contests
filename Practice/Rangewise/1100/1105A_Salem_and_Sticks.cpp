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
 
int a[1010];
int n;

int calc(int t){
    int i;
    int ret = 0;
    for(i=0;i<n;i++){
        if(a[i] < (t-1)){
            ret+=t-1-a[i];
        }

        if(a[i] > (t+1)){
            ret+=a[i]-t-1;
        }
    }

    return ret;
}

void solve()
{
    cin>>n;

    for(ll i=0;i<n;i++){
       cin>>a[i];
    }

    if(n == 1){
        cout<<a[0]<<" "<<0<<endl;
        return;
    }
/* INT DIV ERROR
    ll t = -1;
    ll sm = INT16_MAX;
    ll mx = *max_element(v.begin(),v.end());

    for(ll i = 1;i<=mx;i++){
        
        ll cost = 0;
        for(ll j = 0;j<v.size();j++){

            if(v[j] == i){

            }
            else if(v[j] > i){
                if(abs(v[j]-i) == 1){

                }
                else{
                    cost += (v[j] - (i+1));
                }
            }
            else{ // v[j] < i
                if(abs(v[j]-i) == 1){

                }
                else{
                    cost += ((i-1) - v[j]);
                }

            }
        }

        if(sm > cost){
            sm = cost;
            t = i;
        }

        if(sm >= cost && t == -1){
            sm = cost;
            t = i;
        }
    }

    cout<<t<<" "<<sm<<endl;*/

    sort(a,a+n);
    int ans = 100000;
    int ct=-1;
    for(int t=2;t<100;t++){

        int r = calc(t);
        if(r < ans){
            ct = t;
            ans = r;
        }
        // ans = min(ans,calc(t));
    }

    cout<<ct<<" "<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
   return 0;
}