/*
 * ActIntegradora2 - Ford-Fulkerson Algorithm Implementation
 * Copyright (C) 2024 SamyG
 *
 * This file is part of ActIntegradora2 and is distributed under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ActIntegradora2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Búsqueda en anchura para encontrar un camino aumentante
/**
 * @brief Realiza una búsqueda en anchura para encontrar un camino aumentante en el grafo residual.
 * 
 * @param rGraph Matriz de adyacencia residual (100x100).
 * @param s Nodo fuente.
 * @param t Nodo sumidero.
 * @param parent Array para reconstruir el camino.
 * @param N Número de nodos.
 * @return true Si existe un camino aumentante.
 * @return false Si no existe camino aumentante.
 */
bool bfs(int rGraph[100][100], int s, int t, int parent[], int N)
{
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < N; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

/**
 * @brief Calcula el flujo máximo entre dos nodos en un grafo dirigido usando el algoritmo de Ford-Fulkerson.
 * 
 * @param graph Matriz de adyacencia de capacidades (tamaño 100x100).
 * @param s Nodo fuente.
 * @param t Nodo sumidero.
 * @param N Número de nodos en el grafo.
 * @return int Flujo máximo desde s hasta t.
 */
int ford_fulkerson(int graph[100][100], int s, int t, int N)
{
    int u, v;
    int rGraph[100][100];
    // Copia la capacidad original a la residual
    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
            rGraph[u][v] = graph[u][v];
    int parent[100];
    int max_flow = 0;
    // Mientras exista un camino aumentante
    while (bfs(rGraph, s, t, parent, N)) {
        int path_flow = INT_MAX;
        // Encuentra la capacidad mínima en el camino encontrado
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // Actualiza capacidades residuales
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
