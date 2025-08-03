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
        if(!root)
        return{};

         queue<TreeNode*> que;
        vector<int> result;
         que.push(root);
        while(!que.empty()){
            
            TreeNode* node = NULL;
            int n=que.size();
            while(n--){
                node = que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            result.push_back(node->val);

        }
        return result;
    }
};