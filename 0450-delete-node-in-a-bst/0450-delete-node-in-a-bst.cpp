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
    TreeNode* Findmax(TreeNode*root){
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        

        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if (root->val<key){
            root->right = deleteNode(root->right,key);
        }
        

        
        else{

            if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
            }
            
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }   
            if(root->right != NULL && root->left != NULL){
               TreeNode* predecessor = Findmax(root->left);
                root->val = predecessor->val;
                root->left = deleteNode(root->left, predecessor->val);
            }
        }
        return root;
    }
};