/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode*root, unordered_map<TreeNode*,TreeNode*>& parent){
        if(root == NULL){
            return ;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,bool>visited;
        markparent(root,parent);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]= true;
        int currdis = 0;
        while(!q.empty()){
            if(currdis == k){
                break;
            }
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->left!=NULL && visited[node->left]== false){
                    visited[node->left] = true;
                    q.push(node->left);
                    
                }
                if(node->right!=NULL && visited[node->right] == false){
                    visited[node->right] = true;
                    q.push(node->right);
                    
                }
                if(parent[node]!=NULL && visited[parent[node]]== false){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
                
            }
            currdis++;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};