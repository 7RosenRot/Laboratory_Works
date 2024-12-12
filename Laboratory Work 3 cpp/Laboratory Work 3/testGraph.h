#pragma once
#include "Stack.h"
#include "Graph.h"
#include "Solution.h"

/*
            A          H
          /   \      / | \
         B     C    J  K  L
        / \   / \
       D   E F   G
*/

void crt_firstGraph(Graph& exampleGraph) {
        /*������� 1*/
    exampleGraph.addNode("A");

        /*������� 2*/
    exampleGraph.addNode("B");
    exampleGraph.addNode("C");
    exampleGraph.addNode("D");

        /*������� 3*/
    exampleGraph.addNode("E");
    exampleGraph.addNode("F");
    exampleGraph.addNode("G");

        /*������ ����*/
    exampleGraph.crt_Node("A", "B");
    exampleGraph.crt_Node("A", "C");

    exampleGraph.crt_Node("B", "D");
    exampleGraph.crt_Node("B", "E");

    exampleGraph.crt_Node("C", "F");
    exampleGraph.crt_Node("C", "G");
}

void crt_secondGraph(Graph& exampleGraph) {
        /*������� 1*/
    exampleGraph.addNode("H");

        /*������� 2*/
    exampleGraph.addNode("J");
    exampleGraph.addNode("K");
    exampleGraph.addNode("L");

        /*������ ����*/
    exampleGraph.crt_Node("H", "J");
    exampleGraph.crt_Node("H", "K");
    exampleGraph.crt_Node("H", "L");
}

void testSearch(Graph exampleGraph) {
    cout << "Depth First Search:" << endl;
    firstSearchMethod(exampleGraph, "A");
    cout << endl;

    cout << "Breadth First Search:" << endl;
    secondSearchMethod(exampleGraph, "A");
    cout << endl;
}

void testStart() {
    Graph exampleGraph;

    crt_firstGraph(exampleGraph);
    crt_secondGraph(exampleGraph);

    exampleGraph.Print();

    testSearch(exampleGraph);
}