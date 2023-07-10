#include <iostream>
#include <vector>

bool isCompleteGraph(const std::vector<std::vector<int>> &graph)
{
    int n = graph.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (graph[i][j] == 0 || graph[j][i] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

std::vector<std::vector<int>> constructAdjacencyMatrix(int n, const std::vector<std::pair<int, int>> &edges)
{
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));

    for (const auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    return adjMatrix;
}

int main()
{
    int n, edgesCount;

    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    std::vector<std::pair<int, int>> edges;

    std::cout << "Enter the number of edges: ";
    std::cin >> edgesCount;

    for (int i = 0; i < edgesCount; ++i)
    {
        int u, v;
        std::cout << "Enter an edge (u v): ";
        std::cin >> u >> v;
        edges.emplace_back(u, v);
    }

    std::vector<std::vector<int>> graph = constructAdjacencyMatrix(n, edges);

    bool isComplete = isCompleteGraph(graph);

    if (isComplete)
    {
        std::cout << "The graph is a complete graph." << std::endl;
        std::cout << "Adjacency Matrix:" << std::endl;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cout << graph[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "The graph is not a complete graph." << std::endl;
    }

    return 0;
}
