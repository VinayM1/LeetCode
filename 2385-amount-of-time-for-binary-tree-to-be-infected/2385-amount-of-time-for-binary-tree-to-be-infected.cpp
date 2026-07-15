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
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent , TreeNode*& target,int start){
        if(root == NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node->val == start){
                target = node;
            }
            
            if(node->left!=NULL){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right!=NULL){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,bool> infected;
        queue<TreeNode*> q;
        TreeNode* target = NULL;
        markparent(root,parent,target,start);
        q.push(target);
        infected[target]= true;
        int min = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->left!=NULL && infected[node->left]==false){
                    infected[node->left] = true;
                    q.push(node->left);
                }
                if(node->right!=NULL && infected[node->right]==false){
                    infected[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node]!=NULL && infected[parent[node]] == false){
                    infected[parent[node]] = true;
                    q.push(parent[node]);
                }
               
            }
            if(!q.empty())
            {
                min++;
            }
            
        }
  
    return min;


    }
};