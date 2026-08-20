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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int size = 0, depth = 0;
        auto cur = root;

        if(root == nullptr)
            return 0;

        q.push(root);

        while(!q.empty()) {
            size = q.size();
            for(int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();

                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }

            depth++;
        }

        return depth;

    }
};