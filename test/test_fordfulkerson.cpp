#include <gtest/gtest.h>
#include "FordFulkerson.h"

// Caso básico: grafo simple con flujo máximo conocido
TEST(FordFulkersonTest, BasicGraph) {
    int graph[100][100] = {0};
    int N = 6;
    // Grafo de ejemplo
    graph[0][1] = 16;
    graph[0][2] = 13;
    graph[1][2] = 10;
    graph[1][3] = 12;
    graph[2][1] = 4;
    graph[2][4] = 14;
    graph[3][2] = 9;
    graph[3][5] = 20;
    graph[4][3] = 7;
    graph[4][5] = 4;

    int maxFlow = ford_fulkerson(graph, 0, 5, N);
    EXPECT_EQ(maxFlow, 23);
}

// Grafo sin camino de fuente a sumidero
TEST(FordFulkersonTest, NoPath) {
    int graph[100][100] = {0};
    int N = 4;
    graph[0][1] = 5;
    graph[1][2] = 3;
    // No hay conexión de 2 a 3 (sumidero)
    int maxFlow = ford_fulkerson(graph, 0, 3, N);
    EXPECT_EQ(maxFlow, 0);
}

// Grafo con múltiples caminos y cuellos de botella
TEST(FordFulkersonTest, MultiplePaths) {
    int graph[100][100] = {0};
    int N = 4;
    graph[0][1] = 100;
    graph[0][2] = 100;
    graph[1][2] = 1;
    graph[1][3] = 100;
    graph[2][3] = 100;

    int maxFlow = ford_fulkerson(graph, 0, 3, N);
    EXPECT_EQ(maxFlow, 200);
}
