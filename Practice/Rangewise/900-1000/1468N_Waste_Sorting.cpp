#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll c1,c2,c3;
    cin>>c1>>c2>>c3;

    ll a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;

    c1 = c1-a1;
    c2 = c2-a2;
    c3 = c3-a3;

    if(c1 <0 || c2<0 || c3<0){
        cout<<"NO\n";
        return;
    }

    if(c1>=a4 && c2>=a5){
        cout<<"YES\n";
    }
    else if(c1 >= a4){//but c2<a5
        a5 = a5-c2;
        if(a5 > c3){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    else if(c2 >= a5){//but c1<a4
        a4 = a4-c1;
        if(a4 > c3){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    else{//both c1<a4 && c2<a5
        a4 = a4-c1;
        a5 = a5-c2;
        if((a4+a5) > c3){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }

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
   return 0;
}