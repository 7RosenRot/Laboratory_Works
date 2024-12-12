#include "Graph.h"

Graph::Graph() {}
Graph::~Graph() {}

void Graph::addNode(const string& name) { m_Graph[name] = unordered_set<string>(); }

void Graph::crt_Node(const string& first_address, const string& second_address) {
    m_Graph[first_address].insert(second_address);
    m_Graph[second_address].insert(first_address);
}

void Graph::Print() const {
    int count = 0;
    for (const auto& pair : m_Graph) {
        count += 1;
        if (count < 10) { cout << ' '; }

        cout << count << ") " << "Neighbors of " << pair.first << " - ";
        for (const auto& place : pair.second) { cout << place << " "; }
        cout << endl;
    }
    cout << endl;
}

unordered_set<string> Graph::findNeighbors(const string& node) const {
    auto currentNode = m_Graph.find(node);
    if (currentNode != m_Graph.end()) { return currentNode->second; }
    return {};
}