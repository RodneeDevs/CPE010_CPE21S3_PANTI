#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template <typename T>
class Graph {
private:
    std::vector<char> vertices;
    std::vector<std::vector<T>> adjMatrix;

public:
    Graph(const std::vector<std::vector<T>>& matrix) : adjMatrix(matrix) {
        size_t size = adjMatrix.size();
        vertices.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            vertices[i] = static_cast<char>('A' + i);
        }
    }

    void display() const {
        std::cout << "Adjacency Matrix representation of the graph:\n\n";
        
        std::cout << "    ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            std::cout << vertices[i] << "  ";
        }
        std::cout << "\n";

        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            std::cout << vertices[i] << "   ";
            for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
                std::cout << adjMatrix[i][j] << "  ";
            }
            std::cout << "\n";
        }
    }
};

#endif