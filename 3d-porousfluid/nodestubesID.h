#pragma once

#include <vector>

// node struct
struct Node {
    int x, y, z;
};

// struct tube
struct Tube {
    Node node1;
    Node node2;
};

// Function to generate node id for corner nodes
Node createCornerNode(int x, int y, int z);

// Function to generate node  body-centered nodes
Node createBodyCenteredNode(int x, int y, int z);

// Function to generate tube identities
Tube createTube(Node node1, Node node2);