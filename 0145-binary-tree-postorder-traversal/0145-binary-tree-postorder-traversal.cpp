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
    void pot(TreeNode* node, vector<int>& result) {
        if (!node) return;
        
        pot(node->left, result);               // Traverse left
        pot(node->right, result);    // Traverse right
        result.push_back(node->val);           // Visit root          
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        pot(root, result);
        return result;
    }
};
