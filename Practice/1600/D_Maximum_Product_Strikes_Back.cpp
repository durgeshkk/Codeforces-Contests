//CELEBRATING SEMIANNIVERSARY OF DADDY_DYNAMO!!
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
1. Count only no. of 2's before 0
2. Keep the track of first and last neg no.
3. if prdt is max update a and b else move ahead..
*/

void solve(){
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll f = 0,t = -1;
    ll neg = 0;
    ll z = 0;
    // ll dk = 0,ag = 0;
    ll cnt = 0;

    for(ll i=0;i<n;i++){
        if((v[i] == 2) || (v[i] == -2)){
            f = 1;
        }

        if(v[i] == 0){
            ++z;
        }
        
        if(v[i] < 0){
            ++neg;
        }
    }

    ll ag = 0, dk = 0;
    if(z == 0){
        if(neg & 1){
            ll flag = 0;
            ll t_till = 0;
            ll a = 0, b = 0;
            ll idx1 = 0,idx2 = 0;

            for(ll i = 0;i<n;++i){
                if(v[i] == 2 || v[i] == -2){
                    ++t_till;
                }

                if(v[i] < 0){
                    if(flag == 0){
                        a = t_till;
                        flag ^= 1;
                        idx1 = i;
                        idx2 = i;
                    }else{
                        b = 0;
                        idx2 = i;
                    }
                }

                if((v[i] == 2 || v[i] == -2) and flag == 1){
                    ++b;
                }
            }

            if(a > b){
                ag = n-idx2;
            }else{
                dk = idx1+1;
            }

        }

        cout<<dk<<" "<<ag<<endl;
    }else{
        ll flag = 0;
        ll t_till = 0;
        ll a = 0, b = 0;
        ll idx1 = 0,idx2 = 0;
        ll prdt = 0;
        neg = 0;
        ll prev = -1;

        for(ll i = 0;i<n;++i){
            if(v[i] == 0){
                // cout<<a<<" "<<b<<endl;
                // cout<<idx1<<" "<<idx2<<endl;

                if(neg & 1){
                    t_till -= min(a,b);
                    if(t_till > prdt){
                        if(a < b){
                            dk = idx1+1;
                            ag = (n-i);
                        }else{
                            dk = prev+1;
                            ag = (n-idx2);
                        }
                        prdt = t_till;
                    }
                }else{
                    if(t_till > prdt){
                        dk = prev + 1;
                        ag = (n-i);
                        prdt = t_till;
                    }
                }
                prev = i;
                flag = 0;
                t_till = 0;
                a = 0,b = 0;
                neg = 0;
            }

            if(v[i] == 2 || v[i] == -2){
                ++t_till;
            }

            if(v[i] < 0){
                if(flag == 0){
                    a = t_till;
                    flag ^= 1;
                    idx1 = i;
                    idx2 = i;
                }else{
                    b = 0;
                    idx2 = i;
                }
                ++neg;
            }

            if((v[i] == 2 || v[i] == -2) and (flag == 1)){
                ++b;
            }
        }

        // cout<<"\n";
        // cout<<t_till<<" "<<prdt<<endl;
        //     cout<<a<<" "<<b<<endl;
        //     cout<<idx1<<" "<<idx2<<endl;

        if(neg & 1){
            t_till -= min(a,b);
            if(t_till > prdt){
                if(a < b){
                    dk = idx1+1;
                    ag = (0);
                }else{
                    dk = prev+1;
                    ag = (n-idx2);
                }
                prdt = t_till;
            }
        }else{

            if(t_till > prdt){
                dk = prev + 1;
                ag = (0);
                prdt = t_till;
            }
        }

        if(prdt == 0){
            dk = n;ag = 0;   
        }

        cout<<dk<<" "<<ag<<endl;
    }
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
   return 0;
}

/*
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll f = 0,t = -1;
    ll neg = 0;
    ll z = 0;
    for(ll i=0;i<n;i++){
        if((v[i] == 2) || (v[i] == -2)){
            f = 1;
        }
        if(v[i] == 0){
            ++z;
        }
        
        if(v[i] < 0){
            ++neg;
        }
    }

    if(f == 0){
        cout<<n<<" "<<0<<endl;
        return;
    }

    if(z == 0){
        ll ak = 1,ag = 1;
        ll idx1 = -1,idx2 = -1;

        if(neg & 1){
            ll p = 1;
            for(ll i = 0;i<n;++i){
                p *= v[i];
                if(v[i] < 0){
                    ak = p;
                    idx1 = i;
                    break;
                }
            }
            
            p = 1;
            for(ll i = n-1;i>=0;--i){
                p *= v[i];
                if(v[i] < 0){
                    idx2 = i;
                    ag = p;
                    break;
                }
            }

            if(ak > ag){
                cout<<idx1+1<<" "<<0<<endl;
            }else{
                cout<<0<<" "<<n-idx2<<endl;
            }
        }else{
            cout<<0<<" "<<0<<endl;
        }
        return;
    }
    else{
        ll ne = 0;
        ll prdt = 1;
        ll flag = 0;
        ll ak = 1,ag = 1;
        ll p = 1;
        ll idx1 = -1, idx2 = -1;
        ll a,b;ll prev = 0;

        for(ll i = 0;i<n;++i){
            if(v[i] == 0){
                cout<<idx1<<" "<<idx2<<endl;
                // cout<<ak<<" "<<ag<<endl;
                if(ne & 1){
                    if(abs(p) > prdt){
                        if(ak > ag){
                            p /= (ak);
                            if(p > prdt){
                                a = idx1,b = n-i-1;
                            }
                            // cout<<idx1+1<<" "<<0<<endl;
                        }else{
                            p /= (ag);
                            if(p > prdt){
                                a = prev;
                                b = (n-idx2-1);
                            }
                            // cout<<0<<" "<<n-idx2<<endl;
                        }
                    }
                }else{
                    if(p > prdt){
                        prdt = p;
                        a = prev,b = n-i-1;
                    }
                }
                p = 1;
                flag = 0;
                ne = 0;
                ak = -10,ag = -10;
                idx1 = -1,idx2 = -1;
                prev = i;
                continue;
            }

            ag *= v[i];
            p *= v[i];
            
            if(v[i] < 0){
                ++ne;
                if(ne == 1){
                    ak = ag;
                    ag = v[i];
                    flag = 1;
                    idx1 = i;
                }else{
                    ag = v[i];
                    idx2 = i;
                }
            }
        }
    
        if(ne & 1){
            if(abs(p) > prdt){
                if(ak > ag){
                    p /= (ak);
                    if(p > prdt){
                        a = idx1,b = (-1);
                    }
                    // cout<<idx1+1<<" "<<0<<endl;
                }else{
                    p /= (ag);
                    if(p > prdt){
                        a = prev,b = (n-idx2-1);
                    }
                    // cout<<0<<" "<<n-idx2<<endl;
                }
            }
        }else{
            if(p > prdt){
                prdt = p;
                a = prev,b = (-1);
            }
        }

        if(prdt != 1){
            cout<<a+1<<" "<<b+1<<endl;
        }else{
            cout<<n<<" "<<0<<endl;
        }
    }

    return;
}
 */
