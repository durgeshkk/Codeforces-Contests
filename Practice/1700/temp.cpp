// Lets go to the next level 
// AIM CM at CF *__* asap 
// Hit A,B,C and D faster and reach Candidate Master
// template taken from Striver_79  
// Remember you were also a novice when you started, 
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts 
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.  
// Any doubts or want to have a talk, contact https://www.facebook.com/raj.striver 

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int) 1000000007
#define MOD (int) 1e9+7
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
// Big two primes 
#define X 1001100011100001111ll
#define M 26388279066623ll

#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long 
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int> 
#define fi first
#define se second
#define kitna se
#define endl "\n"
#define pi pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 100);
int gcd(int a,int b) { if (a == 0) return b; return gcd(b%a, a);}
int max(int a,int b){if(a>b) return a; else return b;}
int min(int a,int b){if(a<b) return a; else return b;}  
int cbrt(int x){ int lo=1,hi=min(2000000ll,x);while(hi-lo>1){int mid=(lo+hi)/2;if(mid*mid*mid<x){lo=mid;}else hi=mid;}if(hi*hi*hi<=x) return hi;else return lo;} 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int N =  (int)(1e5+5); 

int dp[N], ans[N]; 
int k; 

int func(int x)
{
  
  if(x<0) return 0; 
  else if(x==0) return 1; 
  else if(dp[x]!=-1) return dp[x]; 
  return dp[x] = (func(x-1) + func(x-k))%mod;   
}
signed main(){
fio;
int t = 1;
cin >> t >> k;
ini(dp,-1); 


for(int i = 1;i<=N-2;i++)
{
  ans[i] = func(i);
  ans[i] += ans[i-1];
  ans[i] %= mod;  
}

for(int i = 1;i<=10;i++){
    cout<<ans[i]<<" "<<dp[i]<<endl;
}

while(t--){ 
  int a,b;
  cin >> a >> b;
  cout << (ans[b]-ans[a-1]+mod)%mod  << endl;
}

   rr; 

}