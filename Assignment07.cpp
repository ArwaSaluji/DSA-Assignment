#include <iostream>
using namespace std;

int main()
{
    int graph[4][4] = 
    {
        {0, 2, 3, 4},
        {2, 0, 9, 8},
        {3, 9, 0, 5},
        {4, 8, 5, 0}
    };
    
    int n = 4;
    int visited[4] = {0};
    visited[0] = 1;
    int edges = 0;
    int total_cost = 0;

    cout << "Edges in the Minimum Spanning Tree:" << endl;

    while (edges < n - 1)
    {
        int smallest = 100; 
        int x = 0;
        int y = 0;
        
        for (int i = 0; i < n; i++) 
        {
            if (visited[i]) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (!visited[j] && graph[i][j] && graph[i][j] < smallest) 
                    {
                        smallest = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        
        visited[y] = 1;
        total_cost += smallest;
        edges++;
        cout << "Edge: " << (x + 1) << " - " << (y + 1) << " with weight " << smallest << endl;
    }
    
    cout << "Total cost of Minimum Spanning Tree: " << total_cost << endl;

    return 0;
}

