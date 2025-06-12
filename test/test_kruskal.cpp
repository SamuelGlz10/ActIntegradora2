#include <gtest/gtest.h>
#include "Kruskal.h"
#include <vector>
#include <algorithm>

// Definición mínima para pruebas (ajusta según tu implementación real)
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

class KruskalGraph {
public:
    int V;
    std::vector<Edge> edges;
    KruskalGraph(int V) : V(V) {}
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
    // Implementación simple de Kruskal para pruebas
    std::vector<Edge> kruskalMST() {
        std::vector<Edge> result;
        std::vector<int> parent(V);
        for (int i = 0; i < V; ++i) parent[i] = i;
        auto find = [&](int x) {
            while (parent[x] != x) x = parent[x];
            return x;
        };
        auto unite = [&](int x, int y) {
            parent[find(x)] = find(y);
        };
        std::sort(edges.begin(), edges.end());
        for (const auto& e : edges) {
            if (find(e.u) != find(e.v)) {
                result.push_back(e);
                unite(e.u, e.v);
            }
        }
        return result;
    }
};

// Caso básico: grafo conectado simple
TEST(KruskalTest, BasicConnectedGraph) {
    KruskalGraph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    auto mst = g.kruskalMST();
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += edge.weight;
    }
    EXPECT_EQ(mst.size(), 3);
    EXPECT_EQ(totalWeight, 19); // 4 + 5 + 10
}

// Grafo desconectado: el MST no puede conectar todos los nodos
TEST(KruskalTest, DisconnectedGraph) {
    KruskalGraph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(2, 3, 2);

    auto mst = g.kruskalMST();
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += edge.weight;
    }
    EXPECT_EQ(mst.size(), 2);
    EXPECT_EQ(totalWeight, 3);
}

// Grafo con múltiples aristas de igual peso
TEST(KruskalTest, MultipleEdgesSameWeight) {
    KruskalGraph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);

    auto mst = g.kruskalMST();
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += edge.weight;
    }
    EXPECT_EQ(mst.size(), 2);
    EXPECT_EQ(totalWeight, 2);
}