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

    void preOrder(TreeNode* root, int level, vector<int>&ans){
        if(!root) return;

        if(ans.size()<level){
            ans.push_back(root->val);
        }

        preOrder(root->right,level+1,ans);
        preOrder(root->left,level+1,ans);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        preOrder(root,1,ans);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) {
//             return {};
//         }
//     queue<TreeNode*> que;
//     vector<int>ans;

//     que.push(root);

//     while(!que.empty()){
//         int n=que.size();
//         TreeNode* node = NULL;

//         while(n--){
//             node = que.front();
//             que.pop();
//             if(node->left){
//                 que.push(node->left);
//             }
//             if(node->right){
//                 que.push(node->right);
//             }
//         }
//             ans.push_back(node->val);
//         }
//         return ans;
//     }

// };