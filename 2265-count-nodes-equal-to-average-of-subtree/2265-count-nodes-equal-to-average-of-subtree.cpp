class Solution {
public:

    int ans = 0;

    pair<int,int> dfs(TreeNode* root) {

        if(root == NULL) {
            return {0, 0};
        }

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        int average = sum / count;

        if(root->val == average) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        dfs(root);

        return ans;
    }
};