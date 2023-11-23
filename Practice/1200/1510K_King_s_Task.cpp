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

int fun(vector<ll>v,int k){
	map<vector<ll>, int> mp;
	mp[v]++;
	vector<ll> vv = v;

	sort(vv.begin(),vv.end());

	if(vv==v){
		return 0;
	}

	int c = 0;
	while(true){
		if(vv==v){
			return c;
		}

		if(k==0){
			for (int i = 0; i < v.size()-1;i+=2){
				swap(v[i], v[i + 1]);
			}

			c++;
			
            if(vv==v){
				return c;
			}

			if(mp.find(v)!=mp.end()){
				return -1;
			}
			mp[v]++;
			k = 1;
		}
        else{
			int n = v.size() / 2;
			for (int i = 0; i < n;i++){
				swap(v[i], v[i + n]);
			}
			c++;
			if(vv==v){
				return c;
			}
            
			if(mp.find(v)!=mp.end()){
				return -1;
			}
			mp[v]++;
			k = 0;
		}
	}
	return -1;
}

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n*2);
	for(ll i=0;i<n*2;i++){
		cin >> v[i];
	}

	int k1 = fun(v,0);//start with alternate swap 1st
	int k2 = fun(v,1);//start with (n+1) swap next

	if(k1== -1 && k2==-1){
		cout << -1 << endl;
		return;
	}
	if(k1==-1 || k2==-1){
		if(k1==-1){
			cout << k2 << endl;
			return;
		}
        else{
			cout << k1 << endl;
			return;
		}
	}
    else{
		cout << min(k1, k2) << endl;
	}
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}