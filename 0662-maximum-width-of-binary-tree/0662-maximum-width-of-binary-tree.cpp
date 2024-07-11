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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0,first,last;
        while(!q.empty()){
            int size=q.size();
            int min=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int newId=q.front().second-min;
                q.pop();
                if(i==0) first=newId;
                if(i==size-1) last=newId;
                if(node->left)
                    q.push({node->left,(long long)newId*2+1});
                if(node->right)
                    q.push({node->right,(long long)newId*2+2});
                
            }
            ans=max(last-first+1,ans);
        }
        return ans;
    }
};