#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;

    if((a+c) == (2*b)){
        cout<<"YES\n";
        return;
    }

    float j=1.0;
    float f = (((a*j)+(c*j))/2);
    int i = ((a+c)/2);
    // cout<<f<<" "<<i<<endl;
    if(f==i)
    {
        if(i%b == 0){
            cout<<"YES\n";
            return;
        }
    }

    ll d1 = b-a;
    ll d2 = c-b;
    ll x = b-d2; 
    ll y = b+d1; 

    if(x%a == 0 && x>0){
        cout<<"YES\n";
    }
    else if(y%c == 0 && (y>0)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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