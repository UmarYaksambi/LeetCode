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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);

        auto head = root;

        while(true) {
            if(root->right == nullptr && root->val < val) {
                TreeNode* cur = new TreeNode(val);
                root->right = cur;
                break;
            }
            else if(root->left == nullptr && root->val > val) {
                TreeNode* cur = new TreeNode(val);
                root->left = cur;
                break;
            }
            else {
                if(root->val < val)
                    root = root->right;
                else
                    root = root->left;
            }
        }

        return head;
    }
};