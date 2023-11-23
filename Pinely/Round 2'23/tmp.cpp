#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 200000;

vector<int> adj[N];
int h[N], seg[4 * N], lazy[4 * N], q[N], ans[N], hv[N];
long long pwr[N];

void dfs(int v) {
    q[v] = 1;
    for (int u : adj[v]) {
        dfs(u);
        q[v] += q[u];
    }
}

void propagate(int v, int tl, int tr) {
    if (lazy[v] == 0) return;

    int tm = (tl + tr) / 2;
    seg[2 * v] = (seg[2 * v] + 1LL * (tm - tl + 1) * lazy[v]) % MOD;
    seg[2 * v + 1] = (seg[2 * v + 1] + 1LL * (tr - tm) * lazy[v]) % MOD;

    lazy[2 * v] = (lazy[2 * v] + lazy[v]) % MOD;
    lazy[2 * v + 1] = (lazy[2 * v + 1] + lazy[v]) % MOD;

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (tl == l && tr == r) {
        seg[v] = (seg[v] + 1LL * (r - l + 1) * val) % MOD;
        lazy[v] = (lazy[v] + val) % MOD;
    } else {
        propagate(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        seg[v] = (seg[2 * v] + seg[2 * v + 1]) % MOD;
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return seg[v];
    propagate(v, tl, tr);
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dfs(1);

    pwr[0] = 1;
    for (int i = 1; i < N; i++) {
        pwr[i] = (2 * pwr[i - 1]) % MOD;
    }

    int q;
    cin >> q;

    for (int i = 0; i <= q; i++) {
        ans[i] = 1;
    }

    for (int i = 1; i <= q; i++) {
        int v, x;
        cin >> v >> x;
        update(1, 1, n, q[v] - 1, q[v] - 1, x - hv[v]);
        hv[v] = x;

        int cur = v;
        for (int j = 0; j < 60; j++) {
            cur = cur / 2;
            update(1, 1, n, q[cur] - 1, q[cur] - 1, -1);
            int subtree = (query(1, 1, n, q[cur] - 1, q[cur] - 1) * pwr[j]) % MOD;
            update(1, 1, n, q[cur] - 1, q[cur] - 1, subtree);
        }

        for (int j = 0; j <= i; j++) {
            ans[j] = (ans[j] + query(1, 1, n, 0, n - 1)) % MOD;
        }
    }

    for (int i = 0; i <= q; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}