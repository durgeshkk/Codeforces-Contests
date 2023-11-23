#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);

constexpr static ll MAXSIZE = 800005;
constexpr static ll INF = numeric_limits<ll>::max();
// Segment Tree array
ll tree[MAXSIZE];

// Lazy Update array
ll lazy[MAXSIZE];

// This tuple will hold tree state
// the stacks
using QueryAdaptor = tuple<ll,
                           ll,
                           ll>;

// Build our segment tree
void build_tree(ll *arr,
                ll arr_size)
{

    // Stack will use to update
    // the tree value
    stack<QueryAdaptor> st;

    // Emplace the root of the tree
    st.emplace(1, 0, arr_size - 1);

    // Repeat until empty
    while (!st.empty())
    {

        // Take the indexes at the
        // top of the stack
        ll currnode, curra, currb;

        // value at the top of the
        // stack
        tie(currnode, curra, currb) = st.top();

        // Pop the value from the
        // stack
        st.pop();

        // Flag with INF ranges are merged
        if (curra == INF && currb == INF)
        {
            tree[currnode] = tree[currnode * 2] + tree[currnode * 2 + 1];
        }

        // Leaf node
        else if (curra == currb)
        {
            tree[currnode] = arr[curra];
        }

        else
        {

            // Insert flag node inverse
            // order of evaluation
            st.emplace(currnode, INF, INF);
            ll mid = (curra + currb) / 2;

            // Push children
            st.emplace(currnode * 2,
                       curra, mid);
            st.emplace(currnode * 2 + 1,
                       mid + 1, currb);
        }
    }
}

// A utility function that propagates
// updates lazily down the tree
inline void push_down(ll node,
                      ll a,
                      ll b)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node] * (b - a + 1);

        if (a != b)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

// Iterative Range_Update function to
// add val to all elements in the
// range i-j (inclusive)
void update_tree(ll arr_size,
                 ll i,
                 ll j,
                 ll val)
{

    // Initialize the stack
    stack<QueryAdaptor> st;

    // Emplace the root of the tree
    st.emplace(1, 0, arr_size - 1);

    // Work until empty
    while (!st.empty())
    {

        // Take the indexes at the
        // top of the stack
        ll currnode, curra, currb;
        tie(currnode, curra, currb) = st.top();
        st.pop();

        // Flag with INF ranges are merged
        if (curra == INF && currb == INF)
        {
            tree[currnode] = tree[currnode * 2] + tree[currnode * 2 + 1];
        }

        // Traverse the previous updates
        // down the tree
        else
        {
            push_down(currnode, curra, currb);

            // No overlap condition
            if (curra > currb || curra > j || currb < i)
            {
                continue;
            }

            // Total overlap condition
            else if (curra >= i && currb <= j)
            {

                // Update lazy array
                tree[currnode] += val * (currb - curra + 1);

                if (curra != currb)
                {
                    lazy[currnode * 2] += val;
                    lazy[currnode * 2 + 1] += val;
                }
            }

            // Partial Overlap
            else
            {

                // Insert flag node inverse
                // order of evaluation
                st.emplace(currnode, INF, INF);

                ll mid = (curra + currb) / 2;

                // Push children
                st.emplace(currnode * 2,
                           curra, mid);
                st.emplace(currnode * 2 + 1,
                           mid + 1, currb);
            }
        }
    }
}

// A function that find the sum of
// all elements in the range i-j
ll query(ll arr_size,
         ll i,
         ll j)
{

    // Initialize stack
    stack<QueryAdaptor> st;

    // Emplace root of the tree
    st.emplace(1, 0, arr_size - 1);

    ll result = 0;

    while (!st.empty())
    {

        // Take the indexes at the
        // top of the stack
        ll currnode, curra, currb;
        tie(currnode, curra, currb) = st.top();
        st.pop();

        // Traverse the previous updates
        // down the tree
        push_down(currnode, curra, currb);

        // No overlap
        if (curra > currb || curra > j || currb < i)
        {
            continue;
        }

        // Total Overlap
        else if (curra >= i && currb <= j)
        {
            result += tree[currnode];
        }

        // Partial Overlap
        else
        {
            ll mid = (curra + currb) / 2;

            // Push children
            st.emplace(currnode * 2,
                       curra, mid);
            st.emplace(currnode * 2 + 1,
                       mid + 1, currb);
        }
    }

    return result;
}
void solve()
{
    ll n;
    cin >> n;

    vector<ll> v1(n), v2(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> v2[i];
    }

    vector<ll> sum(n);
    for (ll i = 0; i < n; i++)
    {
        sum[i] += v2[i];
        if (i - 1 >= 0)
        {
            sum[i] += sum[i - 1];
        }
    }
    vector<ll> t1(n + 1);

    ll f[4*n+1];
    vector<ll> ans(n + 1);
    for (ll i = 0; i < 4*n+1; i++)
    {
        f[i] = 0;
    }
    build_tree(f, n);
    for (ll i = 0; i < n; i++)
    {
        ll t = v1[i];
        if (i - 1 >= 0)
        {
            t += sum[i - 1];
        }
        ll idx = lower_bound(sum.begin(), sum.end(), t) - sum.begin();

        if (idx < n)
        {
            ans[idx] += t;
            if (idx - 1 >= 0)
            {
                ans[idx] -= sum[idx - 1];
            }
        }
        idx--;
        update_tree(n, i, idx, 1);
    }

    for (ll i = 0; i < n; i++)
    {
        ll t = query(n, i, i);

        ans[i] += v2[i] * t;
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}