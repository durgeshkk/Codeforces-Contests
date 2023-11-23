#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
/*  TLE :   
    ll a1,p1;
    cin>>a1>>p1;

    ll a2,p2;
    cin>>a2>>p2;

    long double x=a1,y=a2;


    // while(p1>0){
    if(p1>0){
        while(p1>0){
            // double ansx = pow(10,p1);
            // cout<<"ansx "<<ansx<<endl;
            // x = x*ansx*1.0;
            x = x*10;
            p1--;
        }
    }

    // while(p2>0){
    if(p2>0){
        while(p2>0){
            // double ansx = pow(10,p1);
            // cout<<"ansx "<<ansx<<endl;
            // x = x*ansx*1.0;
            y = y*10;
            p2--;
        }

        // double ansy = pow(10,p2);
        // cout<<"ansy "<<ansy<<endl;
        // y = y*ansy*1.0;
        // p2--;
    }

    // cout<<x<<" "<<y<<endl;

    if(x>y){
        cout<<">\n";
    }

    else if(x<y){
        cout<<"<\n";
    }

    else {
        cout<<"=\n";
    }
*/
    string x1,x2;
    ll p1,p2;

    cin>>x1>>p1;
    cin>>x2>>p2;

    ll l1 = x1.size() + p1;
    ll l2 = x2.size() + p2;
    
    if(l1 > l2){
        cout<<">\n";
    }
    else if(l1<l2){
        cout<<"<\n";
    } 
    else{
        while(x2.size()<x1.size()){
            x2 += '0';
        }

        while(x2.size()>x1.size()){
            x1 += '0';
        }
        
        if(x1 > x2){
          cout<<">\n";
        }
        else if(x1<x2){
            cout<<"<\n";
        }
        else{
            cout<<"=\n";
        } 
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