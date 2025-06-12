#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Estructura para conjuntos disjuntos (Union-Find) con compresión de caminos y unión por rango.
 */
class DSU {
    vector<int> parent, rank;
public:
    /**
     * @brief Inicializa la estructura DSU para n elementos.
     * @param n Número de elementos.
     */
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    /**
     * @brief Encuentra el representante del conjunto de i.
     * @param i Elemento.
     * @return int Representante del conjunto.
     */
    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }
    /**
     * @brief Une dos conjuntos.
     * @param x Elemento x.
     * @param y Elemento y.
     */
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

/**
 * @brief Calcula el árbol de expansión mínima usando el algoritmo de Kruskal.
 * 
 * @param dist Matriz de distancias.
 * @return vector<pair<int, int>> Aristas del MST.
 */
vector<pair<int, int>> kruskal_mst(vector<vector<int>>& dist) {
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

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(KruskalTest, SimpleGraph) {
    vector<vector<int>> dist = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    auto mst = kruskal_mst(dist);
    // El MST de este grafo debe tener 2 aristas
    EXPECT_EQ(mst.size(), 2);
    // Las aristas deben conectar todos los nodos
    set<int> nodes;
    for (auto& e : mst) {
        nodes.insert(e.first);
        nodes.insert(e.second);
    }
    EXPECT_EQ(nodes.size(), 3);
}

#endif