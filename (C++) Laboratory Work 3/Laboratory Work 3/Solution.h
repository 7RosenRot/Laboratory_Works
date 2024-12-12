#pragma once
#include "Stack.h"
#include "Stack.cpp"
#include "Graph.h"

void firstSearchMethod(const Graph& m_Graph, const string& firstNode) {
    Stack<string> m_Stack;
    unordered_set<string> upLayer;

    m_Stack.Push(firstNode);

    while (!m_Stack.Empty()) {
        string currentNode = m_Stack.Pop();
        if (upLayer.find(currentNode) == upLayer.end()) {
            cout << currentNode << " ";
            upLayer.insert(currentNode);

            for (const auto& neighbor : m_Graph.findNeighbors(currentNode)) {
                if (upLayer.find(neighbor) == upLayer.end()) { m_Stack.Push(neighbor); }
            }
        }
    }
}

void secondSearchMethod(const Graph& m_Graph, const string& firstNode) {
    Stack<string> firstStack;
    Stack<string> secondStack;
    unordered_set<string> upLayer;

    firstStack.Push(firstNode);
    upLayer.insert(firstNode);

    while (!firstStack.Empty() || !secondStack.Empty()) {
        while (!firstStack.Empty()) {
            string currentNode = firstStack.Pop();
            cout << currentNode << " ";

            for (const auto& neighbor : m_Graph.findNeighbors(currentNode)) {
                if (upLayer.find(neighbor) == upLayer.end()) {
                    secondStack.Push(neighbor);
                    upLayer.insert(neighbor);
                }
            }
        }

        while (!secondStack.Empty()) {
            string currentNode = secondStack.Pop();
            cout << currentNode << " ";

            for (const auto& neighbor : m_Graph.findNeighbors(currentNode)) {
                if (upLayer.find(neighbor) == upLayer.end()) {
                    firstStack.Push(neighbor);
                    upLayer.insert(neighbor);
                }
            }
        }
    }
}