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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;

        if(root == nullptr)
            return res;

        q.push(root);

        int size = 0;
        vector<int> level;

        while(!q.empty()) {
            size = q.size();

            for(int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                
                level.push_back(cur->val);

                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }

            res.push_back(level[level.size() - 1]);
            level.clear();
        }

        return res;
    }
};