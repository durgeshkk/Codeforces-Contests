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
 
    ll n,m;
    cin>>n>>m;

    ll arr[n][m];
    multiset<pair<int,int>> s;
    // vector<ll> v(n);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll x;
            cin>>x;
            arr[i][j] = -1;
            s.insert({x,i});
        }
    }

// Initialize min. of the row
    for(int j=0;j<m;j++){
        auto itr=s.begin();
        arr[itr->second][j]=itr->first;
        s.erase(itr);
    }

    // Add remaining no's at pos=-1
    while(!s.empty()){
          auto itr=s.begin();
          int in=0;
          while(arr[itr->second][in]!=-1){
                in++;
          }
          arr[itr->second][in]=itr->first;
          s.erase(itr);
    }

/*
    ll min_req = min(m,n);
    ll k = 0;

    ll z = 0;
    multiset<ll> s1;
    for(auto it = s.begin();it!=s.end();it++,z++){
        if(z == min_req){
            break;
        }
        s1.insert(*it);
    }

    for(auto it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++)
        sort(arr[i], arr[i] + m);
    
    ll idx = -1,f=0;
    for(ll i=0;i<n;i++){
        ll pre = 0;

        for(ll j=0;j<m;j++){
            if(s1.find(arr[i][j]) != s1.end()){
                pre++;
            }
            else{
                break;
            }
        }

        if(i == 0){
            idx = pre;
            continue;
        }

        if(idx == min_req){
            f = 1;
            break;
        }

        for(ll j=0;j<pre;j++,idx++){
            if(idx == min_req){
                f = 1;
                break;
            }   
            swap(arr[i][j],arr[i][idx]);
        }

        if(f == 1){
            break;
        }
    }*/

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
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