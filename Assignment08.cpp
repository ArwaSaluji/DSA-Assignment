// Name: Arwa Salujiwala	Roll no: 23555	Batch: S3  

// DSA Assignment 08 

//Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various 
//landmarks and links should represent the distance between them. Find the shortest path using 
//Dijkstra's algorithm from single source to all destinations. 

#include <iostream>
#include <climits>

using namespace std;

#define V 6  // Number of landmarks (nodes)

class CityGraph {
public:
    int adjMatrix[V][V];  // Adjacency matrix to represent distances between landmarks

    // Constructor to initialize the adjacency matrix
    CityGraph() {
        // Initialize the adjacency matrix with 0 (no distances) and maximum values (infinity)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
    }

    // Function to add an edge between two landmarks
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;  // Since the graph is undirected
    }

    // Dijkstra's Algorithm to find the shortest path from source to all landmarks
    void dijkstra(int src) {
        int dist[V];  // Array to store the shortest distance from the source to each landmark
        bool visited[V];  // Boolean array to check if a landmark has been processed

        // Initialize distances and visited status
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[src] = 0;  // Distance to the source itself is 0

        // Find the shortest path for all landmarks
        for (int count = 0; count < V - 1; count++) {
            // Pick the landmark with the minimum distance that has not been processed
            int u = -1;
            for (int i = 0; i < V; i++) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }

            // Mark the picked landmark as processed
            visited[u] = true;

            // Update the distance of the adjacent landmarks of the picked landmark
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != INT_MAX && !visited[v] && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        // Output the shortest distances
        cout << "Shortest distances from source landmark " << src << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Landmark " << i << ": INF\n";
            } else {
                cout << "Landmark " << i << ": " << dist[i] << " km\n";
            }
        }
    }
};

int main() {
    CityGraph city;

    // Add edges (u, v, distance in km)
    city.addEdge(0, 1, 7);   // A-B: 7 km
    city.addEdge(0, 2, 9);   // A-C: 9 km
    city.addEdge(1, 2, 10);  // B-C: 10 km
    city.addEdge(1, 3, 15);  // B-D: 15 km
    city.addEdge(2, 3, 11);  // C-D: 11 km
    city.addEdge(2, 5, 2);   // C-F: 2 km
    city.addEdge(3, 4, 6);   // D-E: 6 km
    city.addEdge(4, 5, 9);   // E-F: 9 km
    city.addEdge(0, 5, 14);  // A-F: 14 km

    // Find shortest paths from landmark A (source = 0)
    city.dijkstra(0);

    return 0;
}
