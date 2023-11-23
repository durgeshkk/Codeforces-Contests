#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    int n=0;
    cin>>n;
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
    // cout<<n<<endl;
    for(int i=0;i<=150;i++){
        int left = n-(7*i);
        for(int j=0;j<=250;j++){
            int Left = (left- 5*j);

            if((Left >=0) && (Left%3 == 0)){
                cout<<(Left/3)<<" "<<j<<" "<<i<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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