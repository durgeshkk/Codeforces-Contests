#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    if(n >= 46){
        cout<<-1<<endl;
    }
    else if(n <= 9){
        cout<<n<<endl;
    }
    else if(n>= 9 && n<=17){
        cout<<n-9;
        cout<<9<<endl;
    }
    else if(n> 17 && n<=24){
        cout<<n-(17);
        cout<<89<<endl;
    }
    else if(n>24 && n<=30){
        cout<<n-24;
        cout<<789<<endl;
    }
    else if(n>30 && n<=35){
        cout<<n-30;
        cout<<6789<<endl;
    }
    else if(n>35 && n<=39){
        cout<<n-35;
        cout<<56789<<endl;
    }
    else if(n>39 && n<=42){
        cout<<n-39;
        cout<<456789<<endl;
    }
    else if(n>42 && n<=44){
        cout<<n-42;
        cout<<3456789<<endl;
    }
    else if(n == 45){
        cout<<123456789<<endl;
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