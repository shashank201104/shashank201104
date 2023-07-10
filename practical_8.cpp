#include <iostream>
#include <vector>

void computeDegrees(const std::vector<std::vector<int>>& graph, std::vector<int>& inDegree, std::vector<int>& outDegree) {
    int n = graph.size();
    
    
    inDegree.resize(n, 0);
    outDegree.resize(n, 0);
    
   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1) {
                
                outDegree[i]++;
                
                
                inDegree[j]++;
            }
        }
    }
}

int main() {
    int n;
    
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    
    std::cout << "Enter the adjacency matrix of the directed graph:" << std::endl;
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }
    
    std::vector<int> inDegree, outDegree;
    
    computeDegrees(graph, inDegree, outDegree);
    
    std::cout << "Vertex\tIn-Degree\tOut-Degree" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        std::cout << i << "\t" << inDegree[i] << "\t\t" << outDegree[i] << std::endl;
    }
    
    return 0;
}
