#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    string s;cin>>s;
/*
If the len is odd then victory is in Raze hand
& as he wants to win so he will keep the last
digit as odd to win & consume all even digits

If the len is even then victory is in Breach hand
& as he wants to win so he will keep the last
digit as even to win & consume all odd digits
*/

/*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }
*/
    if(n%2 == 0){
        for(ll i=1;i<n;i+=2){
            if(s[i]%2 == 0){
                cout<<2<<endl;
                return;
            }
        }
        cout<<1<<endl;
    }
    else{
        for(ll i=0;i<n;i+=2){
            if(s[i]%2 != 0){
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
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