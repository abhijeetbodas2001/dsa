// Problem: https://leetcode.com/problems/clone-graph/

// Basic DFS
// O(n) time, O(n) space

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
    unordered_map<Node*, Node*> clones;
public:
    Node* cloneGraph(Node* node) {
        if (clones.find(node) != clones.end()) {
            return clones[node];
        }

        Node* clone = new Node(node -> val);
        clones[node] = clone;

        for (Node* neighbor: node -> neighbors) {
            (clone -> neighbors).push_back(
                cloneGraph(neighbor)
            );
        }

        // Note! Don't set the map key here (but do that before the loop).
        // Not setting the key before the loop will cause infinite recursion,
        // because `clone` is a neighbor of `clone`'s neighbor too.
        // clones[node] = clone;
        return clone;
    }
};