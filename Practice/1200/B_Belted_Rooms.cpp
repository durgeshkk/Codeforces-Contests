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

    string s;
    cin>>s;
/*
    char prev = s[0];
    ll cnt = 0;
    for(ll i=1;i<n;i++){
        if(s[i] == '-'){
            continue;
        }

        if(s[i] == '>' && prev == '<'){
            cnt++;
        }
        else if(s[i] == '<' && prev == '>'){
            cnt++;
        }

        prev = s[i];
    }

    if(cnt != (n-2)){
        if(s[0] == '>' && s[s.size()-1] == '<'){
            cnt++;
        }
        else if(s[0] == '<' && s[s.size()-1] == '>'){
            cnt++;
        }
    }

    ll ans = s.size()-cnt;
    if(cnt == (n-1)){
        ans = 0;
    }
    cout<<ans<<endl;*/

    bool hasCW = false,hasACW = false;
    for(ll i=0;i<n;i++){
        if(s[i] == '>'){
            hasACW = true;
        }
        else if(s[i] == '<'){
            hasCW = true;
        }
    }

    if(hasCW && hasACW){
		int ans = 0;
		s += s[0];
		for(int i = 0;i < n;i++){
			if(s[i] == '-' || s[i+1] == '-') {
                ans++;
            }
		}
		cout << ans << "\n";
	}
	else{
		cout << n << "\n";
	}
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