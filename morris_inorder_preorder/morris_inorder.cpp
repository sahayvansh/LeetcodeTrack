#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* f_left = curr->left;   
                while(f_left->right && f_left->right!=curr){
                    f_left=f_left->right;
                }
                if(f_left->right==NULL){
                    f_left->right=curr;
                    curr=curr->left;
                }
                else{
                    f_left->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->right=new TreeNode(6);

    // Create a Solution object
    Solution sol;

    // Call the inorderTraversal function
    vector<int> result = sol.inorderTraversal(root);

    // Print the result
    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (important to avoid memory leaks)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}