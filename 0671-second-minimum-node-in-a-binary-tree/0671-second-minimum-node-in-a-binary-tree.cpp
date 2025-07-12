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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int minVal = root->val;
        long secondMin = LONG_MAX;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            if (node->val > minVal && node->val < secondMin) {
                secondMin = node->val;
            }
            dfs(node->left);
            dfs(node->right);
        };
        
        dfs(root);
        return secondMin == LONG_MAX ? -1 : secondMin;
    }
};
