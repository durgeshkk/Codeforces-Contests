#include<bits/stdc++.h>
#include<iomanip>
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
 
    ll n;
    cin>>n;

    vector<ll> v1(n),v2(n);
    for(ll i=0;i<n;i++){
       cin>>v1[i];
    }

    for(ll i=0;i<n;i++){
       cin>>v2[i];
    }

    bool b1 = is_sorted(v1.begin(),v1.end());
    bool b2 = is_sorted(v2.begin(),v2.end());

    if(b1==true && b2==true){
        cout<<0<<endl;
        return;
    }
    /*
    else if(b1==true || b2==true){
        cout<< -1 <<endl;
        return;
    }*/


    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        ll p1 = v1[i];
        ll p2 = v2[i];

        v[i] = make_pair(p1,p2);
    }


    vector<pair<ll,ll>> unsort(v);

    sort(v.begin(),v.end());

    vector<pair<ll,ll>> ans;
/*
    cout<<" V : "<<endl;
    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    
    cout<<" UNS : "<<endl;
    for(auto it:unsort){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    */


    for(ll i =0;i<n;++i){
        ll t1 = v[i].first;
        ll t2 = v[i].second;
        ll f = 0;

        if(unsort[i] == v[i]){
            continue;
        }

        for(ll j = (i+1);j<n;++j){
            if(unsort[j] == v[i]){
                f = 1;
                if(i == j){
                    continue;
                }
                ans.push_back(make_pair(j+1,i+1));
                swap(unsort[i],unsort[j]);
                // cout<<j+1<<" "<<i+1<<endl;
                break;
            }
        }

        if(f == 0){
            cout<< -1 << endl;
            return;
        }
    }
    // cout<<"END\n";

    ll i = 0;
    for(auto it:unsort){
        v1[i] = it.first;
        v2[i] = it.second;
        ++i;
    }

    b1 = is_sorted(v1.begin(),v1.end());
    b2 = is_sorted(v2.begin(),v2.end());
/*
    for(auto it:v1){
        cout<<it<<" ";
    }
    cout<<endl;

    for(auto it:v2){
        cout<<it<<" ";
    }
    cout<<endl;
    */

    if(b1==true && b2 == true){

        cout<<ans.size()<<endl;

        if(ans.size() == 0){
            return;
        }

        for(auto it: ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    else{
        cout<< -1 <<endl;
    }
    // cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}

