/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void toGraph(TreeNode* root, unordered_map<int, vector<int>>& graph) {
        if(root == nullptr)
            return;

        if(root->left != nullptr) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);

            toGraph(root->left, graph);
        }

        if(root->right != nullptr) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);

            toGraph(root->right, graph);
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        toGraph(root, graph);

        unordered_set<int> visited;
        queue<pair<int, int>> q; //{node, time}
        q.push({start, 0});
        visited.insert(start);

        int t = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int tm = q.front().second;
            q.pop();

            t = max(tm, t);

            for(auto nei : graph[node]) {
                if(visited.find(nei) == visited.end()) {
                    visited.insert(nei);
                    q.push({nei, tm + 1});
                }
            }
        }

        return t;

    }
};