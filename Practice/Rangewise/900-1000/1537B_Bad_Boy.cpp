#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,m,i,j;
    cin>>n>>m>>i>>j;

    ll a = abs(1-i)+abs(1-j);
    ll b = abs(1-i)+abs(m-j);
    ll c = abs(n-i)+abs(1-j);
    ll d = abs(n-i)+abs(m-j);

    ll s1 = a+b+(m-1);
    ll s2 = a+c+(n-1);
    ll s3 = a+d+(m+n-2);
    ll s4 = b+c+(m+n-2);
    ll s5 = b+d+(n-1);
    ll s6 = c+d+(m-1);

    ll mx = max(s1,max(s2,max(s3,max(s4,max(s5,s6)))));

    if(mx == s1){
        cout<<1<<" "<<1<<" ";
        cout<<1<<" "<<m<<endl;
    }
    else if(mx == s2){
        cout<<1<<" "<<1<<" ";
        cout<<n<<" "<<1<<endl;
    }
    else if(mx == s3){
        cout<<1<<" "<<1<<" ";
        cout<<n<<" "<<m<<endl;
    }
    else if(mx == s4){
        cout<<1<<" "<<m<<" ";
        cout<<n<<" "<<1<<endl;
    }
    else if(mx == s5){
        cout<<1<<" "<<m<<" ";
        cout<<n<<" "<<m<<endl;
    }
    else if(mx == s6){
        cout<<n<<" "<<1<<" ";
        cout<<n<<" "<<m<<endl;
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