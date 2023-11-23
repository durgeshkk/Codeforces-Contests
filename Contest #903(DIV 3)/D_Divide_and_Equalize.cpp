// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 1000001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		// checking if i is prime
		if (spf[i] == i) {
			// marking SPF for all numbers divisible by i
			for (int j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<int,int> mp;
void getFactorization(int x)
{
	while (x != 1) {
		mp[spf[x]]++;
		x = x / spf[x];
	}
}

void yno(int f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}
 
void solve(){
    mp.clear();
    int n;cin>>n;
    vector<int> v(n);
    for(auto &it:v){cin>>it;}

    for(auto it:v){
        getFactorization(it);
    }

    int f = 1;
    for(auto it:mp){
        if(it.second%n){f = 0;}
    }
    if(f){
        yno(1);
    }else{
        yno(0);
    }
}
#define ll int
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
    sieve();
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}
