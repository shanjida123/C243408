#include <bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<int>>& edges, int start) {

    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto& e : edges) {
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<bool> visited(n + 1, false);
    int totalWeight = 0;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;

        for (auto [weight, v] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int start;
    cin >> start;

    cout << prims(n, edges, start) << endl;
    return 0;
}
