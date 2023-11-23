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

    ll k = 0;
    cin>>k;

    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    // ll mn = *min_element(v.begin(),v.end());
    // ll mx = *max_element(v.begin(),v.end());

    sort(v.begin(),v.end());
/*
    for(ll i=mn;i<=mx;i++){
        mp[i] = 0;
    }*/
    
    for(ll i=0;i<n;i++){
       mp[v[i]]++;
    }

    vector<ll> ans;

    for(auto it:mp){
        if(it.second >= k){
            ans.push_back(it.first);
        }
    }

    if(ans.size() == 0){
        cout<< -1 <<endl;
        return;
    }

    sort(ans.begin(),ans.end());
    ll mx = 0;
    ll idx1 = ans[0],idx2 = ans[0];
    ll l = ans[0];

    for(int i = 1; i < ans.size(); i++)
	{
		if(ans[i]-1 == ans[i-1])
		{
			if(ans[i]-l > mx)
			{
				idx1 = l;
				idx2 = ans[i];
				mx = (ans[i]-l);
			}
		}
		else
		{
			l = ans[i];
		}
	}


/*
    ll f = 0,l = -2,r = -3;
    ll ans = -1;
    ll cnt = 0;

    if(mp.size() == 1){
        if(mp[mn] >= k){
            cout<<mn<<" "<<mn<<endl;
        }
        else{
            cout<< -1 << endl;
        }
        return;
    }
    for(auto it:mp){
        if(it.second >= k && (f==0)){
            f = 1;
            l = it.first;
            r = it.first;
            cnt++;
        }
        
        else if(it.second >= k && (f==1)){
            // f = 1;
            if(mp.find(it.first-1) != mp.end()){
                r = it.first;
            }
            // if((it.first - l) == 1){
            // }
            else{
                f = 0;
                continue;
            }
        }
        
        else if(it.second < k && (f==1)){
            f = 0;
        }

        if(ans < (r-l)){
            idx1 = l;
            idx2 = r;
        }
        ans = max(ans,r-l);
    }

    if(cnt == 0){
        cout<< -1 << endl;
        return;
    }

    // if((ans == 0) || (idx1 == idx2)){
    //     cout<<idx1<<" "<<idx2<<endl;
    //     return;
    // }

*/
    cout<<idx1<<" "<<idx2<<endl;
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