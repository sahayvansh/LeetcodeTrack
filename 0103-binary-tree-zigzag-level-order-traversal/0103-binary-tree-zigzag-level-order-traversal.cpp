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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL){
            return result;
        }
        bool ltr=true;
        while(!q.empty()){
            int qsize=q.size();
            vector<int> row(qsize);
            for(int i=0;i<qsize;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=ltr?i:qsize-i-1;
                row[index]=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ltr=!ltr;
            result.push_back(row);
        }
        return result;
    }

};