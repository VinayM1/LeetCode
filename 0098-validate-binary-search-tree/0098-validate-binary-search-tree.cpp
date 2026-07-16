class Solution {
public:

    TreeNode* prev = NULL;

    bool inorder(TreeNode* root){

        if(root == NULL){
            return true;
        }

        if(!inorder(root->left)){
            return false;
        }

        if(prev != NULL && prev->val >= root->val){
            return false;
        }

        prev = root;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {

        return inorder(root);
    }
};