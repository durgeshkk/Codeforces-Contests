#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 /*
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }
    
    ll rem = 0;
    // cout<<n<<" "<<rem<<endl;
    while(n != 0){
        rem = n%10;
        // cout<<n<<" "<<rem<<endl;
        if(rem == 4 || rem== 7){
        }
        else{
            cout<<"NO\n";
            return;
        }
        // cout<<n<<" "<<rem<<endl;
        n /= 10;
    }
    cout<<"YES\n";*/
   string s;
   cin>>s;

    ll lucky_num = 0;

   for(ll i=0;i<s.length();i++){
       if(s[i] == '4' || s[i] == '7'){
           lucky_num++;
       }
   }

   if(lucky_num == 4 || lucky_num == 7){
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
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}