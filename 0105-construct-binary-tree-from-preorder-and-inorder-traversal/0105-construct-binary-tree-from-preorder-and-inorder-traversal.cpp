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
    int preIndex = 0;
    unordered_map<int, int> inorderIndex; // To speed up index lookup

    TreeNode* buildTreeHelper(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Leaf node condition
        if (inStart == inEnd) return root;

        int inIndex = inorderIndex[rootVal];

        root->left = buildTreeHelper(preorder, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        // Fill value-to-index map for inorder
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};
