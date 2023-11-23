#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
using namespace std;
ll mod = (ll)(1e9+7);

void solve(){
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll sm = 0;
    if(v[0] == 1){
        sm += 1;
    }

    for(ll i=1;i<n-2;i++){
        if(v[i] == 1 && v[i+1] == 1 && v[i+2] == 1){
            ++sm;
            i+=2;
        }
    }

    cout<<sm<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--){
       solve();
   }
   return 0;
}
/*
    for(ll i=0;i<n;i++){
        if(v[i] == 0 && f == 0){//FRND
            if(v[i+1] == 0 && i < (n-1)){
                ++i;
            }
            f = 1;
        }
        else if(v[i] == 1 && f == 0){//FRND
            if(v[i+1] == 0 && i < (n-1)){
                ++i;
            }
            f = 1;
            ++sm;
        }
        else if(v[i] == 0 && f == 1){ //ME
            if(v[i+1] == 1 && i < (n-1)){
                ++i;
            }
            f = 0;
        }
        else if(v[i] == 1 && f == 1){ //ME
            if(v[i+1] == 1 && i < (n-1)){
                ++i;
            }
            f = 0;
        }
        // else{
        //     cout<<"HI\n";
        // }
    }

    ll s = 0;
    f = 1;//frnd picks
    for(ll i=n-1;i>0;i--){
        if(v[i] == 0 && f == 0){//FRND
            if(v[i-1] == 0 && i > 0){
                --i;
            }
            f = 1;
        }
        else if(v[i] == 1 && f == 0){//FRND
            if(v[i-1] == 0 && i > 0){
                --i;
            }
            f = 1;
            ++sm;
        }
        else if(v[i] == 0 && f == 1){ //ME
            if(v[i-1] == 1 && i > 0){
                --i;
            }
            f = 0;
        }
        else if(v[i] == 1 && f == 1){ //ME
            if(v[i-1] == 1 && i > 0){
                --i;
            }
            f = 0;
        }
        // else{
        //     cout<<"HI\n";
        // }
    }
    if(v[0] == 1){
        s += 1;
    }

    sm = min(sm,s);

    if(sm == 0 && v[0] == 1){
        sm = 1;
    }
*/
    