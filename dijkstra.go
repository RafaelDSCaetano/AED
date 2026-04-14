/*
+---+----+---+---+---+---+
| 0 | 10 | 0 | 5 | 0 | 0 |
+---+----+---+---+---+---+
| 0 | 0  | 1 | 0 | 0 | 0 |
+---+----+---+---+---+---+
| 0 | 0  | 0 | 0 | 4 | 4 |
+---+----+---+---+---+---+
| 0 | 3  | 8 | 0 | 2 | 0 |
+---+----+---+---+---+---+
| 0 | 0  | 0 | 0 | 0 | 7 |
+---+----+---+---+---+---+
| 0 | 0  | 0 | 0 | 0 | 0 |
+---+----+---+---+---+---+
*/

package main

import (
	"fmt"
	"math"
)

const MAX = 20

func dijkstra(graph [MAX][MAX]int, n, origem, destino int) ([]int, int) {
	dist := [MAX]int{}
	prev := [MAX]int{}
	visitado := [MAX]bool{}

	for i := 0; i < n; i++ {
		dist[i] = math.MaxInt32
		prev[i] = -1
	}
	dist[origem] = 0

	for i := 0; i < n; i++ {
		u := -1
		for j := 0; j < n; j++ {
			if !visitado[j] && (u == -1 || dist[j] < dist[u]) {
				u = j
			}
		}

		// fmt.Println("\n", dist[:n], "\n", prev[:n], "\n", visitado[:n])

		if dist[u] == math.MaxInt32 {
			break
		}
		visitado[u] = true

		for v := 0; v < n; v++ {
			if graph[u][v] > 0 && dist[u]+graph[u][v] < dist[v] {
				dist[v] = dist[u] + graph[u][v]
				prev[v] = u

				// fmt.Println("\n", dist[:n], "\n", prev[:n], "\n", visitado[:n])

			}
		}
	}

	// Reconstruindo o caminho
	caminho := []int{}
	for at := destino; at != -1; at = prev[at] {
		caminho = append([]int{at}, caminho...) // faz o desempacotamento e insere na sequencia

		//println(caminho[0], prev[at])

	}

	if dist[destino] == math.MaxInt32 {
		return nil, -1
	}
	return caminho, dist[destino]
}

func main() {
	var n int
	fmt.Print("Numero de vertices (max 20): ")
	fmt.Scan(&n)
	if n > MAX {
		fmt.Println("Erro: numero maximo é 20.")
		return
	}

	var graph [MAX][MAX]int

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("Peso da aresta de %d para %d (0 = sem ligação): ", i, j)
			fmt.Scan(&graph[i][j])
		}
	}
	for i := 0; i < n; i++ {
		fmt.Println(graph[i][:n])
	}

	var origem, destino int
	fmt.Print("Vertice de origem: ")
	fmt.Scan(&origem)
	fmt.Print("Vertice de destino: ")
	fmt.Scan(&destino)

	caminho, custo := dijkstra(graph, n, origem, destino)
	if caminho == nil {
		fmt.Println("Nao existe caminho entre os vertices.")
	} else {
		fmt.Printf("Caminho minimo: %v (Custo total: %d)\n", caminho, custo)
	}
}
