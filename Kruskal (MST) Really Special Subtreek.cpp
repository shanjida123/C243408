#include <bits/stdc++.h>
using namespace std;


vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    parent[px] = py;
    return true;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {


    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < g_from.size(); i++) {
        edges.push_back({g_weight[i], g_from[i], g_to[i]});
    }


    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        int sumA = get<1>(a) + get<2>(a);
        int sumB = get<1>(b) + get<2>(b);
        return sumA < sumB;
    });


    parent.resize(g_nodes + 1);
    for (int i = 0; i <= g_nodes; i++) parent[i] = i;

    int totalWeight = 0;

    for (auto& [w, u, v] : edges) {
        if (unite(u, v)) {
            totalWeight += w;
        }

    }

    return totalWeight;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> from, to, weight;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        from.push_back(u);
        to.push_back(v);
        weight.push_back(w);
    }

    cout << kruskals(nodes, from, to, weight) << endl;
    return 0;
}
