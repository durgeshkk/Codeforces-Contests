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

void solve()
{
 
    ll n;
    cin>>n;

    vector<string> s1(n),s2(n),s3(n);
    enter(s1);
    enter(s2);
    enter(s3);

    map<string,ll> mp1;
    map<string,ll> mp2;
    map<string,ll> mp3;

    for(ll i=0;i<n;i++){
        mp1[s1[i]]++;
        mp2[s2[i]]++;
        mp3[s3[i]]++;
    }

    ll p1 = 0;
    for(auto it:mp1){
        ll f = 1;
        if(mp2.find(it.first) != mp2.end()){
            ++f;
        }   
        
        if(mp3.find(it.first) != mp3.end()){
            ++f;
        }   

        if(f == 1){
            p1 += 3;
        }
        else if(f == 2){
            p1 += 1;
        }
        else if(f == 3){
            p1 += 0;
        }

    }
    cout<<p1<<" ";

    ll p2 = 0;
    for(auto it:mp2){
        ll f = 1;
        if(mp1.find(it.first) != mp1.end()){
            ++f;
        }   
        
        if(mp3.find(it.first) != mp3.end()){
            ++f;
        }   

        if(f == 1){
            p2 += 3;
        }
        else if(f == 2){
            p2 += 1;
        }
        else if(f == 3){
            p2 += 0;
        }

    }
    cout<<p2<<" ";

    ll p3 = 0;
    for(auto it:mp3){
        ll f = 1;
        if(mp2.find(it.first) != mp2.end()){
            ++f;
        }   
        
        if(mp1.find(it.first) != mp1.end()){
            ++f;
        }   

        if(f == 1){
            p3 += 3;
        }
        else if(f == 2){
            p3 += 1;
        }
        else if(f == 3){
            p3 += 0;
        }

    }
    cout<<p3<<endl;

/*


    ll p1 = 0;
    for(ll i=0;i<n;i++){
        ll f = 1;
        for(ll j = 0;j<n;++j){
            if(s1[i] == s2[j]){
                ++f;
                break;
            }
        }

        for(ll k = 0;k<n;++k){
            if(s1[i] == s3[k]){
                ++f;
                break;
            }
        }

        if(f == 1){
            p1 += 3;
        }
        else if(f == 2){
            p1 += 1;
        }
        else if(f == 3){
            p1 += 0;
        }
    }
    cout<<p1<<" ";

    ll p2 = 0;
    for(ll i=0;i<n;i++){
        ll f = 1;
        for(ll j = 0;j<n;++j){
            if(s2[i] == s1[j]){
                ++f;
                break;
            }
        }

        for(ll k = 0;k<n;++k){
            if(s2[i] == s3[k]){
                ++f;
                break;
            }
        }

        if(f == 1){
            p2 += 3;
        }
        else if(f == 2){
            p2 += 1;
        }
        else if(f == 3){
            p2 += 0;
        }
    }
    cout<<p2<<" ";

    ll p3 = 0;
    for(ll i=0;i<n;i++){
        ll f = 1;
        for(ll j = 0;j<n;++j){
            if(s3[i] == s2[j]){
                ++f;
                break;
            }
        }

        for(ll k = 0;k<n;++k){
            if(s3[i] == s1[k]){
                ++f;
                break;
            }
        }

        if(f == 1){
            p3 += 3;
        }
        else if(f == 2){
            p3 += 1;
        }
        else if(f == 3){
            p3 += 0;
        }
    }
    cout<<p3<<endl;
    */
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}