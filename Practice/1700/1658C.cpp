#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define MOD 998244353
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    /*
    Such permutation is only possible when & only when : 
    1. 1 exists in an array if the maximum element in array is at ind 0
    1 can only exist once in an array when the largest ele is at the ind = 0..ek se jyada
    baar 1 nhi aa sakta since agar ayya toh cycle will repeat & it will voilate permutation
    property.
    2. the difference between each adjacent array ele must be i-1,i,i+1 ..
    e.g. for 2 adjacent ele should only be either 1,2,3 & not 4 or 5..
    */

   vector<ll> c(n);
   for(ll i=0;i<n;i++){
       cin>>c[i];
   }

   auto it = find(c.begin(),c.end(),1);//if 1 is present then only go ahead else return No
   if(it == c.end()){
       cout<<"NO\n";
       return;
   }

   rotate(c.begin(),it,c.end());//rotate the vector
// 2 3 1 2 3 4 -> 1 2 3 4 3 2

    for(int i=1;i<n;i++){
        if(c[i] > c[i-1]+1 || c[i]==1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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