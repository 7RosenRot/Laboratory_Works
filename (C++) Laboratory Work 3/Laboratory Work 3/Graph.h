#pragma once
#include "Headers.h"
using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> m_Graph;
public:
    Graph();
    ~Graph();

    void addNode(const string& name);
    void crt_Node(const string& first_address, const string& second_address);
    void Print() const;
    unordered_set<string> findNeighbors(const string& node) const;
};