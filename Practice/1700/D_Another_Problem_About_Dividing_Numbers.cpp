#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void yno(ll f){
    if(f & 1) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
  
ll num1,num2;  
// vector<ll> num1,num2;  
/*
ll primeFactors(ll n) 
{ 
    ll cnt = 0;
    while (n % 2 == 0){ 
        ++cnt;
        n = n/2; 
    } 
 
    for (ll i = 3; i <= sqrt(n); i += 2){ 
        while (n % i == 0){ 
            ++cnt;
            n = n/i; 
        } 
    } 
 
    if (n > 2)
        ++cnt;
    return cnt;
} 
*/

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> v1 = sieve(1e5);
ll primeFactors(ll a) {
	ll count1 = 0;
	for (auto i : v1) {
		if (i > a)
			break;
		if (a % i == 0) {
			while (a % i == 0) {
				count1++;
				a /= i;
			}
		}
	}
	if (a > 1)
		count1++;
	return count1;
}

void solve()
{
    // num1.clear();num2.clear();
    num1 = 0,num2 = 0;
    ll a,b,k;cin>>a>>b>>k;
    ll mn_op = 2,mx_op = 0,f = 1;

    // Check base case of a = 1 and b = 1
    if(a > b){swap(a,b);}
    if(a == 1 and b == 1){if(k > 0){yno(0);}else{yno(1);}return;}
    
    if(a == 1 || b == 1){
        // a = 1
        mn_op = 1;
        num1 = primeFactors(b);
        mx_op = num1;
        // mx_op = num1.size();
        if(k >= mn_op and k <= mx_op){
        }else{
            f = 0;
        }
        yno(f);
        return;
    }

    if(a == b){
        mn_op = 0;
        num1 = primeFactors(a);
        // mx_op = 2*num1.size();
        mx_op = 2*num1;
        if(k >= mn_op and k <= mx_op){
        }else{
            f = 0;
        }
        if(k == 1){f = 0;}
        yno(f);
        return;
    }

    if(b%a == 0){
        mn_op = 1;
        num1 = primeFactors(a);num2 = primeFactors(b);
        // mx_op = num1.size()+num2.size();
        mx_op = num1+num2;
        if(k >= mn_op and k <= mx_op){
        }else{f = 0;}
        yno(f);
        return;
    }
    
    mn_op = 2;
    num1 = primeFactors(a);num2 = primeFactors(b);
    mx_op = (num1+num2);
    // mx_op = (num1.size()+num2.size());
    if(k >= mn_op and k <= mx_op){
    }else{f = 0;}
    yno(f);
    return;
}
 
signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}
