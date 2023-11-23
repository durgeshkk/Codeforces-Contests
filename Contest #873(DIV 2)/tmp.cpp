#include <bits/stdc++.h>
#define forj(n) for (ll j = 0; j < n; j++)
#define ls (id << 1)
#define rs (id << 1 | 1) 
#define ll long long
#define inf 0x3f3f3f3f
#define sq(x) ((x) * (x))
#define PI acos(-1.0)
using namespace std;
const int N = 5005, mod = 1e9 + 7;
ll f[N][N];
int a[N];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], f[i][i] = 0;
	// for (int i = 0; i <= n; i++) {
    //     forj(n+1){
    //         cout<<f[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

	for (int len = 2; len <= n; len++) {
		for (int i = 1; i < n; i++) {
			int j = i + len - 1;
			if (a[i] > a[j]) f[i][j] = j - i;
			else f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans += f[i][j];
		}
	}

    // for (int i = 0; i <= n; i++) {
    //     forj(n+1){
    //         cout<<f[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0; 
}