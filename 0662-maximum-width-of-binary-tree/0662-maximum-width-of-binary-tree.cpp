class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty())
        {
            int n = q.size();

            long long first = q.front().second;

            long long left = 0;
            long long right = 0;

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front().first;

                long long index = q.front().second - first;

                q.pop();

                if(i == 0)
                {
                    left = index;
                }

                if(i == n - 1)
                {
                    right = index;
                }

                if(node->left != NULL)
                {
                    q.push({node->left, 2 * index + 1});
                }

                if(node->right != NULL)
                {
                    q.push({node->right, 2 * index + 2});
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};