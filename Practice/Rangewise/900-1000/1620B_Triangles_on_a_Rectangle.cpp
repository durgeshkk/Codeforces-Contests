#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll w,h;
    cin>>w>>h;

    ll kx1;
    cin>>kx1;

    vector<ll> vx1;
    for(int i=0;i<kx1;i++){
        ll ele;
        cin>>ele;
        vx1.push_back(ele);
    }
    
    ll x1 = (vx1[vx1.size()-1]) - vx1[0];

    ll kx2;
    cin>>kx2;

    vector<ll> vx2;
    for(int i=0;i<kx2;i++){
        ll ele;
        cin>>ele;
        vx2.push_back(ele);
    }
    ll x2 = (vx2[vx2.size()-1]) - vx2[0];

    ll xmax = max(x1,x2);
    ll ansx = xmax*h;

    ll ky1;
    cin>>ky1;

    vector<ll> vy1;
    for(int i=0;i<ky1;i++){
        ll ele;
        cin>>ele;
        vy1.push_back(ele);
    }
    ll y1 = (vy1[vy1.size()-1]) - vy1[0];
    
    ll ky2;
    cin>>ky2;

    vector<ll> vy2;
    for(int i=0;i<ky2;i++){
        ll ele;
        cin>>ele;
        vy2.push_back(ele);
    }

    ll y2 = (vy2[vy2.size()-1]) - vy2[0];

    ll ymax = max(y1,y2);
    ll ansy = ymax*w;

    cout<<max(ansx,ansy)<<endl;
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