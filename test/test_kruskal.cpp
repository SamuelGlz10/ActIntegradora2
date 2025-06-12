#include <gtest/gtest.h>
#include "Kruskal.h"
#include <vector>
#include <set>

// Caso básico: grafo conectado simple
TEST(KruskalTest, BasicConnectedGraph) {
    std::vector<std::vector<int>> dist = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };
    auto mst = kruskal_mst(dist);
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += dist[edge.first][edge.second];
    }
    EXPECT_EQ(mst.size(), 3);
    EXPECT_EQ(totalWeight, 19); // 4 + 5 + 10
}

// Grafo desconectado: el MST no puede conectar todos los nodos
TEST(KruskalTest, DisconnectedGraph) {
    std::vector<std::vector<int>> dist = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 2},
        {0, 0, 2, 0}
    };
    auto mst = kruskal_mst(dist);
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += dist[edge.first][edge.second];
    }
    EXPECT_EQ(mst.size(), 2);
    EXPECT_EQ(totalWeight, 3);
}

// Grafo con múltiples aristas de igual peso
TEST(KruskalTest, MultipleEdgesSameWeight) {
    std::vector<std::vector<int>> dist = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    auto mst = kruskal_mst(dist);
    int totalWeight = 0;
    for (const auto& edge : mst) {
        totalWeight += dist[edge.first][edge.second];
    }
    EXPECT_EQ(mst.size(), 2);
    EXPECT_EQ(totalWeight, 2);
}