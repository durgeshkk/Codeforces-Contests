/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long int
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

struct node {
	int minimum;
	int maximum;
};

int getMid(int s, int e) { return s + (e - s) / 2; }

struct node MaxMinUntill(struct node* st, int ss, int se,
						int qs, int qe, int index)
{
	// If segment of this node is a part of given range,
	// then return
	// the minimum and maximum node of the segment
	struct node tmp, left, right;
	if (qs <= ss && qe >= se)
		return st[index];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe) {
		tmp.minimum = INT_MAX;
		tmp.maximum = INT_MIN;
		return tmp;
	}

	// If a part of this segment overlaps with the given
	// range
	int mid = getMid(ss, se);
	left = MaxMinUntill(st, ss, mid, qs, qe, 2 * index + 1);
	right = MaxMinUntill(st, mid + 1, se, qs, qe,
						2 * index + 2);
	tmp.minimum = min(left.minimum, right.minimum);
	tmp.maximum = max(left.maximum, right.maximum);
	return tmp;
}

struct node MaxMin(struct node* st, int n, int qs, int qe)
{
	struct node tmp;

	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe) {
		printf("Invalid Input");
		tmp.minimum = INT_MIN;
		tmp.minimum = INT_MAX;
		return tmp;
	}

	return MaxMinUntill(st, 0, n - 1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se,
					struct node* st, int si)
{
	// If there is one element in array, store it in current
	// node of segment tree and return
	if (ss == se) {
		st[si].minimum = arr[ss];
		st[si].maximum = arr[ss];
		return;
	}

	// If there are more than one elements, then recur for
	// left and right subtrees and store the minimum and
	// maximum of two values in this node
	int mid = getMid(ss, se);
	constructSTUtil(arr, ss, mid, st, si * 2 + 1);
	constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

	st[si].minimum = min(st[si * 2 + 1].minimum,
						st[si * 2 + 2].minimum);
	st[si].maximum = max(st[si * 2 + 1].maximum,
						st[si * 2 + 2].maximum);
}

struct node* constructST(int arr[], int n)
{
	// Allocate memory for segment tree

	// Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2 * (int)pow(2, x) - 1;

	struct node* st = new struct node[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}

void solve()
{
 


    ll n,m;cin>>n>>m;
    // vector<ll> height(m);enter(height);

    int arr[m];
    for(ll i = 0;i<m;++i){cin>>arr[i];}
    // int n = sizeof(arr) / sizeof(arr[0]);

	// Build segment tree from given array
	struct node* st = constructST(arr, m);

    ll q;cin>>q;
    for(ll i=0;i<q;i++){
        ll x1,y1;cin>>x1>>y1;
        ll x2,y2;cin>>x2>>y2;
        ll k;cin>>k;
        if(y1 > y2){swap(y1,y2);swap(x1,x2);}


        ll f = 1;
        ll diff = abs(x1-x2);
        if(diff%k){yno(0);continue;}
        diff = abs(y1-y2);
        if(diff%k){yno(0);continue;}

        if(x1 == x2 and y1 == y2){
            yno(1);continue;
        }

        x1 = x1%k;
        x2 = x2%k;
        if(x1 == 0){x1 = k;}
        if(x2 == 0){x2 = k;}

        if(x1 == x2 and y1 == y2){
            yno(f);continue;
        }

        // Now just check if there is any building lying between y1 & y2 are greater
        // in height than any of x1 | x2
        
        int qs = y1-1; // Starting index of query range
        int qe = y2-1; // Ending index of query range
        struct node result = MaxMin(st, m, qs, qe);
        ll mx = result.maximum;
        // cout<<mx<<" ";
        if(mx >= max(x1,x2)){
            x1 += k * ((mx - x1)/k);
            x1 += k;
            if(x1 > n)	{
                f = 0;
            }
        }

        yno(f);
    }
 
    return;
}
 
int_fast32_t main()
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
 
   ll t=1;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}