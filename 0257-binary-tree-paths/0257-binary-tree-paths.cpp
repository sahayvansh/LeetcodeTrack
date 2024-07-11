class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root != nullptr) {
            dfs(root, "", paths);
        }
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (node != nullptr) {
            path += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {  // Leaf node
                paths.push_back(path);  // Add path to results
            } else {
                path += "->";  // Append arrow for the next node
                dfs(node->left, path, paths);
                dfs(node->right, path, paths);
            }
        }
    }
};