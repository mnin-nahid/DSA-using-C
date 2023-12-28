#include <stdio.h>
#include <limits.h>

#define V 3 

// Function to find the vertex with the minimum distance value,from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[])
{
    printf("Node \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        dist[i] < 999 ?printf("NODE(%d) \t Distance:%d\n", i, dist[i]) : printf("NODE(%d) \t Distance: NO CONNECTION!\n", i);
        
}


// Function that implements Dijkstra's single source shortest path algorithm, for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V];   
    int sptSet[V]; 

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source node from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int i = 0; i < V - 1; i++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if it is not in the sptSet, there is an edge from u to v, and the total weight of path from src to v through u is less than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main()
{
    int input;

    while (1)
    {
        getchar();
        printf("\t\t--------\n\t\t| OSPF |\n\t\t--------\n\n");
        printf("Which Node You Want to GO: ");
        scanf("%d", &input);

        int graph[V][V] = {
            {2, 1, 3},
            {0, 0, 0},
            {3, 2, 1},
        };
        dijkstra(graph, input);
    }

    return 0;
}
