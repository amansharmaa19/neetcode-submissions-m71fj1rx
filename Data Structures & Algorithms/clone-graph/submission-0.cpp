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
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node*, Node*> visited;
        queue<pair<Node*, Node*>> q;
        Node* clonedGraph = new Node(node->val);
        q.push({node, clonedGraph});
        visited[node] = clonedGraph;

        // Perform BFS for graph clone
        while (!q.empty()) {
            pair<Node*, Node*> front = q.front();
            Node* oldNode = front.first;
            Node* newNode = front.second;
            q.pop();

            for (int i = 0; i < oldNode->neighbors.size(); i++) {
                Node* adjNode = oldNode->neighbors[i];
                if (!visited.contains(adjNode)) {
                    Node* newAdjNode = new Node(adjNode->val);
                    visited[adjNode] = newAdjNode;
                    q.push({adjNode, newAdjNode});
                }
                newNode->neighbors.push_back(visited[adjNode]);
            }
        }
        return clonedGraph;
    }
};
