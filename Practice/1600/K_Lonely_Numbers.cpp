#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+5;

#define SIEVE
int primes[N];
vector<int> pr,prs;
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i*i;j<N;j+=i){
				primes[j]=1;
			}
		}
		primes[i]^=1;
	}
	
	for(int x:pr){
		prs.pb(x*x);
	}
}

void solve(){
	int n;
	cin >> n;
	int ans = 1 + upper_bound(all(pr),n) - pr.begin() - (upper_bound(all(prs),n) - prs.begin());
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}

/*
#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 1e6+5;

#define SIEVES
int sieve[N];
vector<int> pr,sq;
void createsieve(){
    for(int i = 2;i<N;++i){
        if(sieve[i] == 0){
            pr.push_back(i);
            for(int j = i*i;j<N;j+=i){
                sieve[j] = 1;
            }
        }
        sieve[i] ^= 1;//Tp
    }

    for(int x:pr){
        sq.push_back(x*x);
    }
}
 
void solve()
{
    int n;cin>>n;
    int ans = 1+(upper_bound(pr.begin(),pr.end(),n)-pr.begin())-(upper_bound(sq.begin(),sq.end(),n)-sq.begin());
    cout<<ans<<endl;
    return;
}
 
signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   #ifdef SIEVES
       createsieve();
   #endif
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}*/