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

    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }
/*
    if(mp.size() == 1){
        cout<<0<<endl;
        return;
    }
// /*
    ll f = 0;
    for(auto it:mp){
        if(it.second == 1){
            if((it.first == v[0]) || ((it.first == v[n-1]))){
                cout<<1<<endl;
                return;
            }
            f = 1;
        }

        if(it.second == 2){
            if((it.first == v[0]) || ((it.first == v[n-1]))){
                cout<<1<<endl;
                return;
            }
            f = 1;
        }
    }

    if(f == 1){
        cout<<2<<endl;
        return;
    }

    ll cnt = INT16_MAX;
    for(auto it:mp){

        ll idx1=-1,idx2=-1;
        ll ans = 0;
        ll i = 0,j=(n-1);
        for(i;i<n;i++){
            if(v[i] == it.first){
                idx1 = i;
                break;
            }
        }
        
        for(j;j>=0;j--){
            if(v[j] == it.first){
                idx2 = j;
                break;
            }
        }

        ll seg = ((it.second)+1);
        if(i == 0){
            seg--;
        }

        if(j == (n-1)){
            seg--;
        }

        for(ll i = 0;i<n-1;i++){
            if((v[i] == it.first) && (v[i+1] == it.first)){
                seg--;
            }
        }
        cnt = min(cnt,seg);
    }
    cout<<cnt<<endl;
*/

    vector<ll> ans(n+1,1);
    n = unique(v.begin(),v.end()) - v.begin();
    v.resize(n);
    for (int i = 0; i < n; ++i) {
		ans[v[i]] += 1;
	}

	ans[v[0]] -= 1;
	ans[v[n - 1]] -= 1;
	
    ll cnt = 1e9;
	for (int i = 0; i < n; ++i) {
		cnt = min(cnt, ans[v[i]]);
	}
	cout << cnt << endl;
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