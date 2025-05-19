#include "graph.hpp"
#include <iostream>

int main() {
    const int N = 8;
    Graph<std::string, int, int> knight_graph;
    
    // Create all chessboard positions
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string pos = std::string(1, col) + std::to_string(row);
            knight_graph.addVertex(pos);
        }
    }
    
    // Add knight moves
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (char col = 'a'; col <= 'h'; ++col) {
        for (int row = 1; row <= 8; ++row) {
            std::string pos = std::string(1, col) + std::to_string(row);
            int x = row - 1;
            int y = col - 'a';
            
            for (int k = 0; k < 8; ++k) {
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                
                if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
                    char new_col = 'a' + new_y;
                    int new_row = new_x + 1;
                    std::string new_pos = std::string(1, new_col) + std::to_string(new_row);
                    knight_graph.addEdge(pos, new_pos);
                }
            }
        }
    }
    
    // Get starting position
    std::string start_pos;
    std::cout << "Enter starting position (e.g., a1): ";
    std::cin >> start_pos;
    
    // Validate input
    if (start_pos.length() != 2) {
        std::cerr << "Invalid input format. Use chess notation like a1.\n";
        return 1;
    }
    
    char col = tolower(start_pos[0]);
    char row = start_pos[1];
    
    if (col < 'a' || col > 'h' || !isdigit(row) || row < '1' || row > '8') {
        std::cerr << "Invalid position. Use format a1-h8.\n";
        return 1;
    }
    start_pos = std::string(1, col) + row;
    
    // Find knight's tour
    std::vector<std::string> path = find_knight_tour(knight_graph, start_pos, N);
    
    if (path.size() != N*N) {
        std::cout << "Full tour not found. Found path length: " << path.size() << "\n";
        return 1;
    }
    
    // Generate visualization
    generateDotFile(path, "knight_tour.dot");
    std::cout << "Knight's tour generated in knight_tour.dot\n";
    
    return 0;
}