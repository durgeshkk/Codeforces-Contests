#include <bits/stdc++.h>
#define ll long long int
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void update(vector<ll> &Tree, ll idx, ll s,ll e, ll pos, ll X){
	if (s == e){
		Tree[idx] += X;
	}else{
		ll m = (s + e) / 2;

		if (pos <= m) {
			update(Tree, 2 * idx, s, m, pos, X);
		}else {
			update(Tree, 2 * idx + 1, m + 1, e,
				pos, X);
		}

		Tree[idx] = Tree[2 * idx] + Tree[2 * idx + 1];
	}
}

ll sum(vector<ll> &Tree, ll idx, ll s,ll e, ll ql, ll qr){
	if (ql == s && qr == e)
		return Tree[idx];

	if (ql > qr)
		return 0;

	ll m = (s + e) / 2;

	return sum(Tree, 2 * idx, s, m, ql, min(m, qr))+ sum(Tree, 2 * idx + 1, m + 1, e,max(ql, m + 1), qr);
}

ll getElement(vector<ll> &Tree, ll X, ll N){
    return sum(Tree, 1, 0, N - 1, 0, X);
}

void range_Update(vector<ll> &Tree, ll L,ll R, ll X, ll N){
	update(Tree, 1, 0, N - 1, L, 1);
	if (R + 1 < N)
		update(Tree, 1, 0, N - 1, R + 1, -1);
}

/*
Performing with set is also good idea for this type of Q's
*/

void solve()
{
    ll n,q;cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){cin>>v[i];}

    vector<ll> tmp(n,0);
    vector<ll> tree(4*n+1,0);

    while(q--){
        ll a;cin>>a;
        if(a == 1){
            ll l,r;cin>>l>>r;
            range_Update(tree, l-1,r-1,1,n);
        }else{
            ll b;cin>>b;
            ll dbz = getElement(tree, b-1, n);
            ll sm = 0,ele = v[b-1];
            ll prev = ele;
            while(dbz > 0){
                while(ele != 0){
                    sm += (ele%10);
                    ele /= 10;
                }

                if(sm == prev){ele = sm;break;}
                
                ele = sm;sm = 0;
                prev = ele;
                --dbz;
            }
            cout<<ele<<endl;
        }
    }
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
   //solve();
   return 0;
}