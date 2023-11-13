#include "nodestubesID.h"
#include <iostream>
#include <vector>

// Function for corner nodes
Node createCornerNode(int x, int y, int z) {
    Node node;
    node.x = x;
    node.y = y;
    node.z = z;
    return node;
}

// Function  body-centered nodes
Node createBodyCenteredNode(int x, int y, int z) {
    Node node;
    node.x = x;
    node.y = y;
    node.z = z;
    return node;
}

// Function to generate tube id
Tube createTube(Node node1, Node node2) {
    Tube tube;
    tube.node1 = node1;
    tube.node2 = node2;
    return tube;
}

int main() {
    int latticeSize = 3; 

    //  vectors to store nodes and tubes
    std::vector<Node> cornerNodes;
    std::vector<Node> bodyCenteredNodes;
    std::vector<Tube> tubes;

    // Generate nodes and tubes 
    for (int x = 0; x < latticeSize; x++) {
        for (int y = 0; y < latticeSize; y++) {
            for (int z = 0; z < latticeSize; z++) {
                
                Node cornerNode = createCornerNode(x, y, z);
                cornerNodes.push_back(cornerNode);

                 
                if (x < latticeSize - 1 && y < latticeSize - 1 && z < latticeSize - 1) {
                    Node bodyCenteredNode = createBodyCenteredNode(x + 1, y + 1, z + 1);
                    bodyCenteredNodes.push_back(bodyCenteredNode);

                    
                    Tube tube = createTube(cornerNode, bodyCenteredNode);
                    tubes.push_back(tube);
                }
            }
        }
    }
/*
    // Print the corner nodes
    std::cout << "Corner Nodes:\n";
    for (const Node& node : cornerNodes) {
        std::cout << "N(" << node.x << ", " << node.y << ", " << node.z << ")\n";
    }

    // Print the body-centered nodes
    std::cout << "Body-Centered Nodes:\n";
    for (const Node& node : bodyCenteredNodes) {
        std::cout << "N(" << node.x << ", " << node.y << ", " << node.z << ")\n";
    }

    // Print the tubes
    std::cout << "Tubes connected to corner nodes:\n";
    for (const Tube& tube : tubes) {
        std::cout << "T(" << tube.node1.x << ", " << tube.node1.y << ", " << tube.node1.z << ")";
        std::cout << " - ";
        std::cout << "N(" << tube.node2.x << ", " << tube.node2.y << ", " << tube.node2.z << ")\n";
    }
    */
    return 0;
}
