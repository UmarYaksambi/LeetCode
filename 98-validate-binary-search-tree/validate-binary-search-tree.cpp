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
    bool check(TreeNode* root, long min, long max) {
        if(root == nullptr)
            return true;

        bool isBST = true;

        if(root->left != nullptr) {
            if(root->left->val > min && root->left->val < root->val)
                isBST = isBST && true;
            else
                isBST = isBST && false;
        }
        if(root->right != nullptr) {
            if(root->right->val < max && root->right->val > root->val)
                isBST = isBST && true;
            else
                isBST = isBST && false;
        }

        return check(root->left, min, root->val) && check(root->right, root->val, max) && isBST;
    }


public:
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN, LONG_MAX);
    }
};