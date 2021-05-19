#include <vector>
#include <iostream>
#include <map>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 1;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* copy(Node* node, map<Node*, Node*>& nodemap) {
    if (nodemap.find(node) == nodemap.end()) {
        Node* newnode = new Node(node->val);
        nodemap[node] = newnode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            newnode->neighbors.push_back(copy(node->neighbors[i], nodemap));
        }
        return newnode;
    }
    else {
        return nodemap[node];
    }
}

// note without the map the function while continuously create space for seen nodes;
Node* cloneGraph(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    map<Node*, Node*> nodemap;
    return copy(node, nodemap);
}