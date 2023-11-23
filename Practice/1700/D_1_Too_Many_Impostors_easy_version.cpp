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

// Implementation is Pending, commented part
// Logic is also a bit wrong!!
void solve()
{
 
    ll n;cin>>n;

    ll m = n/4;
    ll mad = n%4;
    ll fc = -1,fi = -1;

    vector<ll> ans;
    for(ll i=0;i<m;i++){
        ll a = i*4+1;
        ll b = a+1,c = a+2,d = a+3;
        map<ll,ll> mp;

        cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
        fflush(stdout);
        ll ans1,ans2,ans3,ans4;
        cin>>ans1;mp[ans1]++;

        cout<<"? "<<a<<" "<<b<<" "<<d<<endl;
        fflush(stdout);
        cin>>ans2;mp[ans2]++;

        cout<<"? "<<a<<" "<<c<<" "<<d<<endl;
        fflush(stdout);
        cin>>ans3;mp[ans3]++;

        cout<<"? "<<b<<" "<<c<<" "<<d<<endl;
        fflush(stdout);
        cin>>ans4;mp[ans4]++;
        
        if(mp.size() == 1){
            // One of I, C present
            // All r I/C or one of them is different from other all 
            if(ans1 == 0){
                if(fi == -1){
                    fi = a;
                }
                ans.push_back(a);
                ans.push_back(b);
                ans.push_back(c);
                ans.push_back(d);
            }else{
                if(fc == -1){fc = a;}
            }
        }else{
            // Both I & C present
            if(ans1 == ans2){
                // a n b njoy same grp
                if(ans1 == 0){
                    ans.push_back(a);
                    ans.push_back(b);
                    if(fi == -1){
                        fi = a;
                    }
                }else{if(fc == -1){fc = a;}}
            }
            else if(ans1 == ans3){
                if(ans1 == 0){
                    ans.push_back(a);
                    ans.push_back(c);
                    if(fi == -1){
                        fi = a;
                    }
                }else{if(fc == -1){fc = a;}}
            }
            else if(ans1 == ans4){
                if(ans1 == 0){
                    ans.push_back(a);
                    ans.push_back(d);
                    if(fi == -1){
                        fi = a;
                    }
                }else{if(fc == -1){fc = a;}}
            }
            else if(ans2 == ans3){
                if(ans2 == 0){
                    ans.push_back(b);
                    ans.push_back(c);
                    if(fi == -1){
                        fi = b;
                    }
                }else{if(fc == -1){fc = b;}}
            }
            else if(ans2 == ans4){
                if(ans2 == 0){
                    ans.push_back(b);
                    ans.push_back(d);
                    if(fi == -1){
                        fi = b;
                    }
                }else{if(fc == -1){fc = b;}}
            }
            else if(ans3 == ans4){
                if(ans3 == 0){
                    ans.push_back(c);
                    ans.push_back(d);
                    if(fi == -1){
                        fi = d;
                    }
                }else{if(fc == -1){fc = d;}}
            }
        }
    }

    if(mad == 1){
        ll a = 4*m+1; 
        cout<<"? "<<fi<<" "<<fc<<" "<<a<<endl;
        fflush(stdout);
        ll j;cin>>j;
        if(j == 0){ans.push_back(a);}
    }else if(mad == 2){
        ll a = 4*m+1;
        ll b = a+1; 
        
        cout<<"? "<<fi<<" "<<fc<<" "<<a<<endl;
        fflush(stdout);
        ll j;cin>>j;
        if(j == 0){ans.push_back(a);}
        
        cout<<"? "<<fi<<" "<<fc<<" "<<b<<endl;
        fflush(stdout);
        cin>>j;
        if(j == 0){ans.push_back(b);}

    }else if(mad == 3){
        ll a = 4*m+1;
        ll b = a+1,c = a+2; 

        cout<<"? "<<fi<<" "<<fc<<" "<<a<<endl;
        fflush(stdout);
        ll j;cin>>j;
        if(j == 0){ans.push_back(a);}
        
        cout<<"? "<<fi<<" "<<fc<<" "<<b<<endl;
        fflush(stdout);
        cin>>j;
        if(j == 0){ans.push_back(b);}

        cout<<"? "<<fi<<" "<<fc<<" "<<c<<endl;
        fflush(stdout);
        cin>>j;
        if(j == 0){ans.push_back(c);}
    }

    ll val = ans.size();
    cout<<"! "<<val<<" ";
    // fflush(stdout);
    show(ans);
    fflush(stdout);
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