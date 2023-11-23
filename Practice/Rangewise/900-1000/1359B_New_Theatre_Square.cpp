#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m,x,y;
    cin>>n>>m>>x>>y;

    ll count21 = 0; 
    ll count11 = 0; 
    ll count11cheap = 0;

    for(ll i=0;i<n;i++){
       string ele;
       cin>>ele;

       for(ll i=0;i<ele.length()-1;i++){
           if(ele[i] == '.' && ele[i+1] == '.'){
               ele[i] = '*';
               ele[i+1] = '*';
               count21++;
               count11cheap += 2;
               i++;
           }
           else if(ele[i] == '.' && ele[i+1] == '*'){
               count11++;
               ele[i] = '*';
           }
       }

       if(ele[ele.size()-2] == '*' && ele[ele.size()-1] == '.'){
           count11++;
       }
       else if(ele[ele.size()-1] == '.' && ele.length()==1){
           count11++;
       }

    //    cout<<count21<<" "<<count11<<endl;
    }

    if(((count11cheap+count11)*x) >= (count21*y + count11*x)){
        cout<<count21*y + count11*x<<endl;
    }
    else{
        cout<<count11cheap*x + count11*x<<endl;
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
//    solve();
   return 0;
}