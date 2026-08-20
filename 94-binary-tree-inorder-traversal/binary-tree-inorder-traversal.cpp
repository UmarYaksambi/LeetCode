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
 // github
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;

        if(root == nullptr)
            return inorder;

        auto cur = root;

        while(!st.empty() || cur != nullptr) {
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            inorder.push_back(cur->val);

            cur = cur->right;
        }

        return inorder;
    }
};