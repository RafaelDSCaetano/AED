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
	"sort"
)

const MAX = 20

// Estrutura para Arestas e Funções auxiliares para Kruskal
type Edge struct {
	u, v, weight int
}

func find(parent []int, i int) int {
	if parent[i] != i {
		parent[i] = find(parent, parent[i])
	}
	return parent[i]
}

func union(parent, rank []int, x, y int) {
	xroot := find(parent, x)
	yroot := find(parent, y)

	if rank[xroot] < rank[yroot] {
		parent[xroot] = yroot
	} else if rank[xroot] > rank[yroot] {
		parent[yroot] = xroot
	} else {
		parent[yroot] = xroot
		rank[xroot]++
	}
}

func kruskal(graph [MAX][MAX]int, n int) ([]Edge, int) {
	edges := []Edge{}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if graph[i][j] != 0 {
				edges = append(edges, Edge{i, j, graph[i][j]})
			}
		}
	}

	sort.Slice(edges, func(i, j int) bool {
		return edges[i].weight < edges[j].weight
	})

	parent := make([]int, n)
	rank := make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
		rank[i] = 0
	}

	mst := []Edge{}
	totalWeight := 0

	for _, edge := range edges {
		uRoot := find(parent, edge.u)
		vRoot := find(parent, edge.v)

		if uRoot != vRoot {
			mst = append(mst, edge)
			totalWeight += edge.weight
			union(parent, rank, uRoot, vRoot)
		}
	}

	return mst, totalWeight
}

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

		if dist[u] == math.MaxInt32 {
			break
		}
		visitado[u] = true

		for v := 0; v < n; v++ {
			if graph[u][v] > 0 && dist[u]+graph[u][v] < dist[v] {
				dist[v] = dist[u] + graph[u][v]
				prev[v] = u
			}
		}
	}

	// Reconstruindo o caminho
	caminho := []int{}
	for at := destino; at != -1; at = prev[at] {
		caminho = append([]int{at}, caminho...)
	}

	if dist[destino] == math.MaxInt32 {
		return nil, -1
	}
	return caminho, dist[destino]
}

func main() {
	var n int
	var exitProgram, newGraph bool

	for !exitProgram {
		fmt.Print("Numero de vertices (max 20): ")
		fmt.Scan(&n)
		if n > MAX {
			fmt.Println("Erro: numero maximo é 20.")
			continue
		}

		var graph [MAX][MAX]int

		// Entrada da matriz de adjacência
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				fmt.Printf("Peso da aresta de %d para %d (0 = sem ligação): ", i, j)
				fmt.Scan(&graph[i][j])
			}
		}

		fmt.Println("\nMatriz de Adjacência:")
		for i := 0; i < n; i++ {
			fmt.Println(graph[i][:n])
		}

		// inicia o menu
		newGraph = false

		for !newGraph {
			var opcao int
			fmt.Println("\nEscolha uma opção:")
			fmt.Println("1 - Dijkstra (Caminho mínimo)")
			fmt.Println("2 - Kruskal (Árvore Geradora Mínima)")
			fmt.Println("3 - Novo Grafo")
			fmt.Println("4 - Sair")
			fmt.Print("Opção: ")
			fmt.Scan(&opcao)

			switch opcao {
			case 1:
				var origem, destino int
				fmt.Print("Vertice de origem: ")
				fmt.Scan(&origem)
				fmt.Print("Vertice de destino: ")
				fmt.Scan(&destino)

				caminho, custo := dijkstra(graph, n, origem, destino)
				if caminho == nil || custo == 0 {
					fmt.Println("Nao existe caminho entre os vertices.")
				} else {
					fmt.Printf("Caminho minimo: %v (Custo total: %d)\n", caminho, custo)
				}

			case 2:
				mst, totalWeight := kruskal(graph, n)
				fmt.Println("\nArvore Geradora Minima usando Kruskal:")
				for _, edge := range mst {
					fmt.Printf("Aresta (%d - %d) com peso %d\n", edge.u, edge.v, edge.weight)
				}
				fmt.Printf("Custo total: %d\n", totalWeight)

			case 3:
				// Volta para criar um novo grafo
				newGraph = true

			case 4:
				newGraph = true
				exitProgram = true

			default:
				fmt.Println("Opção invalida.")
			}
		}
	}
}
