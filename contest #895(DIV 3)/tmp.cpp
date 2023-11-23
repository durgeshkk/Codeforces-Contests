#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> tree;
vector<int> lazy;

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}

// Function to propagate lazy updates
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] ^= (lazy[node] * ((end - start + 1) % 2));

        if (start != end) {
            lazy[2 * node] ^= lazy[node];
            lazy[2 * node + 1] ^= lazy[node];
        }

        lazy[node] = 0;
    }
}

// Function to update a range [l, r] with a value
void update(int node, int start, int end, int l, int r, int value) {
    propagate(node, start, end);

    if (r < start || end < l) {
        return;
    }

    if (l <= start && end <= r) {
        tree[node] ^= (value * ((end - start + 1) % 2));

        if (start != end) {
            lazy[2 * node] ^= value;
            lazy[2 * node + 1] ^= value;
        }

        return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, value);
    update(2 * node + 1, mid + 1, end, l, r, value);
    tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

// Function to query the XOR of elements in a range [l, r]
int query(int node, int start, int end, int l, int r) {
    propagate(node, start, end);

    if (r < start || end < l) {
        return 0;
    }

    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);
    return left ^ right;
}

int main() {
    int n;
    cin >> n;

    a.resize(n);
    tree.resize(4 * n);
    lazy.resize(4 * n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    build(1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int value = 1;
            update(1, 0, n - 1, l, r, value);
        } else if (queryType == 2) {
            int g;
            cin >> g;
            int result = 0;
            if (g == 0) {
                result = query(1, 0, n - 1, 0, n - 1);
            } else {
                int l = 0, r = n - 1;
                while (l < n && s[l] != '1') ++l;
                while (r >= 0 && s[r] != '1') --r;
                if (l <= r) {
                    result = query(1, 0, n - 1, l, r);
                }
            }
            cout << result << endl;
        }
    }

    return 0;
}
