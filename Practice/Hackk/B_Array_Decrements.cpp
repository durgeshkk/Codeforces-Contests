#include<bits/stdc++.h>
#include <sstream>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ld long double
//#define int long long
#define maxx ((ll)2e7+7)
#define mod (ll)1000000007//((ll)1e18+7)//998244353//
#define pii pair<ll,ll>
#define loop(i,a,n)     for(ll i=a;i<n;i++)
#define loopr(i,a,n)    for(ll i =n-1;i>=a;i--)
#define vec(a)    (a).begin(),(a).end()
#define arr(a)     a,a+n
#define minArr(a)  *min_element(arr(a))
#define minVec(a)  *min_element(vec(a))
#define maxArr(a)  *max_element(arr(a))
#define maxVec(a)  *max_element(vec(a))
#define setbits(x) __builtin_popcountll(x)
#define dec(x)         cout<<fixed<<setprecision(x)
#define inp(a,n)        ll a[n];for(ll i = 0;i<n;i++) cin>>a[i];
#define printarr(a)     for(auto i : a) cout<<i<<' ';cout<<"\n";



using namespace std;

bool isPrime(ll n){if(n <= 1)return false;if(n <= 3)return true;if(n%2 == 0 || n%3 == 0)return false;for(ll i=5; i*i<=n; i=i+6)if(n%i == 0 || n%(i+2) == 0)return false;return true;}
ll nextPrime(ll N){if(N<=1)return 2;ll prime = N;bool found = false;while(!found){prime++;if(isPrime(prime))found=true;}return prime;}
ll cl(ll n,ll d){return (n+d-1)/d;}
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*b)/(gcd(a,b));}
bool isPerSquare(long double a) {if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a);}

ll exp(ll x, ll y, ll p) {x %= p; ll res = 1; while (y) {if (y % 2) res = (res * x % p) % p; x = (x * x) % p; y /= 2; } return res;}
ll expo(ll x, ll y) { ll res = 1; while (y) {if (y % 2) res = (res * x % mod) % mod; x = (x * x) % mod; y /= 2; } return res;}
ll add(ll a, ll b) {return (a % mod + b % mod + mod) % mod;}
ll sub(ll a, ll b) {return (a % mod - b % mod + mod) % mod;}
ll mul(ll a, ll b) {return ((a % mod) * (b % mod) + mod) % mod;}
ll inv(ll x) {return expo(x, mod - 2);}
int isbitset(ll n, ll k){if (n & (1ll << (k))) return 1 ;else return 0;}


//ll sv[20000007]={0};
//ll fact[1000006]={0};
//void facto() {fact[0]=1;fact[1]=1;for(ll i=2;i<1000006;i++)fact[i]=(fact[i-1]*i)%mod;}
//void sve() {sv[0]=1;sv[1]=1;for(ll i=2;i<maxx;i++)sv[i] = i;for(ll i=2;i*i<maxx;i++){if(sv[i]==i){for(ll j=i*i;j<maxx;j+=i)if(sv[j] == j)sv[j]=i;}}}//i hai to prime
//ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(expo(fact[r],mod-2)))%mod; res=(res*(expo(fact[n-r],mod-2)))%mod; return res;}
//ll npr(int n,int r) {ll res=1; res=fact[n]; res=(res*(expo(fact[n-r],mod-2)))%mod; return res;}


 
 
 
 
 
 
 
 
 

 void solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    bool f=false;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(b[i]!=0){
            f=true;
        }
    }
    for(ll i=0;i<n;i++){
        if(b[i]>a[i]){
            cout<<"NO\n";
            return;
        }
    }
    if(!f){
        cout<<"YES\n";
    }
    else{
        ll mini=INT_MAX,ind;
        for(ll i=0;i<n;i++){
            if(b[i]!=0 && b[i]<mini){
                mini=b[i];
                ind=i;
            }
        }
        ll ab=a[ind]-b[ind];
        for(ll i=0;i<n;i++){
            a[i]-=ab;
        }
        for(ll i=0;i<n;i++){
            if(b[i]!=0 && a[i]!=b[i]){
                cout<<"NO\n";
                return;
            }
            else if(b[i]==0 && a[i]>0){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
    
    
    
    
        
    
    
    
    
      
      
      
      
      
      
      
 }







int main(){
    IOS;
    //sve();
   // facto();
    //compute();
    //compute2();
    ll t=1;
    cin>>t;

    for(ll x=1;x<=t;x++){
      //cout<<"Case #"<<x<<": ";  
      solve();
      





    }
}





































