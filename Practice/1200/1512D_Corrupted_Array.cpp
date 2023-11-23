#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    int n;
    cin>>n;

    vector<int> v(n+2);
    for(int i=0;i<n+2;i++){
       cin>>v[i];
    }
    
    multiset<int> mp(v.begin(),v.end());
    // sort(v.begin(),v.end());

    // for(ll i=0;i<n+2;i++){
    //    cout<<v[i]<<" ";
    // }
    // cout<<endl;

    ll sm = accumulate(v.begin(),v.end(),0LL);
    // cout<<sm<<endl;

    for(ll x : v){
        mp.erase(mp.find(x));
        sm -= x;

        if((sm%2 == 0) && (sm<=2'000'000'000) && (mp.find(sm/2) != mp.end())){
            mp.erase(mp.find(sm/2));

            for(int y : mp){
                cout<<y<<" ";
            }
            cout<<endl;
            return;
        }
        sm += x;
        mp.insert(x);
    }
/*
    ll idx = -1,ele = -1,f = 0;

    for(ll i = 0;i<n+2;i++){
        ll guess = v[i];

            sm += guess;
            continue;
        }
        else{
            ll el = sm/2;
            if(mp.find(el) == mp.end()){
                sm += guess;
                continue;
            }
            else{
                idx = i;
                ele = el;
                f = 1;
                break;
            }
        }
    }

    if(f == 1){
        for(ll i = 0;i<n+2;i++){
            if(i == idx){
                continue;
            }
            if(v[i] == ele && f == 1){
                f = 0;
                continue;
            }
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }*/
    cout<<"-1"<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}