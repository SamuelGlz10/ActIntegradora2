#include <gtest/gtest.h>
#include "TravelingSalesman.h"

// Caso básico: 4 nodos, solución conocida
TEST(TSPTest, BasicGraph) {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int result = tsp(cost);
    EXPECT_EQ(result, 80);
}

// Grafo con un solo nodo
TEST(TSPTest, SingleNode) {
    vector<vector<int>> cost = {
        {0}
    };
    int result = tsp(cost);
    EXPECT_EQ(result, 0);
}

// Grafo con distancias iguales
TEST(TSPTest, AllEqualDistances) {
    vector<vector<int>> cost = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    int result = tsp(cost);
    EXPECT_EQ(result, 3);
}
