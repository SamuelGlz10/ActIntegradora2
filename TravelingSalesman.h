/*
 * ActIntegradora2 - Traveling Salesman Problem Implementation
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

// Calcula el costo total mínimo usando programación dinámica y bitmask
/**
 * @brief Calcula el costo mínimo del recorrido del viajante usando programación dinámica y bitmask.
 * 
 * @param mask Máscara de visitados.
 * @param pos Posición actual.
 * @param n Número de nodos.
 * @param cost Matriz de costos.
 * @return int Costo mínimo del recorrido.
 */
int totalCost(int mask, int pos, int n, vector<vector<int>> &cost) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, cost[pos][i] + 
                      totalCost((mask | (1 << i)), i, n, cost));
        }
    }
    return ans;
}

// Wrapper para el problema del viajante
/**
 * @brief Calcula el costo mínimo del recorrido del viajante para una matriz de costos dada.
 * 
 * @param cost Matriz de costos.
 * @return int Costo mínimo del recorrido.
 */
int tsp(vector<vector<int>> &cost) {
    int n = cost.size();
    return totalCost(1, 0, n, cost);  
}
