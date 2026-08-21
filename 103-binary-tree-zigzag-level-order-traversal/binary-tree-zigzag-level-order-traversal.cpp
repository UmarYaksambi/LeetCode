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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        int size = 0;
        bool zig = false;

        if(root == nullptr)
            return levels;

        q.push(root);

        while(!q.empty()) {
            size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
            
            if(zig)
                reverse(level.begin(), level.end());

            levels.push_back(level);
            zig = !zig;
        }

        return levels;
    }
};