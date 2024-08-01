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
    
    TreeNode* Convert(int l,int h,vector<int>& A) 
    {
        if(h<l) return nullptr;

        int m = l + (h-l)/2;

        TreeNode* a = new TreeNode(A[m]);
        a->left=Convert(l,m-1,A);
        a->right=Convert(m+1,h,A);

        return a;
    }

    TreeNode* sortedArrayToBST(vector<int>& A) {
        return Convert(0,A.size()-1,A);
    }

};