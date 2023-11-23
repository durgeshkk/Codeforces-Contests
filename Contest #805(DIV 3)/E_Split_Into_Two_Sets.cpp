#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);

// from vertex v.
const int n = 200010;
vector<int> adj[n];
vector<bool> visited(n);

bool containsOdd(vector<int> adj[], int src)
{
    int colorArr[n + 1];
    for (int i = 0; i <= n; ++i)
        colorArr[i] = -1;

    colorArr[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {

        int u = q.front();
        visited[u] = true;
        q.pop();

        for (auto it : adj[u])
        {

            if (colorArr[it] == -1)
            {

                colorArr[it] = 1 - colorArr[u];
                q.push(it);
            }

            else if (colorArr[it] == colorArr[u])
                return true;
        }
    }

    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> f(n + 1);
    int mx = 0;
    int flag = 0;

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        adj[i].clear();
        ll a, b;
        cin >> a >> b;
        f[a]++;
        f[b]++;
        if (a == b || f[a] > 2 || f[b] > 2)
        {
            flag = 1;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (flag == 1)
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0 || visited[i])
        {
            continue;
        }
        if (containsOdd(adj, i))
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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