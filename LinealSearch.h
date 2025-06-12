/*
 * ActIntegradora2 - Linear Search Implementation
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

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Realiza una búsqueda lineal en un vector de enteros.
 * 
 * @param arr Vector de enteros.
 * @param x Elemento a buscar.
 * @return int Índice del elemento si se encuentra, -1 en caso contrario.
 */
int search(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == x)
            return i;
    return -1;
}