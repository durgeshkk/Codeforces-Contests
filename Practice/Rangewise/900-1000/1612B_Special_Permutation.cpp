#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;

    if((b>a) && ((b<=(n/2)) || (a > (n/2)))){
        cout<<-1<<endl;
        return;
    }

    ll l_count=0;
    ll r_count=0;

    vector<ll> vl;
    vector<ll> vr;

    if((a > b)){
        if((b == (n/2)) && ((b+1) == a)){//iske alawa koi bhi case is not pssbl
            for(ll i=1;i<=n/2;i++){
                vr.push_back(i);
                r_count++;
            }
            for(ll i=((n/2)+1);i<=n;i++){
                vl.push_back(i);
                l_count++;
            }
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    else{//a<b(l<r)
        vl.push_back(a);
        vr.push_back(b);

        l_count=1,r_count=1;

        for(ll i=1;i<a;i++){
            vr.push_back(i);
            r_count++;
        }
        for(ll i=b+1;i<=n;i++){
            vl.push_back(i);
            l_count++;
        }

        ll i=a+1;
        while(i != b){
            if(l_count < (n/2)){
                vl.push_back(i);
                l_count++;
            }
            else{
                vr.push_back(i);
                r_count++;
            }
            i++;
        }
    }

    for(ll i=0;i<vl.size();i++){
        cout<<vl[i]<<" ";
    }
    for(ll i=0;i<vr.size();i++){
        cout<<vr[i]<<" ";
    }
    cout<<endl;
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