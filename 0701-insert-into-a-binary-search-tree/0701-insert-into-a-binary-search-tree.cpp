class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL)
            return new TreeNode(val);

        TreeNode* originalRoot = root;
        TreeNode* prev = NULL;

        while(root != NULL){

            prev = root;

            if(val < root->val)
                root = root->left;
            else
                root = root->right;
        }

        TreeNode* newNode = new TreeNode(val);

        if(val < prev->val)
            prev->left = newNode;
        else
            prev->right = newNode;

        return originalRoot;
    }
};