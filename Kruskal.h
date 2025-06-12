/*
 * ActIntegradora2 - Kruskal's Algorithm Implementation
 * Copyright (C) 2024 Samuel Gonzalez
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

#include <bits/stdc++.h>
using namespace std;

// Estructura de conjuntos disjuntos (Union-Find)
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
            rank[i] = 0;
        }
    }
    /**
     * @brief Encuentra el representante del conjunto de x.
     * @param x Elemento.
     * @return int Representante del conjunto.
     */
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    /**
     * @brief Une los conjuntos de x e y.
     * @param x Elemento x.
     * @param y Elemento y.
     */
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};

// Estructura para representar una arista
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

/**
 * @brief Grafo para ejecutar el algoritmo de Kruskal.
 */
class KruskalGraph {
public:
    int V;
    vector<Edge> edges;
    /**
     * @brief Inicializa el grafo con V vértices.
     * @param V Número de vértices.
     */
    KruskalGraph(int V) : V(V) {}
    /**
     * @brief Agrega una arista al grafo.
     * @param u Nodo origen.
     * @param v Nodo destino.
     * @param w Peso de la arista.
     */
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
    /**
     * @brief Ejecuta el algoritmo de Kruskal y retorna el árbol de expansión mínima.
     * @return vector<Edge> Aristas del MST.
     */
    vector<Edge> kruskalMST() {
        vector<Edge> result;
        DSU dsu(V);
        sort(edges.begin(), edges.end());
        for (const auto& e : edges) {
            if (dsu.find(e.u) != dsu.find(e.v)) {
                result.push_back(e);
                dsu.unite(e.u, e.v);
            }
        }
        return result;
    }
};