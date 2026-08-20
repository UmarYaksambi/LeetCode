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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;

        if(root == nullptr)
            return preorder;

        auto cur = root;
        st.push(cur);

        while(!st.empty()) {
            cur = st.top();
            preorder.push_back(cur->val);
            st.pop();

            if(cur->right != nullptr)
                st.push(cur->right);
            if(cur->left != nullptr)
                st.push(cur->left);

        }

        return preorder;
    }
};