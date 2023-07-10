#include <iostream>
#include <vector>
#include <list>

bool isCompleteGraph(const std::vector<std::list<int>>& graph) {
    int n = graph.size();
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool hasEdge = false;
            
            
            for (const auto& v : graph[i]) {
                if (v == j) {
                    hasEdge = true;
                    break;
                }
            }
            
            if (!hasEdge) {
                return false;
            }
        }
    }
    
    return true;
}

std::vector<std::list<int>> constructAdjacencyList(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::list<int>> adjList(n);
    
    
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    return adjList;
}

int main() {
    int n, edgesCount;
    
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;
    
    std::vector<std::pair<int, int>> edges;
    
    std::cout << "Enter the number of edges: ";
    std::cin >> edgesCount;
    
    
    for (int i = 0; i < edgesCount; ++i) {
        int u, v;
        std::cout << "Enter an edge (u v): ";
        std::cin >> u >> v;
        edges.emplace_back(u, v);
    }
    
    std::vector<std::list<int>> graph = constructAdjacencyList(n, edges);
    
    bool isComplete = isCompleteGraph(graph);
    
    if (isComplete) {
        std::cout << "The graph is a complete graph." << std::endl;
        std::cout << "Adjacency List:" << std::endl;
        
        for (int i = 0; i < n; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (const auto& v : graph[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "The graph is not a complete graph." << std::endl;
    }
    
    return 0;
}
