
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
    int Find(int i) {
        return (parent[i] == i) ? i : (parent[i] = Find(parent[i]));
    }
    /**
     * @brief Une dos conjuntos.
     * @param x Elemento x.
     * @param y Elemento y.
     */
    void Unite(int x, int y) {
        int s1 = Find(x);
        int s2 = Find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};
/**
 * @brief Comparador para ordenar aristas por peso.
 * 
 * @param a Arista a comparar.
 * @param b Arista a comparar.
 * @return true si el peso de a es menor que el de b.
 */
inline bool comparator(vector<int> &a, vector<int> &b) {
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
        int x = e[0];
        int y = e[1];
        int w = e[2];
        if (dsu.Find(x) != dsu.Find(y)) {
            dsu.Unite(x, y);
            mst_edges.push_back({x, y});
            count++;
            if (count == V - 1) {
                break;
            }
        }
    }
    
    return mst_edges;
}
