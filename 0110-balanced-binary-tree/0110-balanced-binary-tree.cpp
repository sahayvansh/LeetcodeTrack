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
    bool isBalanced(TreeNode* root) {
        TreeNode* node=root;
        if(!node)
            return true;
        int ans=helper(node);
        return ans!=-1;
    }
    int helper(TreeNode* node){
        if(!node)
            return 0;
        int lh=helper(node->left);
        if(lh==-1)
            return -1;
        int rh=helper(node->right);
        if(rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        return 1+max(lh,rh);
    }
};