/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
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
*/

class Solution {
private:
    Node * cloneGraphWorker(Node* node, unordered_map<Node*, Node*> &mapper) {
        if (!node) {
            return node;
        }
        const auto &it = mapper.find(node);
        if (it != mapper.end()) {
            return it->second;
        }
        Node *cloned = new Node(node->val);
        mapper[node] = cloned;
        for (Node *child : node->neighbors) {
            cloned->neighbors.push_back(cloneGraphWorker(child, mapper));
        }
        return cloned;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mapper;
        return cloneGraphWorker(node, mapper);        
    }
};