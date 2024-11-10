// Name: Arwa Salujiwala	Roll no: 23555	Batch: S3 

// DSA Assignment 07   

// Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should //represent the various departments/institutes and links should represent the distance between them. //Find minimum spanning tree a) Using Kruskal’s algorithm. b) Using Prim’s algorithm. 

//Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various //landmarks and links should represent the distance between them. Find the shortest path using //Dijkstra's algorithm from single source to all destinations. 

 

#include <iostream> 

#include <climits> 

#include <algorithm> 

  

using namespace std; 

  

#define V 6  // Number of vertices in the graph 

  

// Graph class for the adjacency matrix 

class Graph { 

public: 

    int adjMatrix[V][V];  // Adjacency matrix for graph 

  

    // Initialize the adjacency matrix with infinity (INT_MAX) 

    Graph() { 

        for (int i = 0; i < V; i++) { 

            for (int j = 0; j < V; j++) { 

                adjMatrix[i][j] = INT_MAX; 

            } 

        } 

    } 

  

    // Function to add an edge to the graph 

    void addEdge(int u, int v, int weight) { 

        adjMatrix[u][v] = weight; 

        adjMatrix[v][u] = weight; 

    } 

  

    // Kruskal's Algorithm to find MST 

    void kruskalMST() { 

        int parent[V], rank[V]; 

  

        // Initialize parent and rank arrays 

        for (int i = 0; i < V; i++) { 

            parent[i] = i; 

            rank[i] = 0; 

        } 

  

        // Create an edge list 

        struct Edge { 

            int u, v, weight; 

        }; 

        Edge edges[V * V]; 

        int e = 0; 

  

        for (int u = 0; u < V; u++) { 

            for (int v = u + 1; v < V; v++) { 

                if (adjMatrix[u][v] != INT_MAX) { 

                    edges[e].u = u; 

                    edges[e].v = v; 

                    edges[e].weight = adjMatrix[u][v]; 

                    e++; 

                } 

            } 

        } 

  

        // Sort edges by weight 

        sort(edges, edges + e, [](Edge a, Edge b) { 

            return a.weight < b.weight; 

        }); 

  

        int mstWeight = 0; 

        cout << "Edges in MST (Kruskal's):\n"; 

        for (int i = 0; i < e; i++) { 

            int u = edges[i].u; 

            int v = edges[i].v; 

  

            // Find function to find the parent of a vertex 

            int findParent(int x) { 

                if (parent[x] != x) { 

                    parent[x] = findParent(parent[x]); 

                } 

                return parent[x]; 

            } 

  

            // Union function to join two subsets 

            void unionSets(int x, int y) { 

                int rootX = findParent(x); 

                int rootY = findParent(y); 

  

                if (rootX != rootY) { 

                    if (rank[rootX] > rank[rootY]) { 

                        parent[rootY] = rootX; 

                    } else if (rank[rootX] < rank[rootY]) { 

                        parent[rootX] = rootY; 

                    } else { 

                        parent[rootY] = rootX; 

                        rank[rootX]++; 

                    } 

                } 

            } 

  

            // If including this edge doesn't form a cycle 

            if (findParent(u) != findParent(v)) { 

                unionSets(u, v); 

                cout << u << " - " << v << " : " << adjMatrix[u][v] << endl; 

                mstWeight += adjMatrix[u][v]; 

            } 

        } 

  

        cout << "Total weight of MST: " << mstWeight << endl; 

    } 

  

    // Prim's Algorithm to find MST 

    void primMST() { 

        int parent[V], key[V]; 

        bool inMST[V]; 

        for (int i = 0; i < V; i++) { 

            key[i] = INT_MAX; 

            inMST[i] = false; 

        } 

  

        key[0] = 0; 

        parent[0] = -1; 

  

        for (int count = 0; count < V - 1; count++) { 

            int u = -1; 

  

            // Find the vertex with the minimum key value 

            for (int i = 0; i < V; i++) { 

                if (!inMST[i] && (u == -1 || key[i] < key[u])) { 

                    u = i; 

                } 

            } 

  

            inMST[u] = true; 

  

            // Update key and parent values of the adjacent vertices of u 

            for (int v = 0; v < V; v++) { 

                if (adjMatrix[u][v] != INT_MAX && !inMST[v] && adjMatrix[u][v] < key[v]) { 

                    key[v] = adjMatrix[u][v]; 

                    parent[v] = u; 

                } 

            } 

        } 

  

        cout << "Edges in MST (Prim's):\n"; 

        int mstWeight = 0; 

        for (int i = 1; i < V; i++) { 

            cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl; 

            mstWeight += adjMatrix[i][parent[i]]; 

        } 

        cout << "Total weight of MST: " << mstWeight << endl; 

    } 

}; 

  

int main() { 

    Graph g; 

  

    // Add edges (u, v, weight) 

    g.addEdge(0, 1, 5); 

    g.addEdge(0, 2, 10); 

    g.addEdge(1, 3, 15); 

    g.addEdge(2, 3, 5); 

    g.addEdge(2, 4, 20); 

    g.addEdge(3, 5, 10); 

    g.addEdge(4, 5, 5); 

  

    // Find MST using Kruskal's Algorithm 

    g.kruskalMST(); 

  

    // Find MST using Prim's Algorithm 

    g.primMST(); 

  

    return 0; 

}  
