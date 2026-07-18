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

class NodeValue{
public:
    int MinNode;
    int MaxNode;
    int sum;
    NodeValue(int MinNode, int MaxNode , int sum ){
        this->MinNode = MinNode;
        this->MaxNode = MaxNode;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans = 0;
    NodeValue solve(TreeNode* root){
        if(root == NULL){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);
        if(root->val > left.MaxNode && root->val < right.MinNode){
            int cursum = left.sum + right.sum + root->val;
            ans = max(ans,cursum);
            return NodeValue(
                min(root->val,left.MinNode),
                max(root->val,right.MaxNode),
                cursum
                
            );
        }
        
        return NodeValue(
            INT_MIN,
            INT_MAX,
            0
        );
    }
    int maxSumBST(TreeNode* root) {
      solve(root);
      return ans;
    }
};