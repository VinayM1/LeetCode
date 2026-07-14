class Solution {
public:

    void Traversal(TreeNode* root, string path, vector<string>& ans)
    {
        if(root == NULL)
        {
            return;
        }

        if(path.empty())
        {
            path = to_string(root->val);
        }
        else
        {
            path = path + "->" + to_string(root->val);
        }

        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return;
        }

        Traversal(root->left, path, ans);
        Traversal(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;

        string path = "";

        Traversal(root, path, ans);

        return ans;
    }
};