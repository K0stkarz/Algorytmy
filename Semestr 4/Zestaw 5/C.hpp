#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
class Graph {
private:
    std::unordered_map<VertexType, std::unordered_set<VertexType>> adjacency_list;
    std::unordered_map<VertexType, VertexValueType> vertex_values;
    std::unordered_map<VertexType, std::unordered_map<VertexType, EdgeValueType>> edge_values;

public:
    Graph() = default;
    Graph(const Graph& other) = default;
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
};

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
bool Graph<VertexType, VertexValueType, EdgeValueType>::adjacent(const VertexType& x, const VertexType& y) const {
    auto it = adjacency_list.find(x);
    if (it == adjacency_list.end()) return false;
    return it->second.find(y) != it->second.end();
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
std::vector<VertexType> Graph<VertexType, VertexValueType, EdgeValueType>::neighbours(const VertexType& x) const {
    std::vector<VertexType> result;
    auto it = adjacency_list.find(x);
    if (it != adjacency_list.end()) {
        for (const auto& neighbor : it->second) {
            result.push_back(neighbor);
        }
    }
    return result;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::addVertex(const VertexType& x) {
    if (adjacency_list.find(x) != adjacency_list.end()) {
        return;
    }
    adjacency_list[x] = std::unordered_set<VertexType>();
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::removeVertex(const VertexType& x) {
    if (adjacency_list.find(x) == adjacency_list.end()) {
        return;
    }
    adjacency_list.erase(x);
    edge_values.erase(x);
    for (auto& pair : adjacency_list) {
        auto& neighbors = pair.second;
        if (neighbors.erase(x) > 0) {
            edge_values[pair.first].erase(x);
        }
    }
    vertex_values.erase(x);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::addEdge(const VertexType& x, const VertexType& y) {
    if (adjacency_list.find(x) == adjacency_list.end() || adjacency_list.find(y) == adjacency_list.end()) {
        return;
    }
    adjacency_list[x].insert(y);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::removeEdge(const VertexType& x, const VertexType& y) {
    auto x_it = adjacency_list.find(x);
    if (x_it == adjacency_list.end()) {
        return;
    }
    auto& neighbors = x_it->second;
    if (neighbors.erase(y) > 0) {
        edge_values[x].erase(y);
    }
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
VertexValueType Graph<VertexType, VertexValueType, EdgeValueType>::getVertexValue(const VertexType& x) const {
    auto it = vertex_values.find(x);
    if (it == vertex_values.end()) {
        throw std::runtime_error("Vertex not found");
    }
    return it->second;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::setVertexValue(const VertexType& x, const VertexValueType& v) {
    if (adjacency_list.find(x) == adjacency_list.end()) {
        throw std::runtime_error("Vertex not found");
    }
    vertex_values[x] = v;
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
EdgeValueType Graph<VertexType, VertexValueType, EdgeValueType>::getEdgeValue(const VertexType& x, const VertexType& y) const {
    if (!adjacent(x, y)) {
        throw std::runtime_error("Edge not found");
    }
    return edge_values.at(x).at(y);
}

template <typename VertexType, typename VertexValueType, typename EdgeValueType>
void Graph<VertexType, VertexValueType, EdgeValueType>::setEdgeValue(const VertexType& x, const VertexType& y, const EdgeValueType& v) {
    if (!adjacent(x, y)) {
        throw std::runtime_error("Edge not found");
    }
    edge_values[x][y] = v;
}