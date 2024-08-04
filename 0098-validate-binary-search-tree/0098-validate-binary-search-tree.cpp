/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isValidBST(TreeNode *root)
        {
            return helper(root,LONG_MIN,LONG_MAX);
        }
        bool helper(TreeNode *root, long lr,long rr){
            if(root==NULL)
                return true;
            if(root->val <= lr || root->val  >= rr)
                return false;
            bool leftCheck=helper(root->left, lr, root->val);
            bool rightCheck=helper(root->right, root->val,rr);
            if(leftCheck&&rightCheck)
                return true;
            return false;
        }
};