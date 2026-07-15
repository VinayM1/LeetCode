/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<int,int> inorderIndex;

    TreeNode* build(vector<int>& inorder,
                    int inStart,
                    int inEnd,
                    vector<int>& postorder,
                    int postStart,
                    int postEnd)
    {
        if(inStart > inEnd || postStart > postEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int index = inorderIndex[root->val];

        int leftNodes = index - inStart;

        root->left = build(inorder,
                           inStart,
                           index - 1,
                           postorder,
                           postStart,
                           postStart + leftNodes - 1);

        root->right = build(inorder,
                            index + 1,
                            inEnd,
                            postorder,
                            postStart + leftNodes,
                            postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }

        return build(inorder,
                     0,
                     inorder.size() - 1,
                     postorder,
                     0,
                     postorder.size() - 1);
    }
};