#include <bits/stdc++.h>
using namespace std;

// Estructura de conjuntos disjuntos (Union-Find)
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    // Encuentra el representante del conjunto de i
    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }
    // Une dos conjuntos
    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};
// Comparador para ordenar aristas por peso
inline bool comparator(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}

vector<pair<int, int>> kruskalMST(vector<vector<int>>& dist) {
    int V = dist.size();
    vector<vector<int>> edges;
    
    // Convertir matriz de distancias a lista de aristas
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (dist[i][j] > 0) {  // Considerar solo conexiones válidas
                edges.push_back({i, j, dist[i][j]});
            }
        }
    }
    
    sort(edges.begin(), edges.end(), comparator);
    DSU dsu(V);
    vector<pair<int, int>> mst_edges;
    int count = 0;
    
    for (auto &e : edges) {
        int x = e[0], y = e[1], w = e[2];
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            mst_edges.push_back({x, y});
            if (++count == V - 1) break;
        }
    }
    
    return mst_edges;
}