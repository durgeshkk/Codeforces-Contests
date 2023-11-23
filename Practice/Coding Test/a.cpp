#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void func(int arr[], int n, int x)
{
	int res_l, res_r; 
	int l = 0, r = n-1, diff = INT_MAX;

	while (r > l)
	{
	if (abs(abs(arr[l] - arr[r]) - x) < diff)
	{
		res_l = l;
		res_r = r;
		diff = abs(arr[l] - arr[r] - x);
	}

	if (abs(arr[l] - arr[r]) > x)
		r--;
	else 
		l++;
	}
    cout<<(arr[res_r]+arr[res_l]);
	// return  (arr[res_l] + arr[res_r]);
}

int main()
{
	int arr[] = {2,1,4,2,3,2,2,6};
    int x = 5;
	int n = sizeof(arr)/sizeof(arr[0]);
	func(arr, n, x);
	return 0;
}