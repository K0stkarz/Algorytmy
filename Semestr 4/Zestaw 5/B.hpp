#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream> 

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
class Graph {
private:
    std::unordered_map<VertexType, int> vertices;
    std::vector<VertexType> index_to_vertex;
    std::vector<std::vector<bool>> adjacency_matrix;
    std::unordered_map<VertexType, VertexValueType> vertex_values;
    std::unordered_map<std::string, EdgeValueType> edge_values;

    std::string createEdgeKey(const VertexType& x, const VertexType& y) const;

public:
    Graph() = default;
    ~Graph() = default;
    bool adjacent(const VertexType& x, const VertexType& y) const;
    std::vector<VertexType> neighbours(const VertexType& x) const;
    void addVertex(const VertexType& x);
    void removeVertex(const VertexType& x);
    void addEdge(const VertexType& x, const VertexType& y);
    void removeEdge(const VertexType& x, const VertexType& y);
    VertexValueType getVertexValue(const VertexType& x) const;
    void setVertexValue(const VertexType& x, const VertexValueType& v);
    EdgeValueType getEdgeValue(const VertexType& x, const VertexType& y) const;
    void setEdgeValue(const VertexType& x, const VertexType& y, const EdgeValueType& v);
    void generateDotFile(const std::string& filename) const;
};

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
std::string Graph<VertexType, VertexValueType, EdgeValueType>::createEdgeKey(const VertexType& x, const VertexType& y) const {
    int idx_x = vertices.at(x);
    int idx_y = vertices.at(y);
    return std::to_string(idx_x) + "_" + std::to_string(idx_y);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
bool Graph<VertexType, VertexValueType, EdgeValueType>::adjacent(const VertexType& x, const VertexType& y) const {
    if (vertices.find(x) == vertices.end() || vertices.find(y) == vertices.end()) {
        return false;
    }
    int idx_x = vertices.at(x);
    int idx_y = vertices.at(y);
    return adjacency_matrix[idx_x][idx_y];
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
std::vector<VertexType> Graph<VertexType, VertexValueType, EdgeValueType>::neighbours(const VertexType& x) const {
    std::vector<VertexType> result;
    if (vertices.find(x) == vertices.end()) {
        return result;
    }
    
    int idx_x = vertices.at(x);
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        if (adjacency_matrix[idx_x][i]) {
            result.push_back(index_to_vertex[i]);
        }
    }
    return result;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::addVertex(const VertexType& x) {
    if (vertices.find(x) != vertices.end()) {
        return;
    }
    
    int new_index = adjacency_matrix.size();
    vertices[x] = new_index;
    index_to_vertex.push_back(x);
    
    for (auto& row : adjacency_matrix) {
        row.push_back(false);
    }
    adjacency_matrix.push_back(std::vector<bool>(adjacency_matrix.size() + 1, false));
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::removeVertex(const VertexType& x) {
    if (vertices.find(x) == vertices.end()) {
        return;
    }
    
    int idx_x = vertices.at(x);
    
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        if (adjacency_matrix[idx_x][i]) {
            std::string key = createEdgeKey(x, index_to_vertex[i]);
            edge_values.erase(key);
        }
        if (adjacency_matrix[i][idx_x]) {
            std::string key = createEdgeKey(index_to_vertex[i], x);
            edge_values.erase(key);
        }
    }
    
    adjacency_matrix.erase(adjacency_matrix.begin() + idx_x);
    
    for (auto& row : adjacency_matrix) {
        row.erase(row.begin() + idx_x);
    }
    
    vertex_values.erase(x);
    
    index_to_vertex.erase(index_to_vertex.begin() + idx_x);
    vertices.erase(x);
    
    for (int i = 0; i < index_to_vertex.size(); ++i) {
        vertices[index_to_vertex[i]] = i;
    }
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::addEdge(const VertexType& x, const VertexType& y) {
    if (vertices.find(x) == vertices.end() || vertices.find(y) == vertices.end()) {
        return;
    }
    
    int idx_x = vertices.at(x);
    int idx_y = vertices.at(y);
    adjacency_matrix[idx_x][idx_y] = true;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::removeEdge(const VertexType& x, const VertexType& y) {
    if (vertices.find(x) == vertices.end() || vertices.find(y) == vertices.end()) {
        return;
    }
    
    int idx_x = vertices.at(x);
    int idx_y = vertices.at(y);
    
    if (adjacency_matrix[idx_x][idx_y]) {
        adjacency_matrix[idx_x][idx_y] = false;
        
        std::string key = createEdgeKey(x, y);
        edge_values.erase(key);
    }
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
VertexValueType Graph<VertexType, VertexValueType, EdgeValueType>::getVertexValue(const VertexType& x) const {
    if (vertex_values.find(x) == vertex_values.end()) {
        throw std::runtime_error("Vertex not found");
    }
    return vertex_values.at(x);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::setVertexValue(const VertexType& x, const VertexValueType& v) {
    if (vertices.find(x) == vertices.end()) {
        throw std::runtime_error("Vertex not found");
    }
    vertex_values[x] = v;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
EdgeValueType Graph<VertexType, VertexValueType, EdgeValueType>::getEdgeValue(const VertexType& x, const VertexType& y) const {
    if (!adjacent(x, y)) {
        throw std::runtime_error("Edge not found");
    }
    std::string key = createEdgeKey(x, y);
    return edge_values.at(key);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::setEdgeValue(const VertexType& x, const VertexType& y, const EdgeValueType& v) {
    if (!adjacent(x, y)) {
        throw std::runtime_error("Edge not found");
    }
    std::string key = createEdgeKey(x, y);
    edge_values[key] = v;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::generateDotFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    
    file << "digraph G {\n";
    
    for (const auto& vertex : index_to_vertex) {
        file << "    \"" << vertex << "\";\n";
    }
    
    for (const auto& x : index_to_vertex) {
        auto neighbors = neighbours(x);
        for (const auto& y : neighbors) {
            file << "    \"" << x << "\" -> \"" << y << "\";\n";
        }
    }
    
    file << "}\n";
    file.close();
}
