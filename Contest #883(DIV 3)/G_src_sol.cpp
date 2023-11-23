#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        bitset<10> tmp;
        cin >> tmp;
        int s = (int) tmp.to_ulong();
        vector<pair<pair<int, int>, int>> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].second;
            cin >> tmp;
            edges[i].first.first = ((1 << n) - 1) ^ (int) tmp.to_ulong();
            cin >> tmp;
            edges[i].first.second = (int) tmp.to_ulong();
        }
        vector<int> dist(1 << n, INT_MAX);
        dist[s] = 0;
        set<pair<int, int>> q = {{0, s}};
        while (!q.empty()) {
            auto p = *q.begin();
            int d = p.first,v = p.second;
            q.erase(q.begin());
            for (int i = 0; i < m; i++) {
                int to = v & edges[i].first.first;
                to |= edges[i].first.second;
                if (dist[to] > d + edges[i].second) {
                    q.erase({dist[to], to});
                    dist[to] = d + edges[i].second;
                    q.insert({dist[to], to});
                }
            }
        }
        if (dist[0] == INT_MAX) dist[0] = -1;
        cout << dist[0] << '\n';
    }
    return 0;
}