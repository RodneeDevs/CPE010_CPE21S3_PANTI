#include "Graph.h"
#include <vector>

int main() {
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 3, 2, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {4, 0, 0, 0}
    };

    Graph<int> myGraph(adjacencyMatrix);

    myGraph.display();

    return 0;
}